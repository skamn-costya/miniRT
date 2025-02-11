/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 23:01:48 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"
#include <math.h>

static void	ksx_draw_axis_(t_object *p_object,
				t_camera *p_camera, t_vector4 *p_v4);

void	ksx_draw_axis(t_object *p_object, mlx_image_t *p_img, t_camera *p_cam)
{
	t_pixel		pixel[2];
	t_vector4	v4[4];

	ksx_draw_axis_(p_object, p_cam, v4);
	pixel[0].x = roundf(v4[0].x) + WIDTH * .5f;
	pixel[0].y = roundf(v4[0].y) + HEIGHT * .5f;
	pixel[0].color.mlx_color = 0xff0000ff;
	pixel[1].x = roundf(v4[1].x) + WIDTH * .5f;
	pixel[1].y = roundf(v4[1].y) + HEIGHT * .5f;
	pixel[1].color.mlx_color = pixel[0].color.mlx_color;
	ksx_line(p_img, pixel[0], pixel[1]);
	pixel[0].color.mlx_color = 0xff00ff00;
	pixel[1].x = roundf(v4[2].x) + WIDTH * .5f;
	pixel[1].y = roundf(v4[2].y) + HEIGHT * .5f;
	pixel[1].color.mlx_color = pixel[0].color.mlx_color;
	ksx_line(p_img, pixel[0], pixel[1]);
	pixel[0].color.mlx_color = 0xffff0000;
	pixel[1].x = roundf(v4[3].x) + WIDTH * .5f;
	pixel[1].y = roundf(v4[3].y) + HEIGHT * .5f;
	pixel[1].color.mlx_color = pixel[0].color.mlx_color;
	ksx_line(p_img, pixel[0], pixel[1]);
	(void) p_img;
}

static void	ksx_draw_axis_(t_object *p_object,
				t_camera *p_camera, t_vector4 *p_v4)
{
	p_v4[0] = ksx_vec3_vec4(&p_object->c_center, 1);
	p_v4[1] = ksx_vec3_vec4(&p_object->axis.p_ver1->p_cp, 1);
	p_v4[2] = ksx_vec3_vec4(&p_object->axis.p_ver2->p_cp, 1);
	p_v4[3] = ksx_vec3_vec4(&p_object->axis.p_ver3->p_cp, 1);
	p_v4[0] = ksx_m4_vec4(&p_camera->pm, &p_v4[0]);
	p_v4[1] = ksx_m4_vec4(&p_camera->pm, &p_v4[1]);
	p_v4[2] = ksx_m4_vec4(&p_camera->pm, &p_v4[2]);
	p_v4[3] = ksx_m4_vec4(&p_camera->pm, &p_v4[3]);
}
