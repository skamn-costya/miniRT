/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/31 09:45:01 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_utils.h"

// in English
// https://www.haroldserrano.com/blog/vectors-in-computer-graphics
// https://www.allmath.com/cross-product-calculator.php
// https://matrixcalc.org
// https://www.mathnirvana.com/math-rules/equation-of-a-circle.htm

// in Russin
// https://www.mathnirvana.com/ru/vse-pravila-matematiki/uravneniye-okruzhnosti.htm

float	get_dist_xyz(const float xyz1[], const float xyz2[])
{
	float	dis;

	dis = sqrtf(powf(xyz1[X] - xyz2[X], 2.0f) + powf(xyz1[Y] - xyz2[Y], 2.0f)
			+ powf(xyz1[Z] - xyz2[Z], 2.0f));
	return (dis);
}

float	get_dist_vector(const t_vector v1, const t_vector v2)
{
	float	dis;

	dis = get_dist_xyz(v1.dir.xyz, v2.dir.xyz);
	return (dis);
}

float	get_dist_point(const t_point p1, const t_point p2)
{
	float	dis;

	dis = get_dist_xyz(p1.xyz, p2.xyz);
	return (dis);
}

void	get_middle_point(const t_point p1, const t_point p2, t_point *p)
{
	p->x = (p1.x + p2.x) / 2.0f;
	p->y = (p1.y + p2.y) / 2.0f;
	p->z = (p1.z + p2.z) / 2.0f;
}

void	vector_resize(t_vector v1, float new_size, t_vector *v)
{
	float f;

	f= get_magnitude(v1);

	f = new_size / f;

	v->dir.x = v1.dir.x * f;
	v->dir.y = v1.dir.y * f;
	v->dir.z = v1.dir.z * f;
}