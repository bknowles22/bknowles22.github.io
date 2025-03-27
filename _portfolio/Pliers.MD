---
title: "Multimaterial Pliers"
excerpt: "3D Printed Multimaterial Functional Pliers"
header:
  image: /assets/img/resitor_pickup.jpg
  teaser: /assets/img/resitor_pickup.jpg
gallery:
  - image_path: /assets/img/final_draft_pliers.jpg
  - image_path: /assets/img/resitor_pickup2.jpg
  - image_path: /assets/img/side_profile_resistor.jpg
     
---

# Summary 

The objective of this project was to 3D print a pair of functional pliers using two different materials. The pliers should be able to pick up a Through-Hole Resistor and return to the open position when not being used. Print in place parts are assemblies that can be printed with a single extruder that require no post processing assembly. 

# Print in Place Technique Overview

Print-in-place techniques can be used to create functional assemblies such as gear bearings, hinges, or articulated joints. Rigid and flexible materials can be combined to produce multifunctional parts, including shock-absorbing components, grippers, and clamps. Grippers, in particular, are highly useful for robotic applications. Combining ABS with flexible materials for the gripper enhances compliance with the object being grasped, improving the ability to securely hold irregularly shaped items [1]

One challenge when printing rigid and flexible materials together is their differing mechanical properties, which can lead to poor adhesion or mechanical failure. On a single-extruder printer, switching between materials requires manually changing the filament during the print and adjusting the print settings to match the properties of each material. On a dual-extruder printer, each material is loaded into a separate extruder, but print settings must still be configured correctly for each filament to ensure proper adhesion and performance. In both cases, reducing print speed can help improve layer bonding, especially when working with flexible filaments [2].

# Design Iteration 

The spring was printed from flexible TPU while the handles and jaws were printed using PLA. The flexible piece was printed using a pattern rather than full infill to allow for flexibility. The first design prioritized the jaws sitting flushed when closed however the initial opening angle of the jaws were too wide given the amount of flexibility present in the connecting piece. Further this design used an triangular pattern as it fit better with the design of the middle connector, this design did not allow for the flexibility needed to fully close the jaws. Additionally, the tops of tips on the jaws did not meet, meaning it was impossible to pick up a resistor. After the initial print the design was completely reconstructed to account for the previously mentioned factors. The connection between the flexible potion and the stiff portion was well done in the first model. An offset of 0.1 was used to account for any printing error. The second model incorporated the successful connection design. 

<img src="/assets/img/first_draft_pliers.jpg" style="width:200px;"/>

# Final Design Specifications 

The final pliers featured a jaw capacity of 6.93 mm, and given that the resistor has an approximate width of 2 mm, the jaws only need to close by 71.14% to securely grasp the component. Additionally, the handles of the pliers were designed to remain 36.624 mm apart at the point where they could theoretically meet under applied force, ensuring that the handles would not touch before the jaws fully closed. Furthermore, the jaws make contact only at the tip, while a 17 mm flat section extends beyond this point. This configuration allows the pliers to effectively grasp the resistor without necessitating the use of only the tip, thus enhancing their overall functionality.

# Citations 

[1]	W. Y. Yeong et al., “3D printing of soft grippers with multimaterial design: Towards shape conformance and tunable rigidity,” Mater. Today Proc., vol. 70, pp. 525–530, Jan. 2022, doi: 10.1016/j.matpr.2022.09.552.

[2]	“Multi-material 3D Printer: Types & Printing Guide,” All3DP. Accessed: Mar. 26, 2025. [Online]. Available: https://all3dp.com/2/multi-material-3d-printing-an-overview/

# CAD Model
<iframe src="https://vanderbilt643.autodesk360.com/shares/public/SH286ddQT78850c0d8a4df26be5dab0d5619?mode=embed" width="640" height="480" allowfullscreen="true" webkitallowfullscreen="true" mozallowfullscreen="true"  frameborder="0"></iframe>

# Working Demonstration
<img src="/assets/img/Pliers_Resitors.GIF" alt="Alt Text" width="200">


{% include gallery caption="Plier Gallery" %}
