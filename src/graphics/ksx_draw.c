/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:23:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/04 15:23:17 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>

// void	ksx_draw(t_vars *vars);
// static void	ksx_draw_zord(t_vars *vars);
// static void	fdf_lines(t_vars *vars, int idx_xy[]);

void	ksx_draw(t_graphics *p_grph)
{
	t_obj		**pp_obj;
	t_obj		*p_obj;
	uint32_t	idx[2];
	t_pixel		pixel;

	if (!p_grph->world.pp_wobj)
		return ;
	pixel.color.mlx_color = 0xffffffff;
	idx[0] = 0;
	pp_obj = p_grph->world.pp_wobj;
	while (idx[0] < p_grph->world.size_wobj)
	{
		p_obj = pp_obj[idx[0]];
		idx[1] = 0;
		while (idx[1] < p_obj->size_otri)
		{
			// p_grph->camera
			p_obj->pp_otri[idx[1]]->c_p1 =
				ksx_point_m4(p_obj->pp_otri[idx[1]]->w_p1, p_grph->camera.pm);
			printf("w_p1: (%f, %f, %f); c_p1: (%f, %f, %f);\n",
				p_obj->pp_otri[idx[1]]->w_p1.x,
				p_obj->pp_otri[idx[1]]->w_p1.y,
				p_obj->pp_otri[idx[1]]->w_p1.z,
				p_obj->pp_otri[idx[1]]->c_p1.x,
				p_obj->pp_otri[idx[1]]->c_p1.x,
				p_obj->pp_otri[idx[1]]->c_p1.x);
			p_obj->pp_otri[idx[1]]->c_p2 =
				ksx_point_m4(p_obj->pp_otri[idx[1]]->w_p2, p_grph->camera.pm);
			printf("w_p2: (%f, %f, %f); c_p2: (%f, %f, %f);\n",
				p_obj->pp_otri[idx[1]]->w_p2.x,
				p_obj->pp_otri[idx[1]]->w_p2.y,
				p_obj->pp_otri[idx[1]]->w_p2.z,
				p_obj->pp_otri[idx[1]]->c_p2.x,
				p_obj->pp_otri[idx[1]]->c_p2.x,
				p_obj->pp_otri[idx[1]]->c_p2.x);
			p_obj->pp_otri[idx[1]]->c_p3 =
				ksx_point_m4(p_obj->pp_otri[idx[1]]->w_p3, p_grph->camera.pm);
			printf("w_p3: (%f, %f, %f); c_p3: (%f, %f, %f);\n",
				p_obj->pp_otri[idx[1]]->w_p3.x,
				p_obj->pp_otri[idx[1]]->w_p3.y,
				p_obj->pp_otri[idx[1]]->w_p3.z,
				p_obj->pp_otri[idx[1]]->c_p3.x,
				p_obj->pp_otri[idx[1]]->c_p3.x,
				p_obj->pp_otri[idx[1]]->c_p3.x);			
			pixel.x = roundf(p_obj->pp_otri[idx[1]]->w_p1.x) + WIDTH / 2;
			pixel.y = roundf(p_obj->pp_otri[idx[1]]->w_p1.y) + HEIGHT / 2;
			printf("pixel: (%lu, %lu);\n", pixel.x, pixel.y);
			ksx_set_pixel(p_grph->img, pixel);
			pixel.x = roundf(p_obj->pp_otri[idx[1]]->w_p2.x) + WIDTH / 2;
			pixel.y = roundf(p_obj->pp_otri[idx[1]]->w_p2.y) + HEIGHT / 2;
			printf("pixel: (%lu, %lu);\n", pixel.x, pixel.y);
			ksx_set_pixel(p_grph->img, pixel);
			pixel.x = roundf(p_obj->pp_otri[idx[1]]->w_p3.x) + WIDTH / 2;
			pixel.y = roundf(p_obj->pp_otri[idx[1]]->w_p3.y) + HEIGHT / 2;
			printf("pixel: (%lu, %lu);\n", pixel.x, pixel.y);
			ksx_set_pixel(p_grph->img, pixel);
			idx[1]++;
		}
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
