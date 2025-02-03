/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils06.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/03 01:06:04 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	ksx_triangle_rotation_w(t_triangle *p_triangle, const float angle_x,
	const float angle_y, const float angle_z)
{
	p_triangle->w_p1 = ksx_point_rotation
		(p_triangle->p1, angle_x, angle_y, angle_z);
	p_triangle->w_p2 = ksx_point_rotation
		(p_triangle->p2, angle_x, angle_y, angle_z);
	p_triangle->w_p3 = ksx_point_rotation
		(p_triangle->p3, angle_x, angle_y, angle_z);
}

void	ksx_triangle_rotation_c(t_triangle *p_triangle, const float angle_x,
	const float angle_y, const float angle_z)
{
	p_triangle->c_p1 = ksx_point_rotation
		(p_triangle->p1, angle_x, angle_y, angle_z);
	p_triangle->c_p2 = ksx_point_rotation
		(p_triangle->p2, angle_x, angle_y, angle_z);
	p_triangle->c_p3 = ksx_point_rotation
		(p_triangle->p3, angle_x, angle_y, angle_z);
}

void	ksx_rotation_w(t_obj *p_obj, const float angle_x,
	const float angle_y, const float angle_z)
{
	uint32_t	idx;

	idx = 0;
	while (idx < p_obj->size)
	{
		ksx_triangle_rotation_w(p_obj->pp_tris[idx], angle_x, angle_y, angle_z);
		idx++;
	}
}

void	ksx_rotation_c(t_obj *p_obj, const float angle_x,
	const float angle_y, const float angle_z)
{
	uint32_t	idx;

	idx = 0;
	while (idx < p_obj->size)
	{
		ksx_triangle_rotation_c(p_obj->pp_tris[idx], angle_x, angle_y, angle_z);
		idx++;
	}
}
