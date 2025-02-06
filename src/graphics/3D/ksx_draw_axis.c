/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/06 16:02:50 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"

static void	ksx_draw_axis_(t_object *p_obj, t_camera *p_cam, t_vector4 *p_v4);

void	ksx_draw_axis(t_object *p_obj, mlx_image_t *p_img, t_camera *p_cam)
{
	t_pixel		pixel;
	t_vector4	v4[4];

	ksx_draw_axis_(p_obj, p_cam, v4);
	(void) pixel;
	(void) p_img;
}

static void	ksx_draw_axis_(t_object *p_obj, t_camera *p_cam, t_vector4 *p_v4)
{
	p_v4[0] = ksx_vec3_vec4(p_obj->basis.o, 1);
	p_v4[1] = ksx_vec3_vec4(p_obj->axis.p1, 1);
	p_v4[2] = ksx_vec3_vec4(p_obj->axis.p2, 1);
	p_v4[3] = ksx_vec3_vec4(p_obj->axis.p3, 1);
	p_v4[0] = ksx_vec3_vec4(p_obj->basis.o, 1);
	p_v4[0] = ksx_m4_vec4(p_cam->vm, p_v4[0]);
	p_v4[1] = ksx_m4_vec4(p_cam->vm, p_v4[1]);
	p_v4[2] = ksx_m4_vec4(p_cam->vm, p_v4[2]);
	p_v4[3] = ksx_m4_vec4(p_cam->vm, p_v4[3]);
	p_v4[0] = ksx_m4_vec4(p_cam->pm, p_v4[0]);
	p_v4[1] = ksx_m4_vec4(p_cam->pm, p_v4[1]);
	p_v4[2] = ksx_m4_vec4(p_cam->pm, p_v4[2]);
	p_v4[3] = ksx_m4_vec4(p_cam->pm, p_v4[3]);
}
