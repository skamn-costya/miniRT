/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:39:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/04 00:48:11 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_3D.h"
#include "bvh.h"

void	ksx_draw_obj(t_object *p_object,
		mlx_image_t *p_imgage, t_graphics *p_grph)
{
	if (p_grph->camera.flags & DRAW_LINE && p_object->flags & DRAW_LINE)
		ksx_draw_tris (p_object, p_imgage, p_grph);
	else
		ksx_draw_vertexes(p_object, p_imgage, p_grph);
	if (p_grph->camera.flags & DRAW_BVH)
		bvh_draw_world(p_grph, p_imgage);
}
