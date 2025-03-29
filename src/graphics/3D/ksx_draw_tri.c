/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_tri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/28 17:33:43 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"
#include <math.h>

void	ksx_draw_tri(t_triangle *p_tri, mlx_image_t *p_image,
		t_camera *p_camera, uint32_t mlx_color)
{
	t_pixel		pixel[3];

	pixel[0] = ksx_draw_get_pixel(p_camera, &p_tri->p_ver1->cp, mlx_color);
	pixel[1] = ksx_draw_get_pixel(p_camera, &p_tri->p_ver2->cp, mlx_color);
	pixel[2] = ksx_draw_get_pixel(p_camera, &p_tri->p_ver3->cp, mlx_color);
	ksx_line(p_image, &pixel[0], &pixel[1]);
	ksx_line(p_image, &pixel[1], &pixel[2]);
	ksx_line(p_image, &pixel[2], &pixel[0]);
}
