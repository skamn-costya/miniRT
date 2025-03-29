/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_cylinder02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:55:12 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/28 17:30:46 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Cylinder: "cy", coord, vector, d, h, rgb

#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_basis.h"
#include "ksx_vec3_math.h"
#include "ksx_3D.h"
#include "ksx_cylinder.h"
#include "ksx_triangle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void	ksx_init_cylinder_tri_(t_object *p_object,
				uint32_t size, t_vertex **pp_ver_b);
static void	ksx_init_cylinder_tri_cup(t_object *p_object,
				uint32_t size, t_vertex **pp_ver_b);

void	ksx_init_cylinder_tri(t_object *p_object,
			int32_t size, int32_t count)
{
	int32_t		idx[3];
	t_vertex	**pp_ver;
	t_triangle	**pp_tri;

	idx[0] = 1;
	while (++idx[0] < count)
	{
		pp_ver = &p_object->pp_vrtx[2 + size * 2 + idx[0] * size];
		pp_tri = ksx_obj_add_tris(p_object, size * 2);
		idx[1] = -1;
		while (++idx[1] < size)
		{
			idx[2] = idx[1] + 1;
			if (idx[2] == size)
				idx[2] = 0;
			ksx_tri_set_vertexes(pp_tri[idx[1]], pp_ver[idx[1]], pp_ver[idx[2]],
				pp_ver[idx[1] + size]);
			ksx_tri_set_vertexes(pp_tri[idx[1] + size], pp_ver[idx[1] + size],
				pp_ver[idx[2] + size], pp_ver[idx[2]]);
		}
	}
	ksx_init_cylinder_tri_(p_object, size,
		&p_object->pp_vrtx[2 + size * 2 + idx[0] * size]);
	ksx_init_cylinder_tri_cup(p_object, size,
		&p_object->pp_vrtx[2 + idx[0] * size]);
}

static void	ksx_init_cylinder_tri_(t_object *p_object,
	uint32_t size, t_vertex **pp_ver_)
{
	uint32_t	idx[2];
	t_vertex	**pp_ver[4];
	t_triangle	**pp_tri;

	pp_ver[0] = &p_object->pp_vrtx[2 + size * 2];
	pp_ver[3] = &p_object->pp_vrtx[2 + size * 3];
	pp_ver[1] = &p_object->pp_vrtx[2 + size * 4];
	pp_ver[2] = pp_ver_;
	pp_tri = ksx_obj_add_tris(p_object, size * 4);
	idx[0] = 0;
	while (idx[0] < size)
	{
		idx[1] = idx[0] + 1;
		if (idx[1] == size)
			idx[1] = 0;
		ksx_tri_set_vertexes(pp_tri[idx[1]], pp_ver[0][idx[0]],
			pp_ver[0][idx[1]], pp_ver[1][idx[0]]);
		ksx_tri_set_vertexes(pp_tri[idx[1] + size], pp_ver[1][idx[0]],
			pp_ver[1][idx[1]], pp_ver[0][idx[1]]);
		ksx_tri_set_vertexes(pp_tri[idx[1] + size * 2], pp_ver[2][idx[0]],
			pp_ver[2][idx[1]], pp_ver[3][idx[0]]);
		ksx_tri_set_vertexes(pp_tri[idx[1] + size * 3], pp_ver[3][idx[0]],
			pp_ver[3][idx[1]], pp_ver[2][idx[1]]);
		idx[0]++;
	}
}

static void	ksx_init_cylinder_tri_cup(t_object *p_object, uint32_t size,
	t_vertex **pp_ver_b)
{
	uint32_t	idx[2];
	t_vertex	**pp_ver_a;
	t_triangle	**pp_tri;

	pp_tri = ksx_obj_add_tris(p_object, size * 2);
	pp_ver_a = &p_object->pp_vrtx[2];
	pp_ver_b = &p_object->pp_vrtx[2 + size];
	idx[0] = 0;
	while (idx[0] < size)
	{
		idx[1] = idx[0] + 1;
		if (idx[1] == size)
			idx[1] = 0;
		ksx_tri_set_vertexes(pp_tri[idx[0]], pp_ver_a[idx[0]],
			pp_ver_a[idx[1]], p_object->pp_vrtx[0]);
		ksx_tri_set_vertexes(pp_tri[idx[0] + size], pp_ver_b[idx[0]],
			pp_ver_b[idx[1]], p_object->pp_vrtx[1]);
		idx[0]++;
	}
}
