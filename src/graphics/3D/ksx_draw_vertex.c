/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_vertex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/04 00:52:03 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"
#include <math.h>
#include <stdio.h>

void	ksx_draw_vertex(t_vertex *p_vertex, mlx_image_t *p_image,
		t_camera *p_camera, uint32_t mlx_color)
{
	t_pixel		pixel;

	pixel = ksx_draw_get_pixel(p_camera, &p_vertex->cp, mlx_color);
	if (pixel.w <= 0 || pixel.z <= 0 || pixel.x < 0 || pixel.y < 0
			|| pixel.x >= p_image->width || pixel.y >= p_image->height)
		return ((void) printf ("NO vertex\n"));
	ksx_set_pixel(p_image, &pixel);
}

void	ksx_draw_vertexes(t_object *p_object, mlx_image_t *p_image,
		t_graphics *p_grph)
{
	uint32_t	idx;
	uint32_t 	mlx_color;

	mlx_color = 0xffffffff;
	if (p_object == p_grph->world.pp_obj[p_grph->obj_idx])
		mlx_color = 0xffff0000;
	idx = 0;
	while (idx < p_object->size_vrtx)
	{
		// if (!idx)
		// 	printf("%p: [%f, %f, %f]\n", p_object->pp_vrtx[idx],
		// 		p_object->pp_vrtx[idx]->cp.x,
		// 		p_object->pp_vrtx[idx]->cp.y,
		// 		p_object->pp_vrtx[idx]->cp.z);
		ksx_draw_vertex(p_object->pp_vrtx[idx], p_image,
			&p_grph->camera, mlx_color);
		idx++;
	}
}
