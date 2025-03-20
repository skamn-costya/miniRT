/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:10:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/20 14:13:55 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "math.h"
#include <stdio.h>

// static inline uint8_t	clamp(int32_t value)
// {
// 	if (value < 0)
// 		return (0);
// 	if (value > 255)
// 		return (255);
// 	return ((uint8_t)value);
// }

// t_color	ray_colors_blending(t_color *p_color1, t_color *p_color2, float ratio)
// {
// 	t_color	result;
// 	int32_t	rgb[3];

// 	// rgb[0] = p_color1->r + (int32_t)(p_color2->r * ratio);
// 	// rgb[1] = p_color1->g + (int32_t)(p_color2->g * ratio);
// 	// rgb[2] = p_color1->b + (int32_t)(p_color2->b * ratio);
// 	rgb[0] = (int32_t)(p_color1->r * (p_color2->r / 255.f) * ratio);
// 	rgb[1] = (int32_t)(p_color1->g * (p_color2->g / 255.f) * ratio);
// 	rgb[2] = (int32_t)(p_color1->b * (p_color2->b / 255.f) * ratio);
// 	result.r = clamp(rgb[0]);
// 	result.g = clamp(rgb[1]);
// 	result.b = clamp(rgb[2]);
// 	result.a = p_color1->a;
// 	result.material = p_color1->material;
// 	return (result);
// }

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
	// clamp_color(&result);
}

void	ray_colors_scale(t_color *p_color, float scale)
{
	p_color->ur = p_color->ur * scale;
	p_color->ug = p_color->ug * scale;
	p_color->ub = p_color->ub * scale;
	// clamp_color(&result);
}

void ray_colors_8bit(t_color *p_color)
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

	t_vector3 dir = ksx_vec3_sub(&p_ray->p_lgt->point.cp, &p_ray->point);
	dir = ksx_vec3_unit(&dir);
	p_ray->norm = ksx_vec3_unit(&p_ray->norm);

	f[0] = fmaxf(0.f, ksx_vec3_dot(&p_ray->norm, &dir));
	color[0] = p_ray->color;
	ray_colors_multiply(&color[0], &p_ray->p_lgt->color);
	ray_colors_scale(&color[0], p_ray->p_lgt->bright * p_ray->color.material.kd * f[0]);
	vec3[0] = ksx_vec3_reflect(&p_ray->direction, &p_ray->norm);
	// vec3[1] = ksx_vec3_set(0.f, 0.f, 0.f);
	// vec3[2] = ksx_vec3_sub(&vec3[1], &p_ray->point);
	// vec3[2] = ksx_vec3_unit(&vec3[2]);
	vec3[2] = ksx_vec3_unit(&p_ray->point);
	f[1] = fmaxf(0.f, ksx_vec3_dot(&vec3[0], &vec3[2]));
	f[2] = powf(f[1], p_ray->color.material.shininess);
	color[1] = p_ray->p_lgt->color;
	ray_colors_scale(&color[1], p_ray->p_lgt->bright * p_ray->color.material.ks * f[2]);
	ray_colors_add(&color[0], &color[1]);
	ray_colors_add(&p_ray->pixel.color, &color[0]);
}

// Computes the contribution of one light source at a surface point.
// - point: the position on the surface (world space)
// - normal: the normalized surface normal at the point
// - viewDir: the normalized direction from the point to the camera
// - light: pointer to the light source
// - material: pointer to the material properties of the surface
// Returns a t_color (with float channels) representing the diffuse+specular contribution.
// t_color compute_light_contribution(t_ray *p_ray
// 	// const t_vector3 *point
// 	// const t_vector3 *normal
// 	// const t_vector3 *viewDir
// 	// const t_light *light
// 	// const t_material *material
// )
// {
// 	t_color result;

// 	result.mlx_color = 0x00000000;
 
// 	// Compute light direction: from point to light position
// 	// t_vector3 L = subtract(&light->position, point);
// 	// L = normalize(&L);

// 	// Diffuse component (Lambertian):
// 	// float diff = fmaxf(dot(normal, &L), 0.0f);
// 	float diff = fmaxf(0.f, ksx_vec3_dot(&p_ray->norm, &p_ray->direction));

