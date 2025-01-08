/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:44:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/06 22:59:39 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <math.h>

t_point	get_point(int xyz[], unsigned char flags)
{
	t_point	point;

	if (flags & PERSPEC)
	{
		point.x = round (xyz[3]);
		point.y = round (xyz[4]);
	}
	else
	{
		point.x = round (xyz[3]);
		point.y = round (xyz[4]);
	}
	point.color = 256;
	return (point);
}

void	ksx_point(t_img img, t_point point)
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
