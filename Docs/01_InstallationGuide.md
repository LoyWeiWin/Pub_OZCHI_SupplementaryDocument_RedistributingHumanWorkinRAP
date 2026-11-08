# Installation and Setup Guide

## Scope

This guide summarises preparation for the robotic-assisted imaging workflow documented in the OzCHI paper. The supplied Markdown files previously described a separate AR welding project. Those project-specific requirements have been removed.

The paper does not specify enough implementation detail for a complete, independently reproducible installation. Confirm software versions, Grasshopper dependencies, communication parameters, trigger wiring, and controller configuration from the actual Rhino/Grasshopper files and manufacturer documentation before operation.

## Prepare hardware and software

1. Prepare the UR10, Canon 1300D, Cognisys StackShot macro rail, actuated turntable, controller, lighting, backdrop, and Windows workstation.
2. Secure the camera, rail, and mounting assembly. Account for the offset assembly and the full rail travel when assessing payload and clearance.
3. Prepare Rhino/Grasshopper and inspect the supplied definition for missing dependencies before enabling robot control. The paper confirms Grasshopper control but does not identify every required plugin or version.
4. Prepare software for focus-stack generation if using focal sequences, and RealityScan for photogrammetric reconstruction.
5. Create separate locations for source images, focal stacks, masks, reconstruction projects, and exported meshes. This is a recommended organisation scheme, not a documented repository folder structure.

## Establish connections

1. Configure the workstation-to-robot connection required by the supplied definition. Verify the robot address, network configuration, and RTDE connection against the implementation.
2. Connect the camera, rail, turntable, and StackShot controller according to the equipment documentation and project wiring.
3. For focus-stacked capture, verify the implemented microswitch handoff: the rail reaching the end of its travel supports the trigger for the robot's next programmed elevation.
4. For standard capture, retain the documented operator-mediated handoff unless an alternative has been implemented and validated. Network connectivity alone does not demonstrate that a capture sequence is ready to execute.

## Register and calibrate

1. Register the turntable centre and rotational axis relative to the robot base using the implementation's RTDE-based pose workflow.
2. Calibrate the imaging end effector's tool centre point and establish the camera lens position relative to the flange.
3. Define the focal target from the approximate artefact centre.
4. Check framing at every intended camera elevation and rotational position.
5. For focus stacking, check the full rail travel, focal coverage, and clearance. Checking only the starting frame is insufficient.
6. Check lighting, background, focus, exposure, and object stability before committing to a full sequence.

## Verify the sequence

Use the site's approved robot commissioning procedure to verify motion and capture behaviour before a full run. Confirm that the robot, rail, turntable, and camera reach the expected states and that the operator can identify when a sequence is complete. Validate the handoff independently before relying on it during extended capture.

Robot motion, rail travel, and artefact handling require trained supervision and the applicable workcell procedures. Follow collection-specific handling requirements when repositioning museum objects.

## Implementation details still to confirm

| Item | Status in the paper |
| --- | --- |
| Rhino, Grasshopper, and plugin versions | Not fully specified |
| Robot controller version and communication settings | Not fully specified |
| Camera lens and exposure settings | Not fully specified |
| Trigger wiring and microswitch signal configuration | Mechanism described; detailed wiring not provided |
| Focus-stacking application and parameters | Stack generation described; complete configuration not provided |
| Exact Grasshopper component names and execution controls | Require the project definition |

Continue with [usage instructions](02_UsageInstructions.md).
