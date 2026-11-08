# Robotic-Assisted Photogrammetry and Focus Stacking

Supplementary documentation for **Redistributing Human Work in Robotic-Assisted Photogrammetry and Focus Stacking for Small Museum Object Digitisation**, by Wei Win Loy, David Pyle, Jared W Donovan, and Markus Rittenbruch (OzCHI 2026).

Paper DOI: https://doi.org/10.1145/3847401.3857168

Project repository: https://github.com/LoyWeiWin/Pub_OZCHI_SupplementaryDocument_RedistributingHumanWorkinRAP

## Overview

This project examines how robotic assistance redistributes human work in small-object digitisation. A Universal Robots UR10 positions a camera mounted on a motorised macro rail, while a motorised turntable provides rotational viewpoints. Two configurations support standard photogrammetric capture and focus-stacked capture.

The study involved four image-acquisition sessions with three museum artefacts: the Pot, Sarcophagus, and Red Dragon. Standard capture was used for the Pot and Sarcophagus; focus-stacked capture was used for the Red Dragon. These were situated cases involving different artefacts and acquisition settings, rather than matched experimental conditions.

Robotic positioning reduced repeated manual camera placement. Operators still calibrated the setup, checked framing and focus, coordinated device handoffs, reoriented artefacts, organised image sets, and assessed reconstructed outputs. The system is a partially automated workflow.

## Documentation

- [System overview](00_SystemOverview.md): hardware, software, workflow, and study scope.
- [Installation guide](01_InstallationGuide.md): preparation, connections, and calibration checks.
- [Usage instructions](02_UsageInstructions.md): standard capture, focus-stacked capture, and post-processing.

Keep these four Markdown files together so the relative links resolve.

## Documented equipment and software

| Component | Role |
| --- | --- |
| Universal Robots UR10 | Gross camera positioning |
| Canon 1300D | Image capture |
| Cognisys StackShot macro rail | Fine displacement along the optical axis |
| Cognisys actuated turntable | Rotational viewpoints |
| StackShot controller | Rail and turntable coordination |
| Windows PC with Rhino/Grasshopper | Robotic workflow configuration and control |
| RealityScan | Photogrammetric reconstruction |

The study setup was configured for artefacts approximately 2–5 cm in size. Exact software versions, Grasshopper dependencies, wiring, and controller settings must be checked against the supplied project files and equipment documentation; the paper does not provide a complete installation specification.

## Supplementary materials

The paper identifies session-level spreadsheets reporting image-acquisition and calibration durations, spreadsheets containing deviation data used in the Sarcophagus and Pot mesh-to-mesh analyses, and the Grasshopper definition and associated Rhino file for the robotic imaging setup. This documentation does not verify the current repository inventory or prescribe unconfirmed folder names.

## Interpretation of outputs

Capture duration alone does not represent total workload. Focus-stacked capture adds source-image management and stack processing. Geometric comparisons with CT-derived meshes were available for the Pot and Sarcophagus, but not the Red Dragon. Comparisons after uniform rescaling and ICP registration indicate relative surface agreement, rather than absolute dimensional accuracy. The study does not establish a general ranking of efficiency, accuracy, or usability between the two workflows.

## Acknowledgements

This research was supported by the Australian Government through the Australian Research Council Industrial Transformation Training Centre for Collaborative Robotics in Advanced Manufacturing, grant IC200100001. The authors acknowledge the facilities and support provided by Queensland University of Technology, School of Creative Arts and School of Design.

## Contact and reuse

Contact: Wei Win Loy — loyw@qut.edu.au.

The paper is published under CC BY 4.0. Consult the repository's licence file for terms covering code, datasets, and other supplementary materials; the article licence alone does not establish their licensing.
