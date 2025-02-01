/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils04.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 01:10:15 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float	fraction(t_pixel p, t_pixel p1, t_pixel p2)
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

int32_t	ksx_abs(int32_t num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

mlx_image_t	*create_new_image(mlx_t *mlx)
{
	mlx_image_t	*img;
	uint32_t	size;
	uint32_t	idx;

	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img)
		return(printf("Error: MLX42 create mlx_image_t failed!\n"), NULL);
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

t_tris	*add_triangels(t_tris *p_tirs, uint32_t size)
{
	t_triangle	*p_triangle;

	p_triangle = (t_triangle *) malloc (sizeof(t_triangle) * (p_tirs->size + size));
	if (!p_triangle)
		return(printf("Error: memory allocation failed!\n"), NULL);
	if(!p_tirs->p)
		return (p_tirs->p = p_triangle, p_tirs->size = size, p_tirs);
	size += p_tirs->size;
	while (p_tirs->size > 0)
		p_triangle[--p_tirs->size] = p_tirs->p[p_tirs->size];
	free (p_tirs->p);
	return (p_tirs->p = p_triangle, p_tirs->size = size, p_tirs);
}

// t_triangle	*set_triangel_points(t_triangle *p_triangle, t_point p1, t_point p2, t_point p3)
// {
// 	p_triangle->p1 = p1;

// }

// t_point	get_poit_sphere(t_vector v, t_point p, float r)
// {
// 	t_point p_;
// 	float f;

// 	p_.x = v.dir.x * (p_.y / v.dir.y);

// 	p_.x
// }

// void	fdf_draw_image(t_vars *vars)
// {
// 	mlx_destroy_image (vars->mlx, vars->img.img);
// 	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
// 	vars->img.addr = mlx_get_data_addr (vars->img.img, &vars->img.bpp,
// 			&vars->img.line_len, &vars->img.endian);
// 	vars->img.size = HEIGHT * vars->img.line_len;
// 	fdf_draw (vars);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
// 	print_statuses (vars);
// }

// float	fraction(t_point p, t_point p1, t_point p2)
// {
// 	int		dx;
// 	int		dy;
// 	float	fraction;

// 	dx = (p2.x - p1.x);
// 	dy = (p2.y - p1.y);
// 	if (abs(dx) > abs(dy))
// 	{
// 		if (p1.x != p2.x)
// 			fraction = (float)(p.x - p1.x) / dx;
// 		else
// 			fraction = 0;
// 	}
// 	else
// 	{
// 		if (p1.y != p2.y)
// 			fraction = (float)(p.y - p1.y) / dy;
// 		else
// 			fraction = 0;
// 	}
// 	return (fraction);
// }

// void	print_statuses(t_vars *vars)
// {
// 	mlx_string_put(vars->mlx, vars->win, 25, 25, 0X88888888,
// 		"This is an isometric projection");
// }
