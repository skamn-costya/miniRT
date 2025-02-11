/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_cylinder01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:55:12 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 20:36:59 by ksorokol         ###   ########.fr       */
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

static void			ksx_init_cylinder_box(t_object *p_object);
// static t_triangle	**ksx_init_cylinder_tri(t_object *p_object);
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
	// ksx_init_cylinder_tri(p_object);
	ksx_init_cylinder(p_object);
	ksx_transform_obj(p_object, &p_object->basis);
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
}

static void	ksx_init_cylinder(t_object *p_object)
{
	(void) p_object;
}

// static t_triangle	**ksx_init_cylinder_tri(t_object *p_object)
// {
// 	uint32_t	idx;
// 	t_triangle	*p_tri;
// 	t_triangle	**pp_tri;

// 	return (NULL);
// 	idx = 0;
// 	while (idx < 12)
// 	{
// 		p_tri = (t_triangle *) malloc (sizeof(t_triangle));
// 		if (!p_tri)
// 			return (printf("Error: memory allocation failed!\n"), NULL);
// 		p_tri->generation = 1;
// 		pp_tri = ksx_tri2obj(p_tri, p_object);
// 		idx++;
// 	}
// 	p_object->last_gen = 1;
// 	return (pp_tri);
// }
