/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/25 16:30:45 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include "ksx_object.h"
#include "ksx_basis.h"
#include <math.h>

static void	ksx_transform_obj_wr(t_object *p_object);
static void	ksx_transform_obj_wt(t_object *p_object, t_matrix4 *p_wtm);
static void	ksx_get_wtm(t_matrix4 *p_m4, t_basis *p_basis);

// void	ksx_translate(t_vector3 *p_point, t_vector3 *p_center,
// 		t_vector3 *p_result)
// {
// 	*p_result = ksx_vec3_add (p_point, p_center);
// }

void	ksx_translate_obj(t_object *p_object)
{
	t_matrix4	wtm;

	ksx_transform_obj_wr(p_object);
	ksx_get_wtm(&wtm, &p_object->basis);
	ksx_transform_obj_wt(p_object, &wtm);
}

static void	ksx_transform_obj_wr(t_object *p_object)
{
	uint32_t	idx;
	t_box		**pp_box;

	idx = -1;
	while (++idx < p_object->size_vrtx)
	{
		p_object->pp_vrtx[idx]->wp = ksx_vec3_add
			(&p_object->pp_vrtx[idx]->p, &p_object->basis.w_o);
		p_object->pp_vrtx[idx]->wnorm = ksx_vec3_add
			(&p_object->pp_vrtx[idx]->norm, &p_object->basis.w_o);
	}
	pp_box = p_object->pp_box;
	while (pp_box && *pp_box)
	{
		idx = -1;
		while (++idx < 8)
			(*pp_box)->ver[idx].wp = ksx_vec3_add
				(&(*pp_box)->ver[idx].p, &p_object->basis.w_o);
		pp_box++;
	}
	idx = -1;
	while (++idx < 4)
		p_object->w_axis[idx].wp = ksx_vec3_add
			(&p_object->w_axis[idx].p, &p_object->basis.w_o);
}

static void	ksx_transform_obj_wt(t_object *p_object, t_matrix4 *p_wtm)
{
	uint32_t	idx;
	t_box		**pp_box;

	idx = -1;
	while (++idx < p_object->size_vrtx)
	{
		ksx_transform(&p_object->pp_vrtx[idx]->wp,
			p_wtm, &p_object->pp_vrtx[idx]->wp);
		ksx_transform(&p_object->pp_vrtx[idx]->norm,	// ??? may be need normalisation
			p_wtm, &p_object->pp_vrtx[idx]->wnorm);
	}
	pp_box = p_object->pp_box;
	while (pp_box && *pp_box)
	{
		idx = -1;
		while (++idx < 8)
			ksx_transform(&(*pp_box)->ver[idx].wp,
			p_wtm, &(*pp_box)->ver[idx].wp);
		pp_box++;
	}
	idx = -1;
	while (++idx < 4)
		ksx_transform(&p_object->w_axis[idx].wp,
			p_wtm, &p_object->w_axis[idx].wp);
}

static void	ksx_get_wtm(t_matrix4 *p_m4, t_basis *p_basis)
{
	p_m4->e_11 = p_basis->w_i.x;
	p_m4->e_12 = p_basis->w_i.y;
	p_m4->e_13 = p_basis->w_i.z;
	p_m4->e_14 = -ksx_vec3_dot(&p_basis->w_i, &p_basis->w_o);
	p_m4->e_21 = p_basis->w_j.x;
	p_m4->e_22 = p_basis->w_j.y;
	p_m4->e_23 = p_basis->w_j.z;
	p_m4->e_24 = -ksx_vec3_dot(&p_basis->w_j, &p_basis->w_o);
	p_m4->e_31 = p_basis->w_k.x;
	p_m4->e_32 = p_basis->w_k.y;
	p_m4->e_33 = p_basis->w_k.z;
	p_m4->e_34 = -ksx_vec3_dot(&p_basis->w_k, &p_basis->w_o);
	p_m4->e_41 = 0;
	p_m4->e_42 = 0;
	p_m4->e_43 = 0;
	p_m4->e_44 = 1;
}
