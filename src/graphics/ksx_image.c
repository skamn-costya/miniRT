/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:09:32 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/14 14:31:12 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_camera.h"
#include <math.h>
#include <stdio.h>

mlx_image_t	*ksx_create_image(mlx_t *mlx, uint32_t bg_color)
{
	mlx_image_t	*p_img;
	uint32_t	idx[2];
	uint8_t		*pixel;

	p_img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!p_img)
		return (printf("Error: MLX42 create mlx_image_t failed!\n"), NULL);
	idx[0] = mlx->width * mlx->height;
	idx[1] = 0;
	while (idx[1] < idx[0])
	{
		pixel = &p_img->pixels[idx[1] * BPP];
		*(pixel++) = (uint8_t)(bg_color >> 24);
		*(pixel++) = (uint8_t)(bg_color >> 16);
		*(pixel++) = (uint8_t)(bg_color >> 8);
		*(pixel++) = (uint8_t)(bg_color & 0xFF);
		idx[1]++;
	}
	return (p_img);
}

int32_t	ksx_image_to_window(mlx_t *p_mlx, mlx_image_t *p_img, int32_t z)
{
	int32_t result;

	result = mlx_image_to_window(p_mlx, p_img, 0, 0);
	mlx_set_instance_depth(&p_img->instances[0], z);
	return (result);
}
