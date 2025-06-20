/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_sphere01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 23:04:33 by ksorokol         ###   ########.fr       */
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
#include "ray_texture.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void		ksx_init_sphere_box(t_object *p_object);
static void		ksx_init_sphere01(t_object *p_object);
static void		ksx_init_sphere02(t_object *p_object);

t_object	*ksx_create_sphere(t_vector3 center,
			float diameter, t_color color, uint8_t gen)
{
	t_object	*p_object;
	uint8_t		idx;

	p_object = ksx_create_object(&center);
	p_object->size1 = diameter * .5f;
	p_object->color.mlx_color = color.mlx_color;
	if (gen == 0)
		p_object->color.material.ks = 0.05f;
	ksx_color_unit_fraction(&p_object->color);
	p_object->ray_txtr_uv = &ray_txtr_uv_spheres;
	ksx_init_sphere_box (p_object);
	ksx_init_sphere01(p_object);
	idx = 0;
	while (idx < gen)
	{
		ksx_sphere_split (p_object);
		idx++;
	}
	ksx_sphere_norns(p_object);
	ksx_obj_transform(p_object);
	ksx_obj_tris2box(p_object);
	ksx_obj_set_obj(p_object);
	return (p_object);
}

static void	ksx_init_sphere_box(t_object *p_object)
{
	ksx_box_add_new(&p_object->pp_box);
	p_object->pp_box[0]->ver[0].op = ksx_vec3_set(p_object->size1,
			p_object->size1, p_object->size1);
	p_object->pp_box[0]->ver[1].op = ksx_vec3_set(-p_object->size1,
			p_object->size1, p_object->size1);
	p_object->pp_box[0]->ver[2].op = ksx_vec3_set(-p_object->size1,
			p_object->size1, -p_object->size1);
	p_object->pp_box[0]->ver[3].op = ksx_vec3_set(p_object->size1,
			p_object->size1, -p_object->size1);
	p_object->pp_box[0]->ver[4].op = ksx_vec3_set(p_object->size1,
			-p_object->size1, p_object->size1);
	p_object->pp_box[0]->ver[5].op = ksx_vec3_set(-p_object->size1,
			-p_object->size1, p_object->size1);
	p_object->pp_box[0]->ver[6].op = ksx_vec3_set(-p_object->size1,
			-p_object->size1, -p_object->size1);
	p_object->pp_box[0]->ver[7].op = ksx_vec3_set(p_object->size1,
			-p_object->size1, -p_object->size1);
	ksx_box_triangles(p_object->pp_box[0], p_object);
}

static void	ksx_init_sphere01(t_object *p_object)
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
	ksx_init_sphere02(p_object);
}

static void	ksx_init_sphere02(t_object *p_object)
{
	ksx_tri_set_vertexes(p_object->pp_tri[0], p_object->pp_vrtx[0],
		p_object->pp_vrtx[1], p_object->pp_vrtx[2]);
	ksx_tri_set_vertexes(p_object->pp_tri[1], p_object->pp_vrtx[0],
		p_object->pp_vrtx[2], p_object->pp_vrtx[4]);
	ksx_tri_set_vertexes(p_object->pp_tri[2], p_object->pp_vrtx[0],
		p_object->pp_vrtx[4], p_object->pp_vrtx[5]);
	ksx_tri_set_vertexes(p_object->pp_tri[3], p_object->pp_vrtx[0],
		p_object->pp_vrtx[5], p_object->pp_vrtx[1]);
	ksx_tri_set_vertexes(p_object->pp_tri[4], p_object->pp_vrtx[3],
		p_object->pp_vrtx[1], p_object->pp_vrtx[2]);
	ksx_tri_set_vertexes(p_object->pp_tri[5], p_object->pp_vrtx[3],
		p_object->pp_vrtx[2], p_object->pp_vrtx[4]);
	ksx_tri_set_vertexes(p_object->pp_tri[6], p_object->pp_vrtx[3],
		p_object->pp_vrtx[4], p_object->pp_vrtx[5]);
	ksx_tri_set_vertexes(p_object->pp_tri[7], p_object->pp_vrtx[3],
		p_object->pp_vrtx[5], p_object->pp_vrtx[1]);
}
