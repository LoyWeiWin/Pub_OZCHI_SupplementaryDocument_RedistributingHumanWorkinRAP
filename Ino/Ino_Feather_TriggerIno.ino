/*
  HUZZAH Feather (ESP8266)
  Microswitch Edge Counter + WiFi UDP (stable upload edition)
  ------------------------------------------------------------
  - +1 only on press edge (hold ignored)
  - Wraps to 0 after configurable limit (default 75)
  - Outputs integer over Serial + UDP
  - Responds to Serial/UDP commands:
      R, L=123, INFO, PORT?, LPORT?, HOST=..., SPORT=..., LPORT=..., PING

  Upload tips:
    • Board: Adafruit HUZZAH ESP8266
    • Upload speed: 115200
    • Reset method: ck
    • Press BOOT, tap RST when "Connecting..." appears.

  Wiring:
    C  -> GND
    NO -> D5 (GPIO14)
    NC -> not connected
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// === WiFi setup ===
const char* WIFI_SSID     = "Loy's S23";
const char* WIFI_PASSWORD = "00000000";

String   targetHostStr = "10.170.230.199";   // your PC's LAN IP
uint16_t udpSendPort   = 9000;               // outgoing stream to GH
uint16_t udpListenPort = 9100;               // incoming commands from GH

// === Pin + logic ===
const uint8_t PIN_SWITCH = 14;               // D5
const unsigned long DEBOUNCE_MS = 30;
const unsigned long PRINT_INTERVAL_MS = 50;

// --- NEW: onboard LED (HUZZAH red LED = GPIO0, active-LOW) ---
const uint8_t LED_PIN = 0;

int           countVal = 0;
int           limitVal = 72;
bool          rawState = HIGH;
bool          lastRawState = HIGH;
bool          stableState = HIGH;
bool          lastStableState = HIGH;
unsigned long lastChangeMs = 0;
unsigned long lastPrintMs  = 0;

WiFiUDP udp;
IPAddress targetIP;

void applyHost(const String& host) {
  targetHostStr = host;
  if (!targetIP.fromString(targetHostStr)) {
    IPAddress resolved;
    if (WiFi.hostByName(targetHostStr.c_str(), resolved)) targetIP = resolved;
    else targetIP = IPAddress(255,255,255,255);
  }
}

void handleCommand(const String& cmdRaw) {
  String cmd = cmdRaw; cmd.trim();
  if (!cmd.length()) return;

  if (cmd.equalsIgnoreCase("R")) {
    countVal = 0;
    Serial.println("Reset OK");
  } else if (cmd.startsWith("L=")) {
    int newLimit = cmd.substring(2).toInt();
    if (newLimit > 0) { limitVal = newLimit; Serial.print("Limit="); Serial.println(limitVal); }
  } else if (cmd.equalsIgnoreCase("INFO")) {
    Serial.print("IP: "); Serial.println(WiFi.localIP());
    Serial.print("Host: "); Serial.println(targetHostStr);
    Serial.print("SendPort: "); Serial.println(udpSendPort);
    Serial.print("ListenPort: "); Serial.println(udpListenPort);
    Serial.print("Count: "); Serial.println(countVal);
    Serial.print("Limit: "); Serial.println(limitVal);
  } else if (cmd.startsWith("HOST=")) {
    applyHost(cmd.substring(5)); Serial.println("Host updated");
  } else if (cmd.startsWith("SPORT=")) {
    udpSendPort = (uint16_t)cmd.substring(6).toInt(); Serial.println("SendPort updated");
  } else if (cmd.startsWith("LPORT=")) {
    udp.stop(); udpListenPort = (uint16_t)cmd.substring(6).toInt(); udp.begin(udpListenPort);
    Serial.println("ListenPort updated");
  } else if (cmd.equalsIgnoreCase("PING")) {
    Serial.println("PONG");
  }
}

void setup() {
  Serial.begin(115200);
  delay(200);                       // small pause only (safe for bootloader)

  pinMode(PIN_SWITCH, INPUT_PULLUP);

  // --- NEW: LED setup ---
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);      // LED off (active-LOW)

  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);             // keep WiFi fully awake for stable cadence
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Blink while connecting (max ~8s)
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 8000) {
    digitalWrite(LED_PIN, LOW);     // ON
    delay(150);
    digitalWrite(LED_PIN, HIGH);    // OFF
    delay(150);
  }

  if (WiFi.status() == WL_CONNECTED) {
    udp.begin(udpListenPort);
    digitalWrite(LED_PIN, LOW);     // solid ON → connected
  } else {
    digitalWrite(LED_PIN, HIGH);    // OFF → not connected
  }

  applyHost(targetHostStr);
  Serial.println("HUZZAH ready");
}

void loop() {
  const unsigned long now = millis();

  // --- NEW: keep LED synced & try auto-reconnect if needed ---
  static unsigned long lastNetCheck = 0;
  if (now - lastNetCheck > 3000) {
    if (WiFi.status() != WL_CONNECTED) {
      digitalWrite(LED_PIN, HIGH);  // OFF
      WiFi.reconnect();             // try to come back
    } else {
      digitalWrite(LED_PIN, LOW);   // ON
    }
    lastNetCheck = now;
  }

  // Edge detect
  bool reading = digitalRead(PIN_SWITCH);
  if (reading != lastRawState) lastChangeMs = now;
  if ((now - lastChangeMs) >= DEBOUNCE_MS && reading != stableState) {
    stableState = reading;
    if (lastStableState == HIGH && stableState == LOW) {
      countVal++;
      if (countVal > limitVal) countVal = 0;
    }
    lastStableState = stableState;
  }
  lastRawState = reading;

  // Periodic output
  if (now - lastPrintMs >= PRINT_INTERVAL_MS) {
    Serial.println(countVal);
    if (WiFi.status() == WL_CONNECTED) {
      udp.beginPacket(targetIP, udpSendPort);
      udp.print(countVal); udp.print('\n');
      udp.endPacket();
    }
    lastPrintMs = now;
  }

  // Serial commands
  if (Serial.available()) handleCommand(Serial.readStringUntil('\n'));

  // UDP commands
  int packetSize = udp.parsePacket();
  if (packetSize) {
    char buf[128]; int len = udp.read(buf, sizeof(buf)-1);
    if (len > 0) { buf[len] = 0; handleCommand(String(buf)); }
  }
}
