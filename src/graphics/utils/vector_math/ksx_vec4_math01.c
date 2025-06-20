/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec4_math01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/12 23:20:30 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include <math.h>

// in English
// https://www.haroldserrano.com/blog/vectors-in-computer-graphics
// https://www.allmath.com/cross-product-calculator.php
// https://matrixcalc.org
// https://www.mathnirvana.com/math-rules/equation-of-a-circle.htm
// in Russin
// https://www.mathnirvana.com/ru/vse-pravila-matematiki
// /uravneniye-okruzhnosti.htm

/**
 * @brief returns a vector as addition of v1 and v2
 *
 * @param p_v1 pointer to the first vecot
 * @param p_v2 pointer to the second vecot
 */
t_vector4	ksx_vec4_add(const t_vector4 *p_v1, const t_vector4 *p_v2)
{
	t_vector4	result;

	result.x = p_v1->x + p_v2->x;
	result.y = p_v1->y + p_v2->y;
	result.z = p_v1->z + p_v2->z;
	result.w = p_v1->w + p_v2->w;
	return (result);
}

/**
 * @brief returns a vector as subtraction of v1 and v2
 *
 * @param p_v1 pointer to the first vecot
 * @param p_v2 pointer to the second vecot
 */
t_vector4	ksx_vec4_sub(const t_vector4 *p_v1, const t_vector4 *p_v2)
{
	t_vector4	result;

	result.x = p_v1->x - p_v2->x;
	result.y = p_v1->y - p_v2->y;
	result.z = p_v1->z - p_v2->z;
	result.z = p_v1->w - p_v2->w;
	return (result);
}

// float	ksx_vec3_angle(const t_vector3 *p_v1, const t_vector3 *p_v2)
// {
// 	float	result;

// 	result = acosf(((p_v1->x * p_v2->x) + (p_v1->y * p_v2->y)
// 				+ (p_v1->z * p_v2->z))
// 			/ (ksx_vec3_mag(p_v1) * ksx_vec3_mag(p_v2)));
// 	return (result);
// }

t_vector4	ksx_vec4_cross(const t_vector4 *p_v1, const t_vector4 *p_v2)
{
	t_vector4	result;

	result.x = p_v1->y * p_v2->z - p_v1->z * p_v2->y;
	result.y = p_v1->z * p_v2->x - p_v1->x * p_v2->z;
	result.z = p_v1->x * p_v2->y - p_v1->y * p_v2->x;
	result.w = p_v1->w * p_v2->w - p_v1->w * p_v2->w;
	return (result);
}

/**
 * @brief returns the length of v1.
 * 
 * @param v1 The vecot
  */
float	ksx_vec4_mag(const t_vector4 *p_v)
{
	float	result;

	result = sqrtf(powf(p_v->x, 2.f) + powf(p_v->y, 2.f)
			+ powf(p_v->z, 2.f) + powf(p_v->w, 2.f));
	return (result);
}
