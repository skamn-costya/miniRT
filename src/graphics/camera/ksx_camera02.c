/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_camera02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:50:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/28 17:04:59 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_camera.h"
#include "ksx_object.h"
#include "ksx_m4_math.h"
#include "ksx_vec3_math.h"
#include "stdio.h"

void	ksx_camera_set_vm(t_camera *p_camera)
{
	p_camera->vm.e_11 = p_camera->basis.i.x;
	p_camera->vm.e_12 = p_camera->basis.i.y;
	p_camera->vm.e_13 = p_camera->basis.i.z;
	p_camera->vm.e_14 = -ksx_vec3_dot(&p_camera->basis.i, &p_camera->basis.w_o);
	p_camera->vm.e_21 = p_camera->basis.j.x;
	p_camera->vm.e_22 = p_camera->basis.j.y;
	p_camera->vm.e_23 = p_camera->basis.j.z;
	p_camera->vm.e_24 = -ksx_vec3_dot(&p_camera->basis.j, &p_camera->basis.w_o);
	p_camera->vm.e_31 = p_camera->basis.k.x;
	p_camera->vm.e_32 = p_camera->basis.k.y;
	p_camera->vm.e_33 = p_camera->basis.k.z;
	p_camera->vm.e_34 = -ksx_vec3_dot(&p_camera->basis.k, &p_camera->basis.w_o);
	p_camera->vm.e_41 = 0;
	p_camera->vm.e_42 = 0;
	p_camera->vm.e_43 = 0;
	p_camera->vm.e_44 = 1;
	ksx_m4_invert(&p_camera->vm, &p_camera->ivm);
}

void	ksx_camera_refresh_pm(t_graphics *p_grph, float fov)
{
	t_vector3	vec3;

	if (p_grph->camera.flags & CAM_PM)
	{
		if (p_grph->camera.far == 0.f)
		{
			ksx_transform(&p_grph->world.far, &p_grph->camera.vm, &vec3);
			p_grph->camera.far = p_grph->camera.near + vec3.z + .1f;
			p_grph->camera.far = p_grph->camera.near * 2.f;
			printf("near = %f; far = %f\n", p_grph->camera.near,
				p_grph->camera.far);
		}
		ksx_camera_set_pm2(&p_grph->camera, fov);
	}
	else
		ksx_camera_set_pm1(&p_grph->camera);
}
