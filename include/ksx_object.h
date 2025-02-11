/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_object.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:30:32 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 20:36:39 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_OBJECT_H
# define KSX_OBJECT_H

// ksx_object.c
t_object	*ksx_create_object(t_vector3 *p_center);

t_vertex	**ksx_obj_add_vers(t_object *p_object, uint32_t size);
t_triangle	**ksx_obj_new_tris(uint32_t size);



// ksx_rotation.c
void		ksx_rotation(t_vector3 *point, float angle_x,
				float angle_y, float angle_z);
void		ksx_rotation_obj(t_object *p_object, float angle_x,
				float angle_y, float angle_z);
void		ksx_angle_check(float *angle);

// ksx_translate.c
void		ksx_translate(t_vector3 *p_point, t_vector3 *p_center,
				t_vector3 *p_result);
void		ksx_translate_obj(t_object *p_object);

// ksx_transform.c
void		ksx_transform(t_vector3 *p_point, t_matrix4 *p_mt,
				t_vector3 *p_result);
void	ksx_transform_obj(t_object *p_object, t_basis *p_basis);
void 		ksx_get_tm(t_matrix4 *p_m4, t_basis *p_basis);

#endif	// KSX_OBJECT_H