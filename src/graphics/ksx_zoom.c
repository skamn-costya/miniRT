/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:23:13 by ksorokol          #+#    #+#             */
/*   Updated: 2024/11/01 18:08:50 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_graphics.h"
#include <math.h>

void	fdf_zoom(t_vars *vars, int d)
{
	int		idx_xy[2];
	t_fdf	*pfdf;
	int		mm[6];

	idx_xy[1] = 0;
	while (idx_xy[1] < vars->xy[1])
	{
		idx_xy[0] = 0;
		while (idx_xy[0] < vars->xy[0])
		{
			pfdf = vars->fdf[idx_xy[0]][idx_xy[1]];
			pfdf->xyz_p[0] = pfdf->xyz_p[0] * vars->zoom;
			pfdf->xyz_p[1] = pfdf->xyz_p[1] * vars->zoom;
			pfdf->xyz_p[2] = pfdf->xyz_p[2] * vars->zoom;
			idx_xy[0]++;
		}
		idx_xy[1]++;
	}
	if (vars->flags & PERSPEC)
	{
		fdf_min_nax (vars->fdf, vars->xy, mm);
		set_camera_matrix (CAMERA_A, mm[5] * MGC_NUM, mm[4], &(vars->cm));
	}
	if (d == DRAW)
		fdf_draw_image (vars);
}
