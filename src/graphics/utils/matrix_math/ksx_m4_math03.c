/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_m4_math03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:22:40 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/15 12:24:19 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_m3_math.h"
#include "ksx_m4_math.h"
#include <math.h>

static float	ksx_m4_invert_1(const t_matrix4 *p_m, uint32_t i, uint32_t j);

void 	ksx_m4_invert(const t_matrix4 *p_m1, t_matrix4 *p_m2)
{
	uint32_t	idx;
	float		det;
	t_matrix4	m4;

	det = ksx_m4_det(p_m1);
	if (det == 0)
		return (ksx_m4_reset(p_m2));
	idx = 0;
	while (idx < 16)
	{
		m4.elems[idx] = ksx_m4_invert_1(p_m1, idx / 4, idx % 4);
		m4.elems[idx] *= 1/det;
		idx++;
	}
	ksx_m4_transpose(&m4, p_m2);
}

static float	ksx_m4_invert_1(const t_matrix4 *p_m, uint32_t i, uint32_t j)
{
	t_matrix3	m3;
	uint32_t	idx[2];
	float		result;

	idx[0] = 0;
	idx[1] = 0;
	while (idx[0] < 16)
	{
		if (idx[0] / 4 != i && idx[0] % 4 != j)
		{
			m3.elems[idx[1]] = (*p_m).elems[idx[0]];
			idx[1]++;
		}
		idx[0]++;
	}
	result = ksx_m3_det(&m3) * powf(-1.f, i + j + 2);
	return (result);
}

void 	ksx_m4_transpose(const t_matrix4 *p_m1, t_matrix4 *p_m2)
{
	p_m2->e_11 = p_m1->e_11;
	p_m2->e_12 = p_m1->e_21;
	p_m2->e_13 = p_m1->e_31;
	p_m2->e_14 = p_m1->e_41;
	p_m2->e_21 = p_m1->e_12;
	p_m2->e_22 = p_m1->e_22;
	p_m2->e_23 = p_m1->e_32;
	p_m2->e_24 = p_m1->e_42;
	p_m2->e_31 = p_m1->e_13;
	p_m2->e_32 = p_m1->e_23;
	p_m2->e_33 = p_m1->e_33;
	p_m2->e_34 = p_m1->e_43;
	p_m2->e_41 = p_m1->e_14;
	p_m2->e_42 = p_m1->e_24;
	p_m2->e_43 = p_m1->e_34;
	p_m2->e_44 = p_m1->e_44;
}
