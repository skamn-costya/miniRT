/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pln.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:10:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 01:15:57 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "ray_texture.h"
#include "ksx_utils.h"
#include "math.h"
#include <stdio.h>

inline static void	ray_p2pln01(t_plane *p_plane, t_ray *p_ray);

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
		p_ray->point.cp = v3[1];
		p_ray->pixel.color = p_plane->color;
		ray_p2pln01(p_plane, p_ray);
		p_ray->p_tri = NULL;
		p_ray->p_pln = p_plane;
		p_ray->norm = p_plane->norm.cp;
	}
}

inline static void	ray_p2pln01(t_plane *p_plane, t_ray *p_ray)
{
	t_vector3	v3;
	float		uv[2];
	t_color		result;

	p_plane->color.material.ka = 1.f;
	p_plane->color.material.kd = .64f;
	p_plane->color.material.ks = .5f;
	p_plane->color.material.ns = 3.f;
	v3 = p_ray->point.op;
	ray_txtr_uv_plan(&v3, &uv[0], &uv[1], p_plane);
	if (p_plane->p_texture && p_ray->pixel.color.b < 8)
		result = ray_txtr_sample(p_plane->p_texture, uv[0], uv[1]);
	else if (p_plane->p_texture && p_ray->pixel.color.b == 8)
		result = ray_uv_checker(uv[0], uv[1], 20);
	else if (p_plane->p_texture)
		result = ray_uv_debug_color(uv[0], uv[1]);
	ksx_color_unit_fraction(&result);
	p_ray->pixel.color.mlx_color = result.mlx_color;
	p_ray->pixel.color.ur = result.ur;
	p_ray->pixel.color.ug = result.ug;
	p_ray->pixel.color.ub = result.ub;
	p_ray->pixel.color.ua = result.ua;
	if (p_plane->p_texture && p_plane->p_texture->p_bumpdata)
		p_ray->norm = ray_bump_object(&p_ray->norm,
				p_plane->p_texture, uv[0], uv[1]);
}
