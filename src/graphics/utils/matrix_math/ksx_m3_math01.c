/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_mmath01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:22:40 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/09 01:12:18 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include <math.h>

void	ksx_mreset(t_matrix3 *p_m)
{
	p_m->e_11 = 0.f;
	p_m->e_12 = 0.f;
	p_m->e_13 = 0.f;
	p_m->e_21 = 0.f;
	p_m->e_22 = 0.f;
	p_m->e_23 = 0.f;
	p_m->e_31 = 0.f;
	p_m->e_32 = 0.f;
	p_m->e_33 = 0.f;
}

t_matrix3	ksx_m3_multi(const t_matrix3 *p_m1, const t_matrix3 *p_m2)
{
	t_matrix3	m3;

	m3.e_11 = p_m1->e_11 * p_m2->e_11 + p_m1->e_12 * p_m2->e_21 + p_m1->e_13 * p_m2->e_31;
	m3.e_12 = p_m1->e_11 * p_m2->e_12 + p_m1->e_12 * p_m2->e_22 + p_m1->e_13 * p_m2->e_32;
	m3.e_13 = p_m1->e_11 * p_m2->e_13 + p_m1->e_12 * p_m2->e_23 + p_m1->e_13 * p_m2->e_33;
	m3.e_21 = p_m1->e_21 * p_m2->e_11 + p_m1->e_22 * p_m2->e_21 + p_m1->e_23 * p_m2->e_31;
	m3.e_22 = p_m1->e_21 * p_m2->e_12 + p_m1->e_22 * p_m2->e_22 + p_m1->e_23 * p_m2->e_32;
	m3.e_23 = p_m1->e_21 * p_m2->e_13 + p_m1->e_22 * p_m2->e_23 + p_m1->e_23 * p_m2->e_33;
	m3.e_31 = p_m1->e_31 * p_m2->e_11 + p_m1->e_32 * p_m2->e_21 + p_m1->e_33 * p_m2->e_31;
	m3.e_32 = p_m1->e_31 * p_m2->e_12 + p_m1->e_32 * p_m2->e_22 + p_m1->e_33 * p_m2->e_32;
	m3.e_33 = p_m1->e_31 * p_m2->e_13 + p_m1->e_32 * p_m2->e_23 + p_m1->e_33 * p_m2->e_33;
	return (m3);
}

t_vector3	ksx_mvec3(const t_matrix3 *p_m, const t_vector3 *p_v)
{
	t_vector3	v3;

	v3.x = (p_m->e_11 * p_v->x) + (p_m->e_12 * p_v->y) + (p_m->e_13 * p_v->z);
	v3.y = (p_m->e_21 * p_v->x) + (p_m->e_22 * p_v->y) + (p_m->e_23 * p_v->z);
	v3.z = (p_m->e_31 * p_v->x) + (p_m->e_32 * p_v->y) + (p_m->e_33 * p_v->z);
	return (v3);
}
