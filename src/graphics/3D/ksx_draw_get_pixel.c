/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_get_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/28 10:26:03 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include <stdio.h>
#include <math.h>

t_pixel	ksx_draw_get_pixel(t_camera *p_camera,
		t_vector3 *p_point, uint32_t color)
{
	t_pixel		pixel;
	t_vector4	vec4;

	pixel.color.mlx_color = color;
	vec4 = ksx_vec3_vec4(p_point, 1);
	vec4 = ksx_m4_vec4(&p_camera->pm, &vec4);
	pixel.x = round(vec4.x / vec4.w) + p_camera->right;
	pixel.y = round(vec4.y / vec4.w) + p_camera->top;
	pixel.z = p_point->z;
	pixel.w = vec4.w;
	if (pixel.w <= 0)
		printf("x = %ld;  y= %ld; z = %f; w = %f\n", pixel.x, pixel.y, pixel.z, pixel.w);
	return (pixel);
}
