---
title: "UFludics"
excerpt: "A 3D printed microfludic device capable of sorting particles by size"
header:
  image: /assets/img/PDMS_device.png
  teaser: /assets/img/VPP_mold.png
gallery:
  - image_path: /assets/img/PDMS_device.png
  - image_path: /assets/img/VPP_mold.png
     
---

# Summary 

This 3D-printed microfluidic device demonstrates a cost-effective alternative to using silicon wafers to design and create microfluidic devices. This device was concept tested using plastic particles of different sizes and sorting them into respective channels. However the broader aplications include sorting cells of different types soley on size.

# Introduction 
Microfluidic devices are miniaturized systems fabricated from materials such as glass and polydimethylsiloxane (PDMS), designed to process small liquid volumes, typically in the microliter (μL) range. These devices have diverse biomedical applications, including disease diagnostics, cell sorting based on size, drug delivery, and other analytical processes [1]. By handling minimal fluid volumes, microfluidics enable cost-effective and efficient studies of various drug interactions.

The objective of this project was to develop a microfluidic system capable of sorting particles based on size, simulating potential applications in cell sorting by size for biomedical research.

# Overview of Pinch Flow Fractionation

Pinch Flow Fractionation (PFF) is a technique that separates particles based on size using fluid dynamic principles. Two liquid streams—one containing particles and the other particle-free—are introduced into a microchannel from separate inlets. By precisely adjusting the flow rates, the fluid with particles is “pinched” toward one sidewall in a narrow segment of the channel. This alignment ensures that all particles, regardless of size, start from the same position before entering the broader section of the channel.

As the flow transitions from the narrow (pinched) segment to a wider region, the velocity profile changes, creating size-dependent forces on the particles. Larger particles experience a greater force pushing them toward the center of the channel, while smaller particles remain closer to the sidewall [2]. This amplification of small initial differences in position results in an effective size-based separation perpendicular to the main flow direction. 

[Pinch Flow Fractionation]! (/assets/img/Screenshot 2025-03-21 145832.png)
Figure 1: Demonstration of pinched flow fractionation [2]

# Potential Future Applications 

# Methods 

# Rationale for Parylene Coating 

The resin printed molds need to be coated with parylene prior to casting the PDMS to ensure the PDMS can fully cure. Photoinitator leaching from the resin may occur which can inhibt the PDMS curing [3]. Parylene serves as a protective barrier, preventing contamination and ensuring the integrity of the PDMS mold.

# Design Rational

# Future Changes 

Based on the test results, improvements can be made to enhance the sorting process by mitigating turbulent flow. During sorting, turbulence was observed, which can impact the efficiency and accuracy of particle separation. To address this issue, future modifications should focus on reducing the Reynolds number of the fluid [4].
One potential approach is to use a liquid with lower density to decrease the overall Reynolds number, thereby minimizing turbulence. In the current setup, a surfactant was used to facilitate the flow of hydrophobic particles through the syringe. However, exploring alternative low-density fluids could improve flow stability and enhance the effectiveness of the sorting process.

# Citations

# CAD Model
<iframe src="https://vanderbilt643.autodesk360.com/shares/public/SH286ddQT78850c0d8a41510700b0d818185?mode=embed" width="640" height="480" allowfullscreen="true" webkitallowfullscreen="true" mozallowfullscreen="true"  frameborder="0"></iframe>

{% include gallery caption="Syringe Pump Gallery" %}
