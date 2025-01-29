/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/29 23:24:29 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ksx_utils.h"

// https://www.haroldserrano.com/blog/vectors-in-computer-graphics
// https://www.allmath.com/cross-product-calculator.php
// https://matrixcalc.org

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

	dis = get_dist_xyz(v1.xyz, v2.xyz);
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
	p->xyz[X] = (p1.xyz[X] + p2.xyz[X]) / 2.0f;
	p->xyz[Y] = (p1.xyz[Y] + p2.xyz[Y]) / 2.0f;
	p->xyz[Z] = (p1.xyz[Z] + p2.xyz[Z]) / 2.0f;
}
