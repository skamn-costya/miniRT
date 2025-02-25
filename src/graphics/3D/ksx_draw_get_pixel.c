/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_get_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/25 12:23:15 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
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
	return (pixel);
}
