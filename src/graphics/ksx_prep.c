/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:09:32 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 17:07:44 by ksorokol         ###   ########.fr       */
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
	t_point		point;
	t_vector	vector;

	p_grph = (t_graphics *)p_prep;
	point.x = 400;
	point.y = 300;
	point.z = 200;
	vector.dir = point;
	p_grph->camera = create_camera(point, vector, 70.0f);
	point = ksx_point_m44(point, p_grph->camera.pm);

	p_grph->img = create_new_image(p_grph->mlx);
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
