/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_cylinder01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:55:12 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/19 19:14:34 by ksorokol         ###   ########.fr       */
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
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void	ksx_init_cylinder_box(t_object *p_object);
// static t_triangle	**ksx_init_cylinder_tri(t_object *p_object);
static void	ksx_init_cylinder(t_object *p_object);
static void ksx_init_cylinder_1(t_object *p_object, uint32_t size);
static void ksx_init_cylinder_2(t_object *p_object, uint32_t size);

t_object	*ksx_create_cylinder(t_vector3 center, t_vector3 norm,
			float dia_ht[], t_color color)
{
	t_object	*p_object;

	p_object = ksx_create_object(&center);
	if (!p_object)
		return (NULL);
	p_object->color = color;
	p_object->size1 = dia_ht[0] * .5f;
	p_object->size2 = dia_ht[1] * .5f;
	// p_object->basis = ksx_get_basis_obj(&norm);
	ksx_basis_set_norm(&p_object->basis, &norm);
	ksx_init_cylinder_box (p_object);
	ksx_init_cylinder(p_object);
	ksx_obj_vrts_dup2origin(p_object);
	ksx_transform_obj(p_object);
	return (p_object);
}

static void	ksx_init_cylinder_box(t_object *p_object)
{
	p_object->box_ver[0].p_p = ksx_vec3_set(p_object->size1, p_object->size2, p_object->size1);
	p_object->box_ver[1].p_p = ksx_vec3_set(-p_object->size1, p_object->size2, p_object->size1);
	p_object->box_ver[2].p_p = ksx_vec3_set(-p_object->size1, p_object->size2, -p_object->size1);
	p_object->box_ver[3].p_p = ksx_vec3_set(p_object->size1, p_object->size2, -p_object->size1);
	p_object->box_ver[4].p_p = ksx_vec3_set(p_object->size1, -p_object->size2, p_object->size1);
	p_object->box_ver[5].p_p = ksx_vec3_set(-p_object->size1, -p_object->size2, p_object->size1);
	p_object->box_ver[6].p_p = ksx_vec3_set(-p_object->size1, -p_object->size2, -p_object->size1);
	p_object->box_ver[7].p_p = ksx_vec3_set(p_object->size1, -p_object->size2, -p_object->size1);
	ksx_tri_set_vertexes(&p_object->box[0], &p_object->box_ver[0], &p_object->box_ver[1], &p_object->box_ver[3]);
	ksx_tri_set_vertexes(&p_object->box[1], &p_object->box_ver[1], &p_object->box_ver[2], &p_object->box_ver[3]);
	ksx_tri_set_vertexes(&p_object->box[2], &p_object->box_ver[2], &p_object->box_ver[3], &p_object->box_ver[6]);
	ksx_tri_set_vertexes(&p_object->box[3], &p_object->box_ver[3], &p_object->box_ver[6], &p_object->box_ver[7]);
	ksx_tri_set_vertexes(&p_object->box[4], &p_object->box_ver[0], &p_object->box_ver[3], &p_object->box_ver[4]);
	ksx_tri_set_vertexes(&p_object->box[5], &p_object->box_ver[3], &p_object->box_ver[4], &p_object->box_ver[7]);
	ksx_tri_set_vertexes(&p_object->box[6], &p_object->box_ver[0], &p_object->box_ver[1], &p_object->box_ver[4]);
	ksx_tri_set_vertexes(&p_object->box[7], &p_object->box_ver[1], &p_object->box_ver[4], &p_object->box_ver[5]);
	ksx_tri_set_vertexes(&p_object->box[8], &p_object->box_ver[1], &p_object->box_ver[5], &p_object->box_ver[6]);
	ksx_tri_set_vertexes(&p_object->box[9], &p_object->box_ver[1], &p_object->box_ver[2], &p_object->box_ver[6]);
	ksx_tri_set_vertexes(&p_object->box[10], &p_object->box_ver[4], &p_object->box_ver[5], &p_object->box_ver[6]);
	ksx_tri_set_vertexes(&p_object->box[11], &p_object->box_ver[4], &p_object->box_ver[6], &p_object->box_ver[7]);
	ksx_obj_copy_boxvrts (p_object->box_ver, p_object->box_ver_origin, 8);
}

static void	ksx_init_cylinder(t_object *p_object)
{
	uint32_t	size;
	uint32_t	idx;
	float		xz[2];
	
	size = 360 / CYLINDER_ANGLE;
	ksx_obj_add_vers(p_object, size + 2);
	idx = 0;
	p_object->pp_vrtx[idx]->p_p = ksx_vec3_set(0, p_object->size2, 0);
	p_object->pp_vrtx[++idx]->p_p = ksx_vec3_set(0, -p_object->size2, 0);
	while (idx < size + 1)
	{
		xz[0] = p_object->size1 * cosf(CYLINDER_ANGLE * idx * PI180);
		xz[1] = p_object->size1 * sinf(CYLINDER_ANGLE * idx * PI180);
		idx++;
		p_object->pp_vrtx[idx]->p_p = ksx_vec3_set(xz[0], p_object->size2, xz[1]);
	}
	p_object->edge = ksx_vec3_dist(p_object->pp_vrtx[2]->p_p, p_object->pp_vrtx[3]->p_p);
	ksx_init_cylinder_1(p_object, size);
	ksx_init_cylinder_2(p_object, size);
}

static void	ksx_init_cylinder_1(t_object *p_object, uint32_t size)
{
	uint32_t	idx[2];
	float		step;
	t_vertex	**pp_vertex;

	step = p_object->size2 * 2.f / roundf((p_object->size2 * 2.f) / p_object->edge);
	idx[0] = 1;
	while (idx[0] < (p_object->size2 * 2.f / step) + 1)
	{
		pp_vertex = ksx_obj_add_vers(p_object, size);
		idx[1] = 0;
		while (idx[1] < size)
		{
			pp_vertex[idx[1]]->p_p = ksx_vec3_set(p_object->pp_vrtx[idx[1] + 2]->p_p.x,
				p_object->size2 - (step * idx[0] + 1), p_object->pp_vrtx[idx[1] + 2]->p_p.z);
			// if (idx[0] % 2)
			// 	ksx_qrotation(&pp_vertex[idx[1]]->p_p, CYLINDER_ANGLE * .5f, &v3);
			idx[1]++;
		}
		idx[0]++;
	}
	ksx_init_cylinder_tri(p_object, size, (p_object->size2 * 2.f / step) + 1);
}

static void	ksx_init_cylinder_2(t_object *p_object, uint32_t size)
{
	uint32_t	idx[2];
	float		step;
	float		xz[2];
	t_vertex	**pp_vertex;

	return;
	step = p_object->size1 / roundf(p_object->size1 / p_object->edge);
	idx[0] = 1;
	while (idx[0] < 2)
	{
		pp_vertex = ksx_obj_add_vers(p_object, size * 2);
		idx[1] = 0;
		while (idx[1] < size)
		{
			xz[0] = (p_object->size1 - (step * idx[0])) * cosf(CYLINDER_ANGLE * idx[1] * PI180);
			xz[1] = (p_object->size1 - (step * idx[0])) * sinf(CYLINDER_ANGLE * idx[1] * PI180);
			pp_vertex[idx[1]]->p_p = ksx_vec3_set(xz[0], p_object->size2, xz[1]);
			pp_vertex[idx[1] + size]->p_p = ksx_vec3_set(xz[0], -p_object->size2, xz[1]);
			idx[1]++;
		}
		idx[0]++;
	}
}
