/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec4_math03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/20 18:53:18 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include <math.h>

float	ksx_vec4_dot(const t_vector4 v1, const t_vector4 v2)
{
	float	result;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	return (result);
}

t_vector4	ksx_vec4_multi(const t_vector4 v, const float scalar)
{
	t_vector4	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;
	result.w = v.w * scalar;
	return (result);
}

t_vector4	ksx_vec4_div(const t_vector4 v, const float scalar)
{
	t_vector4	result;

	if (scalar == 0)
	{
		return (v);
	}
	result.x = v.x / scalar;
	result.y = v.y / scalar;
	result.z = v.z / scalar;
	result.w = v.w / scalar;
	return (result);
}

t_vector4	ksx_vec4_set(float x, float y, float z, float w)
{
	t_vector4	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

t_vector3	ksx_vec4_vec3(const t_vector4 *p_v)
{
	t_vector3	v;

	v.x = p_v->x;
	v.y = p_v->y;
	v.z = p_v->z;
	return (v);
}
