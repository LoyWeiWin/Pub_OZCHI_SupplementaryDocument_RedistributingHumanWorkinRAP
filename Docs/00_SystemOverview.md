# System Overview

## Purpose and scope

This project supports robotic-assisted photogrammetry and focus stacking for small museum objects. Its research focus is how partial automation redistributes work across calibration, capture, device handoffs, monitoring, data organisation, and output assessment.

The documented study comprised four acquisition sessions involving three artefacts. It was an exploratory, researcher-operated workflow investigation, rather than a controlled performance benchmark or a broader practitioner usability study.

## Hardware

| Component | Documented role |
| --- | --- |
| Universal Robots UR10 collaborative robotic arm | Moves the imaging assembly between programmed viewpoints |
| Canon 1300D camera | Captures images for reconstruction |
| Cognisys StackShot macro rail | Moves the camera along the optical axis for focal sequences |
| Cognisys actuated turntable | Rotates the artefact between capture positions |
| StackShot controller | Coordinates rail and turntable operations |
| Mechanical microswitch | Supports the focus-stacked handoff to the next robotic elevation |
| Windows workstation | Supports configuration, control, and image processing |
| Lighting and backdrop | Support image acquisition |

The setup was configured for artefacts approximately 2–5 cm in size. Camera, rail, and mounting hardware form a relatively large, offset end effector, so clearance must account for the whole assembly and its travel.

## Software and registration

Grasshopper provides robotic control within the Rhino environment. Robot pose data accessed through real-time data exchange (RTDE) supports registration of the turntable centre and rotational axis relative to the robot base. The camera lens position is defined relative to the tool flange, and the imaging end effector's tool centre point is calibrated before capture. The approximate artefact centre defines the focal target.

RealityScan is used for photogrammetric reconstruction. Focus-stack generation precedes reconstruction in the focus-stacked configuration. Exact plugin versions, stack-processing software, robot communication settings, and wiring are not fully specified in the paper and require verification against the implementation.

## Capture configurations

| Setting | Standard capture | Focus-stacked capture |
| --- | --- | --- |
| Study artefacts | Pot and Sarcophagus | Red Dragon |
| Turntable increment | 5° | 10° |
| Images per rotational position | One | Multiple focal slices, combined before reconstruction |
| Typical camera elevations | Approximately 0°, 20°, 40°, and 60° | Approximately 0°, 20°, 40°, and 60° |
| Elevation handoff | Operator communication followed by robotic repositioning | Rail-triggered microswitch supports robotic repositioning |
| Operator checks | Framing, coverage, image suitability | Framing, focal range, rail clearance, and stack suitability |

These settings describe the study and are not universal acquisition prescriptions. The Pot received an additional elevation, and the Sarcophagus an additional lighting sequence, following expert assessment.

## Workflow and human responsibilities

1. Prepare lighting, backdrop, artefact placement, and the imaging assembly.
2. Register the robot, turntable, camera, and focal target; check the full motion envelope.
3. Capture the programmed rotational sequence at each elevation.
4. Verify framing and capture state at handoffs; adjust focal range when necessary.
5. Manually reorient the artefact to expose occluded surfaces, then repeat capture as needed.
6. Review images, generate focal stacks where applicable, mask datasets, reconstruct, align, and merge outputs.
7. Assess coverage and surface detail against the intended documentation task.

Robotic positioning does not remove operator judgement. Errors in calibration can propagate through a sequence and become apparent only during later review.

## Evaluation boundaries

Outputs were assessed through expert review and, where available, CT-derived reference meshes. Meshes were manually pre-aligned, uniformly rescaled, and refined using iterative closest point registration before surface-distance analysis. Signed mean deviations can conceal local variation and do not establish absolute accuracy. No CT reference was available for the Red Dragon.

See [installation](01_InstallationGuide.md), [usage](02_UsageInstructions.md), and the [project README](README.md).
