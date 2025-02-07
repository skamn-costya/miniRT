/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_rotation_norm01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/07 00:36:48 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_rotation.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include <math.h>

static void	ksx_set_elems_rot(t_matrix4 *p_vm, const t_basis basis);
static void	ksx_set_elems_pos(t_matrix4 *p_vm, const t_vector3 center);

void	ksx_create_vm(t_matrix4 *p_vm, const t_basis basis)
{
	t_matrix4	tmp_m4;

	ksx_set_elems_rot(p_vm, basis);
	ksx_set_elems_pos(&tmp_m4, basis.o);
	*p_vm = ksx_m4_multi(*p_vm, tmp_m4);
}

static void	ksx_set_elems_rot(t_matrix4 *p_vm, const t_basis basis)
{
	p_vm->e_11 = basis.u.x;
	p_vm->e_12 = basis.u.y;
	p_vm->e_13 = basis.u.z;
	p_vm->e_14 = 0;
	p_vm->e_21 = basis.v.x;
	p_vm->e_22 = basis.v.y;
	p_vm->e_23 = basis.v.z;
	p_vm->e_24 = 0;
	p_vm->e_31 = basis.w.x;
	p_vm->e_32 = basis.w.y;
	p_vm->e_33 = basis.w.z;
	p_vm->e_34 = 0;
	p_vm->e_41 = 0;
	p_vm->e_42 = 0;
	p_vm->e_43 = 0;
	p_vm->e_44 = 1;
}

static void	ksx_set_elems_pos(t_matrix4 *p_m4, const t_vector3 center)
{
	p_m4->e_11 = 1;
	p_m4->e_21 = 0;
	p_m4->e_31 = 0;
	p_m4->e_41 = 0;
	p_m4->e_12 = 0;
	p_m4->e_22 = 1;
	p_m4->e_32 = 0;
	p_m4->e_42 = 0;
	p_m4->e_13 = 0;
	p_m4->e_23 = 0;
	p_m4->e_33 = 1;
	p_m4->e_43 = 0;
	p_m4->e_14 = -center.x;
	p_m4->e_24 = -center.y;
	p_m4->e_34 = -center.z;
	p_m4->e_44 = 1;
}
