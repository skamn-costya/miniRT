/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_boxes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:23:15 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/16 13:09:43 by ksorokol         ###   ########.fr       */
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
	float		mm[2];

	ksx_time_print();
	mlx_delete_image(p_grph->mlx, p_grph->img_ray);
	p_grph->img_ray = ksx_create_image(p_grph->mlx, TRANSPARENT);
	ray.origin = p_grph->camera.basis.o;
	// xy[0] = HEIGHT * WIDTH;
	mm[0] = 999999999.f;
	mm[1] = -999999999.f;
	xy[0] = p_grph->img_proj->width * p_grph->img_proj->height;
	xy[1] = 0;
	t_vector3 light = ksx_vec3_set(450.f, 300.f, -250.f);
	while (xy[1] < xy[0])
	{
		{
			ray = ray_generate(xy[1] % p_grph->img_proj->width, xy[1] / p_grph->img_proj->width, &p_grph->camera);
			// t_ray ray1 = ray1_generate_w(xy[1] % p_grph->img_proj->width, xy[1] / p_grph->img_proj->width, &p_grph->camera);
			// (void)ray1;
			ray_check_boxes(&ray, p_grph);
			if (ray.p_tri)
			{
				if (ray.length < mm[0])
					mm[0] = ray.length;
				else if (ray.length > mm[1])
					mm[1] = ray.length;
				// applyDepthAttenuation(&ray.pixel.color, (ray.length - 500.f)/750.f, 7.f);
				// ray.pixel.color = color_bright(&ray.pixel.color, pixel_bright(&ray.norm, &light));
				compute_lighting(&ray.point, &ray.norm, &light, &ray.pixel.color);
				ksx_set_pixel(p_grph->img_ray, &ray.pixel);
			}
		}
		xy[1]++;
	}
	printf("min: %f; max: %f\n", mm[0], mm[1]);
	ksx_time_print();
	ksx_image_to_window(p_grph->mlx, p_grph->img_ray, 1);
}

void	ray_check_boxes(t_ray *p_ray, t_graphics *p_grph)
{
	t_box		**pp_box;
	int32_t		idx[3];
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
					if (p_ray->length < p_ray->min_length)
						p_ray->pixel.color.mlx_color = pp_box[idx[0]]->pp_tris[idx[1]]->color.mlx_color;// & p_grph->world.ambient.color.mlx_color;
				}
				break;
			}
		}
	}
}
/*
^^^^^^^^^^^^^^^^^^^
without break
2025-03-12 17:21:56
2025-03-12 17:23:06

with break
2025-03-12 17:24:14
2025-03-12 17:24:28
*/

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
	return (ray);
}

t_ray	ray_generate_w(int32_t x, int32_t y, t_camera *p_camera)
{
/*
	Vec3 compute_ray_direction(int i, int j, int width, int height, float fovh, Vec3 cam_pos, Vec3 cam_forward) {
    // Compute aspect ratio
    float aspect = (float)width / (float)height;

    // Compute image plane size
    float half_width = tanf((fovh * M_PI / 180.0f) / 2.0f);
    float half_height = half_width / aspect;

    // Define the world up vector
    Vec3 world_up = {0, 1, 0};

    // Compute camera basis vectors
    Vec3 forward = normalize(cam_forward);
    Vec3 right = normalize(cross(world_up, forward));
    Vec3 up = cross(forward, right); // Ensure an orthogonal up vector

    // Convert pixel coordinates to [-1, 1] range
    float x = ((2.0f * (i + 0.5f) / width) - 1.0f) * half_width;
    float y = (1.0f - (2.0f * (j + 0.5f) / height)) * half_height;

    // Compute ray direction
    Vec3 direction = normalize(add(add(scale(right, x), scale(up, y)), forward));

    return direction;
}
*/
	t_ray		ray;
	float		xy[2];
	t_vector3	v3[2];

	// Added this - it won't compile - used values before initialization 
	ray.pixel.x = 0; 
	ray.pixel.y = 0;
	xy[0] = ((2.0f * (ray.pixel.x + 0.5f) / WIDTH) - 1.0f) * p_camera->half_width;
  xy[1] = (1.0f - (2.0f * (ray.pixel.y + 0.5f) / HEIGHT)) * p_camera->half_height;
	v3[0] = ksx_vec3_smulti(&p_camera->basis.i, xy[0]);
	v3[1] = ksx_vec3_smulti(&p_camera->basis.j, xy[1]);
	v3[0] = ksx_vec3_add(&v3[0], &v3[1]);
	v3[0] = ksx_vec3_add(&v3[0], &p_camera->basis.k);
	ray.direction = ksx_vec3_unit(&v3[0]);
	
	ray.length = MAX_LEN;
	ray.origin = p_camera->basis.o;
	ray.pixel.x = x;
	ray.pixel.y = y;
	ray.pixel.color.mlx_color = TRANSPARENT;
	ray.pixel.color.a = 0xff;
	ray.norm = ksx_vec3_set(0.f, 0.f, 0.f);
	ray.p_tri = NULL;
	return (ray);
}

t_color compute_lighting(t_vector3 *p_point, t_vector3 *p_norm,
	t_vector3 *p_light, t_color *p_color)
{
	t_vector3 dir = ksx_vec3_sub(p_light, p_point);
	dir = ksx_vec3_unit(&dir);
	*p_norm = ksx_vec3_unit(p_norm);

	// Фоновая подсветка
	float ambient = 0.2f; 

	// Диффузное освещение
	float diff = fmax(0.f, ksx_vec3_dot(p_norm, &dir));

	// Зеркальное отражение
	t_vector3 reflect_dir = ksx_vec3_reflect(&dir, p_norm);
	t_vector3 view_dir = ksx_vec3_unit(p_point); // Камера в (0,0,0)
	float spec = powf(fmax(ksx_vec3_dot(&reflect_dir, &view_dir), 0.f), 128);

	// Итоговое освещение
	float intensity = ambient + (1.0f - ambient) * diff + 0.5f * spec;
	intensity = fminf(intensity, 1.0f); // Ограничение яркости

	p_color->r = (uint8_t)((p_color->r * intensity));
	p_color->g = (uint8_t)((p_color->g * intensity));
	p_color->b = (uint8_t)((p_color->b * intensity));
	return (*p_color);
}


t_color compute_lighting_my(t_vector3 *p_point, t_vector3 *p_norm,
	t_vector3 *p_light, t_color *p_color)
{
	t_vector3 dir = ksx_vec3_sub(p_light, p_point);
	dir = ksx_vec3_unit(&dir);
	float intensity = ksx_vec3_dot(p_norm, &dir);
	intensity = fmax(0.f, intensity);
	p_color->r = (uint8_t)((p_color->r * intensity));
	p_color->g = (uint8_t)((p_color->g * intensity));
	p_color->b = (uint8_t)((p_color->b * intensity));
	return (*p_color);
}
