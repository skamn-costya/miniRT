/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:44:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 23:15:32 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "MLX42.h"
#include <math.h>

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

void	ksx_set_pixel(mlx_image_t *p_img, t_pixel *p_pix)
{
	uint8_t		*p_pixel;

	if (p_pix->x >= p_img->width || p_pix->y >= p_img->height
		|| p_pix->x < 0 || p_pix->y < 0)
		return ;
	p_pixel = &p_img->pixels[(p_img->width * p_pix->y + p_pix->x) * BPP];
	p_pixel[0] = p_pix->color.rgba[0];
	p_pixel[1] = p_pix->color.rgba[1];
	p_pixel[2] = p_pix->color.rgba[2];
	p_pixel[3] = p_pix->color.rgba[3];
}

// *(p_pixel++) = (uint8_t)(pix.color.mlx_color >> 24);
// *(p_pixel++) = (uint8_t)(pix.color.mlx_color >> 16);
// *(p_pixel++) = (uint8_t)(pix.color.mlx_color >> 8);
// *(p_pixel++) = (uint8_t)(pix.color.mlx_color & 0xFF);

// void applyDepthAttenuation(t_color *p_color, float depth, float k)
// {
// 	// Извлекаем компоненты ARGB
// 	uint8_t b = (p_color->mlx_color >> 24) & 0xFF;
// 	uint8_t g = (p_color->mlx_color >> 16) & 0xFF;
// 	uint8_t r = (p_color->mlx_color >> 8)  & 0xFF;
// 	uint8_t a = (p_color->mlx_color)       & 0xFF;

// 	// Вычисляем коэффициент яркости
// 	float attenuation = expf(-k * depth); // Экспоненциальное затухание

// 	// Применяем затемнение (умножаем на attenuation)
// 	r = (uint8_t)(r * attenuation);
// 	g = (uint8_t)(g * attenuation);
// 	b = (uint8_t)(b * attenuation);

// 	// Собираем пиксель обратно в ARGB
// 	p_color->mlx_color = (b << 24) | (g << 16) | (r << 8) | a;
// }
