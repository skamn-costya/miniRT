/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec3_math02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/08 23:51:59 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include <math.h>

/**
 * @brief returnss the vector as an unit vector, which means a vector of length 1
 * 
 * @param v Original vector
 */
t_vector3	ksx_vec3_unit(const t_vector3 *p_v)
{
	t_vector3	v;

	v = *p_v;
	ksx_vec3_resize(&v, 1.f);
	return (v);
}

t_vector3	ksx_vec3_norm(const t_vector3 v, const t_vector3 norm)
{
	t_vector3	result;

	result = ksx_vec3_cross(v, norm);
	return (result);
}

/**
 * @brief returns the distance between v1 and v2.
 * 
 * @param v1 The first vecot
 * @param v2 The second vecot
 */
float	ksx_vec3_dist(const t_vector3 v1, const t_vector3 v2)
{
	float	result;

	result = sqrtf(powf(v1.x - v2.x, 2.f) + powf(v1.y - v2.y, 2.f)
			+ powf(v1.z - v2.z, 2.f));
	return (result);
}

/**
 * @brief returns resizeed vector
 * 
 * @param v Original vector
 * @param size Size of new vector
  */
void	ksx_vec3_resize(t_vector3 *p_v, const float size)
{
	float		f;

	f = size / ksx_vec3_mag(*p_v);
	p_v->x = p_v->x * f;
	p_v->y = p_v->y * f;
	p_v->z = p_v->z * f;
}

t_matrix3	ksx_vec3_tensor(const t_vector3 v1, const t_vector3 v2)
{
	t_matrix3	result;

	result.e_11 = v1.x * v2.x;
	result.e_12 = v1.x * v2.y;
	result.e_13 = v1.x * v2.z;
	result.e_21 = v1.y * v2.x;
	result.e_22 = v1.y * v2.y;
	result.e_23 = v1.y * v2.z;
	result.e_31 = v1.z * v2.x;
	result.e_32 = v1.z * v2.y;
	result.e_33 = v1.z * v2.z;
	return (result);
}
