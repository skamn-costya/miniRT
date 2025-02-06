/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:54 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/06 15:25:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_3D_H
# define KSX_3D_H

#include "ksx_graphics.h"

t_basis		ksx_get_basis(const t_vector3 norm, const t_vector3 center);
void		ksx_draw_axis(t_object *p_obj, mlx_image_t *p_img, t_camera *p_cam);

#endif	// KSX_3D_H //