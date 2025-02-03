/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/04 00:24:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
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
 * @brief returns the distance between v1 and v2.
 * 
 * @param v1 The first vecot
 * @param v2 The second vecot
 */
float	ksx_dist_vec3(const t_vector3 v1, const t_vector3 v2)
{
	float	dis;

	dis = sqrtf(powf(v1.x - v2.x, 2.f) + powf(v1.y - v2.y, 2.f)
			+ powf(v1.z - v2.z, 2.f));
	return (dis);
}

/**
 * @brief returns the lenght of v1.
 * 
 * @param v1 The first vecot
  */
float	ksx_magnit_vec3(const t_vector3 v)
{
	float	dis;

	dis = sqrtf(powf(v.x, 2.f) + powf(v.y, 2.f)
			+ powf(v.z, 2.f));
	return (dis);
}


/**
 * @brief returns resizeed vector
 * 
 * @param v1 Original vector
 * @param new_size Size of new vector
  */
t_vector3	ksx_resize_vec3(const t_vector3 v1,	const float new_size)
{
	float		f;
	t_vector3	result;

	f = new_size / ksx_magnit_vec3(v1);
	result.x = v1.x * f;
	result.y = v1.y * f;
	result.z = v1.z * f;
	return (result);
}

/**
 * @brief makes the vector into a unit vector, which means a vector of length 1
 * and puts the result into v
 * 
 * @param v1 Original vector
 * @param v The pointer to result vector
 */
t_vector3	ksx_norm_vec3(const t_vector3 v1)
{
	return (ksx_resize_vec3(v1, 1.f));
}

/**
 * @brief makes the vector as sum of v1 and v2
 * and and puts the result into v
 * 
 * @param v1 The first vecot
 * @param v2 The second vecot
 * @param v The pointer to result vector
 */
void	ksx_sum_vec3(const t_vector3 v1, const t_vector3 v2, t_vector3 *v)
{
	v->x = v1.x + v2.x;
	v->y = v1.y + v2.y;
	v->z = v1.z + v2.z;
}
