/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/30 00:49:55 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ksx_utils.h"

void	get_cross_product(const t_vector v1, const t_vector v2, t_vector *v)
{
	v->xyz[X] = v1.xyz[Y] * v2.xyz[Z] - v1.xyz[Z] * v2.xyz[Y];
	v->xyz[Y] = v1.xyz[Z] * v2.xyz[X] - v1.xyz[X] * v2.xyz[Z];
	v->xyz[Z] = v1.xyz[X] * v2.xyz[Y] - v1.xyz[Y] * v2.xyz[X];
}

float	get_magnitude(const t_vector v)
{
	float	dis;

	dis = sqrtf(powf(v.xyz[X], 2.0f) + powf(v.xyz[Y], 2.0f)
			+ powf(v.xyz[Z], 2.0f));
	return (dis);
}

void	get_normal(t_vector v1, t_vector *v)
{
	float	f;

	f = 1.0f / get_magnitude(v1);
	v->xyz[X] = v1.xyz[X] * f;
	v->xyz[Y] = v1.xyz[Y] * f;
	v->xyz[Z] = v1.xyz[Z] * f;
}

// function is_point_on_ray in debug ...
int	is_point_on_ray(const t_point p, const t_vector v)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
	float		f;

	v1.xyz[X] = p.xyz[X];
	v1.xyz[Y] = p.xyz[Y];
	v1.xyz[Z] = p.xyz[Z];
	v2.xyz[X] = 0;
	v2.xyz[Y] = 0;
	v2.xyz[Z] = 0;
	v3.xyz[X] = 0;
	v3.xyz[Y] = 0;
	v3.xyz[Z] = 0;
	get_normal(v, &v2);
	get_normal(v1, &v3);
	f = get_dist_vector (v2, v3);
	(void) f;
	get_cross_product(v, v1, &v2);
	if (get_magnitude(v2) / get_magnitude(v) > PRECISION / 2.0f)
		return (FALSE);
	return (TRUE);
}
