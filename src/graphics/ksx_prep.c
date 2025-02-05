/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:09:32 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/05 21:57:14 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_camera.h"
#include <math.h>
#include <stdio.h>

int	ksx_prep(void *p_prep)
{
	t_graphics	*p_grph;

	p_grph = (t_graphics *) p_prep;
	p_grph->img = ksx_create_image(p_grph->mlx);
	if (!p_grph->img)
		return (printf("Create image failed!\n"), FALSE);
	ksx_set_camera_pm(&p_grph->camera, 1.f, 200.f);
	if (mlx_image_to_window(p_grph->mlx, p_grph->img, 0, 0) < 0)
		return (printf("Image to window failed!\n"), FALSE);
	return (TRUE);
}
