/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:39:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/13 16:30:24 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_3D.h"

void	ksx_draw_obj(t_object *p_object,
		mlx_image_t *p_imgage, t_camera *p_camera)
{
	ksx_draw_tris (p_object->pp_otri,
		&p_object->size_otri, p_imgage, p_camera);
}
