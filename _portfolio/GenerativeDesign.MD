---
title: "Generative Design Project"
excerpt: "3D Printed Arm Brace for Radius Fracture"
header:
  image: /assets/img/HorizontalBrace.JPG
  teaser: master/assets/img/HorizontalBrace.jpg
gallery:
  - image_path: /assets/img/BraceVertical.JPG
  - image_path: master/assets/img/BraceUseCase1.jpg
  - image_path: /assets/img/BraceUseCase2.jpg
  - image_path: /assets/img/BraceUseCase3.png
     
---
# Summary and Design Context

The final part is an arm brace designed to stabilize and correct a distal radial fracture. This brace is a lightweight version of a traditional brace designed to resist forces of flexion and extension in the wrist. The final part was designed to resist forces for a woman who is 5’9” and 130 lbs. By using generative design, a brace could be developed that is custom to the specifications of the person who broke their wrist. 	A diagram below shows exactly where the wrist fracture would occur, in the radius closest to the patient’s thumb [1].

<img src="/assets/img/RadialFracture.png" alt="Alt Text" width="300">

This object combines my interest in biomedical design and 3D printed prototypes. Medicine is becoming more personalized. For this design, a hand from GrabCAD was used and scaled down to approximately fit a model hand. Ideally, data from CT scans could be used to import a patient’s data and create an entirely custom brace. St. Luke’s Hospital in Colorado has already started to custom 3D print casts using scan data [2]. However, St. Luke’s has implemented FFF printing and could benefit from SLS printing and generative design to optimize where material is needed and how much force the material needs to resist without restrictive support material. Further, by minimizing the material needed for the brace, more airflow can get to the arm, minimizing the issue of water getting trapped in the cast if the patient sweats or gets slightly wet. Additionally, the lack of airflow can create skin discomfort and irritation for the patient and potentially even an infection [3].

<img src="/assets/img/BraceWeight.jpg" alt="Alt Text" width="200">

# Rationale behind Preserve and Obstacle Geometry

The critical preserve points in the geometry were based on the geometry of the fracture. At the site of the break a preserve geometry was placed to ensure the cast stabilized the fracture site. Additionally, the thumb joint was also created as a preserve geometry because the muscles that control the movement of the thumb are largely in the wrist and needed to be set in order to prevent the break site from experiencing force. Lastly, the circumference of the arm closest to the elbow was marked as a preserved geometry, this was to retain the shape of the cast, serve as an endpoint for the cast, and serve as an immobile point to be referenced later in the design. The obstacle geometry was defined as the hand model that was inputted.

# Load Case Application and Structural Constraints

To determine the magnitude of each load, anthropometric tables that were provided by a biomedical engineering professor at Vanderbilt were used in order to approximate the weights of the components of the wrist, thumb, and forearm. Using these tables, and by inputting the height, weight, and gender of the patient the forces acting on the hand could be calculated. Below is a free-body diagram (FBD) demonstrating where the forces were acting. Fmuscle was determined to be 8.3 N, and the force was determined to act 0.02 away from the wrist joint. The distance from the wrist joint was approximated to zero and the force was placed on the preserve geometry encompassing the broken wrist. 

The model was designed to resist forces that mimic my own, meaning that to test the brace I can try it on and attempt to force my wrist into flexion or extension to test the integrity of the design. Further, trying on the brace will reflect how accurate the scaled-down version of the grab-cad hand was and if it could be used to model off in the future.

<img src="/assets/img/ChatFBD.png" alt="Alt Text" width="200">

The generative outcomes from the input variables are shown below. The final design was chosen based on which design had the least amount of material while simultaneously supporting the arm and wrist. 

<img src="/assets/img/GenerativeOutcomes.png" alt="Alt Text" width="400">

# Forces Applied 

| **Force** | **Magnitude** | **Application Site**|
| --- | --- | --- |
| Bending Moment | 1.9 nM clockwise | At wrist fracture site |
| Wrist Muscle | 8.3 N away from wrist | At wrist fracture site |
|Torsion - Shear force | 0.42 towards the wrist | Across the fracture plane |

The moment of the wrist was determined as the force needed to resist rotation in 360 degrees on the wrist. This force was placed on the fracture site as well as on the sides of the wrist in a clockwise direction. The calculations for the wrist muscle force were determined as the amount of force the muscle would need to produce to keep the wrist in a neutral horizontal position rather than a limp position. Lastly, the torsion was determined across the fracture plane as well as at the site of injury. The calculations generated by AI are shown below. All calculations took into account the height, weight, and gender of the patient. 

<img src="/assets/img/ChatCalc.png" alt="Alt Text" width="200">

# Critique of Generative Design 

When creating the preserved geometries, they had to encompass the form and structure of the hand without creating something too bulky. To create the form-fitting brace, a cylindrical shape centered on the hand or wrist was first created and then the preserved hand was subtracted from the cylindrical body. This allowed for confirmation to the shape of the hand, but because of the changing geometries, the preserved regions were rather bulky to encompass the entire region of the hand. Using fillets and small cuts, this issue could be mitigated, but the preserve regions remained bulky in comparison to the remaining generative design. Further, the majority of  forces experienced occured at the site of injury. 


# CAD Model
<iframe src="https://vanderbilt643.autodesk360.com/shares/public/SH286ddQT78850c0d8a4a277aa1322249a25?mode=embed" width="640" height="480" allowfullscreen="true" webkitallowfullscreen="true" mozallowfullscreen="true"  frameborder="0"></iframe>
