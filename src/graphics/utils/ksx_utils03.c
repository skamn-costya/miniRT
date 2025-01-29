/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/29 18:20:58 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ksx_graphics.h"


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
