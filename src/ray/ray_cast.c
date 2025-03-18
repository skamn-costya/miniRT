/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:23:15 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/19 00:02:14 by ksorokol         ###   ########.fr       */
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

void	ray_cast(t_graphics *p_grph)
{
	int32_t	xy[2];
	t_ray		ray;

	ksx_time_print();
	mlx_delete_image(p_grph->mlx, p_grph->img_ray);
	p_grph->img_ray = ksx_create_image(p_grph->mlx, TRANSPARENT);
	ray.origin = p_grph->camera.basis.o;
	xy[0] = p_grph->img_proj->width * p_grph->img_proj->height;
	xy[1] = -1;
	while (++xy[1] < xy[0])
	{
			ray = ray_generate(xy[1] % p_grph->img_proj->width, xy[1] / p_grph->img_proj->width, &p_grph->camera);
			ray_p2boxes(&p_grph->world, &ray);
			ray_p2planes(&p_grph->world, &ray);
			if (ray.p_tri || ray.p_pln)
			{
				// compute_lightings(&ray, p_grph);
				ray.pixel.color = compute_lighting(&ray.point, &ray.norm, &ray.pixel.color);
				ray.pixel.color = add_ambient_to_color(ray.pixel.color,
					p_grph->world.ambient.bright, p_grph->world.ambient.color);
				ksx_set_pixel(p_grph->img_ray, &ray.pixel);
			}
	}
	ksx_time_print();
	ksx_image_to_window(p_grph->mlx, p_grph->img_ray, 1);
}

t_ray	ray_generate(int32_t x, int32_t y, t_camera *p_camera)
{
	t_ray		ray;
	float		xy[2];
	t_vector3	v3;

	xy[0] = (2.f * (float)x / (float)WIDTH - 1.f) * p_camera->tng;
	xy[1] = (1.f - 2.f * (float)y / (float)HEIGHT) * p_camera->tng / p_camera->aspect;
	v3 = ksx_vec3_set(xy[0], xy[1], 1.0f);
	v3 = ksx_vec3_unit(&v3);
	ray.length = MAX_LEN;
	ray.min_length = MAX_LEN;
	ray.origin = p_camera->basis.o;
	ray.direction = v3;
	ray.pixel.x = x;
	ray.pixel.y = y;
	ray.pixel.color.mlx_color = TRANSPARENT;
	ray.pixel.color.a = 0xff;
	ray.norm = ksx_vec3_set(0.f, 0.f, 0.f);
	ray.p_tri = NULL;
	ray.p_pln = NULL;
	return (ray);
}
