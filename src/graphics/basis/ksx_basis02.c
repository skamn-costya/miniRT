/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/22 17:23:45 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include "ksx_object.h"
#include <math.h>

void	ksx_basis_copy_len(t_basis *p_basis_src, t_basis *p_basis_des)
{
	ksx_vec3_resize(&p_basis_des->i, ksx_vec3_mag(&p_basis_src->i));
	ksx_vec3_resize(&p_basis_des->j, ksx_vec3_mag(&p_basis_src->j));
	ksx_vec3_resize(&p_basis_des->k, ksx_vec3_mag(&p_basis_src->k));
}

// void	ksx_basis_copy(t_basis *p_basis_src, t_basis *p_basis_des)
// {
// 	p_basis_des->i = p_basis_src->i;
// 	p_basis_des->j = p_basis_src->j;
// 	p_basis_des->k = p_basis_src->k;
// }

uint32_t	ksx_basis_check(t_basis *p_basis, uint32_t axis)
{
	if (p_basis->ijko[axis].x < 0 || p_basis->ijko[axis].y < 0
		|| p_basis->ijko[axis].z < 0)
		return (0);
	return (1);
}

void	ksx_basis_unit(t_basis *p_basis)
{
	ksx_vec3_resize(&p_basis->i, 1.f);
	ksx_vec3_resize(&p_basis->j, 1.f);
	ksx_vec3_resize(&p_basis->k, 1.f);
}

// static void	ksx_basis111(t_basis *p_basis)
// {
// 	p_basis->i = ksx_vec3_set(1, 0, 0);
// 	p_basis->j = ksx_vec3_set(0, 1, 0);
// 	p_basis->k = ksx_vec3_set(0, 0, 1);
// }
