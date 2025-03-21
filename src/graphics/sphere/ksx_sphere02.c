/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_sphere02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/21 11:20:27 by ksorokol         ###   ########.fr       */
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
static void	ksx_sphere_split_1(t_triangle *p_tris, t_triangle **pp_tri,
				uint32_t idx, t_vertex **pp_ver);

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
		ksx_sphere_split_1(p_tris, pp_tri, idx, pp_ver);
		ksx_vec3_resize(&pp_ver[idx * 3]->op, p_object->size1);
		ksx_vec3_resize(&pp_ver[idx * 3 + 1]->op, p_object->size1);
		ksx_vec3_resize(&pp_ver[idx * 3 + 2]->op, p_object->size1);
		pp_tri[idx * 4]->p_color = &p_object->color;
		pp_tri[idx * 4 + 1]->p_color = &p_object->color;
		pp_tri[idx * 4 + 2]->p_color = &p_object->color;
		pp_tri[idx * 4 + 3]->p_color = &p_object->color;
		idx++;
	}
	ksx_free_pointers((void ***) &p_object->pp_tri);
	p_object->pp_tri = pp_tri;
	p_object->size_tri *= 4;
}

static void	ksx_sphere_split_1(t_triangle *p_tris, t_triangle **pp_tri,
		uint32_t idx, t_vertex **pp_ver)
{
	pp_ver[idx * 3]->op = ksx_mid_point(&p_tris->p_ver1->op,
			&p_tris->p_ver2->op);
	pp_ver[idx * 3 + 1]->op = ksx_mid_point(&p_tris->p_ver2->op,
			&p_tris->p_ver3->op);
	pp_ver[idx * 3 + 2]->op = ksx_mid_point(&p_tris->p_ver3->op,
			&p_tris->p_ver1->op);
	ksx_tri_set_vertexes (pp_tri[idx * 4], p_tris->p_ver1,
		pp_ver[idx * 3], pp_ver[idx * 3 + 2]);
	ksx_tri_set_vertexes (pp_tri[idx * 4 + 1], pp_ver[idx * 3],
		p_tris->p_ver2, pp_ver[idx * 3 + 1]);
	ksx_tri_set_vertexes (pp_tri[idx * 4 + 2], pp_ver[idx * 3 + 1],
		p_tris->p_ver3, pp_ver[idx * 3 + 2]);
	ksx_tri_set_vertexes (pp_tri[idx * 4 + 3], pp_ver[idx * 3],
		pp_ver[idx * 3 + 1], pp_ver[idx * 3 + 2]);
}

void	ksx_sphere_norns(t_object *p_object)
{
	uint32_t	idx[2];

	ksx_obj_add_vnrm(p_object, p_object->size_vrtx);
	idx[0] = 0;
	while (idx[0] < p_object->size_vrtx)
	{
		*p_object->pp_vnrm[idx[0]] = *p_object->pp_vrtx[idx[0]];
		ksx_vec3_resize(&p_object->pp_vnrm[idx[0]]->op, UNIT);
		idx[1] = 0;
		while (idx[1] < p_object->size_tri)
		{
			if(p_object->pp_tri[idx[1]]->p_ver1 == p_object->pp_vrtx[idx[0]])
				p_object->pp_tri[idx[1]]->p_norm1 = p_object->pp_vnrm[idx[0]];
			else if(p_object->pp_tri[idx[1]]->p_ver2 == p_object->pp_vrtx[idx[0]])
				p_object->pp_tri[idx[1]]->p_norm2 = p_object->pp_vnrm[idx[0]];
			else if(p_object->pp_tri[idx[1]]->p_ver3 == p_object->pp_vrtx[idx[0]])
				p_object->pp_tri[idx[1]]->p_norm3 = p_object->pp_vnrm[idx[0]];
			idx[1]++;
		}
		idx[0]++;
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
