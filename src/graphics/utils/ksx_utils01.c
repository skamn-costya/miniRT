/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/29 18:25:39 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ksx_graphics.h"
#include "ksx_utils.h"

// https://www.haroldserrano.com/blog/vectors-in-computer-graphics
// https://www.allmath.com/cross-product-calculator.php
// https://matrixcalc.org

float	get_distance(const t_point p1, const t_point p2)
{
	float	dis;

	dis = sqrtf(powf(p1.xyz[X] - p2.xyz[X], 2) + powf(p1.xyz[Y] - p2.xyz[Y], 2)
			+ powf(p1.xyz[Z] - p2.xyz[Z], 2));
	return (dis);
}

void	get_middle_point(const t_point p1, const t_point p2, t_point p)
{
	p.xyz[X] = (p1.xyz[X] + p2.xyz[X]) / 2;
	p.xyz[Y] = (p1.xyz[Y] + p2.xyz[Y]) / 2;
	p.xyz[Z] = (p1.xyz[Z] + p2.xyz[Z]) / 2;
}

void	get_cross_product(const t_vector v1, const t_vector v2, t_vector v)
{
	v.xyz[X] = v1.xyz[Y] * v2.xyz[Z] - v1.xyz[Z] * v2.xyz[Y];
	v.xyz[Y] = v1.xyz[Z] * v2.xyz[X] - v1.xyz[X] * v2.xyz[Z];
	v.xyz[Z] = v1.xyz[X] * v2.xyz[Y] - v1.xyz[Y] * v2.xyz[X];
}

float	get_magnitude(const t_vector v)
{
	float	dis;

	dis = sqrtf(powf(v.xyz[X], 2) + powf(v.xyz[Y], 2) + powf(v.xyz[Z], 2));
	return (dis);
}

int	is_point_on_ray(const t_point p, const t_vector v)
{
	t_vector	v1;
	t_vector	v2;
	
	v1.xyz[X] = p.xyz[X];
	v1.xyz[Y] = p.xyz[Y];
	v1.xyz[Z] = p.xyz[Z];
	v2.xyz[X] = 0;
	v2.xyz[Y] = 0;
	v2.xyz[Z] = 0;
	get_cross_product(v, v1, v2);

	if (get_magnitude(v2) / get_magnitude(v) > PRECISION / 2)
		return (FALSE);
	return (TRUE);
}
