/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_gc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:08:16 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/10 12:32:09 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ANSI_color_codes.h"
#include <stdio.h>
#include <stdlib.h>

void	ksx_garbage_collector(t_graphics *p_grph)
{
	static t_graphics	*p_g;

	if (p_grph)
	{
		p_g = p_grph;
		return ;
	}
	mlx_delete_image(p_g->mlx, p_g->img_proj);
	mlx_delete_image(p_g->mlx, p_g->img_ray);
	mlx_close_window(p_g->mlx);
	mlx_terminate(p_g->mlx);
	ksx_world_clean(&p_g->world);
	p_g->f_gc(NULL);
	exit (EXIT_SUCCESS);
}

void	ksx_error(char *error, char *file_name, int str_num)
{
	printf("%sERROR:%s %s.\nFile: %s\nString: %d\n\n",
		RED, RESET, error, file_name, str_num);
	ksx_garbage_collector(NULL);
}
