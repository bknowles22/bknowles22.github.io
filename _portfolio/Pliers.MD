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

This 3D-printed microfluidic device demonstrates a cost-effective alternative to using silicon wafers to design and create microfluidic devices. This device was concept tested using plastic particles of different sizes and sorting them into respective channels. However the broader aplications include sorting cells of different types soley on size.

# Introduction 

Microfluidic devices are miniaturized systems fabricated from materials such as glass and polydimethylsiloxane (PDMS), designed to process small liquid volumes, typically in the microliter (μL) range. These devices have diverse biomedical applications, including disease diagnostics, cell sorting based on size, drug delivery, and other analytical processes [1]. By handling minimal fluid volumes, microfluidics enable cost-effective and efficient studies of various drug interactions.

The objective of this project was to develop a microfluidic system capable of sorting particles based on size, simulating potential applications in cell sorting by size for biomedical research.

# Overview of Pinch Flow Fractionation

Pinch Flow Fractionation (PFF) is a technique that separates particles based on size using fluid dynamic principles. Two liquid streams—one containing particles and the other particle-free—are introduced into a microchannel from separate inlets. By precisely adjusting the flow rates, the fluid with particles is “pinched” toward one sidewall in a narrow segment of the channel. This alignment ensures that all particles, regardless of size, start from the same position before entering the broader section of the channel.

As the flow transitions from the narrow (pinched) segment to a wider region, the velocity profile changes, creating size-dependent forces on the particles. Larger particles experience a greater force pushing them toward the center of the channel, while smaller particles remain closer to the sidewall [2]. This amplification of small initial differences in position results in an effective size-based separation perpendicular to the main flow direction. 

Pinch Flow Fractionation

<img src="/assets/img/first_draft_pliers" style="width:200px;"/>


Figure 1: Demonstration of pinched flow fractionation [2]

# Potential Future Applications 

Cancer metastasis occurs when circulating tumor cells (CTCs) infiltrate the bloodstream and migrate to healthy tissues. An important part of diagnosis and cancer treatment research lies in separating CTCs from the bloodstream. Pinched flow fractionation is described as a method to separate blood cells from CTCs [3].

# Methods 

First, a CAD model was created to define the mold impression, designed to optimize Pinched Flow Fractionation (PFF) and accommodate barbs for later insertion into the PDMS mold. The mold was then 3D printed using Vat Photopolymerization on a Formlabs Form 4 printer with clear resin. After printing, it was washed twice with isopropanol for five minutes each, left to dry for 30 minutes, and UV cured for 30 seconds. Once cured, the mold was coated with parylene to prevent pore leaching between the mold and PDMS. PDMS was then poured into the mold and allowed to fully cure. After curing, a glass slide was plasma bonded to the PDMS to ensure a leak-proof seal. Finally, barbs were inserted into the device, and two pumps were connected to tubing for testing. 
 
# Rationale for Parylene Coating 

The resin-printed molds need to be coated with parylene prior to casting the PDMS to ensure the PDMS can fully cure. Photoinitator leaching from the resin may occur which can inhibit the PDMS curing [4]. Parylene serves as a protective barrier, preventing contamination and ensuring the integrity of the PDMS mold.

# Design Rational

The geometry was designed based on Pinched Flow Fractionation (PFF) principles, ensuring effective particle sorting. Calculations were performed to determine particle center positions during flow. The broad section was maximized at 18.50 mm to enhance separation, while the pinch section was minimized at 0.65 mm, allowing the largest particles to pass through.

Using the equation Yo = (Wp - D/2) * Wb/Wp, larger particles (0.425–0.5 mm in diameter) were expected to flow between 11.38 mm and 12.45 mm from the bottom of the device. To accommodate these tolerances while maintaining space for the upper channel, the second sorting channel was centered at 12 mm. Smaller particles (0.125–0.15 mm in diameter) were calculated to flow between 16.36 mm and 16.72 mm, so the first channel was centered at 16 mm to ensure proper separation.

Four outlets were designed to ensure equal flow distribution to the first two channels. The channel lengths varied to accommodate the barb widths, while proper separation was maintained by adjusting the spacing between the channels. Each outlet was positioned as close as possible to the centerline of the corresponding particle stream, but slight adjustments were made to account for the barb width and ensure uniform width for the four outlet channels.

# Future Changes 

Based on the test results, improvements can be made to enhance the sorting process by mitigating turbulent flow. During sorting, turbulence was observed, which can impact the efficiency and accuracy of particle separation. To address this issue, future modifications should focus on reducing the Reynolds number of the fluid [5].

One potential approach is to use a liquid with lower density to decrease the overall Reynolds number, thereby minimizing turbulence. In the current setup, a surfactant was used to facilitate the flow of hydrophobic particles through the syringe. However, exploring alternative low-density fluids could improve flow stability and enhance the effectiveness of the sorting process.

# Citations



# CAD Model
<iframe src="https://vanderbilt643.autodesk360.com/shares/public/SH286ddQT78850c0d8a4df26be5dab0d5619?mode=embed" width="640" height="480" allowfullscreen="true" webkitallowfullscreen="true" mozallowfullscreen="true"  frameborder="0"></iframe>

# Working Demonstration
<img src="/assets/img/Pliers_Resitors.GIF" alt="Alt Text" width="200">

{% include gallery caption="PDMS Device and Casting Mold" %}
