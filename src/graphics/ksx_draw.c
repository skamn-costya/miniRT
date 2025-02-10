/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:23:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/10 14:37:28 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"
#include "ksx_rotation.h"
#include <math.h>
#include <stdio.h>

// void	ksx_draw(t_vars *vars);
// static void	ksx_draw_zord(t_vars *vars);
// static void	fdf_lines(t_vars *vars, int idx_xy[]);

void	ksx_draw(t_graphics *p_grph)
{
	t_object	**pp_object;
	t_object	*p_object;
	uint32_t	idx[3];
	t_pixel		pixel;
	t_pixel		pixel2;
	t_pixel		pixel3;

	if (!p_grph->world.pp_wobj)
		return ;
	mlx_delete_image(p_grph->mlx, p_grph->img);
	p_grph->img = ksx_create_image(p_grph->mlx);
	mlx_image_to_window(p_grph->mlx, p_grph->img, 0, 0);
	pixel.color.mlx_color = 0xffffffff;
	pixel.x= 25;
	pixel.y= 25;
	pixel2.color.mlx_color = 0xff0000ff;
	pixel2.x= WIDTH - 25;
	pixel2.y= 25;
	ksx_line (p_grph->img, pixel, pixel2);
	idx[0] = 0;
	pp_object = p_grph->world.pp_wobj;
	while (idx[0] < p_grph->world.size_wobj)
	{
		p_object = pp_object[idx[0]];
		// if(idx[0] == 0)
		// ksx_rotation_obj_y(p_object, p_object->angle.y);
		ksx_rotation_obj(p_object, p_object->angle.x, p_object->angle.y, p_object->angle.z);
		// else
		// 	ksx_rotation_obj(p_object, 0.f, 115.f, 135.f);
		// ksx_rotation_obj_x(p_object, 45.f);
		// ksx_draw_box(p_object, p_grph->img, &p_grph->camera);
		pixel.color.mlx_color = 0x88ffffff;
		pixel2.color.mlx_color = 0x88ffffff;
		pixel3.color.mlx_color = 0x88ffffff;
		idx[1] = 0;
		idx[2] = 0;
		while (idx[1] < p_object->size_otri)
		{
			if (p_object->pp_otri[idx[1]]->generation == p_object->last_gen)
			{
				idx[2]++;
				ksx_translate_tri(p_object->pp_otri[idx[1]], &p_object->center);
				ksx_draw_tri(p_object->pp_otri[idx[1]], p_grph->img, &p_grph->camera);
			}
			idx[1]++;
		}
		idx[1] = 0;
		while (idx[1] < 12)
		{
			ksx_translate_tri(&p_object->box[idx[1]], &p_object->center);
			ksx_draw_tri(&p_object->box[idx[1]], p_grph->img, &p_grph->camera);
			idx[1]++;
		}
		ksx_draw_box(p_object, p_grph->img, &p_grph->camera);
		ksx_translate_tri(&p_object->axis, &p_object->center);
		ksx_draw_axis(p_object, p_grph->img, &p_grph->camera);
		idx[0]++;
	}
}

	// point[0] = ksx_point_m4(point[0], p_grph->camera.pm);
	// point[1] = ksx_point_m4(point[1], p_grph->camera.pm);
	// point[2] = ksx_point_m4(point[2], p_grph->camera.pm);

// void	ksx_draw(t_vars *vars)
// {
// 	int	idx_xy[2];

// 	idx_xy[1] = 0;
// 	while (idx_xy[1] < vars->xy[1])
// 	{
// 		idx_xy[0] = 0;
// 		while (idx_xy[0] < vars->xy[0])
// 		{
// 			// fdf_lines (vars, idx_xy);
// 			idx_xy[0]++;
// 		}
// 		idx_xy[1]++;
// 	}
// }

// static void	ksx_draw_zord(t_vars *vars)
// {
// 	int	idx_xy[2];
// 	int	mm[6];

// 	fdf_min_nax (vars->fdf, vars->xy, mm);
// 	while (mm[4] <= mm[5])
// 	{
// 		idx_xy[1] = 0;
// 		while (idx_xy[1] < vars->xy[1])
// 		{
// 			idx_xy[0] = 0;
// 			while (idx_xy[0] < vars->xy[0])
// 			{
// 				if (round (vars->fdf[idx_xy[0]][idx_xy[1]]->xyz_p[2]) == mm[4])
// 					fdf_lines (vars, idx_xy);
// 				idx_xy[0]++;
// 			}
// 			idx_xy[1]++;
// 		}
// 		mm[4]++;
// 	}
// }

// static void	ksx_lines(t_vars *vars, int idx_xy[])
// {
// 	t_fdf	*fdf;

// 	fdf = vars->fdf[idx_xy[0]][idx_xy[1]];
// 	fdf_point (vars->img, get_point (fdf, vars->as_xyz, vars->flags));
// 	if (idx_xy[0] < vars->xy[0] - 1)
// 		fdf_line (vars->img, get_point (fdf, vars->as_xyz, vars->flags),
// 			get_point (vars->fdf[idx_xy[0] + 1][idx_xy[1]],
// 				vars->as_xyz, vars->flags));
// 	if (idx_xy[1] < vars->xy[1] - 1)
// 		fdf_line (vars->img, get_point (fdf, vars->as_xyz, vars->flags),
// 			get_point (vars->fdf[idx_xy[0]][idx_xy[1] + 1],
// 				vars->as_xyz, vars->flags));
// }
