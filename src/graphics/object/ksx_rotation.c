/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/12 19:06:29 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_m3_math.h"
#include "ksx_object.h"
#include <math.h>

// https://www.mathworks.com/help/nav/ug/rotations-orientation-and-quaternions.html

void	ksx_rotation(t_vector3 *point, float angle_x,
		float angle_y, float angle_z)
{
	t_matrix3	m3;
	float		r[3];

	if (angle_x == 0 && angle_y == 0 && angle_z == 0)
		return ;
	r[0] = (angle_x * PI) / 180.f;
	r[1] = (angle_y * PI) / 180.f;
	r[2] = (angle_z * PI) / 180.f;
	ksx_m3_reset(&m3);
	m3.e_11 = cos (r[1]) * cos (r[2]);
	m3.e_12 = -(sin (r[2]) * cos (r[1]));
	m3.e_13 = sin (r[1]);
	m3.e_21 = (sin (r[0]) * sin (r[1]) * cos (r[2]))
		+ (sin (r[2]) * cos (r[0]));
	m3.e_22 = -(sin (r[0]) * sin (r[1]) * sin (r[2]))
		+ (cos (r[0]) * cos (r[2]));
	m3.e_23 = -(sin (r[0]) * cos (r[1]));
	m3.e_31 = (sin (r[0]) * sin (r[2])) - (sin (r[1])
			* cos (r[0]) * cos (r[2]));
	m3.e_32 = (sin (r[0]) * cos (r[2])) + (sin (r[1])
			* sin (r[2]) * cos (r[0]));
	m3.e_33 = cos (r[0]) * cos (r[1]);
	*point = ksx_m3_vec3(&m3, point);
}

void	ksx_rotation_obj(t_object *p_object, float angle_x,
	float angle_y, float angle_z)
{
	uint32_t	idx;

	if (angle_x == 0 && angle_y == 0 && angle_z == 0)
		return ;
	// p_object->angle.x += angle_x;
	// p_object->angle.y += angle_y;
	// p_object->angle.z += angle_z;
	ksx_angle_check(&p_object->angle.x);
	ksx_angle_check(&p_object->angle.y);
	ksx_angle_check(&p_object->angle.z);
	idx = 0;
	while (idx < p_object->size_over)
	{
		ksx_rotation(&p_object->pp_over[idx]->p_p, angle_x, angle_y, angle_z);
		idx++;
	}
	ksx_rotation(&p_object->axis.p_ver1->p_p, angle_x, angle_y, angle_z);
	ksx_rotation(&p_object->axis.p_ver2->p_p, angle_x, angle_y, angle_z);
	ksx_rotation(&p_object->axis.p_ver3->p_p, angle_x, angle_y, angle_z);
	idx = 0;
	while (idx < 8)
	{
		ksx_rotation(&p_object->box_ver[idx].p_p, angle_x, angle_y, angle_z);
		idx++;
	}
}

void	ksx_angle_check(float *angle)
{
	if (*angle == 0)
		return ;
	if (*angle > 360.f)
		*angle = fmodf(*angle, 360.f);
}
