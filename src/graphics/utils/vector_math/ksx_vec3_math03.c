/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec3_math03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 20:23:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include <math.h>

float	ksx_vec3_dot(const t_vector3 v1, const t_vector3 v2)
{
	float	result;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (result);
}

t_vector3	ksx_vec3_multi(const t_vector3 v, const float scalar)
{
	t_vector3	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;
	return (result);
}

t_vector3	ksx_vec3_div(const t_vector3 v, const float scalar)
{
	t_vector3	result;

	if (scalar == 0)
	{
		return (v);	
	}
	result.x = v.x / scalar;
	result.y = v.y / scalar;
	result.z = v.z / scalar;
	return (result);
}

t_vector3	ksx_vec3_set(float x, float y, float z)
{
	t_vector3	v;

	// v.start_x = 0;
	// v.start_y = 0;
	// v.start_z = 0;
	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector4	ksx_vec3_vec4(const t_vector3 *p_v, float w)
{
	t_vector4	v4;

	v4.x = p_v->x;
	v4.y = p_v->y;
	v4.z = p_v->z;
	v4.w = w;
	return (v4);
}
