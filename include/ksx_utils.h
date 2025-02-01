/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:22:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 19:43:03 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_UTILS_H
# define KSX_UTILS_H

# include "ksx_graphics.h"

// ksx_utils01.c
float		get_dist_vector3(const t_vector3 v1, const t_vector3 v2);
void		middle_point(const t_vector3 p1,
				const t_vector3 p2, t_vector3 *p);
void		vector_resize3(t_vector3 v1, float new_size, t_vector3 *v);

// ksx_utils02.c
void		ksx_cross_product(const t_vector3 v1, const t_vector3 v2,
				t_vector3 *v);
float		get_magnitude(const t_vector3 v);
void		vector3_norm(t_vector3 v1, t_vector3 *v);
int			is_point_on_ray(const t_vector3 p, const t_vector3 v);

// ksx_utils03.c
float		ksx_determinant2(t_matrix22 m);
float		ksx_determinant3(t_matrix33 m);
float		ksx_determinant4(t_matrix44 m);

// ksx_utils04.c
float		ksx_fraction(t_pixel p, t_pixel p1, t_pixel p2);
int32_t		ksx_abs(int32_t num);
mlx_image_t	*ksx_create_image(mlx_t *mlx);
t_tris		*ksx_add_triangels(t_tris *p_tirs, uint32_t size);
t_triangle	ksx_init_tps(t_vector3 center, t_vector3 norm);

// ksx_utils06.c
void		ksx_triangle_rotation_w(t_triangle *p_triangle, float angle_x,
				float angle_y, float angle_z);
void		ksx_triangle_rotation_c(t_triangle *p_triangle, float angle_x,
				float angle_y, float angle_z);

// ksx_utils07.c
t_vector3	ksx_point_m33(t_vector3 point, t_matrix33 m);
t_vector3	ksx_point_m44(t_vector3 point, t_matrix44 m);

#endif	// KSX_UTILS_H //
