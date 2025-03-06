/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_cylinder01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:55:12 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/06 17:37:28 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Cylinder: "cy", coord, vector, d, h, rgb

#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_basis.h"
#include "ksx_boxes.h"
#include "ksx_vec3_math.h"
#include "ksx_3D.h"
#include "ksx_cylinder.h"
#include "ksx_triangle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void	ksx_init_cylinder_box(t_object *p_object);
// static t_triangle	**ksx_init_cylinder_tri(t_object *p_object);
static void	ksx_init_cylinder(t_object *p_object);
static void	ksx_init_cylinder_1(t_object *p_object, uint32_t size);
static void	ksx_cylinder_norns(t_object *p_object);

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
	ksx_basis_set_norm(&p_object->basis, &norm);
	ksx_init_cylinder_box (p_object);
	ksx_init_cylinder(p_object);
	// ksx_obj_copy_vrts(p_object->pp_vrtx, ORIP, LOCP);
	ksx_obj_transform(p_object);
	ksx_obj_tris2box(p_object);
	ksx_cylinder_norns(p_object);
	return (p_object);
}

static void	ksx_init_cylinder_box(t_object *p_object)
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
	ksx_create_box(p_object->pp_box[0], BOX_COLOR);
	// ksx_obj_copy_boxvrts(p_object->pp_box[0]->ver, p_object->pp_box[0]->ver_origin, 8);
}

static void	ksx_init_cylinder(t_object *p_object)
{
	uint32_t	size;
	uint32_t	idx;
	float		xz[2];

	size = 360 / CYLINDER_ANGLE;
	ksx_obj_add_vers(p_object, (size * 4) + 2);
	ksx_obj_add_vnrm(p_object, (size * 4) + 2);
	idx = 0;
	p_object->pp_vrtx[idx]->op = ksx_vec3_set(0, p_object->size2, 0);
	p_object->pp_vnrm[idx]->op = ksx_vec3_set(0, 1.f , 0);
	idx++;
	p_object->pp_vrtx[idx]->op = ksx_vec3_set(0, -p_object->size2, 0);
	p_object->pp_vnrm[idx]->op = ksx_vec3_set(0, -1.f , 0);
	idx++;
	while (idx < size + 2)
	{
		xz[0] = p_object->size1 * cosf(CYLINDER_ANGLE * idx * PI180);
		xz[1] = p_object->size1 * sinf(CYLINDER_ANGLE * idx * PI180);
		p_object->pp_vrtx[idx]->op = ksx_vec3_set(xz[0], p_object->size2, xz[1]);
		p_object->pp_vnrm[idx]->op = ksx_vec3_set(0, 1.f , 0);
		p_object->pp_vrtx[idx + size]->op = ksx_vec3_set(xz[0], -p_object->size2, xz[1]);
		p_object->pp_vnrm[idx + size]->op = ksx_vec3_set(0, -1.f , 0);

		p_object->pp_vrtx[idx + size * 2]->op = ksx_vec3_set(xz[0], p_object->size2, xz[1]);
		p_object->pp_vnrm[idx + size * 2]->op = ksx_vec3_set(xz[0], 0, xz[1]);
		p_object->pp_vnrm[idx + size * 2]->op = ksx_vec3_unit(&p_object->pp_vnrm[idx + size * 2]->op);
		
		p_object->pp_vrtx[idx + size * 3]->op = ksx_vec3_set(xz[0], -p_object->size2, xz[1]);
		p_object->pp_vnrm[idx + size * 3]->op = ksx_vec3_set(xz[0], 0, xz[1]);
		p_object->pp_vnrm[idx + size * 3]->op = ksx_vec3_unit(&p_object->pp_vnrm[idx + size * 3]->op);
		idx++;
	}
	p_object->edge = ksx_vec3_dist(&p_object->pp_vrtx[2]->op, &p_object->pp_vrtx[3]->op);
	ksx_init_cylinder_1(p_object, size);
}

static void	ksx_init_cylinder_1(t_object *p_object, uint32_t size)
{
	uint32_t	idx[2];
	float		step[2];
	t_vertex	**pp_vertex;
	t_vertex	**pp_norm;

	// step = p_object->size2 * 2.f / roundf((p_object->size2 * 2.f) / p_object->edge);
	step[0] = roundf(p_object->size2 * 2.f / p_object->size1);
	step[1] = p_object->size2 * 2.f / step[0];
	idx[0] = 1;
	while (idx[0] < step[0])
	{
		pp_vertex = ksx_obj_add_vers(p_object, size);
		pp_norm = ksx_obj_add_vnrm(p_object, size);
		idx[1] = 0;
		while (idx[1] < size)
		{
			pp_vertex[idx[1]]->op = ksx_vec3_set(p_object->pp_vrtx[idx[1] + 2]->op.x,
					p_object->size2 - (step[1] * idx[0] + 1), p_object->pp_vrtx[idx[1] + 2]->op.z);
			pp_norm[idx[1]]->op = ksx_vec3_set(pp_vertex[idx[1]]->op.x,
					0, pp_vertex[idx[1]]->op.z);
			pp_norm[idx[1]]->op = ksx_vec3_unit(&pp_norm[idx[1]]->op);
			// if (idx[0] % 2)
			// 	ksx_qrotation(&pp_vertex[idx[1]]->p_p, CYLINDER_ANGLE * .5f, &v3);
			idx[1]++;
		}
		idx[0]++;
	}
	ksx_init_cylinder_tri(p_object, size, step[0]);
}

static void	ksx_cylinder_norns(t_object *p_object)
{
	uint32_t	idx[2];

	idx[0] = 0;
	while (idx[0] < p_object->size_tri)
	{
		idx[1] = 0;
		while (idx[1] < p_object->size_vrtx)	
		{
			if(p_object->pp_tri[idx[0]]->p_ver1 == p_object->pp_vrtx[idx[1]])
				p_object->pp_tri[idx[0]]->p_norm1 = p_object->pp_vnrm[idx[1]];
			else if(p_object->pp_tri[idx[0]]->p_ver2 == p_object->pp_vrtx[idx[1]])
				p_object->pp_tri[idx[0]]->p_norm2 = p_object->pp_vnrm[idx[1]];
			else if(p_object->pp_tri[idx[0]]->p_ver3 == p_object->pp_vrtx[idx[1]])
				p_object->pp_tri[idx[0]]->p_norm3 = p_object->pp_vnrm[idx[1]];
			idx[1]++;
		}
		idx[0]++;
	}
}
