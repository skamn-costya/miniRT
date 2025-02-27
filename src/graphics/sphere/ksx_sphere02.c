/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_sphere02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/27 17:11:15 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Sphere: "sp", coord, d, rgb

#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_sphere.h"
#include "ksx_triangle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// static void	ksx_sphere_split_(t_object *p_object, float *p_radius,
// 				t_triangle **p_tris, t_vector3 *p_v);

void	ksx_sphere_split(t_object *p_object)
{
	t_triangle	*p_tris;
	t_vertex	**pp_ver;
	t_triangle	**pp_tri;
	uint32_t	idx;

	idx = 0;
	pp_ver = ksx_obj_add_vers(p_object, (p_object->size_tri * 3));
	pp_tri = ksx_obj_new_tris(p_object->size_tri * 4);
	while (idx < p_object->size_tri)
	{
		p_tris = p_object->pp_tri[idx];
		pp_ver[idx * 3]->op = ksx_mid_point(&p_tris->p_ver1->op, &p_tris->p_ver2->op);
		pp_ver[idx * 3 + 1]->op = ksx_mid_point(&p_tris->p_ver2->op, &p_tris->p_ver3->op);
		pp_ver[idx * 3 + 2]->op = ksx_mid_point(&p_tris->p_ver3->op, &p_tris->p_ver1->op);
		ksx_vec3_resize(&pp_ver[idx * 3]->op, p_object->size1);
		ksx_vec3_resize(&pp_ver[idx * 3 + 1]->op, p_object->size1);
		ksx_vec3_resize(&pp_ver[idx * 3 + 2]->op, p_object->size1);
		ksx_tri_set_vertexes (pp_tri[idx * 4], p_tris->p_ver1, pp_ver[idx * 3], pp_ver[idx * 3 + 2]);
		ksx_tri_set_vertexes (pp_tri[idx * 4 + 1], pp_ver[idx * 3], p_tris->p_ver2, pp_ver[idx * 3 + 1]);
		ksx_tri_set_vertexes (pp_tri[idx * 4 + 2], pp_ver[idx * 3 + 1], p_tris->p_ver3, pp_ver[idx * 3 + 2]);
		ksx_tri_set_vertexes (pp_tri[idx * 4 + 3], pp_ver[idx * 3], pp_ver[idx * 3 + 1], pp_ver[idx * 3 + 2]);
		pp_tri[idx * 4]->color = p_object->color;
		pp_tri[idx * 4 + 1]->color = p_object->color;
		pp_tri[idx * 4 + 2]->color = p_object->color;
		pp_tri[idx * 4 + 3]->color = p_object->color;
		idx++;
	}
	ksx_free_pointers((void ***) &p_object->pp_tri);
	p_object->pp_tri = pp_tri;
	p_object->size_tri *= 4;
}

void	ksx_sphere_norns(t_object *p_object)
{
	uint32_t	idx;
	t_vertex	*p_vrtx;

	idx = 0;
	while (idx < p_object->size_vrtx)
	{
		p_vrtx = p_object->pp_vrtx[idx];
		p_vrtx->onorm = p_vrtx->op;
		ksx_vec3_resize(&p_vrtx->onorm, UNIT);
		idx++;
	}
}

// static void	ksx_sphere_split_(t_object *p_object, float *p_radius,
// 				t_triangle **p_tris, t_vector3 *p_v)
// {
// 	ksx_vec3_resize(&p_v[0], *p_radius);
// 	ksx_vec3_resize(&p_v[1], *p_radius);
// 	ksx_vec3_resize(&p_v[2], *p_radius);
// 	p_tris[1]->c_p1 = p_tris[0]->c_p1;
// 	p_tris[1]->c_p2 = p_v[0];
// 	p_tris[1]->c_p3 = p_v[2];
// 	p_tris[2]->c_p1 = p_v[0];
// 	p_tris[2]->c_p2 = p_tris[0]->c_p2;
// 	p_tris[2]->c_p3 = p_v[1];
// 	p_tris[3]->c_p1 = p_v[1];
// 	p_tris[3]->c_p2 = p_tris[0]->c_p3;
// 	p_tris[3]->c_p3 = p_v[2];
// 	p_tris[4]->c_p1 = p_v[0];
// 	p_tris[4]->c_p2 = p_v[1];
// 	p_tris[4]->c_p3 = p_v[2];
// 	ksx_tri2obj (p_tris[1], p_object);
// 	ksx_tri2obj (p_tris[2], p_object);
// 	ksx_tri2obj (p_tris[3], p_object);
// 	ksx_tri2obj (p_tris[4], p_object);
// }
