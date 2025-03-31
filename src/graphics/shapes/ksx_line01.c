/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_line01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:52:47 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 23:14:00 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>

static uint32_t	ksx_line_in(mlx_image_t *p_img, t_pixel *p_pix1,
					t_pixel *p_pix2);
static void		ksx_line_(mlx_image_t *p_img,
					t_pixel *p_p1, t_pixel *p_p2, int32_t d_xy[]);
static void		ksx_line_y(mlx_image_t *img,
					t_pixel *p_p1, t_pixel *p_p2, int32_t d_xy[]);
static void		ksx_line_x(mlx_image_t *img,
					t_pixel *p_p1, t_pixel *p_p2, int32_t d_xy[]);

void	ksx_line(mlx_image_t *p_img, t_pixel *p_pix1, t_pixel *p_pix2)
{
	float	m;
	int32_t	d_xy[4];

	if (!ksx_line_in(p_img, p_pix1, p_pix2))
		return ;
	d_xy[0] = p_pix2->x - p_pix1->x;
	d_xy[1] = p_pix2->y - p_pix1->y;
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
		ksx_line_(p_img, p_pix1, p_pix2, d_xy);
		return ;
	}
	m = ksx_abs (d_xy[1]) / ksx_abs (d_xy[0]);
	if (m < 1)
		ksx_line_x (p_img, p_pix1, p_pix2, d_xy);
	else
		ksx_line_y (p_img, p_pix1, p_pix2, d_xy);
}

static uint32_t	ksx_line_in(mlx_image_t *p_img,
		t_pixel *p_pix1, t_pixel *p_pix2)
{
	if (p_pix1->w <= 0 || p_pix2->w <= 0 || p_pix1->z <= 0 || p_pix2->z <= 0
		|| p_pix1->x < 0 || p_pix2->x < 0 || p_pix1->y < 0 || p_pix2->y < 0
		|| p_pix1->x >= p_img->width || p_pix1->y >= p_img->height
		|| p_pix2->x >= p_img->width || p_pix2->y >= p_img->height)
		return (0);
	return (1);
}

static void	ksx_line_(mlx_image_t *p_img,
				t_pixel *p_pix1, t_pixel *p_pix2, int32_t d_xy[])
{
	t_pixel	pix;
	int32_t	xy[2];

	xy[0] = 0;
	pix.x = p_pix1->x;
	pix.y = p_pix1->y;
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
		pix.color = ksx_get_color (&pix, p_pix1, p_pix2);
		ksx_set_pixel(p_img, &pix);
		xy[0]++;
	}
}

static void	ksx_line_x(mlx_image_t *img,
				t_pixel *p_pix1, t_pixel *p_pix2, int32_t d_xy[])
{
	t_pixel	pix;
	int32_t	x;
	int32_t	c;

	x = 0;
	c = 2 * d_xy[1] - d_xy[0];
	pix.x = p_pix1->x;
	pix.y = p_pix1->y;
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
		pix.color = ksx_get_color (&pix, p_pix1, p_pix2);
		ksx_set_pixel(img, &pix);
		x++;
	}
}

static void	ksx_line_y(mlx_image_t *img,
				t_pixel *p_pix1, t_pixel *p_pix2, int32_t d_xy[])
{
	t_pixel	pix;
	int32_t	y;
	int32_t	c;

	y = 0;
	c = 2 * d_xy[0] - d_xy[1];
	pix.x = p_pix1->x;
	pix.y = p_pix1->y;
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
		pix.color = ksx_get_color (&pix, p_pix1, p_pix2);
		ksx_set_pixel(img, &pix);
		y++;
	}
}
