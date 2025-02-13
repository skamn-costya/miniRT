/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/13 16:30:10 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"

void	ksx_draw_box(t_object *p_object,
			mlx_image_t *p_image, t_camera *p_camera)
{
	uint32_t	idx;

	idx = 0;
	while (idx < 12)
	{
		p_object->box[idx].color.mlx_color = BOX_COLOR; // move to create box
		ksx_draw_tri(&p_object->box[idx], p_image, p_camera, 1);
		idx++;
	}
}
