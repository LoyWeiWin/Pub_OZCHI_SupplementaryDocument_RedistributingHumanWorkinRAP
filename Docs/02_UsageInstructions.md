# Usage Instructions

## Before capture

Complete the [installation and calibration checks](01_InstallationGuide.md). Inspect the actual Grasshopper definition and controller configuration for execution controls; this guide does not invent component names or button labels.

Record the artefact identifier, orientation, workflow, elevation, rotational increment, lighting, and relevant camera settings. For focus-stacked capture, also record rail travel and focal-stack grouping. This logging scheme is recommended to keep source images traceable to reconstruction inputs.

## Standard photogrammetric capture

1. Place the artefact in its initial orientation and verify the focal target, framing, lighting, and clearance.
2. Capture one image at each turntable position. The study used 5° increments.
3. At completion of the rotational sequence, confirm completion before moving the robot to the next elevation. In the documented setup, the imaging operator informed the robot operator, who initiated repositioning.
4. Recheck framing and image suitability after repositioning, then continue capture. The study used elevations of approximately 0°, 20°, 40°, and 60°.
5. Inspect coverage and add views or adjust lighting where justified. The study included an extra elevation for the Pot and an additional lighting sequence for the Sarcophagus.

## Focus-stacked capture

1. Verify that the artefact remains framed and clear of the imaging assembly throughout the rail's full travel.
2. Set a focal range that covers the apparent artefact depth at the current camera elevation.
3. Capture multiple focal slices at each rotational position. The study used 10° turntable increments to offset the additional capture time.
4. Monitor the StackShot-controlled rail and turntable sequence. The documented microswitch handoff supported movement to the next programmed robotic elevation after the rail reached the end of its travel.
5. After robotic repositioning, verify framing and adjust the focal range where necessary before continuing. Higher elevations reduced apparent artefact depth in the study, allowing fewer focal slices.
6. Preserve each focal sequence as an identifiable group for subsequent stack generation.

The handoff is only partially automated. It does not replace operator checks of framing, focal coverage, or clearance.

## Additional object orientations

Upright capture may leave underside and support-contact regions undocumented. The study generally used at least two object orientations. Pause the workflow, manually reposition the artefact using appropriate handling procedures, recheck alignment and framing, and capture the newly exposed surfaces. Keep orientation datasets distinct so they can be reviewed, masked, and aligned during processing.

## Post-processing

1. Review source images for blur, cropping, missing views, and inconsistent capture.
2. For focus-stacked capture, combine each focal sequence into an extended-depth-of-field image before photogrammetric reconstruction. Review the stacks before proceeding.
3. Import the relevant images into RealityScan. Review alignment and reconstruction rather than assuming all orientations will merge automatically.
4. Mask separate orientation datasets as needed, align them, and merge reconstructed outputs to improve coverage.
5. Inspect holes, smoothing, surface detail, and incomplete regions. The paper reports that some repair work required another application; no universal repair procedure is specified.
6. Retain source images, stacks, masks, settings, intermediate outputs, and final meshes with their relationships documented.

## Output review and records

Assess whether the model is adequate for its intended use. A visually coherent partial model may support viewing or public engagement while remaining insufficient for complete archival documentation or measurement of occluded regions.

Record image count, acquisition duration, dataset size, processing time, calibration effort, and post-processing effort where available. The study estimated acquisition duration from the first and last image EXIF timestamps, including necessary adjustments during acquisition. This interval is not a measure of total labour or total workflow duration.

Where a CT-derived reference mesh is available, document pre-alignment, uniform rescaling, ICP registration, and surface-distance calculation. Interpret the resulting deviations as relative surface agreement after alignment and rescaling, rather than absolute dimensional accuracy. The study had no CT-derived reference for the Red Dragon.

## Troubleshooting

| Observation | Checks and response |
| --- | --- |
| Artefact is cropped or shifts across focal slices | Recheck framing, focal target, registration, and full rail travel before restarting |
| Coverage is incomplete | Review elevations, rotational overlap, object orientation, and occluded surfaces |
| Next elevation does not begin | Verify capture completion and the configured operator or microswitch handoff before initiating further motion |
| Focal stack is incomplete | Review focal range and source slices for the current elevation |
| Orientation datasets fail to align | Review image suitability, masking, overlap, and reconstruction settings |
| Reconstruction has holes or smoothing | Check source coverage and processing settings; assess whether recapture or further processing is justified |

See the [system overview](00_SystemOverview.md) for configuration differences and evaluation limits.
