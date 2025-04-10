---
title: "Top Down Modeling Project"
excerpt: "3D Printed Phone Holder to Attach to a Bike"
header:
  image: /assets/img/BacksidePhoneView.jpg
  teaser: /assets/img/BacksidePhoneView.jpg
gallery:
  - image_path: /assets/img/Handlebars.jpg
  - image_path: /assets/img/BacksidePhoneView.jpg
  - image_path: /assets/img/PhoneHolderField.png
  - image_path: /assets/img/PhoneHolderFieldBack.png
     
---

# Summary 


# Top Down Modeling Philosophy 

Top-down modeling is a CAD design methodology in which individual components are developed within the context of a larger assembly. This approach streamlines the design process by allowing seamless referencing of geometry and dimensions from other parts in the assembly. Rather than importing external models or manually referencing measurements, top-down modeling enables components to be built relative to one another, fostering precision and cohesion in complex designs.
For this project, top-down modeling was integral to ensuring all components fit together accurately. The use of the project geometry feature allowed for direct referencing of features and dimensions from previously constructed parts. As the assembly required precise alignment and mechanical interaction between multiple components, this approach significantly improved efficiency and reduced the potential for error. In particular, referencing the geometry of mating surfaces and alignments ensured a snug and functional fit, reducing the need for iterative adjustments and facilitating a more cohesive assembly process.

# Rationale behind the Design of the Rotating Mechanism

The rotation mechanism at the heart of this design utilizes a detent system comprising a ball bearing and spring. The rotating cylinder features indentations at 0°, 90°, 180°, and 270°, which enable bidirectional rotation and allow the phone holder to lock securely in four distinct orientations. During rotation, the spring compresses, allowing the ball bearing to move out of the detent and into the next one with a click. This design choice was made to provide users with reliable and repeatable rotation positions, enhancing both usability and functionality. The mechanism has proven effective and consistent, as demonstrated in the accompanying .gif!

<img src="/assets/img/RotatingPhone.GIF" alt="Alt Text" width="200">

# Adjustments for 3D Printing

Accommodating the realities of 3D printing required several design modifications, particularly in regard to tolerancing for fasteners. Initially, bolt holes were dimensioned too tightly, preventing proper insertion post-print. To resolve this, I increased the bolt hole diameter to 4.5 mm, resulting in a clearance of approximately 1.5 mm around the threads, which facilitated easier assembly.
Additionally, I included a countersink for the center bolt head located on a circular face. However, due to limitations in support removal and minor warping during printing, the fit was tighter than anticipated. Rather than reprinting, I applied additional force to seat the bolt securely, as the dimensions were technically correct. This solution, while not ideal, proved effective for this iteration.

# 3D Printing Method and Material Choices

I used fused filament fabrication (FFF) to build up my pieces layer by layer. I used this technique because it allowed me to print multiple iterations of the mechanism. This was necessary since the tolerance of my bolt holes was initially too small. Ideally, I would have used selective laser sintering (SLS) to create my model so I would not have had to print the main body separately from the attachment piece to the bike handle. Additionally, I had to print a cover for my spring mechanism to enclose the spring and the spinning cylinder. This was done because I anticipated not being able to accurately remove supports from the inner compartment creating a bumpy surface unsuitable for a spring to sit on. However, in SLS printing, this support is not necessary which would have eliminated the need for multiple components.
The main body and attachment components were printed using Polylactic Acid (PLA), chosen for its strength and ease of use. The phone holder itself was printed in Thermoplastic Polyurethane (TPU), a flexible material that accommodates dimensional variance and offers a snug yet adaptable grip on the iPhone 11 Otterbox clear case. This material flexibility helped to mitigate small discrepancies introduced by printing tolerances, ensuring a secure fit for the phone.

# Assembly and Use Instructions 

The final assembly comprises eight threaded bolts. Five are secured via heat-set inserts embedded in the plastic, while the remaining three utilize hex nuts for fastening. Two of the nuts are positioned strategically to clamp the mechanism around the bike handle, allowing the assembly to be both secure and adjustable. The remaining nut is placed through the center of the assembly loosely to allow rotation. 

1. Tighten the central bolt until the phone is held firmly in place, even when the assembly is shaken.
2. Secure the two clamping bolts with the hex nuts around the bike handlebar to ensure stability.
3. Insert the phone into the flexible TPU holder section.
4. To rotate the phone, pull gently on the teal flaps and rotate to the desired angle. A clicking sound indicates the ball bearing has locked into the next detent position.

# Citations 

# CAD Model
<iframe src="https://vanderbilt643.autodesk360.com/shares/public/SH286ddQT78850c0d8a4a858f7e5ebdb6b1c?mode=embed" width="640" height="480" allowfullscreen="true" webkitallowfullscreen="true" mozallowfullscreen="true"  frameborder="0"></iframe>


{% include gallery caption="Bike Phone Holder Gallery" %}

