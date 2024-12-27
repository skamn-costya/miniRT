/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2024/12/26 17:43:48 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <math.h>

static void	fdf_rotation_(t_obj *obj, float r[]);

void	fdf_rotation(t_obj ***obj, int xy[], int a[])
{
	int		idx_xy[2];
	float	r[3];

	r[0] = (a[0] * PI) / 180;
	r[1] = (a[1] * PI) / 180;
	r[2] = (a[2] * PI) / 180;
	idx_xy[1] = 0;
	while (idx_xy[1] < xy[1])
	{
		idx_xy[0] = 0;
		while (idx_xy[0] < xy[0])
		{
			fdf_rotation_ (obj[idx_xy[0]][idx_xy[1]], r);
			idx_xy[0]++;
		}
		idx_xy[1]++;
	}
}

static void	fdf_rotation_(t_obj *obj, float r[])
{
	float	xyz[3];
	float	d[3][3];

	xyz[0] = obj->xyz_p[0];
	xyz[1] = obj->xyz_p[1];
	xyz[2] = obj->xyz_p[2];
	d[0][0] = cos (r[1]) * cos (r[2]);
	d[0][1] = - (sin (r[2]) * cos (r[1]));
	d[0][2] = sin (r[1]);
	d[1][0] = (sin (r[0]) * sin (r[1]) * cos (r[2]))
		+ (sin (r[2]) * cos (r[0]));
	d[1][1] = - (sin (r[0]) * sin (r[1]) * sin (r[2]))
		+ (cos (r[0]) * cos (r[2]));
	d[1][2] = - (sin (r[0]) * cos (r[1]));
	d[2][0] = (sin (r[0]) * sin (r[2]))
		- (sin (r[1]) * cos (r[0]) * cos (r[2]));
	d[2][1] = (sin (r[0]) * cos (r[2]))
		+ (sin (r[1]) * sin (r[2]) * cos (r[0]));
	d[2][2] = cos (r[0]) * cos (r[1]);
	obj->xyz_p[0] = xyz[0] * d[0][0] + xyz[1] * d[0][1] + xyz[2] * d[0][2];
	obj->xyz_p[1] = xyz[0] * d[1][0] + xyz[1] * d[1][1] + xyz[2] * d[1][2];
	obj->xyz_p[2] = xyz[0] * d[2][0] + xyz[1] * d[2][1] + xyz[2] * d[2][2];
}
