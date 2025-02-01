/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:55:19 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 19:42:15 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>

mlx_t	*ksx_init(void)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "miniRT by Stepan & Konstantin", false);
	if (!mlx)
		return (printf("Error: MLX42 initialization failed!\n"), NULL);
	return (mlx);
}

// int	close_x(t_vars *vars)
// {
// 	mlx_destroy_image (vars->mlx, vars->img.img);
// 	mlx_destroy_window (vars->mlx, vars->win);
// 	mlx_destroy_display (vars->mlx);
// 	free (vars->mlx);
// 	exit (EXIT_SUCCESS);
// }
