/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:10:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/28 21:19:50 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "math.h"
#include <stdio.h>

void	ray_colors_add(t_color *p_color1, t_color *p_color2)
{
	p_color1->ur = p_color1->ur + p_color2->ur;
	p_color1->ug = p_color1->ug + p_color2->ug;
	p_color1->ub = p_color1->ub + p_color2->ub;
}

void	ray_colors_multiply(t_color *p_color1, const t_color *p_color2)
{
	p_color1->ur = p_color1->ur * p_color2->ur;
	p_color1->ug = p_color1->ug * p_color2->ug;
	p_color1->ub = p_color1->ub * p_color2->ub;
}

void	ray_colors_scale(t_color *p_color, float scale)
{
	p_color->ur = p_color->ur * scale;
	p_color->ug = p_color->ug * scale;
	p_color->ub = p_color->ub * scale;
}

void	ray_colors_8bit(t_color *p_color)
{
	p_color->r = (uint8_t)fminf(p_color->ur * 255.f, 255);
	p_color->g = (uint8_t)fminf(p_color->ug * 255.f, 255);
	p_color->b = (uint8_t)fminf(p_color->ub * 255.f, 255);
}

void	ray_colors_calc(t_ray *p_ray)
{
	float		f[3];
	t_vector3	vec3[3];
	t_color		color[2];

	vec3[0] = ksx_vec3_sub(&p_ray->p_lgt->point.cp, &p_ray->point.cp);
	vec3[0] = ksx_vec3_unit(&vec3[0]);
	p_ray->norm = ksx_vec3_unit(&p_ray->norm);
	f[0] = fmaxf(0.f, ksx_vec3_dot(&p_ray->norm, &vec3[0]));
	color[0] = p_ray->color;
	ray_colors_multiply(&color[0], &p_ray->p_lgt->color);
	ray_colors_scale(&color[0], p_ray->p_lgt->bright
		* p_ray->color.material.kd * f[0]);
	vec3[1] = ksx_vec3_reflect(&p_ray->direction, &p_ray->norm);
	vec3[2] = ksx_vec3_unit(&p_ray->point.cp);
	f[1] = fmaxf(0.f, ksx_vec3_dot(&vec3[1], &vec3[2]));
	f[2] = powf(f[1], p_ray->color.material.ns);
	color[1] = p_ray->p_lgt->color;
	ray_colors_scale(&color[1], p_ray->p_lgt->bright
		* p_ray->color.material.ks * f[2]);
	ray_colors_add(&color[0], &color[1]);
	ray_colors_add(&p_ray->pixel.color, &color[0]);
}
