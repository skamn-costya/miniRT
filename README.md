# miniRT

![Screenshot from 2025-06-15 14-16-59](https://github.com/user-attachments/assets/ba34dadc-d55c-48b6-8ec9-eb1615902109)


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



