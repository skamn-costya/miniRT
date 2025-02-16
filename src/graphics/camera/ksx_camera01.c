/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_camera01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:50:20 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/16 23:59:50 by ksorokol         ###   ########.fr       */
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

	camera.basis.o = center;
	// camera.norm = norm;
	ksx_camera_set_basis(&camera, &norm);
	// ksx_create_vm(&camera.vm, &camera.basis);
	camera.fov = fov;
	camera.right = WIDTH * .5f;
	camera.left = - camera.right;
	camera.top = HEIGHT * .5f;
	camera.bottom = -camera.top;
	camera.aspect = 1.f * WIDTH / HEIGHT;
	ksx_camera_set_vm(&camera);
	// camera.vfov = 2.f * atanf(tanf(camera.hfov * 0.5f) / camera.aspect);
	camera.flags = 0;
	return (camera);
}

// void ksx_camera_set_vm(t_camera *p_camera)
// {
// 	ksx_get_tm(&p_camera->vm, &p_camera->basis);
// 	ksx_m4_invert(&p_camera->vm, &p_camera->ivm);
// }

void ksx_camera_obj_vm(t_object *p_object, t_matrix4 *p_vm)
{
	uint32_t	idx;

	idx = 0;
	while (idx < p_object->size_over)
	{
		ksx_transform(&p_object->pp_over[idx]->p_wp, p_vm, &p_object->pp_over[idx]->p_cp);
		idx++;
	}
	ksx_transform(&p_object->center, p_vm, &p_object->c_center);
	ksx_transform(&p_object->axis.p_ver1->p_wp, p_vm, &p_object->axis.p_ver1->p_cp);
	ksx_transform(&p_object->axis.p_ver2->p_wp, p_vm, &p_object->axis.p_ver2->p_cp);
	ksx_transform(&p_object->axis.p_ver3->p_wp, p_vm, &p_object->axis.p_ver3->p_cp);
	idx = 0;
	while (idx < 8)
	{
		ksx_transform(&p_object->box_ver[idx].p_wp, p_vm, &p_object->box_ver[idx].p_cp);
		idx++;
	}	
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
//  /notes/computer-graphics/viewing/projection-transform/

void	ksx_camera_set_pm(t_camera *p_camera, float fov, float far)
{
	if (fov < 1 || fov > 179)
		return;
	p_camera->fov = fov;
	p_camera->hfov = fov * PI180;
	p_camera->near = (WIDTH * .5f) * tanf(p_camera->hfov * .5f);
	p_camera->far = p_camera->near + far;
	ksx_m4_reset(&p_camera->pm);
	p_camera->pm.e_11 = 1.f / tanf(p_camera->hfov * .5f);
	p_camera->pm.e_22 = -1.f / tanf(p_camera->hfov * .5f);
	// p_camera->pm.e_22 = 1.f / (p_camera->aspect * tanf(p_camera->vfov * .5f));
	p_camera->pm.e_33 = -((p_camera->far + p_camera->near)
			/ (p_camera->far - p_camera->near));
	// p_camera->pm.e_33 = -((p_camera->far)
	// 		/ (p_camera->far - p_camera->near));
	p_camera->pm.e_34 = -1.f;
	p_camera->pm.e_43 = -((2.f * p_camera->far * p_camera->near)
			/ (p_camera->far - p_camera->near));
}

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
