# miniRT

![image](https://github.com/user-attachments/assets/8c7c891e-b99f-423b-8bcb-80a4adc98d4f)

## 🌐 Features

- Scene file parsing (`.rt` format)
- Ray generation and tracing
- Support for basic shapes:
  - Sphere
  - Plane
  - Cylinder
- Camera setup with orientation and field of view
- Ambient lighting
- Point lights with diffuse and specular shading
- Phong lighting model
- Basic input handling (e.g., closing the window with ESC or the window button)

## ✨ Bonus (if implemented)

- Additional shapes (cone, triangle, etc.)
- Support some .obj file (triangles only)
- Anti-aliasing
- Shadows
- Reflection and/or refraction
- Save rendered image to BMP
- Scene manipulation via keyboard

## 📁 File Format (.rt)

Example of a minimal valid scene file:
A 0.2 255,255,255  
C 0,0,0 0,0,1 70  
L 10,10,10 0.6 255,255,255  
sp 0,0,20 5 255,0,0  
pl 0,-5,0 0,1,0 0,255,0  
cy 2,0,20 0,1,0 2 5 0,0,255  

![Screenshot from 2025-06-15 14-49-21](https://github.com/user-attachments/assets/8ca8d012-5a68-4006-bfcd-22a70a3b26b5)

Supported elements:
- `A` — Ambient light  
- `C` — Camera  
- `L` — Light source  
- `sp` — Sphere  
- `pl` — Plane  
- `cy` — Cylinder

## 🧠 Learning Outcomes
Through miniRT, we learned:  
Ray tracing fundamentals  
Vector and matrix math  
3D geometry and camera projection  
Graphics window management with MiniLibX  
Code structuring and parsing techniques  
Handling floating-point precision  
Performance optimizations for real-time rendering  

## 🧪 Testing
Multiple .rt scene files with valid and invalid input  
Boundary testing (extreme values, zero sizes, invalid vectors)  
Rendering edge cases (overlapping shapes, objects behind camera)  
Leak and crash testing with valgrind  

![image](https://github.com/user-attachments/assets/f77d4b34-6078-4800-ba1e-f25b036da73b)
![image](https://github.com/user-attachments/assets/f90804c8-470d-47fb-9580-e90ffe914a4b)
![Screenshot from 2025-06-15 14-16-59](https://github.com/user-attachments/assets/ba34dadc-d55c-48b6-8ec9-eb1615902109)
![Screenshot from 2025-03-29 16-04-26](https://github.com/user-attachments/assets/988eb885-693f-4e3c-a2cf-531ea9fcf7ba)
![mickey_b](https://github.com/user-attachments/assets/9f2cf8d9-a4d2-4462-be52-be0bc4ea1cb2)
![Screenshot from 2025-03-29 14-46-10](https://github.com/user-attachments/assets/152038b1-f3b6-4ff2-9eb7-18d6efcc496f)
![Screenshot from 2025-03-28 01-03-30](https://github.com/user-attachments/assets/a6991d5e-1501-40ba-8da3-bc50a1cc0efa)





