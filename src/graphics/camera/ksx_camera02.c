/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_camera02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:50:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/19 23:11:48 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_m4_math.h"
#include "ksx_vec3_math.h"

void ksx_camera_set_vm(t_camera *p_camera)
{
	p_camera->vm.e_11 = p_camera->basis.i.x;
	p_camera->vm.e_12 = p_camera->basis.i.y;
	p_camera->vm.e_13 = p_camera->basis.i.z;
	p_camera->vm.e_14 = -ksx_vec3_dot(&p_camera->basis.i, &p_camera->basis.o);
	p_camera->vm.e_21 = p_camera->basis.j.x;
	p_camera->vm.e_22 = p_camera->basis.j.y;
	p_camera->vm.e_23 = p_camera->basis.j.z;
	p_camera->vm.e_24 = -ksx_vec3_dot(&p_camera->basis.j, &p_camera->basis.o);
	p_camera->vm.e_31 = p_camera->basis.k.x;
	p_camera->vm.e_32 = p_camera->basis.k.y;
	p_camera->vm.e_33 = p_camera->basis.k.z;
	p_camera->vm.e_34 = -ksx_vec3_dot(&p_camera->basis.k, &p_camera->basis.o);
	p_camera->vm.e_41 = 0;
	p_camera->vm.e_42 = 0;
	p_camera->vm.e_43 = 0;
	p_camera->vm.e_44 = 1;
	ksx_m4_invert(&p_camera->vm, &p_camera->ivm);
}
