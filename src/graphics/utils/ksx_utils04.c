/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils04.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/08 23:07:14 by ksorokol         ###   ########.fr       */
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
	float	result;

	dx = (p2.x - p1.x);
	dy = (p2.y - p1.y);
	if (ksx_abs(dx) > ksx_abs(dy))
	{
		if (p1.x != p2.x)
			result = (float)(p.x - p1.x) / dx;
		else
			result = 0;
	}
	else
	{
		if (p1.y != p2.y)
			result = (float)(p.y - p1.y) / dy;
		else
			result = 0;
	}
	return (result);
}

int32_t	ksx_abs(const int32_t num)
{
	int32_t	result;

	result = num;
	if (num < 0)
		result *= -1;
	return (result);
}

mlx_image_t	*ksx_create_image(mlx_t *mlx)
{
	mlx_image_t	*p_img;
	uint32_t	size;
	uint32_t	idx;

	p_img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!p_img)
		return (printf("Error: MLX42 create mlx_image_t failed!\n"), NULL);
	size = mlx->width * mlx->height * BPP;
	idx = 0;
	while (idx < size)
	{
		p_img->pixels[idx] = 0;
		p_img->pixels[idx + 1] = 0;
		p_img->pixels[idx + 2] = 0;
		p_img->pixels[idx + 3] = 255;
		idx += 4;
	}
	return (p_img);
}

/**
 * @brief returns coordinates of the midpoint (between p1 and p2)
 * 
 * @param p_p1 a pointer to the first point
 * @param p_p2 a pointer to the second point
 * @param p point
 */
t_vector3	ksx_mid_point(const t_vector3 *p_p1, const t_vector3 *p_p2)
{
	t_vector3	result;

	result.x = (p_p1->x + p_p2->x) * 0.5f;
	result.y = (p_p1->y + p_p2->y) * 0.5f;
	result.z = (p_p1->z + p_p2->z) * 0.5f;
	return (result);
}
