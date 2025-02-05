/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec3_math01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/05 15:53:13 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
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
 * @param v1 The first vecot
 * @param v2 The second vecot
 */
t_vector3	ksx_vec3_add(const t_vector3 v1, const t_vector3 v2)
{
	t_vector3	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

/**
 * @brief returns a vector as subtraction of v1 and v2
 *
 * @param v1 The first vecot
 * @param v2 The second vecot
 */
t_vector3	ksx_vec3_sub(const t_vector3 v1, const t_vector3 v2)
{
	t_vector3	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

float	ksx_vec3_angle(const t_vector3 v1, const t_vector3 v2)
{
	float	result;

	result = acosf(((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z))
			/ (ksx_vec3_mag(v1) * ksx_vec3_mag(v2)));
	return (result);
}

t_vector3	ksx_vec3_cross(const t_vector3 v1, const t_vector3 v2)
{
	t_vector3	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

/**
 * @brief returns the length of v1.
 * 
 * @param v1 The vecot
  */
float	ksx_vec3_mag(const t_vector3 v)
{
	float	result;

	result = sqrtf(powf(v.x, 2.f) + powf(v.y, 2.f)
			+ powf(v.z, 2.f));
	return (result);
}
