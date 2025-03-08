/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_boxes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:23:15 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/08 19:28:58 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ray.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_3D.h"
#include "ksx_vec3_math.h"
#include <stdio.h>
#include <math.h>

void	ray_cast_boxes(t_graphics *p_grph)
{
	uint32_t	xy[2];
	t_ray		ray;
	mlx_image_t *p_img = ksx_create_image(p_grph->mlx);
	float		mm[2];

	ray.origin = p_grph->camera.basis.o;
	// xy[0] = HEIGHT * WIDTH;
	mm[0] = 999999999.f;
	mm[1] = -999999999.f;
	xy[0] = p_grph->img->width * p_grph->img->height;
	xy[1] = 0;
	while (xy[1] < xy[0])
	{
		{
			ray = ray_generate(xy[1] % p_grph->img->width, xy[1] / p_grph->img->width, &p_grph->camera);
			ray_check_boxes(&ray, p_grph);
			if (ray.length != MAX_LEN)
			{
				if (ray.length < mm[0])
					mm[0] = ray.length;
				else if (ray.length > mm[1])
					mm[1] = ray.length;
				applyDepthAttenuation(&ray.pixel.color, (ray.length - 500.f)/750.f, 7.f);
				// compute_lighting(&ray.point, &ray.norm, &ray.direction, &ray.pixel.color); // segmentation fault (NO norms ...)
				ksx_set_pixel(p_img, &ray.pixel);
			}
		}
		xy[1]++;
	}
	// mlx_delete_image(p_grph->mlx, p_grph->img);
	// p_grph->img = p_img;
	printf("min: %f; max: %f\n", mm[0], mm[1]);
	mlx_image_to_window(p_grph->mlx, p_img, 0, 0);
}

void	ray_check_boxes(t_ray *p_ray, t_graphics *p_grph)
{
	t_box		**pp_box;
	uint32_t	idx[3];
	t_vector3	v3;

	pp_box = p_grph->world.pp_box;
	idx[0] = -1;
	while (++idx[0] < p_grph->world.size_box)
	{
		idx[2] = -1;
		while (++idx[2] < 12)
		{
			v3 = triangle_intersection(&pp_box[idx[0]]->tris[idx[2]], p_ray);
			if (p_ray->length != MAX_LEN)
			{
				p_ray->length = MAX_LEN;
				idx[1] = -1;
				while (pp_box[idx[0]]->pp_tris[++idx[1]])
				{
					v3 = triangle_intersection(pp_box[idx[0]]->pp_tris[idx[1]], p_ray);
					(void)v3;
					if (p_ray->length != MAX_LEN)
						p_ray->pixel.color.mlx_color = 0x84FFFFFF;// & p_grph->world.ambient.color.mlx_color;
				}
			}
		}
	}
}

t_ray	ray_generate(int32_t x, int32_t y, t_camera *p_camera)
{
	t_ray		ray;
	float		xy[2];
	t_vector3	v3;

	// Преобразование экранных координат в NDC (-1 до 1)
	xy[0] = (2.f * (float)x / (float)WIDTH - 1.f) * p_camera->tng;
	xy[1] = (1.f - 2.f * (float)y / (float)HEIGHT) * p_camera->tng / p_camera->aspect;
	// Направление луча в пространстве камеры
	v3 = ksx_vec3_set(xy[0], xy[1], 1.0f);
	v3 = ksx_vec3_unit(&v3);
	ray.length = MAX_LEN;
	ray.origin = p_camera->basis.o;
	ray.direction = v3;
	ray.pixel.x = x;
	ray.pixel.y = y;
	ray.pixel.color.mlx_color = 0x00000000;
	// Преобразуем в мировые координаты
	// ksx_transform(&v3, &p_camera->ivm, &ray.direction);
	return (ray);
}

t_color compute_lighting(t_vector3 *p_point, t_vector3 *p_norm,
	t_vector3 *p_light, t_color *p_color)
{
	// Направление к источнику света (нормализованное)
	t_vector3 dir = ksx_vec3_sub(p_light, p_point);
	dir = ksx_vec3_unit(&dir);
	// Вычисление коэффициента освещенности (Lambertian shading)
	float intensity = ksx_vec3_dot(p_norm, &dir);
	intensity = fmax(0.f, intensity);
	p_color->r = (unsigned char)(p_color->r * intensity);
	p_color->g = (unsigned char)(p_color->g * intensity);
	p_color->b = (unsigned char)(p_color->b * intensity);
	return (*p_color);
}
