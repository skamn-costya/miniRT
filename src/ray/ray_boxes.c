/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_boxes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:23:15 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/07 19:21:16 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ray.h"
#include "ksx_utils.h"
#include "ksx_3D.h"
#include "ksx_vec3_math.h"
#include <stdio.h>
#include <math.h>

void	ray_cast_boxes(t_graphics *p_grph)
{
	uint32_t	xy[2];
	t_ray		ray;
	// mlx_image_t *p_img = ksx_create_image(p_grph->mlx);

	ray.origin = p_grph->camera.basis.o;
	xy[1] = 0;
	while (xy[1] < HEIGHT)
	{
		xy[0] = 0;
		while (xy[0] < WIDTH)
		{
			ray.direction = ksx_vec3_set((float)xy[0] + p_grph->camera.left, (float)xy[1] + p_grph->camera.bottom, p_grph->camera.near);
			ray.direction = ksx_vec3_unit(&ray.direction);
			// printf("RAY DIR: [%f, %f, %f]\n", ray.direction.x, ray.direction.y, ray.direction.z);
			ray.length = 1e30f;
			ray.pixel.color.mlx_color = 0x00000000;
			ray.pixel.x = xy[0];
			ray.pixel.y = xy[1];
			ray.pixel.y = 1;
			ray.pixel.w = 1;
			ray_check_boxes(&ray, p_grph->world.pp_box, &p_grph->camera);
			if (ray.pixel.color.mlx_color != 0x00000000)
				ksx_set_pixel(p_grph->img, &ray.pixel);
			xy[0]++;
			// if (ray.length >= 1e30f)
			// 	continue ;
			// t_pixel pix = ksx_draw_get_pixel(&grph->camera, &pixelPos, 0xFFFFFFFF);
			// ksx_set_pixel(p_img, &pix);
		}
		xy[1]++;
	}
	// mlx_delete_image(p_grph->mlx, p_grph->img);
	// p_grph->img = p_img;
	// mlx_image_to_window(p_grph->mlx, p_grph->img, 0, 0);
	printf("TRI: finish\n");
}

void	ray_check_boxes(t_ray *p_ray, t_box **pp_box, t_camera *p_camera)
{
	uint16_t	idx[2];
	t_vector3	v3;

	idx[0] = 0;
	while (pp_box && pp_box[idx[0]])
	{
		idx[1] = 0;
		while (pp_box[idx[0]]->pp_tris[idx[1]])
		{
			// t_triangle *p_tri = pp_box[idx[0]]->pp_tris[idx[1]];
			// triangle_intersection1(pp_box[idx[0]]->pp_tris[idx[1]], p_ray);
			// intersect_tri(p_ray, *p_tri);
			// if (p_ray->length < 1e30f)
			// {
			// 	printf("TRI[%p]: touch len = %f\n", pp_box[idx[0]]->pp_tris[idx[1]], p_ray->length);
			// 	printf("P0: [%f, %f, %f]\n", p_tri->p_ver1->cp.x, p_tri->p_ver1->cp.y, p_tri->p_ver1->cp.z);
			// 	printf("P1: [%f, %f, %f]\n", p_tri->p_ver2->cp.x, p_tri->p_ver2->cp.y, p_tri->p_ver2->cp.z);
			// 	printf("P2: [%f, %f, %f]\n", p_tri->p_ver3->cp.x, p_tri->p_ver3->cp.y, p_tri->p_ver3->cp.z);
			// }
			v3 = triangle_intersection2(pp_box[idx[0]]->pp_tris[idx[1]], p_ray);
			if (ksx_vec3_mag(&v3) != 0)
			{
				// printf("TRI: pixel [%ld, %ld]\n", p_ray->pixel.x, p_ray->pixel.y);
				// printf("TRI[%p]: touch in %f, %f, %f\n", pp_box[idx[0]]->pp_tris[idx[1]], v3.x, v3.y, v3.z);
				// p_ray->pixel = ksx_draw_get_pixel(p_camere, &v3, 0xFFFFFFFF);
				p_ray->pixel.x = round(v3.x) + p_camera->right;
				p_ray->pixel.y = round(v3.y) + p_camera->top;
				p_ray->pixel.color.mlx_color = 0x84848484;
			}
			idx[1]++;
		}	
		idx[0]++;
	}
}
