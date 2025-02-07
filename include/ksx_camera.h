/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_camera.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:54:53 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/07 00:39:35 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_CAMERA_H
# define KSX_CAMERA_H

# include "ksx_graphics.h"

// ksx_camera01.c

t_camera	ksx_create_camera(t_vector3 center, t_vector3 norm, float fov);
void		ksx_set_camera_pm(t_camera *p_camera, float far);

#endif	// KSX_CAMERA_H //
