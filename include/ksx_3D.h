/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:54 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/04 16:14:44 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_3D_H
# define KSX_3D_H

# define BOX_COLOR		0x80888888
# define PIXEL_RED		0xFF0000FF
# define PIXEL_BLACK	0xFF000000
# define OBJ_COLOR		0xA0E5E5E5
# define SEL_OBJ_COLOR	0xA05E5EFF

# include "ksx_graphics.h"

void	ksx_draw_axis(t_object *p_object, mlx_image_t *p_image,
			t_camera *p_camera);
void	ksx_draw_tri(t_triangle *p_tri, mlx_image_t *p_image,
			t_camera *p_camera, uint32_t mlx_color);
void	ksx_draw_tris(t_object *p_object,
			mlx_image_t *p_image, t_graphics *p_grph);
void	ksx_draw_box(t_object *p_obj, mlx_image_t *p_image,
			t_camera *p_camera);
void	ksx_draw_obj(t_object *p_obj, mlx_image_t *p_image,
			t_graphics *p_grph);
t_pixel	ksx_draw_get_pixel(t_camera *p_camera,
			t_vector3 *p_point, uint32_t color);
void	ksx_draw_vertex(t_vertex *p_vertex, mlx_image_t *p_image,
			t_camera *p_camera, uint32_t mlx_color);
void	ksx_draw_vertexes(t_object *p_object, mlx_image_t *p_image,
			t_graphics *p_grph);
void	ksx_draw_norms(t_object *p_object,
			mlx_image_t *p_image, t_camera *p_camera);
#endif	// KSX_3D_H //