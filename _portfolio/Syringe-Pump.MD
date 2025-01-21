---
title: "Syringe Pump"
excerpt: "DIY syringe pump capable of 1 uL/min flow rate for up to 10 mL"
header:
  image: /assets/img/Syringe_pump.jpg
  teaser: /assets/img/Syringe_pump.jpg
gallery:
  - image_path: assets/img/Syringe_pump.jpg
  - image_path: assets/img/Syringe Pump Render.png
  - image_path: assets/img/Syringe Pump Render2.png
   
---

# Function

This pump is a DIY cost-effective alternative to expensive medical-grade syringe pumps. To dispense liquid at a controllable rate, the syringe pump is controlled by a microcontroller, using a potentiometer the speed of dispensing can be controlled.

# Operation 
The smallest red button controls the power of the syringe pump. The other two buttons dictate which way the linear actuator moves. The LCD will display the rate at which the liquid is dispensed, to change the rate, the spinner can be moved.

# Off-The-Shelf Parts Needed:

| **Part Name** | **Qty** | 
| --- | --- |
| [250 mm lead screw with 2 mm pitch and 2 mm lead](https://www.amazon.com/dp/B07R1H5ZMV/ref=cm_sw_em_r_mt_dp_0YZ13D4HQBGW2Z86PBV1?_encoding=UTF8&psc=1) | 1 | 
| [250 mm lead screw with 2 mm pitch and 8 mm lead](https://www.amazon.com/gp/product/B0B8RKN89V?ie=UTF8&th=1&linkCode=sl1&tag=drd0cf-20&linkId=bb4eefbbfff880704d7cd0784b1af8c0&language=en_US&ref_=as_li_ss_tl) | 1 | 
| [1/4" x 8 mm flexible coupling](https://us.openbuilds.com/1-4-x-8mm-flexible-coupling/) | 1 |
| [200 mm linear rod with 8 mm diameter](https://www.amazon.com/dp/B07MPGWJMS/ref=cm_sw_em_r_mt_dp_X5AQS0ES7JH8JG83AAZ3) | 2 |
| [LM8UU linear bearing for 8 mm diameter rod](https://www.amazon.com/gp/product/B087WPGQ8T/ref=ppx_yo_dt_b_asin_image_o00_s00?ie=UTF8&psc=1) | 2 |
| [2040 aluminum extrusion 1' length](https://us.openbuilds.com/v-slot-20x40-linear-rail/) | 1 |
| [Nema 17 stepper motor](https://www.amazon.com/gp/product/B07LF898KN/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&th=1) | 1 |
[Mean well RQ-65D AC-DC power supply quad output 5V 12V 24V 4Amp](https://www.amazon.com/dp/B005T9HGLI/ref=cm_sw_em_r_mt_dp_A8CZ056TM52EJGZTGZGR?_encoding=UTF8&psc=1) | 1 |
| [Ardunio uno](https://www.amazon.com/dp/B007R9TUJE/ref=cm_sw_em_r_mt_dp_TY8JGK0CJD1JEJM4BNNJ) | 1 |
| [A4988 stepper driver](https://www.amazon.com/dp/B01FFGAKK8/ref=cm_sw_em_r_mt_dp_V0YKTYKDWMR8WHTKA53T?_encoding=UTF8&psc=1) | 1 |
| [Small breadboard](https://www.amazon.com/dp/B082VYXDF1/ref=cm_sw_em_r_mt_dp_N6Q28CAGPAYCKCSJKDDC?_encoding=UTF8&psc=1) | 1 |
| [Panel mount latching push buttons](https://www.amazon.com/dp/B07XTBL1NP?psc=1&smid=A2NNH5C5IP9N3O&linkCode=sl1&tag=drd0cf-20&linkId=43b42a7cb2a088ebd85d65cb9da46725&language=en_US&ref_=as_li_ss_tl) | 1 |
| [Limit switch](https://www.amazon.com/gp/product/B073TYWX86/ref=ppx_yo_dt_b_asin_image_o01_s00?ie=UTF8&psc=1) | 1 |
| [RGB common cathode LED](https://www.amazon.com/dp/B0194Y6MW2/ref=cm_sw_em_r_mt_dp_FW3CFQT7ZGFQ2R04N6G3?_encoding=UTF8&psc=1) | 1 |
| F688ZZ Flanged Ball Bearing | 2 |
| M5 Tee Nut | 8 |
| M3x8 Thread Forming Screw | 4 |
| M3x10 Bolt | 1 |
| Nut tr8x8-4 | 1 |
| LCD Screen | 1 |
| 20 mL Syringe | 1 |
| 9.5 mm push button | 1 |



# 3D Printed Parts Needed:

| **Part Name** | **Qty** | 
| --- | --- |
| Carriage | 1 |
| End Support | 1 |
| Motor Mounting Plate | 1 |
| Enclosure Base | 1 |
| Enclosure Lid | 1 |
| Syringe Tip Support | 1 |
| Syringe Body Support | 1 |
| LCD Attachment | 1 |


# CAD Model
<iframe src="https://vanderbilt643.autodesk360.com/shares/public/SH286ddQT78850c0d8a4e8e535a0e1e463f6?mode=embed" width="640" height="480" allowfullscreen="true" webkitallowfullscreen="true" mozallowfullscreen="true"  frameborder="0"></iframe>

{% include gallery caption="Syringe Pump Gallery" %}

# Arduino Code
<a href="https://raw.githubusercontent.com/bknowles22/bknowles22.github.io/0e7c4a1cb18e46bbe3aec0dee28c3cca4a868dbb/Digital_Fab_final_code.ino" download>Click Here to Read Raw File</a>

#Test 
[Click Me](assets/syringepumpcode.ino)

