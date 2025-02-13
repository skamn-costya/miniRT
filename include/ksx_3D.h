/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:54 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/13 16:28:25 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_3D_H
# define KSX_3D_H

# define BOX_COLOR	0x88888888
# define DRAW_LINE	1

# include "ksx_graphics.h"

void	ksx_draw_axis(t_object *p_object, mlx_image_t *p_image,
			t_camera *p_camera);
void	ksx_draw_tri(t_triangle *p_tri, mlx_image_t *p_image,
			t_camera *p_camera, uint8_t lines);
void	ksx_draw_tris(t_triangle **pp_tri, uint32_t *p_size,
			mlx_image_t *p_img, t_camera *p_camera);
void	ksx_draw_box(t_object *p_obj, mlx_image_t *p_image,
			t_camera *p_camera);
void	ksx_draw_obj(t_object *p_obj, mlx_image_t *p_image,
			t_camera *p_camera);
#endif	// KSX_3D_H //