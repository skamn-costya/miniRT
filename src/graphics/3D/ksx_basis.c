/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/06 14:33:07 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include <math.h>

t_basis	ksx_get_basis(const t_vector3 norm, const t_vector3 center)
{
	t_basis		basis;
	t_vector3	tmp_v3;

	basis.o = center;
	if ((norm.y == 0 && norm.z == 0)
		|| (norm.x == 0 && norm.z == 0)
		|| (norm.x == 0 && norm.y == 0))
	{
		basis.u = ksx_vec3_set(1, 0, 0);
		basis.v = ksx_vec3_set(0, 1, 0);
		basis.w = ksx_vec3_set(0, 0, 1);
		basis.set = 0;
		return (basis);
	}
	tmp_v3 = ksx_vec3_sub(norm, center);
	basis.w = ksx_vec3_unit(tmp_v3);
	tmp_v3 = ksx_vec3_set(0, 1, 0);
	tmp_v3 = ksx_vec3_cross(basis.w, tmp_v3);
	basis.u = ksx_vec3_div(tmp_v3, ksx_vec3_mag(tmp_v3));
	basis.v = ksx_vec3_cross(basis.w, basis.u);
	basis.set = 1;
	return (basis);
}
