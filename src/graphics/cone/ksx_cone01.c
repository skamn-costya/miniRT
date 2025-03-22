/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_cone01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:55:12 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/22 06:27:10 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Cone: "co", coord, vector, d, h, rgb

#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_basis.h"
#include "ksx_boxes.h"
#include "ksx_vec3_math.h"
#include "ksx_3D.h"
#include "ksx_cone.h"
#include "ksx_triangle.h"
#include "ray_texture.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void	ksx_init_cone_box(t_object *p_object);

static void	ksx_init_cone(t_object *p_object);

t_object	*ksx_create_cone(t_vector3 center, t_vector3 norm,
			float dia_ht[], t_color color)
{
	t_object	*p_object;

	p_object = ksx_create_object(&center);
	if (!p_object)
		return (NULL);
	p_object->color.mlx_color = color.mlx_color;
	ksx_color_unit_fraction(&p_object->color);
	p_object->size1 = dia_ht[0] * .5f;
	p_object->size2 = dia_ht[1] * .5f;
	norm = ksx_vec3_unit(&norm);
	ksx_basis_set_norm(&p_object->basis, &norm);
	ksx_init_cone_box(p_object);
	ksx_init_cone(p_object);
	ksx_obj_transform(p_object);
	ksx_obj_tris2box(p_object);
	ksx_obj_set_obj(p_object);
	return (p_object);
}

static void	ksx_init_cone_box(t_object *p_object)
{
	ksx_box_add_new(&p_object->pp_box);
	p_object->pp_box[0]->ver[0].op = ksx_vec3_set(p_object->size1, p_object->size2, p_object->size1);
	p_object->pp_box[0]->ver[1].op = ksx_vec3_set(-p_object->size1, p_object->size2, p_object->size1);
	p_object->pp_box[0]->ver[2].op = ksx_vec3_set(-p_object->size1, p_object->size2, -p_object->size1);
	p_object->pp_box[0]->ver[3].op = ksx_vec3_set(p_object->size1, p_object->size2, -p_object->size1);
	p_object->pp_box[0]->ver[4].op = ksx_vec3_set(p_object->size1, -p_object->size2, p_object->size1);
	p_object->pp_box[0]->ver[5].op = ksx_vec3_set(-p_object->size1, -p_object->size2, p_object->size1);
	p_object->pp_box[0]->ver[6].op = ksx_vec3_set(-p_object->size1, -p_object->size2, -p_object->size1);
	p_object->pp_box[0]->ver[7].op = ksx_vec3_set(p_object->size1, -p_object->size2, -p_object->size1);
	ksx_create_box(p_object->pp_box[0], p_object);
}

static void	ksx_init_cone(t_object *p_obj)
{
	uint32_t	size;
	uint32_t	idx;
	float		xz[2];

	size = 360 / CYLINDER_ANGLE;
	ksx_obj_add_vers(p_obj, size + 2);
	ksx_obj_add_vnrm(p_obj, (size * 3) + 2);
	idx = 0;
	p_obj->pp_vrtx[idx]->op = ksx_vec3_set(0, p_obj->size2, 0);
	p_obj->pp_vnrm[idx]->op = ksx_vec3_set(0, 1.f , 0);
	idx++;
	p_obj->pp_vrtx[idx]->op = ksx_vec3_set(0, -p_obj->size2, 0);
	p_obj->pp_vnrm[idx]->op = ksx_vec3_set(0, -1.f , 0);
	idx++;
	while (idx < size + 2)
	{
		xz[0] = p_obj->size1 * cosf(CYLINDER_ANGLE * (idx - 2) * PI180);
		xz[1] = p_obj->size1 * sinf(CYLINDER_ANGLE * (idx - 2) * PI180);
		p_obj->pp_vrtx[idx]->op = ksx_vec3_set(xz[0], -p_obj->size2, xz[1]);
		p_obj->pp_vnrm[idx]->op =
			ksx_vec3_unit(&p_obj->pp_vnrm[idx]->op);
		p_obj->pp_vnrm[idx + size]->op = ksx_vec3_set(xz[0], 0, xz[1]);
		p_obj->pp_vnrm[idx + size]->op =
			ksx_vec3_unit(&p_obj->pp_vnrm[idx + size]->op);
		idx++;
	}
	ksx_init_cone_tri(p_obj, size);
}

void	ksx_init_cone_tri(t_object *p_object, uint32_t size)
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
		pp_tri[idx[0]]->p_norm1 = p_object->pp_vnrm[idx[0] + size + 2];
		pp_tri[idx[0]]->p_norm2 = p_object->pp_vnrm[idx[1] + size + 2];
		pp_tri[idx[0]]->p_norm3 = p_object->pp_vnrm[idx[1] + size + 2];
		ksx_tri_set_vertexes(pp_tri[idx[0] + size], pp_ver_a[idx[0]], pp_ver_a[idx[1]], p_object->pp_vrtx[1]);
		pp_tri[idx[0] + size]->p_norm1 = p_object->pp_vnrm[1];
		pp_tri[idx[0] + size]->p_norm2 = p_object->pp_vnrm[1];
		pp_tri[idx[0] + size]->p_norm3 = p_object->pp_vnrm[1];
		idx[0]++;
	}
}
