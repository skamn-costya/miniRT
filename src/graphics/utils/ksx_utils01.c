/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 23:47:45 by ksorokol         ###   ########.fr       */
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

float	ksx_get_dist_vector3(const t_vector3 v1, const t_vector3 v2)
{
	float	dis;

	dis = sqrtf(powf(v1.x - v2.x, 2.f) + powf(v1.y - v2.y, 2.f)
			+ powf(v1.z - v2.z, 2.f));
	return (dis);
}

void	ksx_middle_point(const t_vector3 p1,
			const t_vector3 p2, t_vector3 *p)
{
	p->x = (p1.x + p2.x) * 0.5f;
	p->y = (p1.y + p2.y) * 0.5f;
	p->z = (p1.z + p2.z) * 0.5f;
}

void	ksx_vector3_resize(const t_vector3 v1,
			const float new_size, t_vector3 *v)
{
	float	f;

	f = new_size / ksx_get_magnitude(v1);
	v->x = v1.x * f;
	v->y = v1.y * f;
	v->z = v1.z * f;
}

void	ksx_vector3_norm(const t_vector3 v1, t_vector3 *v)
{
	ksx_vector3_resize(v1, 1.f, v);
}
