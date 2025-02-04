/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/04 08:25:26 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>

static float	ksx_determinant4_1(const t_matrix4 m);
static float	ksx_determinant4_2(const t_matrix4 m);

float	ksx_determinant2(const t_matrix22 m)
{
	float	result;

	result = m.e_11 * m.e_22;
	result -= m.e_12 * m.e_21;
	return (result);
}

float	ksx_determinant3(const t_matrix3 m)
{
	float	result;

	result = m.e_11 * m.e_22 * m.e_33;
	result += m.e_12 * m.e_23 * m.e_31;
	result += m.e_13 * m.e_21 * m.e_32;
	result -= m.e_13 * m.e_22 * m.e_31;
	result -= m.e_11 * m.e_23 * m.e_32;
	result -= m.e_12 * m.e_21 * m.e_33;
	return (result);
}

float	ksx_determinant4(const t_matrix4 m)
{
	float	result;

	result = ksx_determinant4_1(m);
	result += ksx_determinant4_2(m);
	return (result);
}

static float	ksx_determinant4_1(const t_matrix4 m)
{
	float	result;

	result = m.e_11 * m.e_22 * m.e_33 * m.e_44;
	result -= m.e_11 * m.e_22 * m.e_34 * m.e_43;
	result -= m.e_11 * m.e_23 * m.e_32 * m.e_44;
	result += m.e_11 * m.e_23 * m.e_34 * m.e_42;
	result += m.e_11 * m.e_24 * m.e_32 * m.e_43;
	result -= m.e_11 * m.e_24 * m.e_33 * m.e_42;
	result -= m.e_12 * m.e_21 * m.e_33 * m.e_44;
	result += m.e_12 * m.e_21 * m.e_34 * m.e_43;
	result += m.e_12 * m.e_23 * m.e_31 * m.e_44;
	result -= m.e_12 * m.e_23 * m.e_34 * m.e_41;
	result -= m.e_12 * m.e_24 * m.e_31 * m.e_43;
	result += m.e_12 * m.e_24 * m.e_33 * m.e_41;
	return (result);
}

static float	ksx_determinant4_2(const t_matrix4 m)
{
	float	result;

	result = m.e_13 * m.e_21 * m.e_32 * m.e_44;
	result -= m.e_13 * m.e_21 * m.e_34 * m.e_42;
	result -= m.e_13 * m.e_22 * m.e_31 * m.e_44;
	result += m.e_13 * m.e_22 * m.e_34 * m.e_41;
	result += m.e_13 * m.e_24 * m.e_31 * m.e_42;
	result -= m.e_13 * m.e_24 * m.e_32 * m.e_41;
	result -= m.e_14 * m.e_21 * m.e_32 * m.e_43;
	result += m.e_14 * m.e_21 * m.e_33 * m.e_42;
	result += m.e_14 * m.e_22 * m.e_31 * m.e_43;
	result -= m.e_14 * m.e_22 * m.e_33 * m.e_41;
	result -= m.e_14 * m.e_23 * m.e_31 * m.e_42;
	result += m.e_14 * m.e_23 * m.e_32 * m.e_41;
	return (result);
}
