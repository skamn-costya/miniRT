/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:09:32 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/02 14:18:27 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_camera.h"
#include <math.h>
#include <stdio.h>

int	ksx_prep(void *p_prep)
{
	t_graphics	*p_grph;
	t_pixel		p1, p2;
	t_vector3	point[3];
	t_vector3	vector;

	p_grph = (t_graphics *)p_prep;
	p_grph->img = ksx_create_image(p_grph->mlx);
	if (!p_grph->img)
		return (FALSE);
	vector.x = 0.f;
	vector.y = 0.f;
	vector.z = -500.f;
	p_grph->camera = ksx_create_camera(vector, vector, 70.f);
	ksx_set_camera_pm(&p_grph->camera, 550.f, 1000.f);
	point[0].x = 100.f;
	point[0].y = 100.f;
	point[0].z = 0.f;
	point[1].x = 200.f;
	point[1].y = 200.f;
	point[1].z = 550.f;
	point[2].x = 200.f;
	point[2].y = -100.f;
	point[2].z = 0.f;
	point[0] = ksx_point_m44(point[0], p_grph->camera.pm);
	point[1] = ksx_point_m44(point[1], p_grph->camera.pm);
	point[2] = ksx_point_m44(point[2], p_grph->camera.pm);
	p1.color.mlx_color = 0xff0000ff;
	p2.color.mlx_color = 0xff0000ff;
	p1.x = round (400.f + point[0].x);
	p1.y = round (300.f + point[0].y);
	p2.x = round (400.f + point[1].x);
	p2.y = round (300.f + point[1].y);
	ksx_line(p_grph->img, p1, p2);
	p1.x = round (400.f + point[1].x);
	p1.y = round (300.f + point[1].y);
	p2.x = round (400.f + point[2].x);
	p2.y = round (300.f + point[2].y);
	ksx_line(p_grph->img, p1, p2);
	p1.x = round (400.f + point[2].x);
	p1.y = round (300.f + point[2].y);
	p2.x = round (400.f + point[0].x);
	p2.y = round (300.f + point[0].y);
	ksx_line(p_grph->img, p1, p2);
	
	if (mlx_image_to_window(p_grph->mlx, p_grph->img, 0, 0) < 0)
        return (printf("Image to window failed!\n"), FALSE);
	return (TRUE);
}
