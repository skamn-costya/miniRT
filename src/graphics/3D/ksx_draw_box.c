/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/24 15:48:30 by ksorokol         ###   ########.fr       */
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
	t_box		**pp_box;

	// if (!p_object->pp_box || !p_object->pp_box[0])
	// 	return ;
	pp_box = p_object->pp_box;
	while (pp_box && *pp_box)
	{
		idx = 0;
		while (idx < 12)
		{
			ksx_draw_tri(&(*pp_box)->tris[idx], p_image, p_camera);
			idx++;
		}
		pp_box++;
	}
}
