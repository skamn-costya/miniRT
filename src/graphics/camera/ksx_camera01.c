/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_camera01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:50:20 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/21 16:19:36 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Camera: "C", coord, vector, fov

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_basis.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"
#include "ksx_object.h"
#include "ksx_camera.h"
#include <math.h>
#include <stdio.h>

// https://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/

// We (traditionally) have these coordinate systems to work with:

// Model space (sometimes called "Object space"):
//  The coordinates inside the model.
// World space: The coordinates in the world.
// Camera space: The coordinates relative to the camera.
// Screen space (sometimes called "Window space" or "Device space"):
//  The coordinates for the screen.
// And of course, there are matrices to transform between them:

// Model matrix (sometimes called “Object matrix”):
//  from Model space to World space.
//  You use this matrix to place objects in the world.
// View matrix (sometimes called “Camera Transformation matrix”):
//  from World space to Camera space.
// Projection Matrix (Sometimes called “Camera Projection matrix”):
//  from Camera space to Clip space.

// x,y,z coordinates of the view point: -50.0,0,20
// ∗ 3d normalized orientation vector. 0.0,0.0,1.0
// In range [-1,1] for each x,y,z axis:
// ∗ FOV : Horizontal field of view in degrees in range [0,180]: 70

t_camera	ksx_create_camera(t_vector3 center, t_vector3 norm, float fov)
{
	t_camera	camera;

	camera.basis.o = ksx_vec3_set(0, 0, 0);
	camera.basis.w_o = center;
	norm = ksx_vec3_unit(&norm);
	ksx_basis_set_norm_camera(&camera.basis, &norm);
	camera.fov = fov;
	camera.hfov = fov * PI180;
	camera.tng = tanf(camera.hfov * .5f);
	camera.near = (WIDTH * .5f) / camera.tng;
	// camera.near = 250.f;
	camera.far = 0.f;
	camera.right = WIDTH * .5f;
	camera.left = -camera.right;
	camera.top = HEIGHT * .5f;
	camera.bottom = -camera.top;
	camera.aspect = (float)WIDTH / (float)HEIGHT;
	camera.half_width = camera.hfov;
	camera.half_height = camera.half_width / camera.aspect;
	ksx_camera_set_vm(&camera);
	// camera.flags = DRAW_OBJ | CHANGE | DRAW_LINE | DRAW_NORM;// | CAM_PM;
	camera.flags = CHANGE | CAM_PM;
	return (camera);
}

// void ksx_camera_set_vm(t_camera *p_camera)
// {
// 	ksx_get_tm(&p_camera->vm, &p_camera->basis);
// 	ksx_m4_invert(&p_camera->vm, &p_camera->ivm);
// }

void	ksx_camera_obj_vm(t_object *p_object, t_matrix4 *p_vm)
{
	uint32_t	idx;
	t_box		**pp_box;

	p_object->basis.c_o = ksx_m4_vec3(p_vm,
		&p_object->basis.w_o);
	idx = -1;
	while (++idx < p_object->size_vrtx)
		ksx_transform(&p_object->pp_vrtx[idx]->wp, p_vm,
			&p_object->pp_vrtx[idx]->cp);
	idx = -1;
	while (++idx < p_object->size_vnrm)
		p_object->pp_vnrm[idx]->cp = ksx_m4_vec3(p_vm,
			&p_object->pp_vnrm[idx]->wp);
	pp_box = p_object->pp_box;
	while (pp_box && *pp_box)
	{
		idx = -1;
		while (++idx < 8)
			ksx_transform(&(*pp_box)->ver[idx].wp,
				p_vm, &(*pp_box)->ver[idx].cp);
		pp_box++;
	}
	idx = -1;
	while (++idx < 4)
		ksx_transform(&p_object->axis[idx].wp, p_vm, &p_object->axis[idx].cp);
}

// void	init_camera(t_camera *p_cam, float near, float far)
// {
// 	int		idx;
// 	float	scale;

// 	idx = 15;
// 	while (idx-- != -1)
// 		p_cam->pm.elems[idx] = 0;
// 	scale = WIDTH / HEIGHT;
// 	p_cam->pm.e_11 = 1 / (scale * tanf((p_cam->fov / 2) * (PI / 180)));
// 	p_cam->pm.e_22 = 1 / tanf((p_cam->fov / 2) * (PI / 180));
// 	p_cam->pm.e_33 = (-(far + near)) / (far - near);
// 	p_cam->pm.e_34 = (-(2 * far * near)) / (far - near);
// 	p_cam->pm.e_43 = 1;
// }

