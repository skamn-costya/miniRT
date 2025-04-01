/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:22:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/04/01 14:22:00 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_UTILS_H
# define KSX_UTILS_H

# include "ksx_graphics.h"

// ksx_utils04.c
float		ksx_fraction(const t_pixel *p_p, const t_pixel *p_p1,
				const t_pixel *p_p2);
int32_t		ksx_abs(const int32_t num);
void		ksx_time_print(char *str);
void		ksx_color_unit_fraction(t_color *p_color);

// ksx_utils05.c

// ksx_utils06.c
// void		ksx_triangle_rotation_w(t_triangle *p_triangle, const float angle_x,
// 				const float angle_y, float angle_z);
// void		ksx_triangle_rotation_c(t_triangle *p_triangle, const float angle_x,
// 				const float angle_y, const float angle_z);
// void		ksx_rotation_w(t_object *p_object, float angle_x,
// 				float angle_y, float angle_z);
// void		ksx_rotation_c(t_object *p_object, float angle_x,
// 				float angle_y, float angle_z);

// ksx_utils07.c
// t_vector3	ksx_point_m3(t_vector3 point, t_matrix3 m);

// ksx_utils08.c
uint32_t	ksx_count_pointers(void **pointers);
void		ksx_free_pointers(void ***ppp_mem);
void		ksx_null_pointers(void **pp_mem, uint32_t size);
int32_t		ksx_point_on_ray(const t_vector3 *p_p, const t_vector3 *p_v);
// t_vector3	ksx_translate_vec3(t_vector3 v1, const t_vector3 v2);
// void		ksx_translate_tri(t_triangle *p_tri, const t_vector3 *p_v);

// ksx_utils09.c
// t_triangle	**ksx_tri2obj(t_triangle *p_tri, t_object *p_object);
// t_triangle	**ksx_tris2obj(t_triangle *p_tris[],
// 				uint32_t size, t_object *p_object);
// t_triangle	ksx_init_tps(const t_vector3 center, const t_vector3 norm);
// t_object	*ksx_create_object(t_vector3 *p_center);

// ksx_utils01.c
void		ksx_print_vector(t_vector3 *p_vec);
void		ksx_print_vertex(t_vertex *p_ver, int32_t idx);
void		ksx_print_tri(t_triangle *p_tri, int32_t idx);
void		ksx_print_basis(t_basis *p_basis);
void		ksx_print_error(char *str);

#endif	// KSX_UTILS_H //
