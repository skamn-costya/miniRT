/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:23:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/18 00:24:05 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_world.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"
#include "ksx_object.h"
#include "ksx_basis.h"
#include "ksx_camera.h"
#include <math.h>
#include <stdio.h>

void	ksx_change(t_graphics *p_grph)
{
	t_object	**pp_object;
	t_object	*p_object;
	int32_t		idx;

	if (!p_grph->world.pp_obj)
		return ;
	pp_object = p_grph->world.pp_obj;
	idx = 0;
	while (idx < p_grph->world.size_obj)
	{
		p_object = pp_object[idx];
		if (p_object->flags & CHANGE)
			ksx_change_obj(p_object, p_grph);
		idx++;
	}
	if (p_grph->world.flags & CHANGE)
		ksx_change_world(p_grph);
	if (p_grph->camera.flags & CHANGE)
		ksx_change_world(p_grph);
}

void	ksx_change_obj(t_object *p_object, t_graphics *p_grph)
{
	if (!p_object)
		return ;
	ksx_obj_transform(p_object);
	ksx_world_obj_tm(&p_grph->world, p_object);
	ksx_camera_obj_vm (p_object, &p_grph->camera.vm);
	p_object->flags &= ~CHANGE;
}

void	ksx_change_world(t_graphics *p_grph)
{
	t_object	**pp_object;
	t_object	*p_object;
	int32_t		idx;

	if (!p_grph->world.pp_obj)
		return ;
	pp_object = p_grph->world.pp_obj;
	idx = 0;
	while (idx < p_grph->world.size_obj)
	{
		p_object = pp_object[idx];
		ksx_world_obj_tm(&p_grph->world, p_object);
		ksx_camera_obj_vm (p_object, &p_grph->camera.vm);
		idx++;
	}
	ksx_change_camera(p_grph);
	p_grph->world.flags &= ~CHANGE;
}

void	ksx_change_camera(t_graphics *p_grph)
{
	t_object	**pp_object;
	t_plane		*p_plane;
	int32_t		idx;

	ksx_camera_set_vm(&p_grph->camera);
	ksx_camera_refresh_pm(p_grph, p_grph->camera.fov);
	if (!p_grph->world.pp_obj)
		return ;
	pp_object = p_grph->world.pp_obj;
	idx = -1;
	while (++idx < p_grph->world.size_obj)
		ksx_camera_obj_vm (pp_object[idx], &p_grph->camera.vm);
	idx = -1;
	while (++idx < p_grph->world.size_pln)
	{
		p_plane = p_grph->world.pp_pln [idx];
		ksx_transform(&p_plane->point.wp, &p_grph->camera.vm,
			&p_plane->point.cp);
		// p_plane->norm.cp = ksx_vec3_add(&p_plane->norm.wp, &p_grph->camera.basis.w_o);
		// t_matrix4 m4= p_grph->camera.vm;
		// m4.e_14 = 0;
		// m4.e_24 = 0;
		// m4.e_34 = 0;
		// ksx_transform(&p_plane->norm.wp, &m4,
		// 		&p_plane->norm.cp);
		p_plane->norm.cp = ksx_m4_vec3(&p_grph->camera.vm, &p_plane->norm.wp);
		// p_plane->norm.cp = transform_normal(&p_plane->norm.wp,
		// 		&p_grph->world.basis, &p_grph->camera.basis);
		// p_plane->norm.cp.x *= -1;
		// p_plane->norm.cp.y *= -1;
		p_plane->norm.cp = ksx_vec3_unit(&p_plane->norm.cp);
	}
	p_grph->camera.flags &= ~CHANGE;
}
