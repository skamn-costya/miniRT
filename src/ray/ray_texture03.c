/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/04/01 17:11:10 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ray.h"
#include "ray_texture.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_3D.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "pp_struct.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

void	ray_txtr_object(const t_object *p_object, t_ray *p_ray)
{
	t_vector3	v3;
	float		uv[2];
	t_color		result;

	v3 = p_ray->point.op;
	p_object->ray_txtr_uv(&v3, &uv[0], &uv[1]);
	if (p_ray->pixel.color.b < MAX_TXTR - 1)
	{
		result = ray_txtr_sample(p_object->p_texture, uv[0], uv[1]);
		p_ray->norm = ray_bump_object(&p_ray->norm,
				p_object->p_texture, uv[0], uv[1]);
	}
	else if (p_ray->pixel.color.b == MAX_TXTR - 1)
		result = ray_uv_checker(uv[0], uv[1], 20);
	else
		result = ray_uv_debug_color(uv[0], uv[1]);
	ksx_color_unit_fraction(&result);
	p_ray->pixel.color = result;
}

t_color	ray_uv_debug_color(float u, float v)
{
	t_color	color;

	color.r = (uint8_t)(u * 255);
	color.g = (uint8_t)(v * 255);
	color.b = (uint8_t)((1 - v) * 255);
	color.a = 255;
	color.material.ka = 1.f;
	color.material.kd = .6f;
	color.material.ks = .4f;
	color.material.ns = 512.f;
	return (color);
}

t_color	ray_uv_checker(float u, float v, int scale)
{
	t_color	color;
	int		x;
	int		y;

	color.material.ka = 1.f;
	color.material.kd = .6f;
	color.material.ks = .6f;
	color.material.ns = 1024.f;
	x = (int)(u * scale) % 2;
	y = (int)(v / 2.f * scale) % 2;
	if (x == y)
		color.mlx_color = 0xFFFFFFFF;
	else
		color.mlx_color = 0xFF000000;
	return (color);
}

t_vector3	ray_bump_object(t_vector3 *p_normal, t_texture *p_txtr,
			float u, float v)
{
	float		f[8];
	t_vector3	vec3[3];

	if (!p_txtr->p_bumpdata)
		return (*p_normal);
	f[0] = 1.f / p_txtr->p_bumpdata->width;
	f[1] = 1.f / p_txtr->p_bumpdata->height;
	f[2] = ray_bump_sample(p_txtr, u, v);
	f[3] = ray_bump_sample(p_txtr, u + f[0], v);
	f[4] = ray_bump_sample(p_txtr, u, v + f[1]);
	f[5] = 0.8f;
	f[6] = (f[3] - f[2]) * f[5];
	f[7] = (f[4] - f[2]) * f[5];
	vec3[0] = ksx_vec3_set(1.f, 0.f, 0.f);
	vec3[1] = ksx_vec3_set(0.f, 1.f, 0.f);
	vec3[0] = ksx_vec3_smulti(&vec3[0], f[6]);
	vec3[1] = ksx_vec3_smulti(&vec3[1], f[7]);
	vec3[2] = ksx_vec3_add(&vec3[0], &vec3[1]);
	vec3[2] = ksx_vec3_add(p_normal, &vec3[2]);
	return (ksx_vec3_unit(&vec3[2]));
}
