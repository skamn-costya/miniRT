/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils05.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/04 20:49:18 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

t_vector3	ksx_point_rotation(const t_vector3 point, const float angle_x,
	const float angle_y, const float angle_z)
{
	t_vector3	point_;
	t_matrix3	rm;

	if (angle_x == 0 && angle_y == 0 && angle_z == 0)
		return (point);
	rm.e_11 = cos (angle_y) * cos (angle_z);
	rm.e_12 = - (sin (angle_z) * cos (angle_y));
	rm.e_13 = sin (angle_y);
	rm.e_21 = (sin (angle_x) * sin (angle_y) * cos (angle_z))
		+ (sin (angle_z) * cos (angle_x));
	rm.e_22 = - (sin (angle_x) * sin (angle_y) * sin (angle_z))
		+ (cos (angle_x) * cos (angle_z));
	rm.e_23 = - (sin (angle_x) * cos (angle_y));
	rm.e_31 = (sin (angle_x) * sin (angle_z))
		- (sin (angle_y) * cos (angle_x) * cos (angle_z));
	rm.e_32 = (sin (angle_x) * cos (angle_z))
		+ (sin (angle_y) * sin (angle_z) * cos (angle_x));
	rm.e_33 = cos (angle_x) * cos (angle_y);
	point_ = ksx_point_m3(point, rm);
	return (point_);
}

t_vector3	ksx_point_rotation_x(const t_vector3 point, const float angle)
{
	t_vector3	point_;

	if (angle == 0)
		return (point);
	point_.x = point.x;
	point_.y = (point.y * cosf(angle)) - (point.z * sinf(angle));
	point_.z = (point.y * sinf(angle)) + (point.z * cosf(angle));
	return (point_);
}

t_vector3	ksx_point_rotation_y(const t_vector3 point, const float angle)
{
	t_vector3	point_;

	if (angle == 0)
		return (point);
	point_.x = (point.x * cosf(angle)) + (point.z * sinf(angle));
	point_.y = point.y;
	point_.z = - (point.x * sinf(angle)) + (point.z * cosf(angle));
	return (point_);
}

t_vector3	ksx_point_rotation_z(const t_vector3 point, const float angle)
{
	t_vector3	point_;

	if (angle == 0)
		return (point);
	point_.x = (point.x * cosf(angle)) - (point.y * sinf(angle));
	point_.y = (point.x * sinf(angle)) + (point.y * cosf(angle));
	point_.z = point.z;
	return (point_);
}
