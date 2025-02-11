/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:39:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 16:45:43 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_3D.h"

void	ksx_draw_obj(t_object *p_object, mlx_image_t *p_img, t_camera *p_cam)
{
	ksx_draw_tris (p_object->pp_otri, &p_object->size_otri, p_img, p_cam);
}
