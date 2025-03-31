/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_lgt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:10:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 21:31:37 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "math.h"
#include <stdio.h>

static void	clamp_color(t_color *p_color)
{
	p_color->ur = fminf(fmaxf(0.f, p_color->ur), 1.f);
	p_color->ug = fminf(fmaxf(0.f, p_color->ug), 1.f);
	p_color->ub = fminf(fmaxf(0.f, p_color->ub), 1.f);
}

void	ray_p2lights(t_world *p_world, t_ray *p_ray)
{
	int32_t		idx;
	t_vector3	vec3;

	vec3 = ksx_vec3_smulti(&p_ray->norm, BIAS);
	p_ray->point.cp = ksx_vec3_add(&p_ray->point.cp, &vec3);
	p_ray->origin = p_ray->point.cp;
	p_ray->color = p_ray->pixel.color;
	ray_colors_multiply(&p_ray->pixel.color, &p_world->ambient.color);
	ray_colors_scale(&p_ray->pixel.color,
		p_world->ambient.bright * p_ray->pixel.color.material.ka);
	idx = -1;
	while (++idx < p_world->size_lgt)
		ray_p2lgt(p_world, p_world->pp_lgt[idx], p_ray);
	clamp_color(&p_ray->pixel.color);
	ray_colors_8bit(&p_ray->pixel.color);
}

void	ray_p2lgt(t_world *p_world, t_light *p_light, t_ray *p_ray)
{
	int32_t	idx[3];

	p_ray->p_lgt = p_light;
	p_ray->direction = ksx_vec3_sub(&p_light->point.cp, &p_ray->point.cp);
	p_ray->direction = ksx_vec3_unit(&p_ray->direction);
	p_ray->min_length = ksx_vec3_dist(&p_light->point.cp, &p_ray->point.cp);
	p_ray->length = p_ray->min_length;
	ray_p2lgt_boxes(p_world, p_ray, idx);
	(void) p_world;
	if (p_ray->p_lgt)
		ray_colors_calc(p_ray);
}

void	ray_p2lgt_boxes(t_world *p_world, t_ray *p_ray, int32_t *idx)
{
	idx[0] = -1;
	while (++idx[0] < p_world->size_box)
	{
		idx[1] = -1;
		while (++idx[1] < 12)
		{
			ray_p2tri(&p_world->pp_box[idx[0]]->tris[idx[1]], p_ray);
			if (p_ray->length != p_ray->min_length)
			{
				p_ray->length = p_ray->min_length;
				idx[2] = -1;
				while (p_world->pp_box[idx[0]]->pp_tris[++idx[2]])
				{
					ray_p2tri(p_world->pp_box[idx[0]]->pp_tris[idx[2]], p_ray);
					if (p_ray->length < p_ray->min_length)
					{
						p_ray->p_lgt = NULL;
						break ;
					}
				}
				break ;
			}
		}
	}
}
