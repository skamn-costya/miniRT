/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/17 00:13:02 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include <math.h>

// void	ksx_create_vm(t_matrix4 *p_vm, const t_basis *p_basis)
// {
// 	p_vm->e_11 = p_basis->i.x;
// 	p_vm->e_12 = p_basis->j.x;
// 	p_vm->e_13 = p_basis->k.x;
// 	p_vm->e_14 = -ksx_vec3_dot(p_basis->i, p_basis->o);
// 	p_vm->e_21 = p_basis->i.y;
// 	p_vm->e_22 = p_basis->j.y;
// 	p_vm->e_23 = p_basis->k.y;
// 	p_vm->e_24 = -ksx_vec3_dot(p_basis->j, p_basis->o);
// 	p_vm->e_31 = p_basis->i.z;
// 	p_vm->e_32 = p_basis->j.z;
// 	p_vm->e_33 = p_basis->k.z;
// 	p_vm->e_34 = -ksx_vec3_dot(p_basis->k, p_basis->o);
// 	p_vm->e_41 = 0;
// 	p_vm->e_42 = 0;
// 	p_vm->e_43 = 0;
// 	p_vm->e_44 = 1;
// }

// ksx_camera_change_basis(&camera)
// {}
