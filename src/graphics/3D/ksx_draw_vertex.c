/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_vertex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/28 17:50:18 by ksorokol         ###   ########.fr       */
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
		return ;
	ksx_set_pixel(p_image, &pixel);
}

void	ksx_draw_vertexes(t_object *p_object, mlx_image_t *p_image,
		t_graphics *p_grph)
{
	uint32_t	idx;
	uint32_t	mlx_color;

	mlx_color = OBJ_COLOR;
	if (p_object == p_grph->world.pp_obj[p_grph->obj_idx])
		mlx_color = SEL_OBJ_COLOR;
	idx = 0;
	while (idx < p_object->size_vrtx)
	{
		ksx_draw_vertex(p_object->pp_vrtx[idx], p_image,
			&p_grph->camera, mlx_color);
		idx++;
	}
}
