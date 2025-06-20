/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:23:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/28 17:01:22 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"
#include "ksx_object.h"
#include "ksx_basis.h"
#include "ksx_camera.h"
#include <math.h>
#include <stdio.h>

void	ksx_draw(t_graphics *p_grph)
{
	mlx_image_t	*p_img;
	t_object	**pp_object;
	t_object	*p_object;
	int32_t		idx;

	ksx_change(p_grph);
	p_img = ksx_create_image(p_grph->mlx, TRANSPARENT);
	pp_object = p_grph->world.pp_obj;
	idx = 0;
	while (idx < p_grph->world.size_obj)
	{
		p_object = pp_object[idx];
		if (p_grph->camera.flags & DRAW_OBJ && p_object->flags & DRAW_OBJ)
			ksx_draw_obj(p_object, p_img, p_grph);
		if (p_grph->camera.flags & DRAW_AXIS && p_object->flags & DRAW_AXIS)
			ksx_draw_axis (p_object, p_img, &p_grph->camera);
		if (p_grph->camera.flags & DRAW_BOX && p_object->flags & DRAW_BOX)
			ksx_draw_box (p_object, p_img, &p_grph->camera);
		if (p_grph->camera.flags & DRAW_NORM && p_object->flags & DRAW_NORM)
			ksx_draw_norms(p_object, p_img, &p_grph->camera);
		idx++;
	}
	mlx_delete_image(p_grph->mlx, p_grph->img_proj);
	p_grph->img_proj = p_img;
	ksx_image_to_window(p_grph->mlx, p_grph->img_proj, 2);
}
