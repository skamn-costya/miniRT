/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:52:47 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/19 16:26:00 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>

static void	ksx_line_(mlx_image_t *img,
				t_pixel p1, t_pixel p2, int32_t d_xy[]);
static void	ksx_line_y(mlx_image_t *img,
				t_pixel p1, t_pixel p2, int32_t d_xy[]);
static void	ksx_line_x(mlx_image_t *img,
				t_pixel p1, t_pixel p2, int32_t d_xy[]);

void	ksx_line(mlx_image_t *img, t_pixel pix1, t_pixel pix2)
{
	float	m;
	int32_t	d_xy[4];

	// printf("Line: %lu.%lu : %lu.%lu\n", pix1.x, pix1.y, pix2.x, pix2.y);
	// if ((pix1.x > img->width || pix1.y > img->height) || (pix2.x > img->width || pix2.y > img->height))
	// 	return;
	// ksx_set_pixel(img, &pix1);
	d_xy[0] = pix2.x - pix1.x;
	d_xy[1] = pix2.y - pix1.y;
	d_xy[2] = 0;
	d_xy[3] = 0;
	if (d_xy[0] != 0)
		d_xy[2] = d_xy[0] / ksx_abs (d_xy[0]);
	if (d_xy[1] != 0)
		d_xy[3] = d_xy[1] / ksx_abs (d_xy[1]);
	d_xy[0] = ksx_abs (d_xy[0]);
	d_xy[1] = ksx_abs (d_xy[1]);
	if (d_xy[1] == 0 || (d_xy[0] == 0))
	{
		ksx_line_ (img, pix1, pix2, d_xy);
		return ;
	}
	m = ksx_abs (d_xy[1]) / ksx_abs (d_xy[0]);
	if (m < 1)
		ksx_line_x (img, pix1, pix2, d_xy);
	else
		ksx_line_y (img, pix1, pix2, d_xy);
	// ksx_set_pixel(img, &pix2);
}

static t_color	ksx_get_color(t_pixel p, t_pixel p1, t_pixel p2)
{
	t_color	color[3];
	float	f;

	color[0] = p1.color;
	color[1] = p2.color;
	f = ksx_fraction (p, p1, p2);
	color[2].r = color[0].r + (color[1].r - color[0].r) * f;
	color[2].g = color[0].g + (color[1].g - color[0].g) * f;
	color[2].b = color[0].b + (color[1].b - color[0].b) * f;
	color[2].a = color[0].a + (color[1].a - color[0].a) * f;
	return (color[2]);
}

static void	ksx_line_(mlx_image_t *img,
				t_pixel pix1, t_pixel pix2, int32_t d_xy[])
{
	t_pixel	pix;
	int32_t	xy[2];

	xy[0] = 0;
	pix.x = pix1.x;
	pix.y = pix1.y;
	if (d_xy[0] == 0)
		xy[1] = d_xy[1];
	else
		xy[1] = d_xy[0];
	while (xy[0] < xy[1])
	{
		if (d_xy[0] == 0)
			pix.y += d_xy[3];
		if (d_xy[1] == 0)
			pix.x += d_xy[2];
		pix.color = ksx_get_color (pix, pix1, pix2);
		ksx_set_pixel(img, &pix);
		xy[0]++;
	}
}

static void	ksx_line_x(mlx_image_t *img,
				t_pixel pix1, t_pixel pix2, int32_t d_xy[])
{
	t_pixel	pix;
	int32_t	x;
	int32_t	c;

	x = 0;
	c = 2 * d_xy[1] - d_xy[0];
	pix.x = pix1.x;
	pix.y = pix1.y;
	while (x < d_xy[0])
	{
		pix.x += d_xy[2];
		if (c < 0)
			c = c + 2 * d_xy[1];
		else
		{
			pix.y += d_xy[3];
			c = c + 2 * d_xy[1] - 2 * d_xy[0];
		}
		pix.color = ksx_get_color (pix, pix1, pix2);
		ksx_set_pixel(img, &pix);
		x++;
	}
}

static void	ksx_line_y(mlx_image_t *img,
				t_pixel pix1, t_pixel pix2, int32_t d_xy[])
{
	t_pixel	pix;
	int32_t	y;
	int32_t	c;

	y = 0;
	c = 2 * d_xy[0] - d_xy[1];
	pix.x = pix1.x;
	pix.y = pix1.y;
	while (y < d_xy[1])
	{
		pix.y += d_xy[3];
		if (c < 0)
			c = c + 2 * d_xy[0];
		else
		{
			pix.x += d_xy[2];
			c = c + 2 * d_xy[0] - 2 * d_xy[1];
		}
		pix.color = ksx_get_color (pix, pix1, pix2);
		ksx_set_pixel(img, &pix);
		y++;
	}
}
