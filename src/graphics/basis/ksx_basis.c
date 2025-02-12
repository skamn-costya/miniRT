/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/12 16:19:17 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include <math.h>

static void	ksx_set_basis111(t_basis *p_basis);

t_basis	ksx_get_basis(const t_vector3 *p_norm, const t_vector3 *p_center)
{
	t_basis		basis;
	t_vector3	tmp_v3;

	if (!p_center)
	{
		basis.o = ksx_vec3_set(0, 0, 0);
		if (!p_norm->x && !p_norm->z)
			return (ksx_set_basis111(&basis), basis);
		basis.j = ksx_vec3_unit(p_norm);
		tmp_v3 = ksx_vec3_set(0, 0, 1);
		tmp_v3 = ksx_vec3_cross(&basis.j, &tmp_v3);
		basis.i = ksx_vec3_div(tmp_v3, -ksx_vec3_mag(&tmp_v3));
		basis.k = ksx_vec3_cross(&basis.i, &basis.j);
	}
	else
	{
		basis.o = *p_center;
		if (!p_norm->x && !p_norm->y)
			return (ksx_set_basis111(&basis), basis);
		tmp_v3 = ksx_vec3_sub(p_norm, &basis.o);
		basis.k = ksx_vec3_unit(&tmp_v3);
		tmp_v3 = ksx_vec3_set(0, 1, 0);
		tmp_v3 = ksx_vec3_cross(&basis.k, &tmp_v3);
		basis.i = ksx_vec3_div(tmp_v3, ksx_vec3_mag(&tmp_v3));
		basis.j = ksx_vec3_cross(&basis.k, &basis.i);
	}
	return (basis);
}

static void	ksx_set_basis111(t_basis *p_basis)
{
	p_basis->i = ksx_vec3_set(1, 0, 0);
	p_basis->j = ksx_vec3_set(0, 1, 0);
	p_basis->k = ksx_vec3_set(0, 0, 1);
}
