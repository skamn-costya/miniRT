/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_camera.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:54:53 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/14 10:29:52 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_CAMERA_H
# define KSX_CAMERA_H

# include "ksx_graphics.h"

// ksx_camera01.c

t_camera	ksx_create_camera(t_vector3 center, t_vector3 norm, float fov);
void		ksx_camera_set_pm(t_camera *p_camera, float fov, float far);
void 		ksx_camera_set_vm(t_matrix4 *p_vm, t_basis *p_basis);
void 		ksx_camera_obj_vm(t_object *p_object, t_matrix4 *p_vm);

#endif	// KSX_CAMERA_H //
