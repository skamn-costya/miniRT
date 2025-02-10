/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/10 13:53:00 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include <math.h>

t_basis	ksx_get_basis(const t_vector3 *p_norm, const t_vector3 *p_center)
{
	t_basis		basis;
	t_vector3	tmp_v3;

	basis.o = *p_center;
	if ((p_norm->y == 0 && p_norm->z == 0)
		|| (p_norm->x == 0 && p_norm->z == 0)
		|| (p_norm->x == 0 && p_norm->y == 0))
	{
		basis.i = ksx_vec3_set(1, 0, 0);
		basis.j = ksx_vec3_set(0, 1, 0);
		basis.k = ksx_vec3_set(0, 0, 1);
		basis.set = 0;
		return (basis);
	}
	tmp_v3 = ksx_vec3_sub(p_norm, p_center);
	basis.k = ksx_vec3_unit(&tmp_v3);
	tmp_v3 = ksx_vec3_set(0, 1, 0);
	tmp_v3 = ksx_vec3_cross(&basis.k, &tmp_v3);
	basis.i = ksx_vec3_div(tmp_v3, ksx_vec3_mag(&tmp_v3));
	basis.j = ksx_vec3_cross(&basis.k, &basis.i);
	basis.set = 1;
	return (basis);
}

// void 