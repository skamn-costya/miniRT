/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 16:52:12 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>

void	get_cross_product(const t_vector v1, const t_vector v2, t_vector *v)
{
	v->dir.x = v1.dir.y * v2.dir.z - v1.dir.z * v2.dir.y;
	v->dir.y = v1.dir.z * v2.dir.x - v1.dir.x * v2.dir.z;
	v->dir.z = v1.dir.x * v2.dir.y - v1.dir.y * v2.dir.x;
}

float	get_magnitude(const t_vector v)
{
	float	dis;

	dis = sqrtf(powf(v.dir.x, 2.0f) + powf(v.dir.y, 2.0f)
			+ powf(v.dir.z, 2.0f));
	return (dis);
}

void	get_normal(t_vector v1, t_vector *v)
{
	float	f;

	f = 1.0f / get_magnitude(v1);
	v->dir.x = v1.dir.x * f;
	v->dir.y = v1.dir.y * f;
	v->dir.z = v1.dir.z * f;
}

float	get_angle(const t_vector v1, const t_vector v2)
{
	float	f;

	f = acosf(((v1.dir.x * v2.dir.x) + (v1.dir.y * v2.dir.y)
				+ (v1.dir.z * v2.dir.z))
			/ (get_magnitude(v1) * get_magnitude(v2)));
	return (f);
}

// function is_point_on_ray in debug ...
int	is_point_on_ray(const t_point p, const t_vector v)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
	float		f[2];

	v1.dir = p;
	v2.dir = v1.dir;
	v3.dir = v1.dir;
	get_normal(v, &v2);
	get_normal(v1, &v3);
	// f = get_dist_vector (v2, v3);
	// if (f > PRECISION)
	// 	return (FALSE);
	get_cross_product(v, v1, &v2);
	f[0] = get_magnitude(v2);
	f[1] = get_magnitude(v);
	if (f[0] / f[1] > PRECISION * 0.5f)
		return (KSX_FALSE);
	return (KSX_TRUE);
}
