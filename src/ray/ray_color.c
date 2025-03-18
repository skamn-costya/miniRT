/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:10:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/18 23:56:34 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "math.h"
#include <stdio.h>

static inline uint8_t	clamp(int32_t value)
{
	if (value < 0) return 0;
	if (value > 255) return 255;
	return (uint8_t)value;
}

t_color add_ambient_to_color(t_color base_color, float ambient_ratio,
	t_color ambient_color)
{
	t_color	result;
	int32_t	rgb[3];

    rgb[0] = base_color.r + (int32_t)(ambient_color.r * ambient_ratio);
    rgb[1] = base_color.g + (int32_t)(ambient_color.g * ambient_ratio);
    rgb[2] = base_color.b + (int32_t)(ambient_color.b * ambient_ratio);
    result.r = clamp(rgb[0]);
    result.g = clamp(rgb[1]);
    result.b = clamp(rgb[2]);
	result.a = base_color.a;
	return (result);
}

// void compute_lightings(t_ray *p_ray, t_graphics *p_grph)
// {
// 	int32_t	idx;

// 	idx = -1;
// 	while (++idx < p_grph->world.size_lgt)
// 	{
// 		p_ray->direction = ksx_vec3_sub(&p_grph->world.pp_lgt[idx].point.cp, &p_ray->point);
// 		p_ray->direction = ksx_vec3_unit(&p_ray->direction);
		
// 	}
// 	p_ray->pixel.color = add_ambient_to_color(p_ray->pixel.color,
// 		p_grph->world.ambient.bright, p_grph->world.ambient.color);
// }

// void compute_lighting(t_ray *p_ray, t_light *p_light)
// {
// 	float	diff;
// 	float	spec;
// 	float	intensity;

// 	diff = fmax(0.f, ksx_vec3_dot(&p_ray->norm, &p_ray->direction));
// 	t_vector3 reflect_dir = ksx_vec3_reflect(&p_ray->direction, &p_ray->norm);
// 	t_vector3 view_dir = ksx_vec3_unit(&p_ray->point);
// 	spec = powf(fmax(ksx_vec3_dot(&reflect_dir, &view_dir), 0.f), 256);
// 	intensity = diff + 0.5f * spec;
// 	intensity = fminf(intensity, 1.0f);
// 	p_ray->pixel.color.r = (uint8_t)((p_ray->pixel.color.r * intensity));
// 	p_ray->pixel.color.g = (uint8_t)((p_ray->pixel.color.g * intensity));
// 	p_ray->pixel.color.b = (uint8_t)((p_ray->pixel.color.b * intensity));
// }

t_color compute_lighting(t_vector3 *p_point, t_vector3 *p_norm,
	t_color *p_color)
{
	t_vector3 light  = ksx_vec3_set(450.f, 300.f, -250.f);

	t_vector3 dir = ksx_vec3_sub(&light, p_point);
	dir = ksx_vec3_unit(&dir);
	*p_norm = ksx_vec3_unit(p_norm);

	// Фоновая подсветка
	float ambient = 0.2f; 

	// Диффузное освещение
	float diff = fmax(0.f, ksx_vec3_dot(p_norm, &dir));

	// Зеркальное отражение
	t_vector3 reflect_dir = ksx_vec3_reflect(&dir, p_norm);
	t_vector3 view_dir = ksx_vec3_unit(p_point); // Камера в (0,0,0)
	float spec = powf(fmax(ksx_vec3_dot(&reflect_dir, &view_dir), 0.f), 256);

	// Итоговое освещение
	float intensity = ambient + (1.0f - ambient) * diff + 0.5f * spec;
	intensity = fminf(intensity, 1.0f); // Ограничение яркости

	p_color->r = (uint8_t)((p_color->r * intensity));
	p_color->g = (uint8_t)((p_color->g * intensity));
	p_color->b = (uint8_t)((p_color->b * intensity));
	return (*p_color);
}
