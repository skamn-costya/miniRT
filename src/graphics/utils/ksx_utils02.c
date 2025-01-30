/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/30 10:11:12 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ksx_utils.h"

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

// function is_point_on_ray in debug ...
int	is_point_on_ray(const t_point p, const t_vector v)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
	float		f;

	v1.dir.x = p.x;
	v1.dir.y = p.y;
	v1.dir.z = p.z;
	v2.dir.x = 0;
	v2.dir.y = 0;
	v2.dir.z = 0;
	v3.dir.x = 0;
	v3.dir.y = 0;
	v3.dir.z = 0;
	get_normal(v, &v2);
	get_normal(v1, &v3);
	f = get_dist_vector (v2, v3);
	(void) f;
	get_cross_product(v, v1, &v2);
	if (get_magnitude(v2) / get_magnitude(v) > PRECISION / 2.0f)
		return (FALSE);
	return (TRUE);
}
