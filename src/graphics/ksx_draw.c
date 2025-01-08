/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:23:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/06 23:03:23 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <math.h>

static void	ksx_draw(t_vars *vars);
static void	ksx_draw_zord(t_vars *vars);
static void	fdf_lines(t_vars *vars, int idx_xy[]);

void	ksx_draw(t_vars *vars)
{
	if (vars->flags & PERSPEC)
		impl_matrix2arr (vars->xy, vars->fdf, vars->cm);
	if (vars->flags & Z_ORD)
		ksx_draw_zord (vars);
	else
		ksx_draw(vars);
	print_statuses (vars);
}

static void	ksx_draw(t_vars *vars)
{
	int	idx_xy[2];

	idx_xy[1] = 0;
	while (idx_xy[1] < vars->xy[1])
	{
		idx_xy[0] = 0;
		while (idx_xy[0] < vars->xy[0])
		{
			fdf_lines (vars, idx_xy);
			idx_xy[0]++;
		}
		idx_xy[1]++;
	}
}

static void	ksx_draw_zord(t_vars *vars)
{
	int	idx_xy[2];
	int	mm[6];

	fdf_min_nax (vars->fdf, vars->xy, mm);
	while (mm[4] <= mm[5])
	{
		idx_xy[1] = 0;
		while (idx_xy[1] < vars->xy[1])
		{
			idx_xy[0] = 0;
			while (idx_xy[0] < vars->xy[0])
			{
				if (round (vars->fdf[idx_xy[0]][idx_xy[1]]->xyz_p[2]) == mm[4])
					fdf_lines (vars, idx_xy);
				idx_xy[0]++;
			}
			idx_xy[1]++;
		}
		mm[4]++;
	}
}

static void	ksx_lines(t_vars *vars, int idx_xy[])
{
	t_fdf	*fdf;

	fdf = vars->fdf[idx_xy[0]][idx_xy[1]];
	fdf_point (vars->img, get_point (fdf, vars->as_xyz, vars->flags));
	if (idx_xy[0] < vars->xy[0] - 1)
		fdf_line (vars->img, get_point (fdf, vars->as_xyz, vars->flags),
			get_point (vars->fdf[idx_xy[0] + 1][idx_xy[1]],
				vars->as_xyz, vars->flags));
	if (idx_xy[1] < vars->xy[1] - 1)
		fdf_line (vars->img, get_point (fdf, vars->as_xyz, vars->flags),
			get_point (vars->fdf[idx_xy[0]][idx_xy[1] + 1],
				vars->as_xyz, vars->flags));
}
