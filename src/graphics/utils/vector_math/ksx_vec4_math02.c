/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec4_math02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/27 20:47:58 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include <math.h>

/**
 * @brief returnss the vector as an unit vector, which means a vector of length 1
 * 
 * @param v Original vector
 */
t_vector4	ksx_vec4_unit(const t_vector4 *p_v)
{
	t_vector4	v;

	v = *p_v;
	ksx_vec4_resize(&v, 1.f);
	return (v);
}

// t_vector3	ksx_vec3_norm(const t_vector3 *p_v, const t_vector3 *p_norm)
// {
// 	t_vector3	result;

// 	result = ksx_vec3_cross(p_v, p_norm);
// 	return (result);
// }

/**
 * @brief returns the distance between v1 and v2.
 * 
 * @param p_v1 The pointer to the first vecot
 * @param p_v2 The pointer to the second vecot
 */
float	ksx_vec4_dist(const t_vector4 *p_v1, const t_vector4 *p_v2)
{
	float	result;

	result = sqrtf(powf(p_v1->x - p_v2->x, 2.f) + powf(p_v1->y - p_v2->y, 2.f)
			+ powf(p_v1->z - p_v2->z, 2.f) + powf(p_v1->w - p_v2->w, 2.f));
	return (result);
}

/**
 * @brief returns resizeed vector
 * 
 * @param v Original vector
 * @param size Size of new vector
  */
void	ksx_vec4_resize(t_vector4 *p_v, const float size)
{
	float		f;

	f = size / ksx_vec4_mag(p_v);
	p_v->x = p_v->x * f;
	p_v->y = p_v->y * f;
	p_v->z = p_v->z * f;
	p_v->w = p_v->w * f;
}

t_matrix4	ksx_vec4_tensor(const t_vector4 *p_v1, const t_vector4 *p_v2)
{
	t_matrix4	result;

	result.e_11 = p_v1->x * p_v2->x;
	result.e_12 = p_v1->x * p_v2->y;
	result.e_13 = p_v1->x * p_v2->z;
	result.e_14 = p_v1->x * p_v2->w;
	result.e_21 = p_v1->y * p_v2->x;
	result.e_22 = p_v1->y * p_v2->y;
	result.e_23 = p_v1->y * p_v2->z;
	result.e_24 = p_v1->y * p_v2->w;
	result.e_31 = p_v1->z * p_v2->x;
	result.e_32 = p_v1->z * p_v2->y;
	result.e_33 = p_v1->z * p_v2->z;
	result.e_34 = p_v1->z * p_v2->w;
	result.e_41 = p_v1->w * p_v2->x;
	result.e_42 = p_v1->w * p_v2->y;
	result.e_43 = p_v1->w * p_v2->z;
	result.e_44 = p_v1->w * p_v2->w;
	return (result);
}
