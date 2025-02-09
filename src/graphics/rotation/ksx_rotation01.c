/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_rotation01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/09 01:53:49 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_m3_math.h"
#include "ksx_rotation.h"
#include <math.h>

void	ksx_rotation_x(t_vector3 *point, float angle)
{
	// t_matrix3	m3;
	float		r;

	if (angle == 0)
		return ;
	r = (angle * PI) / 180.f;
	point->y = (point->y * cosf(r)) - (point->z * sinf(r));
	point->z = (point->y * sinf(r)) + (point->z * cosf(r));
	// ksx_m3_reset(&m3);
	// m3.e_11 = 1;
	// m3.e_22 = cosf(r);
	// m3.e_23 = -sinf(r);
	// m3.e_32 = sinf(r);
	// m3.e_33 = cosf(r);
	// *point = ksx_m3_vec3(&m3, point);
}

void	ksx_rotation_y(t_vector3 *point, float angle)
{
	// t_matrix3	m3;
	float		r;

	if (angle == 0)
		return ;
	r = (angle * PI) / 180.f;
	point->x = (point->x * cosf(r)) + (point->z * sinf(r));
	point->z = - (point->x * sinf(r)) + (point->z * cosf(r));
	// ksx_m3_reset(&m3);
	// m3.e_11 = cosf(r);
	// m3.e_13 = sinf(r);
	// m3.e_22 = 1;
	// m3.e_13 = -sinf(r);
	// m3.e_33 = cosf(r);
	// *point = ksx_m3_vec3(&m3, point);
}

void	ksx_rotation_z(t_vector3 *point, float angle)
{
	// t_matrix3	m3;
	float		r;

	if (angle == 0)
		return ;
	r = (angle * PI) / 180.f;
	point->x = (point->x * cosf(r)) - (point->y * sinf(r));
	point->y = (point->x * sinf(r)) + (point->y * cosf(r));
	// ksx_m3_reset(&m3);
	// m3.e_11 = cosf(r);
	// m3.e_12 = -sinf(r);
	// m3.e_21 = sinf(r);
	// m3.e_22 = cosf(r);
	// m3.e_33 = 1;
	// *point = ksx_m3_vec3(&m3, point);
}

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

void	ksx_angle_check(float *angle)
{
	if (*angle == 0 || fmodf(*angle, 360.f) < PRECISION)
		return ;
	if (*angle > 360.f)
		*angle = fmodf(*angle, 360.f);
	if (fmodf(*angle, 360.f) < PRECISION)
		*angle = 0;
}
