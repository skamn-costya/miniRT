/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:32:03 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/12 13:55:38 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include "ksx_m4_math.h"
#include "ksx_object.h"
#include <math.h>

void	ksx_transform(t_vector3 *p_point, t_matrix4 *p_tm,
		t_vector3 *p_result)
{
	t_vector4	v4;

	v4 = ksx_vec3_vec4(p_point, 1);
	v4 = ksx_m4_vec4(p_tm, &v4);
	p_result->x = v4.x;
	p_result->y = v4.y;
	p_result->z = v4.z;
}

void	ksx_transform_obj(t_object *p_object, t_basis *p_basis)
{
	t_matrix4	tm;
	uint32_t	idx;

	ksx_get_tm (&tm, p_basis);
	idx = 0;
	while (idx < p_object->size_over)
	{
		ksx_transform(&p_object->pp_over[idx]->p_p, &tm, &p_object->pp_over[idx]->p_p);
		idx++;
	}
	ksx_transform(&p_object->axis.p_ver1->p_p, &tm, &p_object->axis.p_ver1->p_p);
	ksx_transform(&p_object->axis.p_ver2->p_p, &tm, &p_object->axis.p_ver2->p_p);
	ksx_transform(&p_object->axis.p_ver3->p_p, &tm, &p_object->axis.p_ver3->p_p);
	idx = 0;
	while (idx < 8)
	{
		ksx_transform(&p_object->box_ver[idx].p_p, &tm, &p_object->box_ver[idx].p_p);
		idx++;
	}
}

void ksx_get_tm(t_matrix4 *p_m4, t_basis *p_basis)
{
	p_m4->e_11 = p_basis->i.x;
	p_m4->e_12 = p_basis->i.y;
	p_m4->e_13 = p_basis->i.z;
	p_m4->e_14 = -ksx_vec3_dot(p_basis->i, p_basis->o);
	// p_m4->e_14 = p_basis->i.x * (-p_basis->o.x) + p_basis->i.y
	// 	* (-p_basis->o.y) + p_basis->i.z * (-p_basis->o.z);
	p_m4->e_21 = p_basis->j.x;
	p_m4->e_22 = p_basis->j.y;
	p_m4->e_23 = p_basis->j.z;
	p_m4->e_24 = -ksx_vec3_dot(p_basis->j, p_basis->o);
	// p_m4->e_24 = p_basis->j.x * (-p_basis->o.x) + p_basis->j.y
	// 	* (-p_basis->o.y) + p_basis->j.z * (-p_basis->o.z);
	p_m4->e_31 = p_basis->k.x;
	p_m4->e_32 = p_basis->k.y;
	p_m4->e_33 = p_basis->k.z;
	p_m4->e_34 = -ksx_vec3_dot(p_basis->k, p_basis->o);
	// p_m4->e_34 = p_basis->k.x * (-p_basis->o.x) + p_basis->k.y
	// 	* (-p_basis->o.y) + p_basis->k.z * (-p_basis->o.z);
	p_m4->e_41 = 0;
	p_m4->e_42 = 0;
	p_m4->e_43 = 0;
	p_m4->e_44 = 1;
}
