/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:39:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/21 11:39:18 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_3D.h"

void	ksx_draw_obj(t_object *p_object,
		mlx_image_t *p_imgage, t_camera *p_camera)
{
	if (p_camera->flags & DRAW_LINE && p_object->flags & DRAW_LINE)
		ksx_draw_tris (p_object->pp_tri,
			&p_object->size_tri, p_imgage, p_camera);
	else
		ksx_draw_vertexes(p_object, p_imgage, p_camera);
}
