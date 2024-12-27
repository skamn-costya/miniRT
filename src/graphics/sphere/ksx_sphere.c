/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2024/12/26 17:19:38 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <math.h>

static void	ksx_line_(t_img img, t_point p1, t_point p2, int d_xy[]);
static void	ksx_line_y(t_img img, t_point p1, t_point p2, int d_xy[]);
static void	ksx_line_x(t_img img, t_point p1, t_point p2, int d_xy[]);

void	ksx_sphere(t_img img, t_point point1, t_point point2)
{
	float	m;
	int		d_xy[4];

	fdf_point (img, point1);
	d_xy[0] = point2.x - point1.x;
	d_xy[1] = point2.y - point1.y;
	d_xy[2] = 0;
	d_xy[3] = 0;
	if (d_xy[0] != 0)
		d_xy[2] = d_xy[0] / abs (d_xy[0]);
	if (d_xy[1] != 0)
		d_xy[3] = d_xy[1] / abs (d_xy[1]);
	d_xy[0] = abs (d_xy[0]);
	d_xy[1] = abs (d_xy[1]);
	if (d_xy[1] == 0 || (d_xy[0] == 0))
	{
		fdf_line_ (img, point1, point2, d_xy);
		return ;
	}
	m = abs (d_xy[1]) / abs (d_xy[0]);
	if (m < 1)
		fdf_line_x (img, point1, point2, d_xy);
	else
		fdf_line_y (img, point1, point2, d_xy);
	fdf_point (img, point2);
}

static unsigned int	get_color(t_point p, t_point p1, t_point p2)
{
	int		result;
	int		rgb[3][3];
	float	f;

	rgb[0][0] = p1.color & 0x0000FF;
	rgb[1][0] = p2.color & 0x0000FF;
	rgb[0][1] = p1.color >> SINGLE_COLOR & 0x0000FF;
	rgb[1][1] = p2.color >> SINGLE_COLOR & 0x0000FF;
	rgb[0][2] = p1.color >> (SINGLE_COLOR * 2) & 0x0000FF;
	rgb[1][2] = p2.color >> (SINGLE_COLOR * 2) & 0x0000FF;
	f = fraction (p, p1, p2);
	rgb[2][0] = rgb[0][0] + (rgb[1][0] - rgb[0][0]) * f;
	rgb[2][1] = rgb[0][1] + (rgb[1][1] - rgb[0][1]) * f;
	rgb[2][1] <<= SINGLE_COLOR;
	rgb[2][2] = rgb[0][2] + (rgb[1][2] - rgb[0][2]) * f;
	rgb[2][2] <<= SINGLE_COLOR * 2;
	result = rgb[2][0] + rgb[2][1] + rgb[2][2];
	return (result);
}

static void	ksx_line_(t_img img, t_point p1, t_point p2, int d_xy[])
{
	t_point		point;
	int			xy[2];

	xy[0] = 0;
	point.x = p1.x;
	point.y = p1.y;
	if (d_xy[0] == 0)
		xy[1] = d_xy[1];
	else
		xy[1] = d_xy[0];
	while (xy[0] < xy[1])
	{
		if (d_xy[0] == 0)
			point.y += d_xy[3];
		if (d_xy[1] == 0)
			point.x += d_xy[2];
		point.color = get_color (point, p1, p2);
		fdf_point(img, point);
		xy[0]++;
	}
}

static void	ksx_line_x(t_img img, t_point p1, t_point p2, int d_xy[])
{
	t_point		point;
	int			x;
	int			c;

	x = 0;
	c = 2 * d_xy[1] - d_xy[0];
	point.x = p1.x;
	point.y = p1.y;
	while (x < d_xy[0])
	{
		point.x += d_xy[2];
		if (c < 0)
			c = c + 2 * d_xy[1];
		else
		{
			point.y += d_xy[3];
			c = c + 2 * d_xy[1] - 2 * d_xy[0];
		}
		point.color = get_color (point, p1, p2);
		fdf_point(img, point);
		x++;
	}
}

static void	ksx_line_y(t_img img, t_point p1, t_point p2, int d_xy[])
{
	t_point		point;
	int			y;
	int			c;

	y = 0;
	c = 2 * d_xy[0] - d_xy[1];
	point.x = p1.x;
	point.y = p1.y;
	while (y < d_xy[1])
	{
		point.y += d_xy[3];
		if (c < 0)
			c = c + 2 * d_xy[0];
		else
		{
			point.x += d_xy[2];
			c = c + 2 * d_xy[0] - 2 * d_xy[1];
		}
		point.color = get_color (point, p1, p2);
		fdf_point(img, point);
		y++;
	}
}
