/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_object.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:30:32 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 11:49:41 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_OBJECT_H
# define KSX_OBJECT_H

// ksx_rotation.c
void	ksx_rotation(t_vector3 *point, float angle_x,
				float angle_y, float angle_z);
void	ksx_rotation_tri(t_triangle *p_tri, float angle_x,
				float angle_y, float angle_z);
void	ksx_rotation_obj(t_object *p_object, float angle_x,
				float angle_y, float angle_z);
void	ksx_angle_check(float *angle);

// ksx_translate.c
void	ksx_translate(t_vector3 *p_point, t_vector3 *p_center,
		t_vector3 *p_result);
void	ksx_translate_tri(t_triangle *p_tri, t_vector3 *p_center);
void	ksx_translate_obj(t_object *p_object);

#endif	// KSX_OBJECT_H