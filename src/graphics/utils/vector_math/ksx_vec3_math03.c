/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec3_math03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/19 12:05:18 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include <math.h>

float	ksx_vec3_dot(const t_vector3 *p_v1, const t_vector3 *p_v2)
{
	float	result;

	result = p_v1->x * p_v2->x + p_v1->y * p_v2->y + p_v1->z * p_v2->z;
	return (result);
}

t_vector3	ksx_vec3_smulti(const t_vector3 *p_v, const float scalar)
{
	t_vector3	result;

	result.x = p_v->x * scalar;
	result.y = p_v->y * scalar;
	result.z = p_v->z * scalar;
	return (result);
}

t_vector3	ksx_vec3_sdiv(const t_vector3 *p_v, const float scalar)
{
	t_vector3	result;

	if (scalar == 0)
	{
		return (*p_v);
	}
	result.x = p_v->x / scalar;
	result.y = p_v->y / scalar;
	result.z = p_v->z / scalar;
	return (result);
}

t_vector3	ksx_vec3_set(float x, float y, float z)
{
	t_vector3	v;

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
