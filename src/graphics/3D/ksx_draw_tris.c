/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_tris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/13 16:29:37 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"

void	ksx_draw_tris(t_triangle **pp_tri, uint32_t *p_size,
		mlx_image_t *p_image, t_camera *p_camera)
{
	uint32_t	idx;

	idx = 0;
	while (idx < *p_size)
	{
		ksx_draw_tri(pp_tri[idx], p_image, p_camera, DRAW_LINE);
		idx++;
	}
}
