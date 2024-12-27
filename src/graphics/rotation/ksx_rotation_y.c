/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_rotation_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2024/12/26 17:43:59 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <math.h>

static void	rotation_y_(t_obj *obj, float a);

void	rotation_y(t_obj *obj, int xy[], float a)
{
	int		idx_xy[2];

	if (a == 0)
		return ;
	idx_xy[1] = 0;
	while (idx_xy[1] < xy[1])
	{
		idx_xy[0] = 0;
		while (idx_xy[0] < xy[0])
		{
			rotation_y_ (obj[idx_xy[0]][idx_xy[1]], a);
			idx_xy[0]++;
		}
		idx_xy[1]++;
	}
}

static void	rotation_y_(t_obj *obj, float a)
{
	float	xyz[3];
	float	r;

	if (a == 0)
		return ;
	r = (a * PI) / 180;
	xyz[0] = obj->xyz_p[0];
	xyz[2] = obj->xyz_p[2];
	obj->xyz_p[0] = (xyz[0] * cos (r)) + (xyz[2] * sin (r));
	obj->xyz_p[2] = - (xyz[0] * sin (r)) + (xyz[2] * cos (r));
}
