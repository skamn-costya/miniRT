/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:09:32 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/06 23:22:35 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <math.h>

void	ksx_prep(t_vars *vars)
{
	//ksx_draw (vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	// print_statuses (vars);
}
