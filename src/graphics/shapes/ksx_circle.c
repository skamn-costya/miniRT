/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:52:47 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/31 20:05:20 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//shapes dot line circle square triangle
#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>

static void	ksx_circle_(mlx_image_t *img, t_pixel pix, t_pixel pixr);

void	ksx_circle(mlx_image_t *img, t_pixel center, uint32_t radius)
{
    uint32_t	d;
	t_pixel		pixr;

	pixr.x = 0;
	pixr.y = radius;
	d = 3 - 2 * radius;
	ksx_circle_(img, center, pixr);
    while (pixr.y >= pixr.x){
        if (d > 0) {
            pixr.y--; 
            d = d + 4 * (pixr.x - pixr.y) + 10;
        }
        else
            d = d + 4 * pixr.x + 6;
        pixr.x++;
        ksx_circle_(img, center, pixr);
    }
}

static void	ksx_circle_(mlx_image_t *img, t_pixel centr, t_pixel pixr)
{
	mlx_put_pixel(img, centr.x + pixr.x, centr.y + pixr.y,
		centr.color.mlx_color);
	mlx_put_pixel(img, centr.x - pixr.x, centr.y + pixr.y,
		centr.color.mlx_color);
	mlx_put_pixel(img, centr.x + pixr.x, centr.y - pixr.y,
		centr.color.mlx_color);
	mlx_put_pixel(img, centr.x - pixr.x, centr.y - pixr.y,
		centr.color.mlx_color);
	mlx_put_pixel(img, centr.x + pixr.y, centr.y + pixr.x,
		centr.color.mlx_color);
	mlx_put_pixel(img, centr.x - pixr.y, centr.y + pixr.x,
		centr.color.mlx_color);
	mlx_put_pixel(img, centr.x + pixr.y, centr.y - pixr.x,
		centr.color.mlx_color);
	mlx_put_pixel(img, centr.x - pixr.y, centr.y - pixr.x,
		centr.color.mlx_color);
}
