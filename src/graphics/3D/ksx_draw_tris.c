/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_tris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/04 16:06:19 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"

void	ksx_draw_tris(t_object *p_object,
		mlx_image_t *p_image, t_graphics *p_grph)
{
	uint32_t	idx;
	uint32_t	mlx_color;

	mlx_color = OBJ_COLOR;
	if (p_object == p_grph->world.pp_obj[p_grph->obj_idx])
		mlx_color = SEL_OBJ_COLOR;
	idx = 0;
	while (idx < p_object->size_tri)
	{
		ksx_draw_tri(p_object->pp_tri[idx], p_image,
			&p_grph->camera, mlx_color);
		idx++;
	}
}
