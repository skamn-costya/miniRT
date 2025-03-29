/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_boxes02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:18:43 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/29 19:46:01 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_boxes.h"
#include "ksx_triangle.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	ksx_box_create01(t_object *p_object);
static void	ksx_box_create02(t_object *p_object, t_vertex min_max[]);

void	ksx_box_create(t_object *p_object)
{
	ksx_box_add_new(&p_object->pp_box);
	ksx_box_create01(p_object);
	ksx_box_triangles(p_object->pp_box[0], p_object);
}

static void	ksx_box_create01(t_object *p_object)
{
	t_vertex	min_max[2];
	uint32_t	idx;

	min_max[0].op = p_object->pp_vrtx[0]->op;
	min_max[1].op = min_max[0].op;
	idx = 1;
	while (idx < p_object->size_vrtx)
	{
		if (min_max[0].op.x > p_object->pp_vrtx[idx]->op.x)
			min_max[0].op.x = p_object->pp_vrtx[idx]->op.x;
		if (min_max[0].op.y > p_object->pp_vrtx[idx]->op.y)
			min_max[0].op.y = p_object->pp_vrtx[idx]->op.y;
		if (min_max[0].op.z > p_object->pp_vrtx[idx]->op.z)
			min_max[0].op.z = p_object->pp_vrtx[idx]->op.z;
		if (min_max[1].op.x < p_object->pp_vrtx[idx]->op.x)
			min_max[1].op.x = p_object->pp_vrtx[idx]->op.x;
		if (min_max[1].op.y < p_object->pp_vrtx[idx]->op.y)
			min_max[1].op.y = p_object->pp_vrtx[idx]->op.y;
		if (min_max[1].op.z < p_object->pp_vrtx[idx]->op.z)
			min_max[1].op.z = p_object->pp_vrtx[idx]->op.z;
		idx++;
	}
	ksx_box_create02(p_object, min_max);
}

static void	ksx_box_create02(t_object *p_object, t_vertex min_max[])
{
	p_object->pp_box[0]->ver[0].op = ksx_vec3_set(min_max[0].op.x,
			min_max[0].op.y, min_max[0].op.z);
	p_object->pp_box[0]->ver[1].op = ksx_vec3_set(min_max[0].op.x,
			min_max[0].op.y, -min_max[0].op.z);
	p_object->pp_box[0]->ver[2].op = ksx_vec3_set(-min_max[0].op.x,
			min_max[0].op.y, -min_max[0].op.z);
	p_object->pp_box[0]->ver[3].op = ksx_vec3_set(-min_max[0].op.x,
			min_max[0].op.y, min_max[0].op.z);
	p_object->pp_box[0]->ver[6].op = ksx_vec3_set(min_max[1].op.x,
			min_max[1].op.y, min_max[1].op.z);
	p_object->pp_box[0]->ver[7].op = ksx_vec3_set(min_max[1].op.x,
			min_max[1].op.y, -min_max[1].op.z);
	p_object->pp_box[0]->ver[4].op = ksx_vec3_set(-min_max[1].op.x,
			min_max[1].op.y, -min_max[1].op.z);
	p_object->pp_box[0]->ver[5].op = ksx_vec3_set(-min_max[1].op.x,
			min_max[1].op.y, min_max[1].op.z);
}
