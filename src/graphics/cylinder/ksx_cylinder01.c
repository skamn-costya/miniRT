/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_cylinder01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:55:12 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/10 13:24:37 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Cylinder: "cy", coord, vector, d, h, rgb

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_basis.h"
#include "ksx_vec3_math.h"
#include "ksx_3D.h"
#include "ksx_cylinder.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void			ksx_init_cylinder_box(t_object *p_object);
static t_triangle	**ksx_init_cylinder_tri(t_object *p_object);
static void			ksx_init_cylinder(t_object *p_object);

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
	p_object->basis = ksx_get_basis(&norm, &p_object->center);
	ksx_init_cylinder_box (p_object);
	ksx_init_cylinder_tri(p_object);
	ksx_init_cylinder(p_object);
	return (p_object);
}

static void	ksx_init_cylinder_box(t_object *p_object)
{
	t_vector3	pnts[8];

	pnts[0] = ksx_vec3_set(p_object->size1, p_object->size2, p_object->size1);
	pnts[1] = ksx_vec3_set(-p_object->size1, p_object->size2, p_object->size1);
	pnts[2] = ksx_vec3_set(-p_object->size1, p_object->size2, -p_object->size1);
	pnts[3] = ksx_vec3_set(p_object->size1, p_object->size2, -p_object->size1);
	pnts[4] = ksx_vec3_set(p_object->size1, -p_object->size2, p_object->size1);
	pnts[5] = ksx_vec3_set(-p_object->size1, -p_object->size2, p_object->size1);
	pnts[6] = ksx_vec3_set(-p_object->size1, -p_object->size2, -p_object->size1);
	pnts[7] = ksx_vec3_set(p_object->size1, -p_object->size2, -p_object->size1);
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

static void	ksx_init_cylinder(t_object *p_object)
{
	(void) p_object;
}

static t_triangle	**ksx_init_cylinder_tri(t_object *p_object)
{
	uint32_t	idx;
	t_triangle	*p_tri;
	t_triangle	**pp_tri;

	return (NULL);
	idx = 0;
	while (idx < 12)
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
