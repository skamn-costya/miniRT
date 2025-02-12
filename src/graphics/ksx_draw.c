/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:23:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/12 22:55:38 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"
#include "ksx_object.h"
#include "ksx_camera.h"
#include <math.h>
#include <stdio.h>

// void	ksx_draw(t_vars *vars);
// static void	ksx_draw_zord(t_vars *vars);
// static void	fdf_lines(t_vars *vars, int idx_xy[]);

void	ksx_draw(t_graphics *p_grph)
{
	mlx_image_t	*p_img;
	t_object	**pp_object;
	t_object	*p_object;
	uint32_t	idx;

	if (!p_grph->world.pp_wobj)
		return ;
	
	p_img = ksx_create_image(p_grph->mlx);
	pp_object = p_grph->world.pp_wobj;
	idx = 0;
	while (idx < p_grph->world.size_wobj)
	{
		p_object = pp_object[idx];
		// ksx_rotation_obj(p_object, p_object->angle.x, p_object->angle.y, p_object->angle.z);
		ksx_translate_obj (p_object);
		ksx_camera_obj_vm (p_object, &p_grph->camera.vm);
		ksx_draw_obj(p_object, p_img, &p_grph->camera);
		ksx_draw_axis (p_object, p_img, &p_grph->camera);
		ksx_draw_box (p_object, p_img, &p_grph->camera);
		idx++;
	}
	mlx_delete_image(p_grph->mlx, p_grph->img);
	p_grph->img = p_img;
	mlx_image_to_window(p_grph->mlx, p_grph->img, 0, 0);
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
