/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/03 00:10:37 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>

void	ksx_cross_product(const t_vector3 v1, const t_vector3 v2, t_vector3 *v)
{
	v->x = v1.y * v2.z - v1.z * v2.y;
	v->y = v1.z * v2.x - v1.x * v2.z;
	v->z = v1.x * v2.y - v1.y * v2.x;
}

float	ksx_get_magnitude(const t_vector3 v)
{
	float	dis;

	dis = sqrtf(powf(v.x, 2.f) + powf(v.y, 2.f)
			+ powf(v.z, 2.f));
	return (dis);
}

float	ksx_get_angle(const t_vector3 v1, const t_vector3 v2)
{
	float	f;

	f = acosf(((v1.x * v2.x) + (v1.y * v2.y)
				+ (v1.z * v2.z))
			/ (ksx_get_magnitude(v1) * ksx_get_magnitude(v2)));
	return (f);
}

// function is_point_on_ray in debug ...
int	ksx_point_on_ray(const t_vector3 p, const t_vector3 v)
{
	t_vector3	v1;
	float		f[2];

	ksx_cross_product(p, v, &v1);
	f[0] = ksx_get_magnitude(v1);
	f[1] = ksx_get_magnitude(v);
	if (f[0] / f[1] > PRECISION * 0.5f)
		return (KSX_FALSE);
	return (KSX_TRUE);
}

void	ksx_set_world_coords(t_triangle *triangle, const t_vector3 v)
{
	ksx_vector3_sum(triangle->p1, v, &triangle->w_p1);
	ksx_vector3_sum(triangle->p2, v, &triangle->w_p2);
	ksx_vector3_sum(triangle->p3, v, &triangle->w_p3);
}
