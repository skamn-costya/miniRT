/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_m4_math01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:22:40 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/08 22:24:46 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include <math.h>

void	ksx_m4_reset(t_matrix4 *p_m)
{
	p_m->e_11 = 0.f;
	p_m->e_12 = 0.f;
	p_m->e_13 = 0.f;
	p_m->e_14 = 0.f;
	p_m->e_21 = 0.f;
	p_m->e_22 = 0.f;
	p_m->e_23 = 0.f;
	p_m->e_24 = 0.f;
	p_m->e_31 = 0.f;
	p_m->e_32 = 0.f;
	p_m->e_33 = 0.f;
	p_m->e_34 = 0.f;
	p_m->e_41 = 0.f;
	p_m->e_42 = 0.f;
	p_m->e_43 = 0.f;
	p_m->e_44 = 0.f;
}

static void	ksx_m4_multi_(const t_matrix4 *p_m1,
			const t_matrix4 *p_m2, t_matrix4 *p_m);

t_matrix4	ksx_m4_multi(const t_matrix4 *p_m1, const t_matrix4 *p_m2)
{
	t_matrix4	m;

	m.e_11 = p_m1->e_11 * p_m2->e_11 + p_m1->e_12 * p_m2->e_21
		+ p_m1->e_13 * p_m2->e_31 + p_m1->e_14 * p_m2->e_41;
	m.e_12 = p_m1->e_11 * p_m2->e_12 + p_m1->e_12 * p_m2->e_22
		+ p_m1->e_13 * p_m2->e_32 + p_m1->e_14 * p_m2->e_42;
	m.e_13 = p_m1->e_11 * p_m2->e_13 + p_m1->e_12 * p_m2->e_23
		+ p_m1->e_13 * p_m2->e_33 + p_m1->e_14 * p_m2->e_43;
	m.e_14 = p_m1->e_11 * p_m2->e_14 + p_m1->e_12 * p_m2->e_24
		+ p_m1->e_13 * p_m2->e_34 + p_m1->e_14 * p_m2->e_44;
	m.e_21 = p_m1->e_21 * p_m2->e_11 + p_m1->e_22 * p_m2->e_21
		+ p_m1->e_23 * p_m2->e_31 + p_m1->e_24 * p_m2->e_41;
	m.e_22 = p_m1->e_21 * p_m2->e_12 + p_m1->e_22 * p_m2->e_22
		+ p_m1->e_23 * p_m2->e_32 + p_m1->e_24 * p_m2->e_42;
	m.e_23 = p_m1->e_21 * p_m2->e_13 + p_m1->e_22 * p_m2->e_23
		+ p_m1->e_23 * p_m2->e_33 + p_m1->e_24 * p_m2->e_43;
	m.e_24 = p_m1->e_21 * p_m2->e_14 + p_m1->e_22 * p_m2->e_24
		+ p_m1->e_23 * p_m2->e_34 + p_m1->e_24 * p_m2->e_44;
	ksx_m4_multi_(p_m1, p_m2, &m);
	return (m);
}

static void	ksx_m4_multi_(const t_matrix4 *p_m1,
					const t_matrix4 *p_m2, t_matrix4 *p_m)
{
	p_m->e_31 = p_m1->e_31 * p_m2->e_11 + p_m1->e_32 * p_m2->e_21
		+ p_m1->e_33 * p_m2->e_31 + p_m1->e_34 * p_m2->e_41;
	p_m->e_32 = p_m1->e_31 * p_m2->e_12 + p_m1->e_32 * p_m2->e_22
		+ p_m1->e_33 * p_m2->e_32 + p_m1->e_34 * p_m2->e_42;
	p_m->e_33 = p_m1->e_31 * p_m2->e_13 + p_m1->e_32 * p_m2->e_23
		+ p_m1->e_33 * p_m2->e_33 + p_m1->e_34 * p_m2->e_43;
	p_m->e_34 = p_m1->e_31 * p_m2->e_14 + p_m1->e_32 * p_m2->e_24
		+ p_m1->e_33 * p_m2->e_34 + p_m1->e_34 * p_m2->e_44;
	p_m->e_41 = p_m1->e_41 * p_m2->e_11 + p_m1->e_42 * p_m2->e_21
		+ p_m1->e_43 * p_m2->e_31 + p_m1->e_44 * p_m2->e_41;
	p_m->e_42 = p_m1->e_41 * p_m2->e_12 + p_m1->e_42 * p_m2->e_22
		+ p_m1->e_43 * p_m2->e_32 + p_m1->e_44 * p_m2->e_42;
	p_m->e_43 = p_m1->e_41 * p_m2->e_13 + p_m1->e_42 * p_m2->e_23
		+ p_m1->e_43 * p_m2->e_33 + p_m1->e_44 * p_m2->e_43;
	p_m->e_44 = p_m1->e_41 * p_m2->e_14 + p_m1->e_42 * p_m2->e_24
		+ p_m1->e_43 * p_m2->e_34 + p_m1->e_44 * p_m2->e_44;
}

t_vector4	ksx_m4_vec4(const t_matrix4 *p_m, const t_vector4 *p_v)
{
	t_vector4	v4;

	v4.x = (p_m->e_11 * p_v->x) + (p_m->e_12 * p_v->y)
		+ (p_m->e_13 * p_v->z) + (p_m->e_14 * p_v->w);
	v4.y = (p_m->e_21 * p_v->x) + (p_m->e_22 * p_v->y)
		+ (p_m->e_23 * p_v->z) + (p_m->e_24 * p_v->w);
	v4.z = (p_m->e_31 * p_v->x) + (p_m->e_32 * p_v->y)
		+ (p_m->e_33 * p_v->z) + (p_m->e_34 * p_v->w);
	v4.w = (p_m->e_41 * p_v->x) + (p_m->e_42 * p_v->y)
		+ (p_m->e_43 * p_v->z) + (p_m->e_44 * p_v->w);
	return (v4);
}
