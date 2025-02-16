/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/16 13:08:35 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_object.h"
#include "ksx_basis.h"
#include <math.h>

// void	ksx_camera_move_basis(t_camera *p_camera, const t_vector3 *p_v)
// {
// 	p_camera->basis.o = ksx_vec3_add(&p_camera->basis.o, p_v);
// 	p_camera->basis.w_i = ksx_vec3_add(&p_camera->basis.w_i, p_v);
// 	p_camera->basis.w_j = ksx_vec3_add(&p_camera->basis.w_j, p_v);
// 	p_camera->basis.w_k = ksx_vec3_add(&p_camera->basis.w_k, p_v);
// }
