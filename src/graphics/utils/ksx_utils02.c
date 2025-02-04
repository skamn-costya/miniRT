/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/04 08:23:10 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>

t_vector3	ksx_cross_vec3(const t_vector3 v1, const t_vector3 v2)
{
	t_vector3	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

float	ksx_angle_vec3(const t_vector3 v1, const t_vector3 v2)
{
	float	result;

	result = acosf(((v1.x * v2.x) + (v1.y * v2.y)
				+ (v1.z * v2.z))
			/ (ksx_magnit_vec3(v1) * ksx_magnit_vec3(v2)));
	return (result);
}

t_vector3	ksx_multi_vec3(const t_vector3 v1, const t_vector3 v2)
{
	t_vector3	result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return (result);
}
