/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:32:03 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/23 00:44:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include "ksx_m4_math.h"
#include "ksx_object.h"
#include "ksx_basis.h"
#include <math.h>
#include <stdio.h>

static void	ksx_obj_transform_(t_object *p_object, t_matrix4 *p_tm);

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

	// printf("basis->i.x = %f\n", p_object->basis.i.x);
	// printf("basis->i.y = %f\n", p_object->basis.i.y);
	// printf("basis->i.z = %f\n", p_object->basis.i.z);
	// printf("basis->j.x = %f\n", p_object->basis.j.x);
	// printf("basis->j.y = %f\n", p_object->basis.j.y);
	// printf("basis->j.z = %f\n", p_object->basis.j.z);
	// printf("basis->k.x = %f\n", p_object->basis.k.x);
	// printf("basis->k.y = %f\n", p_object->basis.k.y);
	// printf("basis->k.z = %f\n", p_object->basis.k.z);
	// printf("mag(basis->i) = %f\n", ksx_vec3_mag(&p_object->basis.i));
	// printf("mag(basis->j) = %f\n", ksx_vec3_mag(&p_object->basis.j));
	// printf("mag(basis->k) = %f\n", ksx_vec3_mag(&p_object->basis.k));
	// printf("angle(basis->i, basis->j) = %f\n",
	// ksx_vec3_angle(&p_object->basis.i, &p_object->basis.j) / PI180);
	// printf("angle(basis->j, basis->k) = %f\n",
	// ksx_vec3_angle(&p_object->basis.j, &p_object->basis.k) / PI180);
	// printf("angle(basis->k, basis->i) = %f\n\n",
	// ksx_vec3_angle(&p_object->basis.k, &p_object->basis.i) / PI180);

void	ksx_obj_transform(t_object *p_object)
{
	t_matrix4	tm;
	t_basis		basis;
	t_box		**pp_box;

	ksx_obj_copy_vrts(p_object, ORIP, LOCP);
	pp_box = p_object->pp_box;
	while (pp_box && *pp_box)
	{
		ksx_obj_copy_boxvrts((*pp_box)->ver, ORIP, LOCP, 8);
		pp_box++;
	}
	basis.o = ksx_vec3_set(0.f, 0.f, 0.f);
	ksx_basis_set_norm(&basis, &basis.o);
	ksx_obj_set_axis(p_object->axis, &basis);
	ksx_basis_copy_len(&p_object->basis, &basis);
	ksx_get_tm (&tm, &basis);
	ksx_obj_transform_(p_object, &tm);
	basis = p_object->basis;
	ksx_basis_unit(&basis);
	ksx_get_tm (&tm, &basis);
	ksx_obj_transform_(p_object, &tm);
}

static void	ksx_obj_transform_(t_object *p_object, t_matrix4 *p_tm)
{
	uint32_t	idx;
	t_box		**pp_box;

	idx = -1;
	while (++idx < p_object->size_vrtx)
		ksx_transform(&p_object->pp_vrtx[idx]->lp,
			p_tm, &p_object->pp_vrtx[idx]->lp);
	idx = -1;
	while (++idx < p_object->size_vnrm)
		ksx_transform(&p_object->pp_vnrm[idx]->lp,
			p_tm, &p_object->pp_vnrm[idx]->lp);
	pp_box = p_object->pp_box;
	while (pp_box && *pp_box)
	{
		idx = -1;
		while (++idx < 8)
			ksx_transform(&(*pp_box)->ver[idx].lp,
				p_tm, &(*pp_box)->ver[idx].lp);
		pp_box++;
	}
	idx = -1;
	while (++idx < 4)
		ksx_transform(&p_object->axis[idx].lp,
			p_tm, &p_object->axis[idx].lp);
}

void	ksx_get_tm(t_matrix4 *p_m4, t_basis *p_basis)
{
	p_m4->e_11 = p_basis->i.x;
	p_m4->e_21 = p_basis->i.y;
	p_m4->e_31 = p_basis->i.z;
	p_m4->e_41 = 0;
	p_m4->e_12 = p_basis->j.x;
	p_m4->e_22 = p_basis->j.y;
	p_m4->e_32 = p_basis->j.z;
	p_m4->e_42 = 0;
	p_m4->e_13 = p_basis->k.x;
	p_m4->e_23 = p_basis->k.y;
	p_m4->e_33 = p_basis->k.z;
	p_m4->e_43 = 0;
	p_m4->e_14 = 0;
	p_m4->e_24 = 0;
	p_m4->e_34 = 0;
	p_m4->e_44 = 1;
}

// void	ksx_get_tm(t_matrix4 *p_m4, t_basis *p_basis)
// {
// 	p_m4->e_11 = p_basis->i.x;
// 	p_m4->e_12 = p_basis->i.y;
// 	p_m4->e_13 = p_basis->i.z;
// 	p_m4->e_14 = 0;
// 	p_m4->e_21 = p_basis->j.x;
// 	p_m4->e_22 = p_basis->j.y;
// 	p_m4->e_23 = p_basis->j.z;
// 	p_m4->e_24 = 0;
// 	p_m4->e_31 = p_basis->k.x;
// 	p_m4->e_32 = p_basis->k.y;
// 	p_m4->e_33 = p_basis->k.z;
// 	p_m4->e_34 = 0;
// 	p_m4->e_41 = 0;
// 	p_m4->e_42 = 0;
// 	p_m4->e_43 = 0;
// 	p_m4->e_44 = 1;
// }
