/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_sphere01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/19 20:51:59 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Sphere: "sp", coord, d, rgb

#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_triangle.h"
#include "ksx_vec3_math.h"
#include "ksx_sphere.h"
#include "ksx_3D.h"
#include "ksx_boxes.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void		ksx_init_sphere_box(t_object *p_object);
static void		ksx_init_sphere(t_object *p_object);

t_object	*ksx_create_sphere(t_vector3 center,
			uint32_t diameter, t_color color, uint8_t gen)
{
	t_object	*p_object;
	uint8_t		idx;

	p_object = ksx_create_object(&center);
	p_object->size1 = diameter * .5f;
	p_object->color = color;
	ksx_color_unit_fraction(&p_object->color);
	ksx_init_sphere_box (p_object);
	ksx_init_sphere(p_object);
	idx = 0;
	while (idx < gen)
	{
		ksx_sphere_split (p_object);
		idx++;
	}
	ksx_sphere_norns(p_object);
	ksx_obj_transform(p_object);
	ksx_obj_tris2box(p_object);
	return (p_object);
}

static void	ksx_init_sphere_box(t_object *p_object)
{
	ksx_box_add_new(&p_object->pp_box);
	p_object->pp_box[0]->ver[0].op = ksx_vec3_set(p_object->size1, p_object->size1, p_object->size1);
	p_object->pp_box[0]->ver[1].op = ksx_vec3_set(-p_object->size1, p_object->size1, p_object->size1);
	p_object->pp_box[0]->ver[2].op = ksx_vec3_set(-p_object->size1, p_object->size1, -p_object->size1);
	p_object->pp_box[0]->ver[3].op = ksx_vec3_set(p_object->size1, p_object->size1, -p_object->size1);
	p_object->pp_box[0]->ver[4].op = ksx_vec3_set(p_object->size1, -p_object->size1, p_object->size1);
	p_object->pp_box[0]->ver[5].op = ksx_vec3_set(-p_object->size1, -p_object->size1, p_object->size1);
	p_object->pp_box[0]->ver[6].op = ksx_vec3_set(-p_object->size1, -p_object->size1, -p_object->size1);
	p_object->pp_box[0]->ver[7].op = ksx_vec3_set(p_object->size1, -p_object->size1, -p_object->size1);
	ksx_create_box(p_object->pp_box[0], BOX_COLOR);
	// ksx_obj_copy_boxvrts(p_object->pp_box[0]->ver, p_object->pp_box[0]->ver_origin, 8);
}

static void	ksx_init_sphere(t_object *p_object)
{
	ksx_obj_add_vers(p_object, 6);
	p_object->pp_vrtx[0]->op = ksx_vec3_set(0, p_object->size1, 0);
	p_object->pp_vrtx[1]->op = ksx_vec3_set(p_object->size1, 0, 0);
	p_object->pp_vrtx[2]->op = ksx_vec3_set(0, 0, p_object->size1);
	p_object->pp_vrtx[3]->op = ksx_vec3_set(0, -p_object->size1, 0);
	p_object->pp_vrtx[4]->op = ksx_vec3_set(-p_object->size1, 0, 0);
	p_object->pp_vrtx[5]->op = ksx_vec3_set(0, 0, -p_object->size1);
	p_object->pp_tri = ksx_obj_new_tris(8);
	p_object->size_tri = 8;
	ksx_tri_set_vertexes(p_object->pp_tri[0], p_object->pp_vrtx[0], p_object->pp_vrtx[1], p_object->pp_vrtx[2]);
	ksx_tri_set_vertexes(p_object->pp_tri[1], p_object->pp_vrtx[0], p_object->pp_vrtx[2], p_object->pp_vrtx[4]);
	ksx_tri_set_vertexes(p_object->pp_tri[2], p_object->pp_vrtx[0], p_object->pp_vrtx[4], p_object->pp_vrtx[5]);
	ksx_tri_set_vertexes(p_object->pp_tri[3], p_object->pp_vrtx[0], p_object->pp_vrtx[5], p_object->pp_vrtx[1]);
	ksx_tri_set_vertexes(p_object->pp_tri[4], p_object->pp_vrtx[3], p_object->pp_vrtx[1], p_object->pp_vrtx[2]);
	ksx_tri_set_vertexes(p_object->pp_tri[5], p_object->pp_vrtx[3], p_object->pp_vrtx[2], p_object->pp_vrtx[4]);
	ksx_tri_set_vertexes(p_object->pp_tri[6], p_object->pp_vrtx[3], p_object->pp_vrtx[4], p_object->pp_vrtx[5]);
	ksx_tri_set_vertexes(p_object->pp_tri[7], p_object->pp_vrtx[3], p_object->pp_vrtx[5], p_object->pp_vrtx[1]);
	p_object->pp_tri[0]->color = p_object->color;
	p_object->pp_tri[1]->color = p_object->color;
	p_object->pp_tri[2]->color = p_object->color;
	p_object->pp_tri[3]->color = p_object->color;
	p_object->pp_tri[4]->color = p_object->color;
	p_object->pp_tri[5]->color = p_object->color;
	p_object->pp_tri[6]->color = p_object->color;
	p_object->pp_tri[7]->color = p_object->color;
}
