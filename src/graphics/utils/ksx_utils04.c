/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils04.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/03 12:28:55 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "MLX42.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float	ksx_fraction(const t_pixel p, const t_pixel p1, const t_pixel p2)
{
	int		dx;
	int		dy;
	float	fraction;

	dx = (p2.x - p1.x);
	dy = (p2.y - p1.y);
	if (ksx_abs(dx) > ksx_abs(dy))
	{
		if (p1.x != p2.x)
			fraction = (float)(p.x - p1.x) / dx;
		else
			fraction = 0;
	}
	else
	{
		if (p1.y != p2.y)
			fraction = (float)(p.y - p1.y) / dy;
		else
			fraction = 0;
	}
	return (fraction);
}

int32_t	ksx_abs(const int32_t num)
{
	int32_t	new_num;

	new_num = num;
	if (num < 0)
		new_num *= -1;
	return (new_num);
}

mlx_image_t	*ksx_create_image( mlx_t *mlx)
{
	mlx_image_t	*img;
	uint32_t	size;
	uint32_t	idx;

	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img)
		return (printf("Error: MLX42 create mlx_image_t failed!\n"), NULL);
	size = mlx->width * mlx->height * BPP;
	idx = 0;
	while (idx < size)
	{
		img->pixels[idx] = 0;
		img->pixels[idx + 1] = 0;
		img->pixels[idx + 2] = 0;
		img->pixels[idx + 3] = 255;
		idx += 4;
	}
	return (img);
}
