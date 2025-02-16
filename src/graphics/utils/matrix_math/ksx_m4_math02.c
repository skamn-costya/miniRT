/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_m4_math02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:22:40 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/15 08:49:50 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_m4_math.h"
#include <math.h>

static float	ksx_m4_det_1(const t_matrix4 *p_m);
static float	ksx_m4_det_2(const t_matrix4 *p_m);

float	ksx_m4_det(const t_matrix4 *p_m)
{
	float	result;

	result = ksx_m4_det_1(p_m);
	result += ksx_m4_det_2(p_m);
	return (result);
}

static float	ksx_m4_det_1(const t_matrix4 *p_m)
{
	float	result;

	result = p_m->e_11 * p_m->e_22 * p_m->e_33 * p_m->e_44;
	result -= p_m->e_11 * p_m->e_22 * p_m->e_34 * p_m->e_43;
	result -= p_m->e_11 * p_m->e_23 * p_m->e_32 * p_m->e_44;
	result += p_m->e_11 * p_m->e_23 * p_m->e_34 * p_m->e_42;
	result += p_m->e_11 * p_m->e_24 * p_m->e_32 * p_m->e_43;
	result -= p_m->e_11 * p_m->e_24 * p_m->e_33 * p_m->e_42;
	result -= p_m->e_12 * p_m->e_21 * p_m->e_33 * p_m->e_44;
	result += p_m->e_12 * p_m->e_21 * p_m->e_34 * p_m->e_43;
	result += p_m->e_12 * p_m->e_23 * p_m->e_31 * p_m->e_44;
	result -= p_m->e_12 * p_m->e_23 * p_m->e_34 * p_m->e_41;
	result -= p_m->e_12 * p_m->e_24 * p_m->e_31 * p_m->e_43;
	result += p_m->e_12 * p_m->e_24 * p_m->e_33 * p_m->e_41;
	return (result);
}

static float	ksx_m4_det_2(const t_matrix4 *p_m)
{
	float	result;

	result = p_m->e_13 * p_m->e_21 * p_m->e_32 * p_m->e_44;
	result -= p_m->e_13 * p_m->e_21 * p_m->e_34 * p_m->e_42;
	result -= p_m->e_13 * p_m->e_22 * p_m->e_31 * p_m->e_44;
	result += p_m->e_13 * p_m->e_22 * p_m->e_34 * p_m->e_41;
	result += p_m->e_13 * p_m->e_24 * p_m->e_31 * p_m->e_42;
	result -= p_m->e_13 * p_m->e_24 * p_m->e_32 * p_m->e_41;
	result -= p_m->e_14 * p_m->e_21 * p_m->e_32 * p_m->e_43;
	result += p_m->e_14 * p_m->e_21 * p_m->e_33 * p_m->e_42;
	result += p_m->e_14 * p_m->e_22 * p_m->e_31 * p_m->e_43;
	result -= p_m->e_14 * p_m->e_22 * p_m->e_33 * p_m->e_41;
	result -= p_m->e_14 * p_m->e_23 * p_m->e_31 * p_m->e_42;
	result += p_m->e_14 * p_m->e_23 * p_m->e_32 * p_m->e_41;
	return (result);
}
