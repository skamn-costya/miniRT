/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:55:19 by ksorokol          #+#    #+#             */
/*   Updated: 2025/04/01 15:10:15 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include "bvh.h"

mlx_t	*ksx_init(void)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "miniRT by Stepan & Konstantin", false);
	if (!mlx)
		return (ksx_print_error("MLX42 initialization failed!"), NULL);
	return (mlx);
}

// I think this is not needed in MLX42 - (i just think :P)
// mlx_delete_image (p_grph->mlx, p_grph->img_bg);
// mlx_delete_image (p_grph->mlx, p_grph->img_ray);
// mlx_delete_image (p_grph->mlx, p_grph->img_proj);
// bvh_free_world(&p_grph->world); // To free all BVH resources
// int	graceful_shutdown(t_graphics *p_grph)
// {
// 	bvh_free_world(&p_grph->world);
// 	mlx_close_window(p_grph->mlx);
// 	mlx_terminate(p_grph->mlx);
// 	free (p_grph->mlx);
// 	exit (EXIT_SUCCESS);
// }
