/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec4_math03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/27 20:48:27 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include <math.h>

float	ksx_vec4_dot(const t_vector4 *p_v1, const t_vector4 *p_v2)
{
	float	result;

	result = p_v1->x * p_v2->x + p_v1->y * p_v2->y
		+ p_v1->z * p_v2->z + p_v1->w * p_v2->w;
	return (result);
}

t_vector4	ksx_vec4_multi(const t_vector4 *p_v, const float scalar)
{
	t_vector4	result;

	result.x = p_v->x * scalar;
	result.y = p_v->y * scalar;
	result.z = p_v->z * scalar;
	result.w = p_v->w * scalar;
	return (result);
}

t_vector4	ksx_vec4_div(const t_vector4 *p_v, const float scalar)
{
	t_vector4	result;

	if (scalar == 0)
	{
		return (ksx_vec4_set(0.f, 0.f, 0.f, 0.f));
	}
	result.x = p_v->x / scalar;
	result.y = p_v->y / scalar;
	result.z = p_v->z / scalar;
	result.w = p_v->w / scalar;
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
