---
title: "Pliers"
excerpt: "3D Printed Multimaterial Functional Pliers"
header:
  image: /assets/img/resitor_pickup.jpg
  teaser: /assets/resitor_pickup.jpg
gallery:
  - image_path: /assets/img/final_draft_pliers.jpg
  - image_path: /assets/img/resitor_pickup.jpg
  - image_path: /assets/img/side_profile_resistor.jpg
     
---

# Summary 

The objective of this project was to 3D print a pair of functional pliers using two different materials. The pliers should be able to pick up a Through-Hole Resistor and return to the open position when not being used. Print in place parts are assemblies that can be printed with a single extruder that require no post processing assembly. 

# Print in Place Technique Overview



# Design Iteration 

The spring was printed from flexible TPU while the handles and jaws were printed using PLA. The flexible piece was printed using a pattern rather than full infill to allow for flexibility. The first design prioritized the jaws sitting flushed when closed however the initial opening angle of the jaws were too wide given the amount of flexibility present in the connecting piece. Further this design used an triangular pattern as it fit better with the design of the middle connector, this design did not allow for the flexibility needed to fully close the jaws. Additionally, the tops of tips on the jaws did not meet, meaning it was impossible to pick up a resistor. After the initial print the design was completely reconstructed to account for the previously mentioned factors. The connection between the flexible potion and the stiff portion was well done in the first model. An offset of 0.1 was used to account for any printing error. The second model incorporated the successful connection design. 

<img src="/assets/img/first_draft_pliers" style="width:200px;"/>

# Final Design Specifications 

The final pliers featured a jaw capacity of 6.93 mm, and given that the resistor has an approximate width of 2 mm, the jaws only need to close by 71.14% to securely grasp the component. Additionally, the handles of the pliers were designed to remain 36.624 mm apart at the point where they could theoretically meet under applied force, ensuring that the handles would not touch before the jaws fully closed. Furthermore, the jaws make contact only at the tip, while a 17 mm flat section extends beyond this point. This configuration allows the pliers to effectively grasp the resistor without necessitating the use of only the tip, thus enhancing their overall functionality.

# CAD Model
<iframe src="https://vanderbilt643.autodesk360.com/shares/public/SH286ddQT78850c0d8a4df26be5dab0d5619?mode=embed" width="640" height="480" allowfullscreen="true" webkitallowfullscreen="true" mozallowfullscreen="true"  frameborder="0"></iframe>

# Working Demonstration
<img src="/assets/img/Pliers_Resitors.GIF" alt="Alt Text" width="200">


{% include gallery caption="Plier Gallery" %}
