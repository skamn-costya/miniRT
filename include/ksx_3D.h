/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:54 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/10 13:21:38 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_3D_H
# define KSX_3D_H

# define BOX_COLOR	0x88FFFFFF

#include "ksx_graphics.h"

void		ksx_draw_axis(t_object *p_object, mlx_image_t *p_img, t_camera *p_cam);
void		ksx_draw_tri(t_triangle *p_tri, mlx_image_t *p_img, t_camera *p_cam);
void		ksx_draw_tris(t_triangle *p_tri, mlx_image_t *p_img, t_camera *p_cam);
void		ksx_draw_box(t_object *p_obj, mlx_image_t *p_img, t_camera *p_cam);

#endif	// KSX_3D_H //