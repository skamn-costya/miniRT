/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec3_math04.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/20 12:48:21 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include <math.h>

t_vector3	ksx_vec3_sadd(const t_vector3 *p_v, const float scalar)
{
	t_vector3	result;

	result.x = p_v->x + scalar;
	result.y = p_v->y + scalar;
	result.z = p_v->z + scalar;
	return (result);
}

t_vector3	ksx_vec3_ssub(const t_vector3 *p_v, const float scalar)
{
	t_vector3	result;

	result.x = p_v->x - scalar;
	result.y = p_v->y - scalar;
	result.z = p_v->z - scalar;
	return (result);
}

t_vector3	ksx_vec3_negate(t_vector3 *p_v)
{
    t_vector3	result;

    result.x = -p_v->x;
    result.y = -p_v->y;
    result.z = -p_v->z;
    return result;
}

t_vector3	ksx_vec3_reflect(t_vector3 *p_v, t_vector3 *p_n)
{
    float dot = ksx_vec3_dot(p_v, p_n) * 2.f;
    t_vector3 scaled_n = ksx_vec3_smulti(p_n, dot);
    return ksx_vec3_sub(p_v, &scaled_n);
}
