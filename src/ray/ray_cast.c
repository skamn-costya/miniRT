/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:23:15 by ksorokol          #+#    #+#             */
/*   Updated: 2025/04/01 18:32:09 by ksorokol         ###   ########.fr       */
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
#include "bvh.h"

#ifndef BONUS

void	ray_cast(t_graphics *p_grph)
{
	int32_t	xy[2];
	t_ray	ray;

	bvh_build_world(p_grph);
	printf("Ray tracing\n");
	mlx_delete_image(p_grph->mlx, p_grph->img_ray);
	p_grph->img_ray = ksx_create_image(p_grph->mlx, TRANSPARENT);
	xy[0] = p_grph->img_proj->width * p_grph->img_proj->height;
	xy[1] = -1;
	while (++xy[1] < xy[0])
	{
		ray = ray_generate(xy[1] % p_grph->img_proj->width, xy[1]
				/ p_grph->img_proj->width, &p_grph->camera);
		ray_p2boxes(&p_grph->world, &ray);
		ray_p2planes(&p_grph->world, &ray);
		if (ray.p_tri || ray.p_pln)
		{
			ray_p2lights(&p_grph->world, &ray);
			ksx_set_pixel(p_grph->img_ray, &ray.pixel);
		}
	}
	printf("Ray tracing finished\n");
	ksx_image_to_window(p_grph->mlx, p_grph->img_ray, 1);
}

#else 

void		*ksx_ray_thrd(void *p_data);

inline static void	ksx_ray_thrd_(int32_t idx[], t_thrddata *p_thrddata,
	pthread_t *p_pthrd)
{
	p_thrddata->start = idx[0] * idx[1];
	p_thrddata->finish = idx[0] * idx[1] + idx[1];
	pthread_mutex_init(&p_thrddata->mutex, NULL);
	pthread_mutex_lock(&p_thrddata->mutex);
	p_thrddata->flags |= F_TH_START;
	pthread_mutex_unlock(&p_thrddata->mutex);
	pthread_create(p_pthrd, NULL, &ksx_ray_thrd, p_thrddata);
	pthread_detach(*p_pthrd);
}

void	ray_cast(t_graphics *p_grph)
{
	int32_t		idx[2];
	t_thrddata	thrddata[THREADS];
	pthread_t	pthrd[THREADS + 1];
	t_mondata	mondata;

	ksx_time_print("BVH building");
	bvh_build_world(p_grph);
	ksx_time_print("Ray tracing start");
	ksx_ray_thrd_init(&mondata, thrddata, p_grph);
	mlx_delete_image(p_grph->mlx, p_grph->img_ray);
	p_grph->img_ray = ksx_create_image(p_grph->mlx, TRANSPARENT);
	idx[0] = -1;
	idx[1] = p_grph->img_proj->width * p_grph->img_proj->height / THREADS;
	while (++idx[0] < THREADS)
		ksx_ray_thrd_(idx, &thrddata[idx[0]], &pthrd[idx[0]]);
	pthread_create(&pthrd[THREADS], NULL, &ksx_ray_thrd_mon,
		&mondata);
	pthread_join(pthrd[THREADS], NULL);
	ksx_time_print("Ray tracing finish");
	ksx_image_to_window(p_grph->mlx, p_grph->img_ray, 1);
}

void	*ksx_ray_thrd(void *p_data)
{
	int32_t			idx;
	t_ray			ray;
	t_thrddata		*p_thrddata;

	p_thrddata = (t_thrddata *)p_data;
	idx = p_thrddata->start;
	while (idx < p_thrddata->finish)
	{
		ray = ray_generate(idx % p_thrddata->p_grph->img_proj->width, idx
				/ p_thrddata->p_grph->img_proj->width,
				&p_thrddata->p_grph->camera);
		ray_p2boxes(&p_thrddata->p_grph->world, &ray);
		ray_p2planes(&p_thrddata->p_grph->world, &ray);
		if (ray.p_tri || ray.p_pln)
		{
			ray_p2lights(&p_thrddata->p_grph->world, &ray);
			ksx_set_pixel(p_thrddata->p_grph->img_ray, &ray.pixel);
		}
		idx++;
	}
	pthread_mutex_lock(&p_thrddata->mutex);
	p_thrddata->flags |= F_TH_FINISH;
	pthread_mutex_unlock(&p_thrddata->mutex);
	return (p_data);
}

#endif

t_ray	ray_generate(int32_t x, int32_t y, t_camera *p_camera)
{
	t_ray		ray;
	float		xy[2];
	t_vector3	v3;

	xy[0] = (2.f * (float)x / (float)WIDTH - 1.f) * p_camera->tng;
	xy[1] = (1.f - 2.f * (float)y / (float)HEIGHT)
		* p_camera->tng / p_camera->aspect;
	v3 = ksx_vec3_set(xy[0], xy[1], 1.0f);
	v3 = ksx_vec3_unit(&v3);
	ray.length = MAX_LEN;
	ray.min_length = MAX_LEN;
	ray.origin = p_camera->basis.o;
	ray.direction = v3;
	ray.copy_direction = ray.direction;
	ray.pixel.x = x;
	ray.pixel.y = y;
	ray.pixel.color.mlx_color = TRANSPARENT;
	ray.norm = ksx_vec3_set(0.f, 0.f, 0.f);
	ray.p_tri = NULL;
	ray.p_pln = NULL;
	ray.p_lgt = NULL;
	return (ray);
}
