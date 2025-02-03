/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils07.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/04 00:07:09 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



t_vector3	ksx_point_m33(const t_vector3 point, const t_matrix3 m)
{
	t_vector3		point_;

	point_.x = point.x * m.e_11 + point.y * m.e_12 + point.z * m.e_13;
	point_.y = point.x * m.e_21 + point.y * m.e_22 + point.z * m.e_23;
	point_.z = point.x * m.e_31 + point.y * m.e_32 + point.z * m.e_33;
	return (point_);
}

t_vector3	ksx_point_m44(const t_vector3 point, const t_matrix4 m)
{
	t_vector3		point_;

	point_.x = point.x * m.e_11 + point.y * m.e_12 + point.z * m.e_13 + m.e_14;
	point_.y = point.x * m.e_21 + point.y * m.e_22 + point.z * m.e_23 + m.e_24;
	point_.z = point.x * m.e_31 + point.y * m.e_32 + point.z * m.e_33 + m.e_34;
	return (point_);
}

// t_matrix3	ksx_get_transfor_matrix(const t_vector3 v1, const t_vector3 v2)
// {

// }