// 	t_color diffuse;
// 	// diffuse.r = material->kd * light->intensity * diff * light->color.r;
// 	// diffuse.g = material->kd * light->intensity * diff * light->color.g;
// 	// diffuse.b = material->kd * light->intensity * diff * light->color.b;
// 	diffuse.fr = (p_ray->pixel.color.material.kd * p_ray->p_lgt->bright * diff) * (p_ray->p_lgt->color.r / 32.f);
// 	diffuse.fg = (p_ray->pixel.color.material.kd * p_ray->p_lgt->bright * diff) * (p_ray->p_lgt->color.g / 32.f);
// 	diffuse.fb = (p_ray->pixel.color.material.kd * p_ray->p_lgt->bright * diff) * (p_ray->p_lgt->color.b / 32.f);

// 	// Specular component (Phong reflection model):
// 	t_vector3 r = ksx_vec3_reflect(&p_ray->direction, &p_ray->norm);  // R = L - 2 * dot(L, N) * N
// 	float specAngle = fmaxf(ksx_vec3_dot(&r, &p_ray->copy_direction), 0.0f);
// 	float spec = powf(specAngle, p_ray->pixel.color.material.shininess);

// 	t_color specular;
// 	// specular.r = material->ks * light->intensity * spec * light->color.r;
// 	// specular.g = material->ks * light->intensity * spec * light->color.g;
// 	// specular.b = material->ks * light->intensity * spec * light->color.b;
// 	specular.r = p_ray->pixel.color.material.ks * p_ray->p_lgt->bright * spec * (p_ray->p_lgt->color.r / 255.f);
// 	specular.g = p_ray->pixel.color.material.ks * p_ray->p_lgt->bright * spec * (p_ray->p_lgt->color.g / 255.f);
// 	specular.b = p_ray->pixel.color.material.ks * p_ray->p_lgt->bright * spec * (p_ray->p_lgt->color.b / 255.f);

// 	// Sum diffuse and specular contributions:
// 	result.fr = diffuse.fr;// + specular.fr;
// 	result.fg = diffuse.fg;// + specular.fg;
// 	result.fb = diffuse.fb;// + specular.fb;
// 	result.r = (uint8_t)fminf(p_ray->pixel.color.r * result.fr, 255);
// 	result.g = (uint8_t)fminf(p_ray->pixel.color.g * result.fg, 255);
// 	result.b = (uint8_t)fminf(p_ray->pixel.color.b * result.fb, 255);
// 	result.a = p_ray->pixel.color.a;
// 	result.material = p_ray->pixel.color.material;
// 	return result;
// }

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

// t_color compute_lighting(t_vector3 *p_point, t_vector3 *p_norm,
// 	t_color *p_color)
// {
// 	t_vector3 light  = ksx_vec3_set(450.f, 300.f, -250.f);

// 	t_vector3 dir = ksx_vec3_sub(&light, p_point);
// 	dir = ksx_vec3_unit(&dir);
// 	*p_norm = ksx_vec3_unit(p_norm);

// 	// Фоновая подсветка
// 	float ambient = 0.2f; 

// 	// Диффузное освещение
// 	float diff = fmax(0.f, ksx_vec3_dot(p_norm, &dir));

// 	// Зеркальное отражение
// 	t_vector3 reflect_dir = ksx_vec3_reflect(&dir, p_norm);
// 	t_vector3 view_dir = ksx_vec3_unit(p_point); // Камера в (0,0,0)
// 	float spec = powf(fmax(ksx_vec3_dot(&reflect_dir, &view_dir), 0.f), 256);

// 	// Итоговое освещение
// 	float intensity = ambient + (1.0f - ambient) * diff + 0.5f * spec;
// 	intensity = fminf(intensity, 1.0f); // Ограничение яркости

// 	p_color->r = (uint8_t)((p_color->r * intensity));
// 	p_color->g = (uint8_t)((p_color->g * intensity));
// 	p_color->b = (uint8_t)((p_color->b * intensity));
// 	return (*p_color);
// }