// https://www.mauriciopoppe.com
// /notes/computer-graphics/viewing/projection-transform/
// https://www.opengl-tutorial.org
// /beginners-tutorials/tutorial-3-matrices/#the-view-matrix

void	ksx_camera_set_pm1(t_camera *p_camera)
{
	ksx_m4_reset(&p_camera->pm);
	p_camera->pm.e_11 = 1;
	p_camera->pm.e_22 = 1;
	p_camera->pm.e_33 = 1;
	p_camera->pm.e_44 = 1;
}

void	ksx_camera_set_pm2(t_camera *p_camera, float fov)
{
	float	f;

	if (fov < 1 || fov > 179)
		return ;
	ksx_m4_reset(&p_camera->pm);
	p_camera->fov = fov;
	p_camera->hfov = fov * PI180;
	f = 1.f / tanf(p_camera->hfov * .5f);
	p_camera->pm.e_11 = f;
	p_camera->pm.e_22 = -f;
	p_camera->pm.e_33 = -((p_camera->far)
			/ (p_camera->far - p_camera->near));
	p_camera->pm.e_34 = 1.f;
	p_camera->pm.e_43 = (1.f / (p_camera->far - p_camera->near));
}

// void ksx_camera_set_pm(t_camera *p_camera, float fov, float far)
// {
//     float f;

//     if (fov < 1 || fov > 179)
//         return;

//     p_camera->fov = fov;
//     p_camera->hfov = fov * PI180;
//     p_camera->near = .1f;
// 	p_camera->near = (p_camera->right) * tanf(p_camera->hfov * .5f);
//     p_camera->far = 700;

//     f = 1.f / tanf(p_camera->hfov * 0.5f); // Correct focal length factor

//     ksx_m4_reset(&p_camera->pm);

//     p_camera->pm.e_11 = f;// / p_camera->aspect;
//     p_camera->pm.e_22 = -f;
//     p_camera->pm.e_34 = (far + p_camera->near) / (p_camera->near - far);
// p_camera->pm.e_43 = (2.f * far * p_camera->near) / (p_camera->near - far);
// 	p_camera->pm.e_43 = 5.f/far;
//     // p_camera->pm.e_44 = 0.0f; // Ensure correct homogeneous divide
// }

// void	ksx_camera_set_pm(t_camera *p_camera, float fov, float far)
// {
//     float	f;

// 	ksx_m4_reset(&p_camera->pm);
// 	f = 1.f / tanf(fov * .5f * PI180); // fov is in radians
//     p_camera->pm.e_11 = f;// / p_camera->aspect;
//     p_camera->pm.e_22 = f;
//     p_camera->pm.e_33 = (far + .1f) / (.1f - far);
// 	p_camera->pm.e_43 = 5.f/far; //(2.f * far * .1f) / (.1f - far);
// 	p_camera->pm.e_34 = -1.f;
// }

// void	ksx_camera_set_pm(t_camera *p_camera, float far)
// {
// 	ksx_m4_reset(&p_camera->pm);
// 	p_camera->far = far;
// 	p_camera->far = p_camera->near + 1000;
// 	p_camera->pm.e_11 = p_camera->n / p_camera->r;
// 	p_camera->pm.e_22 = p_camera->n / (p_camera->aspect * p_camera->t);
// 	// p_camera->pm.e_31
// 	// 	= (p_camera->r + p_camera->l) / (p_camera->r - p_camera->l);
// 	// p_camera->pm.e_32
// 	// 	= (p_camera->t + p_camera->b) / (p_camera->t - p_camera->b);
// 	// p_camera->pm.e_33
// 	// 	= - (p_camera->f + p_camera->n) / (p_camera->f - p_camera->n);
// 	p_camera->pm.e_33
// 		= - (p_camera->f + p_camera->n) / (p_camera->f - p_camera->n);
// 	p_camera->pm.e_34 = -1.f;
// 	p_camera->pm.e_43
// 		= (-2.f * p_camera->f * p_camera->n) / (p_camera->f - p_camera->n);
// }

// float	scale;
// scale = WIDTH / HEIGHT;
// p_camera->pm.e_11 = 1 / (scale * tanf((p_camera->hfov / 2) * (PI / 180)));
// p_camera->pm.e_22 = 1 / tanf((p_camera->hfov / 2) * (PI / 180));
// p_camera->pm.e_33 = (-(far + near)) / (far - near);
// p_camera->pm.e_34 = (-(2 * far * near)) / (far - near);
// p_camera->pm.e_43 = 1;
