/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec3_math.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:53:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/05 15:53:55 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_VEC3_MATH_H
# define KSX_VEC3_MATH_H
# include "ksx_graphics.h"

// ksx_vec3_math01.c
t_vector3	ksx_vec3_add(const t_vector3 v1, const t_vector3 v2);
t_vector3	ksx_vec3_sub(const t_vector3 v1, const t_vector3 v2);
float		ksx_vec3_angle(const t_vector3 v1, const t_vector3 v2);
t_vector3	ksx_vec3_cross(const t_vector3 v1, const t_vector3 v2);
float		ksx_vec3_mag(const t_vector3 v);

// ksx_vec3_math02.c
t_vector3	ksx_vec3_unit(const t_vector3 v);
t_vector3	ksx_vec3_norm(const t_vector3 v, const t_vector3 norm);
float		ksx_vec3_dist(const t_vector3 v1, const t_vector3 v2);
t_vector3	ksx_vec3_resize(const t_vector3 v, const float size);
t_matrix3 	ksx_vec3_tensor(const t_vector3 v1, const t_vector3 v2);

// ksx_vec3_math03.c
float		ksx_vec3_dot(const t_vector3 v1, const t_vector3 v2);
t_vector3	ksx_vec3_multi(const t_vector3 v, const float scalar);
t_vector3	ksx_vec3_div(const t_vector3 v, const float scalar);

#endif	// KSX_VEC3_MATH_H