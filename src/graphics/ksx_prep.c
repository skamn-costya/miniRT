/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:09:32 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/31 19:23:26 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_graphics.h"
#include <math.h>

int			get_step(int mm[]);
static void	set_center(t_vars *vars, int m[]);

void	fdf_prep_p(t_vars *vars)
{
	int	mm[6];

	fdf_min_nax (vars->fdf, vars->xy, mm);
	set_center(vars, mm);
	fdf_rotation (vars->fdf, vars->xy, vars->as_xyz);
	fdf_min_nax (vars->fdf, vars->xy, mm);
	vars->zoom = get_step (mm);
	fdf_zoom (vars, NO_DRAW);
	fdf_min_nax (vars->fdf, vars->xy, mm);
	vars->as_xyz[3] = WIDTH / 2;
	vars->as_xyz[4] = HEIGHT / 2;
	fdf_draw (vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	print_statuses (vars);
}

int	get_step(int mm[])
{
	int	s[2];

	s[0] = round ((WIDTH - D_STEP) / (mm[1] - mm[0]));
	s[1] = round ((HEIGHT - D_STEP) / (mm[3] - mm[2]));
	if (s[0] < s[1])
		return (s[0]);
	return (s[1]);
}

static void	set_center(t_vars *vars, int m[])
{
	int		idx_xy[2];
	t_fdf	*pfdf;
	int		d_xyz[3];

	d_xyz[0] = m[1] / 2;
	d_xyz[1] = m[3] / 2;
	d_xyz[2] = (m[5] + m[4]) / 2;
	idx_xy[1] = 0;
	while (idx_xy[1] < vars->xy[1])
	{
		idx_xy[0] = 0;
		while (idx_xy[0] < vars->xy[0])
		{
			pfdf = vars->fdf[idx_xy[0]][idx_xy[1]];
			pfdf->xyz_p[0] -= d_xyz[0];
			pfdf->xyz_p[1] -= d_xyz[1];
			pfdf->xyz_p[2] -= d_xyz[2];
			idx_xy[0]++;
		}
		idx_xy[1]++;
	}
}
