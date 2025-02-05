/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_camera01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:50:20 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/05 22:05:41 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_rotation.h"
#include "ksx_camera.h"
#include <math.h>

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

	camera.center = center;
	camera.norm = norm;
	camera.basis = ksx_get_basis(norm, center);
	camera.vm = ksx_create_vm(camera.basis);
	camera.hfov = (fov * PI) / 180;
	camera.aspect = (WIDTH * 1.0f) / (HEIGHT * 1.0f);
	camera.vfov = 2.0f * atanf(tanf(camera.hfov * 0.5f) / camera.aspect);
	return (camera);
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

void	ksx_set_camera_pm(t_camera *p_camera, float near, float far)
{
	int		idx;

	idx = 15;
	while (idx-- != -1)
		p_camera->pm.elems[idx] = 0;
	p_camera->near = near;
	p_camera->far = far;
	p_camera->pm.e_11 = 1.f / tanf(p_camera->hfov * .5f);
	p_camera->pm.e_22 = 1.f / (p_camera->aspect * tanf(p_camera->vfov * .5f));
	p_camera->pm.e_33 = -((p_camera->far + p_camera->near)
			/ (p_camera->far - p_camera->near));
	p_camera->pm.e_34 = -1.f;
	p_camera->pm.e_43 = -((2.f * p_camera->far * p_camera->near)
			/ (p_camera->far - p_camera->near));
}

// void	set_camera_pm(t_camera *p_camera, float far)
// {
// 	int		idx;

// 	idx = 15;
// 	while (idx-- != -1)
// 		p_camera->pm.elems[idx] = 0;
// 	p_camera->far = far;
// 	p_camera->pm.e_11 = (2 * p_camera->n) / (p_camera->r - p_camera->l);
// 	p_camera->pm.e_22 = (2 * p_camera->n) / (p_camera->t - p_camera->b);
// 	p_camera->pm.e_31
// 		= (p_camera->r + p_camera->l) / (p_camera->r - p_camera->l);
// 	p_camera->pm.e_32
// 		= (p_camera->t + p_camera->b) / (p_camera->t - p_camera->b);
// 	p_camera->pm.e_33
// 		= - (p_camera->f + p_camera->n) / (p_camera->f - p_camera->n);
// 	p_camera->pm.e_34 = -1;
// 	p_camera->pm.e_43
// 		= - (2 * p_camera->f * p_camera->n) / (p_camera->f - p_camera->n);
// }

// float	scale;
// scale = WIDTH / HEIGHT;
// p_camera->pm.e_11 = 1 / (scale * tanf((p_camera->hfov / 2) * (PI / 180)));
// p_camera->pm.e_22 = 1 / tanf((p_camera->hfov / 2) * (PI / 180));
// p_camera->pm.e_33 = (-(far + near)) / (far - near);
// p_camera->pm.e_34 = (-(2 * far * near)) / (far - near);
// p_camera->pm.e_43 = 1;
