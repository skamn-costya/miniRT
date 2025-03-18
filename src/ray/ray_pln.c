/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pln.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:10:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/18 23:46:39 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "math.h"
#include <stdio.h>

void	ray_p2planes(t_world *p_world, t_ray *p_ray)
{
	int32_t		idx;

	idx = -1;
	while (++idx < p_world->size_pln)
		ray_p2pln(p_world->pp_pln[idx], p_ray);
}

void	ray_p2pln(t_plane *p_plane, t_ray *p_ray)
{
	t_vector3	v3[3];
	float		f[2];

	f[0] = ksx_vec3_dot(&p_ray->direction, &p_plane->norm.cp);
	if (fabsf(f[0]) < EPSILON)
		return ;
	v3[0] = ksx_vec3_sub(&p_plane->point.cp, &p_ray->origin);
	f[1] = ksx_vec3_dot(&v3[0], &p_plane->norm.cp) / f[0];
	if (f[1] < 0)
		return ;
	v3[1] = ksx_vec3_smulti(&p_ray->direction, f[1]);
	v3[1] = ksx_vec3_add(&p_ray->origin, &v3[1]);
	v3[2] = ksx_vec3_sub(&v3[1], &p_ray->origin);
	p_ray->length = ksx_vec3_mag(&v3[2]);
	if (p_ray->length > EPSILON && p_ray->length < p_ray->min_length)
	{
		p_ray->length = f[1];
		p_ray->min_length = p_ray->length;
		p_ray->pixel.color.mlx_color = p_plane->color.mlx_color;
		p_ray->point = v3[1];
		p_ray->p_tri = NULL;
		p_ray->p_pln = p_plane;
		p_ray->norm = p_plane->norm.cp;
	}
}
