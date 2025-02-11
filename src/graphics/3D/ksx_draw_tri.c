/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_tri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 13:20:53 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include <math.h>

void	ksx_draw_tri(t_triangle *p_tri, mlx_image_t *p_img,
		t_camera *p_cam, uint8_t line)
{
	t_pixel		pixel[3];
	t_vector4	vec4;

	pixel[0].color.mlx_color = p_tri->color.mlx_color;
	pixel[1].color.mlx_color = p_tri->color.mlx_color;
	pixel[2].color.mlx_color = p_tri->color.mlx_color;
	// vec4 = ksx_vec3_vec4(p_tri->p_ver1->p_cp, 1);
	vec4 = ksx_vec3_vec4(p_tri->p_ver1->p_wp, 1);
	vec4 = ksx_m4_vec4(&p_cam->pm, &vec4);
	pixel[0].x = round(vec4.x) + WIDTH * .5f;
	pixel[0].y = round(vec4.y) + HEIGHT * .5f;
	// vec4 = ksx_vec3_vec4(p_tri->p_ver2->p_cp, 1);
	vec4 = ksx_vec3_vec4(p_tri->p_ver2->p_wp, 1);
	vec4 = ksx_m4_vec4(&p_cam->pm, &vec4);
	pixel[1].x = round(vec4.x) + WIDTH * .5f;
	pixel[1].y = round(vec4.y) + HEIGHT * .5f;
	// vec4 = ksx_vec3_vec4(p_tri->p_ver3->p_cp, 1);
	vec4 = ksx_vec3_vec4(p_tri->p_ver3->p_wp, 1);
	vec4 = ksx_m4_vec4(&p_cam->pm, &vec4);
	pixel[2].x = round(vec4.x) + WIDTH * .5f;
	pixel[2].y = round(vec4.y) + HEIGHT * .5f;
	ksx_set_pixel(p_img, &pixel[0]);
	ksx_set_pixel(p_img, &pixel[1]);
	ksx_set_pixel(p_img, &pixel[2]);
	if (line) {
		ksx_line(p_img, pixel[0], pixel[1]);
		ksx_line(p_img, pixel[1], pixel[2]);
		ksx_line(p_img, pixel[2], pixel[0]);
	}
}
