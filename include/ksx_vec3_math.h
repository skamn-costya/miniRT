/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_vec3_math.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:53:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/04 12:41:04 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"

// ksx_vec3_math01.c
t_vector3	ksx_add_vec3(const t_vector3 v1, const t_vector3 v2);
t_vector3	ksx_sub_vec3(const t_vector3 v1, const t_vector3 v2);
float		ksx_angle_vec3(const t_vector3 v1, const t_vector3 v2);
t_vector3	ksx_cross_vec3(const t_vector3 v1, const t_vector3 v2);
float		ksx_mag_vec3(const t_vector3 v);

// ksx_vec3_math02.c
t_vector3	ksx_unit_vec3(const t_vector3 norm);
t_vector3	ksx_norm_vec3(const t_vector3 v, const t_vector3 norm);
float		ksx_dist_vec3(const t_vector3 v1, const t_vector3 v2);
t_vector3	ksx_resize_vec3(const t_vector3 v1, const float new_size);
t_matrix3 	ksx_tensor_vec3(const t_vector3 v1, const t_vector3 v2);

// ksx_vec3_math03.c
float		ksx_dot_vec3(const t_vector3 v1, const t_vector3 v2);
t_vector3	ksx_mult_vec3(const t_vector3 v, const float scalar);
