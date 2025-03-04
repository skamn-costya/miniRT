/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/04 16:06:54 by ksorokol         ###   ########.fr       */
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
	t_triangle	*p_tri;
	t_pixel		pixel[3];

	pp_box = p_object->pp_box;
	while (pp_box && *pp_box)
	{
		idx = 0;
		while (idx < 12)
		{
			p_tri = &(*pp_box)->tris[idx];
			pixel[0] = ksx_draw_get_pixel(p_camera,
					&p_tri->p_ver1->cp, BOX_COLOR);
			pixel[1] = ksx_draw_get_pixel(p_camera,
					&p_tri->p_ver2->cp, BOX_COLOR);
			pixel[2] = ksx_draw_get_pixel(p_camera,
					&p_tri->p_ver3->cp, BOX_COLOR);
			ksx_line(p_image, &pixel[0], &pixel[1]);
			ksx_line(p_image, &pixel[1], &pixel[2]);
			ksx_line(p_image, &pixel[2], &pixel[0]);
			idx++;
		}
		pp_box++;
	}
}
