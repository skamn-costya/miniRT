/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:44:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 23:38:12 by ksorokol         ###   ########.fr       */
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

void	set_pixel(mlx_image_t *p_img, t_pixel pix)
{
	p_img->pixels[(p_img->width * pix.y + pix.x) * BPP] = pix.color.mlx_color;
}
