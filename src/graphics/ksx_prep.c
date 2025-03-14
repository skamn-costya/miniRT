/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:09:32 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/14 12:48:50 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_camera.h"
#include <math.h>
#include <stdio.h>

// int	ksx_prep(void *p_prep)
// {
// 	t_graphics	*p_grph;

// 	p_grph = (t_graphics *) p_prep;
// 	p_grph->img_proj = ksx_create_image(p_grph->mlx, TRANSPARENT);
// 	if (!p_grph->img_proj)
// 		return (printf("Create image failed!\n"), FALSE);
// 	if (mlx_image_to_window(p_grph->mlx, p_grph->img_proj, 0, 0) < 0)
// 		return (printf("Image to window failed!\n"), FALSE);
// 	return (TRUE);
// }
