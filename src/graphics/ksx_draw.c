/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:23:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/19 20:04:17 by ksorokol         ###   ########.fr       */
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
	uint32_t	idx;

	if (!p_grph->world.pp_wobj)
		return ;
	if (p_grph->camera.flags & CHANGE)
	{
		ksx_camera_set_vm(&p_grph->camera);
		p_grph->camera.flags ^= CHANGE;
	}
	p_img = ksx_create_image(p_grph->mlx);
	pp_object = p_grph->world.pp_wobj;
	idx = 0;
	while (idx < p_grph->world.size_wobj)
	{
		p_object = pp_object[idx];
		ksx_translate_obj (p_object);
		ksx_camera_obj_vm (p_object, &p_grph->camera.vm);
		ksx_draw_obj(p_object, p_img, &p_grph->camera);
		// if (idx == 0)
		// 	printf("z -> %f\n",	p_object->basis.c_k.z);
		ksx_draw_axis (p_object, p_img, &p_grph->camera);
		ksx_draw_box (p_object, p_img, &p_grph->camera);
		idx++;
	}
	mlx_delete_image(p_grph->mlx, p_grph->img);
	p_grph->img = p_img;
	mlx_image_to_window(p_grph->mlx, p_grph->img, 0, 0);
}
