/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_cylinder02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:55:12 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/21 12:53:19 by ksorokol         ###   ########.fr       */
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

static void	ksx_init_cylinder_tri_cup(t_object *p_object,
				uint32_t size, t_vertex **pp_ver_b);

void	ksx_init_cylinder_tri(t_object *p_object,
			uint32_t size, uint32_t count)
{
	uint32_t	idx[3];
	t_vertex	**pp_ver;
	t_triangle	**pp_tri;

	idx[0] = 0;
	while (idx[0] < count - 1)
	{
		pp_ver = &p_object->pp_vrtx[2 + idx[0] * size];
		pp_tri = ksx_obj_add_tris(p_object, size * 2);
		idx[1] = 0;
		while (idx[1] < size)
		{
			idx[2] = idx[1] + 1;
			if (idx[2] == size)
				idx[2] = 0;
			ksx_tri_set_vertexes(pp_tri[idx[1]], pp_ver[idx[1]], pp_ver[idx[2]], pp_ver[idx[1] + size]);
			ksx_tri_set_vertexes(pp_tri[idx[1] + size], pp_ver[idx[1] + size], pp_ver[idx[2] + size], pp_ver[idx[2]]);
			pp_tri[idx[1]]->color = p_object->color;
			pp_tri[idx[1] + size]->color = p_object->color;
			idx[1]++;
		}
		idx[0]++;
	}
	ksx_init_cylinder_tri_cup(p_object, size, &p_object->pp_vrtx[2 + idx[0] * size]);
}

static void	ksx_init_cylinder_tri_cup(t_object *p_object,
		uint32_t size, t_vertex **pp_ver_b)
{
	uint32_t	idx[2];
	t_vertex	**pp_ver_a;
	t_triangle	**pp_tri;

	pp_tri = ksx_obj_add_tris(p_object, size * 2);
	pp_ver_a = &p_object->pp_vrtx[2];
	idx[0] = 0;
	while (idx[0] < size)
	{
		idx[1] = idx[0] + 1;
		if (idx[1] == size)
			idx[1] = 0;
		ksx_tri_set_vertexes(pp_tri[idx[0]], pp_ver_a[idx[0]], pp_ver_a[idx[1]], p_object->pp_vrtx[0]);
		ksx_tri_set_vertexes(pp_tri[idx[0] + size], pp_ver_b[idx[0]], pp_ver_b[idx[1]], p_object->pp_vrtx[1]);
		pp_tri[idx[0]]->color = p_object->color;
		pp_tri[idx[0] + size]->color = p_object->color;
		idx[0]++;
	}
	idx[0]++;
}
