/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_sphere01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/12 21:41:35 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Sphere: "sp", coord, d, rgb

#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_sphere.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void			ksx_init_sphere_box(t_object *p_object);
static void			ksx_init_sphere(t_object *p_object);
// static t_triangle	**ksx_init_sphere_tri(t_object *p_object);

t_object	*ksx_create_sphere(t_vector3 center,
			uint32_t diameter, t_color color)
{
	t_object	*p_object;

	p_object = ksx_create_object(&center);
	if (!p_object)
		return (NULL);
	// if (!ksx_init_sphere_tri(p_object))
	// 	return (NULL);
	p_object->size1 = diameter * .5f;
	p_object->color = color;
	ksx_init_sphere_box (p_object);
	ksx_init_sphere(p_object);
	ksx_sphere_split (p_object);	// 32
	ksx_sphere_split (p_object);	// 128
	ksx_sphere_split (p_object);	// 512
	// ksx_sphere_split (p_object);	// 2048
	// ksx_sphere_split (p_object);	// 8192
	// ksx_sphere_split (p_object);	// 32768
	// ksx_sphere_split (p_object);	// 131072
	// p_object->basis.j = ksx_vec3_set(0,2.5f, 0);	// egg
	p_object->basis.i = ksx_vec3_set(.75f, 0, 0);	// egg
	p_object->basis.k = ksx_vec3_set(0, 0, .75f);	// egg
	ksx_transform_obj(p_object, &p_object->basis);
	return (p_object);
}

static void	ksx_init_sphere_box(t_object *p_object)
{
	p_object->box_ver[0].p_p = ksx_vec3_set(p_object->size1, p_object->size1, p_object->size1);
	p_object->box_ver[1].p_p = ksx_vec3_set(-p_object->size1, p_object->size1, p_object->size1);
	p_object->box_ver[2].p_p = ksx_vec3_set(-p_object->size1, p_object->size1, -p_object->size1);
	p_object->box_ver[3].p_p = ksx_vec3_set(p_object->size1, p_object->size1, -p_object->size1);
	p_object->box_ver[4].p_p = ksx_vec3_set(p_object->size1, -p_object->size1, p_object->size1);
	p_object->box_ver[5].p_p = ksx_vec3_set(-p_object->size1, -p_object->size1, p_object->size1);
	p_object->box_ver[6].p_p = ksx_vec3_set(-p_object->size1, -p_object->size1, -p_object->size1);
	p_object->box_ver[7].p_p = ksx_vec3_set(p_object->size1, -p_object->size1, -p_object->size1);
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
}

static void	ksx_init_sphere(t_object *p_object)
{
	ksx_obj_add_vers(p_object, 6);
	p_object->pp_over[0]->p_p = ksx_vec3_set(0, p_object->size1, 0);
	p_object->pp_over[1]->p_p = ksx_vec3_set(p_object->size1, 0, 0);
	p_object->pp_over[2]->p_p = ksx_vec3_set(0, 0, p_object->size1);
	p_object->pp_over[3]->p_p = ksx_vec3_set(0, -p_object->size1, 0);
	p_object->pp_over[4]->p_p = ksx_vec3_set(-p_object->size1, 0, 0);
	p_object->pp_over[5]->p_p = ksx_vec3_set(0, 0, -p_object->size1);
	p_object->pp_otri = ksx_obj_new_tris(8);
	p_object->size_otri = 8;
	ksx_tri_set_vertexes(p_object->pp_otri[0], p_object->pp_over[0], p_object->pp_over[1], p_object->pp_over[2]);
	ksx_tri_set_vertexes(p_object->pp_otri[1], p_object->pp_over[0], p_object->pp_over[2], p_object->pp_over[4]);
	ksx_tri_set_vertexes(p_object->pp_otri[2], p_object->pp_over[0], p_object->pp_over[4], p_object->pp_over[5]);
	ksx_tri_set_vertexes(p_object->pp_otri[3], p_object->pp_over[0], p_object->pp_over[5], p_object->pp_over[1]);
	ksx_tri_set_vertexes(p_object->pp_otri[4], p_object->pp_over[3], p_object->pp_over[1], p_object->pp_over[2]);
	ksx_tri_set_vertexes(p_object->pp_otri[5], p_object->pp_over[3], p_object->pp_over[2], p_object->pp_over[4]);
	ksx_tri_set_vertexes(p_object->pp_otri[6], p_object->pp_over[3], p_object->pp_over[4], p_object->pp_over[5]);
	ksx_tri_set_vertexes(p_object->pp_otri[7], p_object->pp_over[3], p_object->pp_over[5], p_object->pp_over[1]);
	p_object->pp_otri[0]->color = p_object->color;
	p_object->pp_otri[1]->color = p_object->color;
	p_object->pp_otri[2]->color = p_object->color;
	p_object->pp_otri[3]->color = p_object->color;
	p_object->pp_otri[4]->color = p_object->color;
	p_object->pp_otri[5]->color = p_object->color;
	p_object->pp_otri[6]->color = p_object->color;
	p_object->pp_otri[7]->color = p_object->color;
}

// static t_triangle	**ksx_init_sphere_tri(t_object *p_object)
// {
// 	uint32_t	idx;
// 	t_triangle	*p_tri;
// 	t_triangle	**pp_tri;

// 	idx = 0;
// 	while (idx < 8)
// 	{
// 		p_tri = (t_triangle *) malloc (sizeof(t_triangle));
// 		if (!p_tri)
// 			return (printf("Error: memory allocation failed!\n"), NULL);
// 		// p_tri->generation = 1;
// 		pp_tri = ksx_tri2obj(p_tri, p_object);
// 		idx++;
// 	}
// 	// p_object->last_gen = 1;
// 	return (pp_tri);
// }
