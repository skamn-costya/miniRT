/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:44:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/08 20:20:53 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "MLX42.h"

t_pixel	ksx_get_pixel(mlx_image_t *p_img, uint32_t x, uint32_t y)
{
	t_pixel		pixel;

	pixel.x = x;
	pixel.y = y;
	pixel.color.mlx_color = p_img->pixels[(p_img->width * y + x) * BPP];
	return (pixel);
}

// void	ksx_set_pixel(mlx_image_t *p_img, t_pixel pix)
// {
//  	uint32_t	*p_pixel;

// 	if (pix.x < 0 || pix.x > p_img->width
// 		|| pix.y < 0 || pix.y > p_img->height)
// 		return ;
// 	p_pixel = (uint32_t *) &p_img->pixels[(p_img->width * pix.y + pix.x) * BPP];
// 	*p_pixel = pix.color.mlx_color;
// }

void	ksx_set_pixel(mlx_image_t *p_img, t_pixel pix)
{
	uint8_t		*p_pixel;
	uint32_t	x;
	uint32_t	y;

	if (pix.x >= WIDTH || pix.y >= HEIGHT)
		return ;
	x = pix.x;
	y = pix.y;
	if (x > p_img->width || y > p_img->height)
		return ;
	p_pixel = &p_img->pixels[(p_img->width * y + x) * BPP];
	p_pixel[0] = pix.color.abgr[0];
	p_pixel[1] = pix.color.abgr[1];
	p_pixel[2] = pix.color.abgr[2];
	p_pixel[3] = pix.color.abgr[3];
}

	// *(p_pixel++) = (uint8_t)(pix.color.mlx_color >> 24);
	// *(p_pixel++) = (uint8_t)(pix.color.mlx_color >> 16);
	// *(p_pixel++) = (uint8_t)(pix.color.mlx_color >> 8);
	// *(p_pixel++) = (uint8_t)(pix.color.mlx_color & 0xFF);
