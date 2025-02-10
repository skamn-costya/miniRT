/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_rotation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:30:32 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/10 13:27:11 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_ROTATION_H
# define KSX_ROTATION_H

// ksx_rotation01.c
void	ksx_rotation_x(t_vector3 *point, float angle);
void	ksx_rotation_y(t_vector3 *point, float angle);
void	ksx_rotation_z(t_vector3 *point, float angle);
void	ksx_rotation(t_vector3 *point, float angle_x,
				float angle_y, float angle_z);
void	ksx_angle_check(float *angle);

// ksx_rotation02.c
void	ksx_rotation_tri_x(t_triangle *p_tri, float angle);
void	ksx_rotation_tri_y(t_triangle *p_tri, float angle);
void	ksx_rotation_tri_z(t_triangle *p_tri, float angle);
void	ksx_rotation_tri(t_triangle *p_tri, float angle_x,
				float angle_y, float angle_z);

// ksx_rotation03.c
void	ksx_rotation_obj_x(t_object *p_object, float angle);
void	ksx_rotation_obj_y(t_object *p_object, float angle);
void	ksx_rotation_obj_z(t_object *p_object, float angle);
void	ksx_rotation_obj(t_object *p_object, float angle_x,
				float angle_y, float angle_z);

#endif	// KSX_ROTATION_H