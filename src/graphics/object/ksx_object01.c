/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_object01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:37:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/12 18:55:12 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include "ksx_basis.h"
#include "ksx_object.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

t_object	*ksx_create_object(t_vector3 *p_center)
{
	t_object	*p_object;
	t_vector3	v;

	p_object = (t_object *) malloc (sizeof(t_object));
	if (!p_object)
		return (printf("Error: memory allocation failed!\n"), NULL);
	p_object->flags = 0x00000000;
	p_object->center = *p_center;
	p_object->angle.x = 0;
	p_object->angle.y = 0;
	p_object->angle.z = 0;
	p_object->c_center = p_object->center;
	p_object->pp_over = NULL;
	p_object->size_over = 0;
	p_object->pp_otri = NULL;
	p_object->size_otri = 0;
	// p_object->last_gen = 0;
	v = ksx_vec3_set(0, 1, 0);
	p_object->basis = ksx_get_basis_obj(&v);
	p_object->axis_ver[0].p_p = ksx_vec3_set(AXIS_LEN, 0, 0);
	p_object->axis_ver[1].p_p = ksx_vec3_set(0, AXIS_LEN, 0);
	p_object->axis_ver[2].p_p = ksx_vec3_set(0, 0, AXIS_LEN);
	p_object->axis.p_ver1 = &p_object->axis_ver[0];
	p_object->axis.p_ver2 = &p_object->axis_ver[1];
	p_object->axis.p_ver3 = &p_object->axis_ver[2];
	return (p_object);
}
