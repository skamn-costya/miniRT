/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/31 09:45:12 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_utils.h"

static float	determinant4_1(t_matrix4 m);
static float	determinant4_2(t_matrix4 m);

float	determinant2(t_matrix2 m)
{
	float	f;

	f = m.e_11 * m.e_22;
	f -= m.e_12 * m.e_21;
	return (f);
}

float	determinant3(t_matrix3 m)
{
	float	f;

	f = m.e_11 * m.e_22 * m.e_33;
	f += m.e_12 * m.e_23 * m.e_31;
	f += m.e_13 * m.e_21 * m.e_32;
	f -= m.e_13 * m.e_22 * m.e_31;
	f -= m.e_11 * m.e_23 * m.e_32;
	f -= m.e_12 * m.e_21 * m.e_33;
	return (f);
}

float	determinant4(t_matrix4 m)
{
	float	f;

	f = determinant4_1(m);
	f += determinant4_2(m);
	return (f);
}

static float	determinant4_1(t_matrix4 m)
{
	float	f;

	f = m.e_11 * m.e_22 * m.e_33 * m.e_44;
	f -= m.e_11 * m.e_22 * m.e_34 * m.e_43;
	f -= m.e_11 * m.e_23 * m.e_32 * m.e_44;
	f += m.e_11 * m.e_23 * m.e_34 * m.e_42;
	f += m.e_11 * m.e_24 * m.e_32 * m.e_43;
	f -= m.e_11 * m.e_24 * m.e_33 * m.e_42;
	f -= m.e_12 * m.e_21 * m.e_33 * m.e_44;
	f += m.e_12 * m.e_21 * m.e_34 * m.e_43;
	f += m.e_12 * m.e_23 * m.e_31 * m.e_44;
	f -= m.e_12 * m.e_23 * m.e_34 * m.e_41;
	f -= m.e_12 * m.e_24 * m.e_31 * m.e_43;
	f += m.e_12 * m.e_24 * m.e_33 * m.e_41;
	return (f);
}

static float	determinant4_2(t_matrix4 m)
{
	float	f;

	f = m.e_13 * m.e_21 * m.e_32 * m.e_44;
	f -= m.e_13 * m.e_21 * m.e_34 * m.e_42;
	f -= m.e_13 * m.e_22 * m.e_31 * m.e_44;
	f += m.e_13 * m.e_22 * m.e_34 * m.e_41;
	f += m.e_13 * m.e_24 * m.e_31 * m.e_42;
	f -= m.e_13 * m.e_24 * m.e_32 * m.e_41;
	f -= m.e_14 * m.e_21 * m.e_32 * m.e_43;
	f += m.e_14 * m.e_21 * m.e_33 * m.e_42;
	f += m.e_14 * m.e_22 * m.e_31 * m.e_43;
	f -= m.e_14 * m.e_22 * m.e_33 * m.e_41;
	f -= m.e_14 * m.e_23 * m.e_31 * m.e_42;
	f += m.e_14 * m.e_23 * m.e_32 * m.e_41;
	return (f);
}
