/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:55:19 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/31 21:38:28 by ksorokol         ###   ########.fr       */
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
	// vars->mlx = mlx_init();
	// vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "miniRT by ksorokol");
	// mlx_hook(vars->win, 2, 1L << 0, esc_65307, vars);
	// mlx_hook(vars->win, 17, 1L << 0, close_x, vars);
	// vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	// vars->img.addr = mlx_get_data_addr (vars->img.img, &vars->img.bpp,
	// 		&vars->img.line_len, &vars->img.endian);
	// vars->img.size = HEIGHT * vars->img.line_len;
	// mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	// vars->flags = 0b00000001;
	// ksx_prep (vars);
	// mlx_do_key_autorepeaton(vars->mlx);
	// mlx_loop(vars->mlx);
}



// int	close_x(t_vars *vars)
// {
// 	mlx_destroy_image (vars->mlx, vars->img.img);
// 	mlx_destroy_window (vars->mlx, vars->win);
// 	mlx_destroy_display (vars->mlx);
// 	free (vars->mlx);
// 	exit (EXIT_SUCCESS);
// }
