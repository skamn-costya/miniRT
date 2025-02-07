/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:22:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/07 01:27:38 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_UTILS_H
# define KSX_UTILS_H

# include "ksx_graphics.h"

// ksx_utils03.c
float		ksx_determinant2(const t_matrix2 m);
float		ksx_determinant3(const t_matrix3 m);
float		ksx_determinant4(const t_matrix4 m);

// ksx_utils04.c
float		ksx_fraction(const t_pixel p, const t_pixel p1, const t_pixel p2);
int32_t		ksx_abs(const int32_t num);
mlx_image_t	*ksx_create_image(mlx_t *mlx);
t_vector3	ksx_mid_point(const t_vector3 p1, const t_vector3 p2);

// ksx_utils05.c
t_vector3	ksx_point_rotation(const t_vector3 point, const float angle_x,
				const float angle_y, const float angle_z);
t_vector3	ksx_point_rotation_x(const t_vector3 point, const float angle);
t_vector3	ksx_point_rotation_y(const t_vector3 point, const float angle);
t_vector3	ksx_point_rotation_z(const t_vector3 point, const float angle);

// ksx_utils06.c
void		ksx_triangle_rotation_w(t_triangle *p_triangle, const float angle_x,
				const float angle_y, float angle_z);
void		ksx_triangle_rotation_c(t_triangle *p_triangle, const float angle_x,
				const float angle_y, const float angle_z);
void		ksx_rotation_w(t_object *p_object, float angle_x,
				float angle_y, float angle_z);
void		ksx_rotation_c(t_object *p_object, float angle_x,
				float angle_y, float angle_z);

// ksx_utils07.c
t_vector3	ksx_point_m3(t_vector3 point, t_matrix3 m);
void		ksx_m3_reset(t_matrix3 *p_m3);

// ksx_utils08.c
uint32_t	ksx_count_pointers(void **pointers);
void		ksx_free_pointers(void **pointers);
int			ksx_point_on_ray(const t_vector3 p, const t_vector3 v);
t_vector3	ksx_translate_vec3(t_vector3 v1, const t_vector3 v2);
void		ksx_translate_tri(t_triangle *tri, const t_vector3 norm);

// ksx_utils09.c
t_triangle	**ksx_tri2obj(t_triangle *p_tri, t_object *p_object);
t_triangle	**ksx_tris2obj(t_triangle *p_tris[],
				uint32_t size, t_object *p_object);
t_triangle	ksx_init_tps(const t_vector3 center, const t_vector3 norm);
t_object	*ksx_create_object(t_vector3 center);

#endif	// KSX_UTILS_H //
