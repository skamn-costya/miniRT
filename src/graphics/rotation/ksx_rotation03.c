/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_rotation03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/10 12:10:06 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_m3_math.h"
#include "ksx_rotation.h"
#include <math.h>

void	ksx_rotation_obj_x(t_object *p_object, float angle)
{
	uint32_t	idx;

	ksx_angle_check(&angle);
	if (angle == 0)
		return ;
	p_object->angle.x += angle;
	ksx_angle_check(&p_object->angle.x);
	idx = 0;
	while (idx < p_object->size_otri)
	{
		ksx_rotation_tri_x(p_object->pp_otri[idx], angle);
		idx++;
	}
	ksx_rotation_tri_x(&p_object->axis, angle);
	idx = 0;
	while (idx < 12)
	{
		ksx_rotation_tri_x(&p_object->box[idx], angle);
		idx++;
	}
}

void	ksx_rotation_obj_y(t_object *p_object, float angle)
{
	uint32_t	idx;

	ksx_angle_check(&angle);
	if (angle == 0)
		return ;
	p_object->angle.y += angle;
	ksx_angle_check(&p_object->angle.y);
	idx = 0;
	while (idx < p_object->size_otri)
	{
		ksx_rotation_tri_y(p_object->pp_otri[idx], angle);
		idx++;
	}
	ksx_rotation_tri_y(&p_object->axis, angle);
	idx = 0;
	while (idx < 12)
	{
		ksx_rotation_tri_y(&p_object->box[idx], angle);
		idx++;
	}
}


void	ksx_rotation_obj_z(t_object *p_object, float angle)
{
	uint32_t	idx;

	ksx_angle_check(&angle);
	if (angle == 0)
		return ;
	p_object->angle.z += angle;
	ksx_angle_check(&p_object->angle.z);
	idx = 0;
	while (idx < p_object->size_otri)
	{
		ksx_rotation_tri_z(p_object->pp_otri[idx], angle);
		idx++;
	}
	ksx_rotation_tri_z(&p_object->axis, angle);
	idx = 0;
	while (idx < 12)
	{
		ksx_rotation_tri_z(&p_object->box[idx], angle);
		idx++;
	}
}

void	ksx_rotation_obj(t_object *p_object, float angle_x,
			float angle_y, float angle_z)
{
	uint32_t	idx;

	ksx_angle_check(&angle_x);
	ksx_angle_check(&angle_y);
	ksx_angle_check(&angle_z);
	if (angle_x == 0 && angle_y == 0 && angle_z == 0)
		return ;
	p_object->angle.x += angle_x;
	p_object->angle.y += angle_y;
	p_object->angle.z += angle_z;
	ksx_angle_check(&p_object->angle.x);
	ksx_angle_check(&p_object->angle.y);
	ksx_angle_check(&p_object->angle.z);
	idx = 0;
	while (idx < p_object->size_otri)
	{
		ksx_rotation_tri(p_object->pp_otri[idx], angle_x, angle_y, angle_z);
		idx++;
	}
	ksx_rotation_tri(&p_object->axis, angle_x, angle_y, angle_z);
	idx = 0;
	while (idx < 12)
	{
		ksx_rotation_tri(&p_object->box[idx], angle_x, angle_y, angle_z);
		idx++;
	}
}
