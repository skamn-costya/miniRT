/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:09:32 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 19:26:41 by ksorokol         ###   ########.fr       */
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
	t_pixel		p1, p2, pc;
	t_vector3	point;
	t_vector3	vector;

	p_grph = (t_graphics *)p_prep;
	point.x = -100.f;
	point.y = -100.f;
	point.z = 200.f;
	vector = point;
	p_grph->camera = ksx_create_camera(point, vector, 70.f);
	ksx_set_camera_pm(&p_grph->camera, 0.1f, 100.f);
	point = ksx_point_m44(point, p_grph->camera.pm);

	p_grph->img = ksx_create_image(p_grph->mlx);
	if (!p_grph->img)
		return (FALSE);
	p1.x = 25;
	p1.y = 25;
	p1.color.mlx_color = 0xffffffff;
	p2.x = 125;
	p2.y = 350;
	p2.color.mlx_color = 0xff00ff00;
	ksx_line(p_grph->img, p1, p2);
	pc.x = 50;
	pc.y = 50;
	pc.color.mlx_color = 0xff0000ff;
	ksx_circle(p_grph->img, pc, 35);
	
	if (mlx_image_to_window(p_grph->mlx, p_grph->img, 0, 0) < 0)
        return (printf("Image to window failed!\n"), FALSE);
	return (TRUE);
}
