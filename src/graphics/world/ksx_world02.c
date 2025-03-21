/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_world02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:48:15 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/18 00:36:02 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_world.h"
#include "ksx_camera.h"
#include "ksx_object.h"
#include "ksx_obj_file.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"
#include "parser.h"
#include "libft.h"
#include <math.h>

static void	ksx_world_obj_tm_1(t_world *p_world,
				t_object *p_object, uint32_t idx);

void	ksx_world_obj_tm(t_world *p_world, t_object *p_object)
{
	uint32_t	idx;
	t_box		**pp_box;

	ksx_world_set_tm(p_world, &p_object->basis.w_o);
	idx = -1;
	while (++idx < p_object->size_vrtx)
		ksx_world_obj_tm_1(p_world, p_object, idx);
	idx = -1;
	while (++idx < p_object->size_vnrm)
		p_object->pp_vnrm[idx]->wp = ksx_m4_vec3(&p_world->tm,
			&p_object->pp_vnrm[idx]->lp);
	pp_box = p_object->pp_box;
	while (pp_box && *pp_box)
	{
		idx = -1;
		while (++idx < 8)
			ksx_transform(&(*pp_box)->ver[idx].lp,
				&p_world->tm, &(*pp_box)->ver[idx].wp);
		pp_box++;
	}
	idx = -1;
	while (++idx < 4)
		ksx_transform(&p_object->axis[idx].lp,
			&p_world->tm, &p_object->axis[idx].wp);
}

static void	ksx_world_obj_tm_1(t_world *p_world,
	t_object *p_object, uint32_t idx)
{
	float	f;

	ksx_transform(&p_object->pp_vrtx[idx]->lp,
		&p_world->tm, &p_object->pp_vrtx[idx]->wp);
	// ksx_transform(&p_object->pp_vrtx[idx]->lnorm,
	// 	&p_world->tm, &p_object->pp_vrtx[idx]->wnorm);
	f = fabs(p_object->pp_vrtx[idx]->wp.x);
	if (f > p_world->far.z)
		p_world->far.z = f;
	f = fabs(p_object->pp_vrtx[idx]->wp.y);
	if (f > p_world->far.z)
		p_world->far.z = f;
	f = fabs(p_object->pp_vrtx[idx]->wp.z);
	if (f > p_world->far.z)
		p_world->far.z = f;
}

void	ksx_world_set_tm(t_world *p_world, t_vector3 *p_o)
{
	p_world->tm.e_11 = p_world->basis.i.x;
	p_world->tm.e_12 = p_world->basis.i.y;
	p_world->tm.e_13 = p_world->basis.i.z;
	p_world->tm.e_14 = ksx_vec3_dot(&p_world->basis.i, p_o);
	p_world->tm.e_21 = p_world->basis.j.x;
	p_world->tm.e_22 = p_world->basis.j.y;
	p_world->tm.e_23 = p_world->basis.j.z;
	p_world->tm.e_24 = ksx_vec3_dot(&p_world->basis.j, p_o);
	p_world->tm.e_31 = p_world->basis.k.x;
	p_world->tm.e_32 = p_world->basis.k.y;
	p_world->tm.e_33 = p_world->basis.k.z;
	p_world->tm.e_34 = ksx_vec3_dot(&p_world->basis.k, p_o);
	p_world->tm.e_41 = 0;
	p_world->tm.e_42 = 0;
	p_world->tm.e_43 = 0;
	p_world->tm.e_44 = 1;
}
