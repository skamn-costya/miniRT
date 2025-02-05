/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils07.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/05 16:57:31 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include"ksx_vec3_math.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

t_vector3	ksx_point_m3(const t_vector3 point, const t_matrix3 m)
{
	t_vector3		point_;

	point_.x = point.x * m.e_11 + point.y * m.e_12 + point.z * m.e_13;
	point_.y = point.x * m.e_21 + point.y * m.e_22 + point.z * m.e_23;
	point_.z = point.x * m.e_31 + point.y * m.e_32 + point.z * m.e_33;
	return (point_);
}

void	ksx_m3_reset(t_matrix3 *p_m3)
{
	p_m3->e_11 = 0.f;
	p_m3->e_12 = 0.f;
	p_m3->e_13 = 0.f;
	p_m3->e_21 = 0.f;
	p_m3->e_22 = 0.f;
	p_m3->e_23 = 0.f;
	p_m3->e_31 = 0.f;
	p_m3->e_32 = 0.f;
	p_m3->e_33 = 0.f;
}

t_basis	ksx_get_basis(t_vector3 norm, t_vector3 point)
{
	t_basis		basis;
	t_vector3	tmp_v3;

	basis.w = ksx_vec3_unit(ksx_vec3_sub(point, norm));
	tmp_v3.x = 0;
	tmp_v3.y = 1;
	tmp_v3.z = 0;
	tmp_v3 = ksx_vec3_cross(basis.w, tmp_v3);
	basis.u = ksx_vec3_div(tmp_v3, ksx_vec3_mag(tmp_v3));
	basis.v = ksx_vec3_cross(basis.w, basis.u);
	return (basis);
}

// t_matrix3	ksx_get_transfor_matrix(const t_vector3 v1, const t_vector3 v2)
// {

// }
