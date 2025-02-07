/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/07 10:44:03 by ksorokol         ###   ########.fr       */
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
		basis.x_ = ksx_vec3_set(1, 0, 0);
		basis.y_ = ksx_vec3_set(0, 1, 0);
		basis.z_ = ksx_vec3_set(0, 0, 1);
		basis.set = 0;
		return (basis);
	}
	tmp_v3 = ksx_vec3_sub(norm, center);
	basis.z_ = ksx_vec3_unit(tmp_v3);
	tmp_v3 = ksx_vec3_set(0, 1, 0);
	tmp_v3 = ksx_vec3_cross(basis.z_, tmp_v3);
	basis.x_ = ksx_vec3_div(tmp_v3, ksx_vec3_mag(tmp_v3));
	basis.y_ = ksx_vec3_cross(basis.z_, basis.x_);
	basis.set = 1;
	return (basis);
}
