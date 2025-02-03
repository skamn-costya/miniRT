/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:23:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/03 01:09:20 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <math.h>


// void	ksx_draw(t_vars *vars);
// static void	ksx_draw_zord(t_vars *vars);
// static void	fdf_lines(t_vars *vars, int idx_xy[]);

void	ksx_draw(t_world *p_world)
{
	t_obj		**pp_objs;
	t_obj		*p_obj;
	uint32_t	idx;

	if (!p_world->objs)
		return ;
	idx = 0;
	pp_objs = p_world->objs;
	while (pp_objs[idx])
	{
		p_obj = pp_objs[idx];
		(void) p_obj;
		idx++;
	}
}

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
