/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_object.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:30:32 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/06 15:38:46 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_OBJECT_H
# define KSX_OBJECT_H

// ksx_object.c
t_object	*ksx_create_object(t_vector3 *p_center);
void		ksx_obj_copy_vrts(t_object *p_object, uint32_t idx_src,
				uint32_t idx_des);
void		ksx_obj_copy_boxvrts(t_vertex *p_vrt, uint32_t idx1,
				uint32_t idx2, uint32_t size);
void		ksx_obj_set_axis(t_vertex *p_ver, t_basis *p_basis);

t_vertex	**ksx_obj_add_vers(t_object *p_object, uint32_t size);
t_vertex	**ksx_obj_add_vnrm(t_object *p_object, uint32_t size);
t_triangle	**ksx_obj_new_tris(uint32_t size);
t_triangle	**ksx_obj_add_tris(t_object *p_object, uint32_t size);
void		ksx_obj_tris2box(t_object *p_object);

// ksx_qrotation.c
void		ksx_qrotation(t_vector3 *point, float angle, t_vector3 *p_v);
// void		ksx_qrotation_obj(t_object *p_object, float angle, t_vector3 v);

// ksx_translate.c
void		ksx_translate(t_vector3 *p_point, t_vector3 *p_center,
				t_vector3 *p_result);
void		ksx_translate_obj(t_object *p_object);

// ksx_transform.c
void		ksx_transform(t_vector3 *p_point, t_matrix4 *p_mt,
				t_vector3 *p_result);
void		ksx_obj_transform(t_object *p_object);
void		ksx_get_tm(t_matrix4 *p_m4, t_basis *p_basis);

#endif	// KSX_OBJECT_H