/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/19 20:10:25 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"
#include <math.h>

void	ksx_draw_axis(t_object *p_object,
		mlx_image_t *p_image, t_camera *p_camera)
{
	t_pixel		pixel[2];

	pixel[0] = ksx_draw_get_pixel(p_camera, &p_object->basis.w_o, 0xff0000ff);
	pixel[1] = ksx_draw_get_pixel(p_camera, &p_object->w_axis[X].p_cp, 0xff0000ff);
	ksx_line(p_image, pixel[0], pixel[1]);
	pixel[0].color.mlx_color = 0xff00ff00;
	pixel[1] = ksx_draw_get_pixel(p_camera, &p_object->w_axis[Y].p_cp, 0xff00ff00);
	ksx_line(p_image, pixel[0], pixel[1]);
	pixel[0].color.mlx_color = 0xffff0000;
	pixel[1] = ksx_draw_get_pixel(p_camera, &p_object->w_axis[Z].p_cp, 0xffff0000);
	ksx_line(p_image, pixel[0], pixel[1]);
}
