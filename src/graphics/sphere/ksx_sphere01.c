/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_sphere01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 11:57:41 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Sphere: "sp", coord, d, rgb

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_sphere.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void			ksx_init_sphere_box(t_object *p_object);
static void			ksx_init_sphere(t_object *p_object);
static t_triangle	**ksx_init_sphere_tri(t_object *p_object);

t_object	*ksx_create_sphere(t_vector3 center,
			uint32_t diameter, t_color color)
{
	t_object	*p_object;

	p_object = ksx_create_object(&center);
	if (!p_object)
		return (NULL);
	if (!ksx_init_sphere_tri(p_object))
		return (NULL);
	p_object->size1 = diameter * .5f;
	p_object->color = color;
	ksx_init_sphere_box (p_object);
	ksx_init_sphere(p_object);
	ksx_sphere_split (p_object);	// 32
	ksx_sphere_split (p_object);	// 128
	ksx_sphere_split (p_object);	// 512
	ksx_sphere_split (p_object);	// 2048
	// ksx_sphere_split (p_object);	// 8192
	// ksx_sphere_split (p_object);	// 32768
	// ksx_sphere_split (p_object);	// 131072
	return (p_object);
}

static void	ksx_init_sphere_box(t_object *p_object)
{
	t_vector3	pnts[8];

	pnts[0] = ksx_vec3_set(p_object->size1, p_object->size1, p_object->size1);
	pnts[1] = ksx_vec3_set(-p_object->size1, p_object->size1, p_object->size1);
	pnts[2] = ksx_vec3_set(-p_object->size1, p_object->size1, -p_object->size1);
	pnts[3] = ksx_vec3_set(p_object->size1, p_object->size1, -p_object->size1);
	pnts[4] = ksx_vec3_set(p_object->size1, -p_object->size1, p_object->size1);
	pnts[5] = ksx_vec3_set(-p_object->size1, -p_object->size1, p_object->size1);
	pnts[6] = ksx_vec3_set(-p_object->size1, -p_object->size1, -p_object->size1);
	pnts[7] = ksx_vec3_set(p_object->size1, -p_object->size1, -p_object->size1);
	ksx_tri_set_points(&p_object->box[0], &pnts[0], &pnts[1], &pnts[3]);
	ksx_tri_set_points(&p_object->box[1], &pnts[1], &pnts[2], &pnts[3]);
	ksx_tri_set_points(&p_object->box[2], &pnts[2], &pnts[3], &pnts[6]);
	ksx_tri_set_points(&p_object->box[3], &pnts[3], &pnts[6], &pnts[7]);
	ksx_tri_set_points(&p_object->box[4], &pnts[0], &pnts[3], &pnts[4]);
	ksx_tri_set_points(&p_object->box[5], &pnts[3], &pnts[4], &pnts[7]);
	ksx_tri_set_points(&p_object->box[6], &pnts[0], &pnts[1], &pnts[4]);
	ksx_tri_set_points(&p_object->box[7], &pnts[1], &pnts[4], &pnts[5]);
	ksx_tri_set_points(&p_object->box[8], &pnts[1], &pnts[5], &pnts[6]);
	ksx_tri_set_points(&p_object->box[9], &pnts[1], &pnts[2], &pnts[6]);
	ksx_tri_set_points(&p_object->box[10], &pnts[4], &pnts[5], &pnts[6]);
	ksx_tri_set_points(&p_object->box[11], &pnts[4], &pnts[6], &pnts[7]);
}

static void	ksx_init_sphere(t_object *p_object)
{
	t_vector3	pnts[6];

	pnts[0] = ksx_vec3_set(0, p_object->size1, 0);
	pnts[1] = ksx_vec3_set(p_object->size1, 0, 0);
	pnts[2] = ksx_vec3_set(0, 0, p_object->size1);
	pnts[3] = ksx_vec3_set(0, -p_object->size1, 0);
	pnts[4] = ksx_vec3_set(-p_object->size1, 0, 0);
	pnts[5] = ksx_vec3_set(0, 0, -p_object->size1);
	ksx_tri_set_points(p_object->pp_otri[0], &pnts[0], &pnts[1], &pnts[2]);
	ksx_tri_set_points(p_object->pp_otri[1], &pnts[0], &pnts[2], &pnts[4]);
	ksx_tri_set_points(p_object->pp_otri[2], &pnts[0], &pnts[4], &pnts[5]);
	ksx_tri_set_points(p_object->pp_otri[3], &pnts[0], &pnts[5], &pnts[1]);
	ksx_tri_set_points(p_object->pp_otri[4], &pnts[3], &pnts[1], &pnts[2]);
	ksx_tri_set_points(p_object->pp_otri[5], &pnts[3], &pnts[2], &pnts[4]);
	ksx_tri_set_points(p_object->pp_otri[6], &pnts[3], &pnts[4], &pnts[5]);
	ksx_tri_set_points(p_object->pp_otri[7], &pnts[3], &pnts[5], &pnts[1]);
	p_object->pp_otri[0]->color = p_object->color;
	p_object->pp_otri[1]->color = p_object->color;
	p_object->pp_otri[2]->color = p_object->color;
	p_object->pp_otri[3]->color = p_object->color;
	p_object->pp_otri[4]->color = p_object->color;
	p_object->pp_otri[5]->color = p_object->color;
	p_object->pp_otri[6]->color = p_object->color;
	p_object->pp_otri[7]->color = p_object->color;
}

static t_triangle	**ksx_init_sphere_tri(t_object *p_object)
{
	uint32_t	idx;
	t_triangle	*p_tri;
	t_triangle	**pp_tri;

	idx = 0;
	while (idx < 8)
	{
		p_tri = (t_triangle *) malloc (sizeof(t_triangle));
		if (!p_tri)
			return (printf("Error: memory allocation failed!\n"), NULL);
		p_tri->generation = 1;
		pp_tri = ksx_tri2obj(p_tri, p_object);
		idx++;
	}
	p_object->last_gen = 1;
	return (pp_tri);
}
