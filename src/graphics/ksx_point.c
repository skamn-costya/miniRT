/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:44:38 by ksorokol          #+#    #+#             */
/*   Updated: 2024/12/26 17:33:19 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <math.h>

t_point	get_point(t_fdf *fdf, int as_xyz[], unsigned char flags)
{
	t_point	point;

	if (flags & PERSPEC)
	{
		point.x = round (fdf->xyzw_c[0]) + as_xyz[3];
		point.y = round (fdf->xyzw_c[1]) + as_xyz[4];
	}
	else
	{
		point.x = round (fdf->xyz_p[0]) + as_xyz[3];
		point.y = round (fdf->xyz_p[1]) + as_xyz[4];
	}
	point.color = fdf->color;
	return (point);
}

void	fdf_point(t_img img, t_point point)
{
	char	*pxl;
	int		shift;

	shift = (point.y * img.line_len
			+ point.x * (img.bpp / SINGLE_COLOR));
	if (shift >= 0 && shift < img.size && point.x >= 0 && point.y >= 0
		&& point.x < WIDTH && point.y < HEIGHT)
	{
		pxl = img.addr + shift;
		*(unsigned int *)pxl = point.color;
	}
}
