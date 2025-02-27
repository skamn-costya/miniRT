/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec4_math.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:53:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/27 20:43:03 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_VEC4_MATH_H
# define KSX_VEC4_MATH_H
# include "ksx_graphics.h"

// ksx_vec4_math01.c
t_vector4	ksx_vec4_add(const t_vector4 *p_v1, const t_vector4 *p_v2);
t_vector4	ksx_vec4_sub(const t_vector4 *p_v1, const t_vector4 *p_v2);
// float		ksx_vec4_angle(const t_vector4 *p_v1, const t_vector4 *p_v2);
t_vector4	ksx_vec4_cross(const t_vector4 *p_v1, const t_vector4 *p_v2);
float		ksx_vec4_mag(const t_vector4 *p_v);

// ksx_vec4_math02.c
t_vector4	ksx_vec4_unit(const t_vector4 *p_v);
// t_vector4	ksx_vec4_norm(const t_vector4 *p_v, const t_vector4 *p_norm);
float		ksx_vec4_dist(const t_vector4 *p_v1, const t_vector4 *p_v2);
void		ksx_vec4_resize(t_vector4 *p_v, const float size);
t_matrix4	ksx_vec4_tensor(const t_vector4 *p_v1, const t_vector4 *p_v2);

// // ksx_vec4_math03.c
float		ksx_vec4_dot(const t_vector4 *p_v1, const t_vector4 *p_v2);
t_vector4	ksx_vec4_multi(const t_vector4 *p_v, const float scalar);
t_vector4	ksx_vec4_div(const t_vector4 *p_v, const float scalar);
t_vector4	ksx_vec4_set(float x, float y, float z, float w);
t_vector3	ksx_vec4_vec3(const t_vector4 *p_v);

#endif	// KSX_VEC4_MATH_H