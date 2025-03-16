/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec3_math.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:53:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/16 10:08:59 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_VEC3_MATH_H
# define KSX_VEC3_MATH_H
# include "ksx_graphics.h"

// ksx_vec3_math01.c
t_vector3	ksx_vec3_add(const t_vector3 *p_v1, const t_vector3 *p_v2);
t_vector3	ksx_vec3_sub(const t_vector3 *p_v1, const t_vector3 *p_v2);
float		ksx_vec3_angle(const t_vector3 *p_v1, const t_vector3 *p_v2);
t_vector3	ksx_vec3_cross(const t_vector3 *p_v1, const t_vector3 *p_v2);
float		ksx_vec3_mag(const t_vector3 *p_v);

// ksx_vec3_math02.c
t_vector3	ksx_vec3_unit(const t_vector3 *p_v);
t_vector3	ksx_vec3_norm(const t_vector3 *p_v, const t_vector3 *p_norm);
float		ksx_vec3_dist(const t_vector3 *p_v1, const t_vector3 *p_v2);
void		ksx_vec3_resize(t_vector3 *p_v, const float size);
t_matrix3	ksx_vec3_tensor(const t_vector3 *p_v1, const t_vector3 *p_v2);

// ksx_vec3_math03.c
float		ksx_vec3_dot(const t_vector3 *p_v1, const t_vector3 *p_v2);
t_vector3	ksx_vec3_smulti(const t_vector3 *p_v, const float scalar);
t_vector3	ksx_vec3_sdiv(const t_vector3 *p_v, const float scalar);
t_vector3	ksx_vec3_set(float x, float y, float z);
t_vector4	ksx_vec3_vec4(const t_vector3 *p_v, float w);

// ksx_vec3_math04.c
t_vector3	ksx_vec3_sadd(const t_vector3 *p_v, const float scalar);
t_vector3	ksx_vec3_ssub(const t_vector3 *p_v, const float scalar);
t_vector3	ksx_vec3_negate(t_vector3 *p_v);
t_vector3	ksx_vec3_reflect(t_vector3 *p_v, t_vector3 *p_n);

#endif	// KSX_VEC3_MATH_H