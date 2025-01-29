/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/29 23:16:59 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ksx_utils.h"

static float	determinant4_1(t_matrix_f4 m);
static float	determinant4_2(t_matrix_f4 m);

float	determinant2(t_matrix_f2 m)
{
	float	f;

	f = m.e[M_11] * m.e[M_22];
	f -= m.e[M_12] * m.e[M_21];
	return (f);
}

float	determinant3(t_matrix_f3 m)
{
	float	f;

	f = m.e[M_11] * m.e[M_22] * m.e[M_33];
	f += m.e[M_12] * m.e[M_23] * m.e[M_31];
	f += m.e[M_13] * m.e[M_21] * m.e[M_32];
	f -= m.e[M_13] * m.e[M_22] * m.e[M_31];
	f -= m.e[M_11] * m.e[M_23] * m.e[M_32];
	f -= m.e[M_12] * m.e[M_21] * m.e[M_33];
	return (f);
}

float	determinant4(t_matrix_f4 m)
{
	float	f;

	f = determinant4_1(m);
	f += determinant4_2(m);
	return (f);
}

static float	determinant4_1(t_matrix_f4 m)
{
	float	f;

	f = m.e[M_11] * m.e[M_22] * m.e[M_33] * m.e[M_44];
	f -= m.e[M_11] * m.e[M_22] * m.e[M_34] * m.e[M_43];
	f -= m.e[M_11] * m.e[M_23] * m.e[M_32] * m.e[M_44];
	f += m.e[M_11] * m.e[M_23] * m.e[M_34] * m.e[M_42];
	f += m.e[M_11] * m.e[M_24] * m.e[M_32] * m.e[M_43];
	f -= m.e[M_11] * m.e[M_24] * m.e[M_33] * m.e[M_42];
	f -= m.e[M_12] * m.e[M_21] * m.e[M_33] * m.e[M_44];
	f += m.e[M_12] * m.e[M_21] * m.e[M_34] * m.e[M_43];
	f += m.e[M_12] * m.e[M_23] * m.e[M_31] * m.e[M_44];
	f -= m.e[M_12] * m.e[M_23] * m.e[M_34] * m.e[M_41];
	f -= m.e[M_12] * m.e[M_24] * m.e[M_31] * m.e[M_43];
	f += m.e[M_12] * m.e[M_24] * m.e[M_33] * m.e[M_41];
	return (f);
}

static float	determinant4_2(t_matrix_f4 m)
{
	float	f;

	f = m.e[M_13] * m.e[M_21] * m.e[M_32] * m.e[M_44];
	f -= m.e[M_13] * m.e[M_21] * m.e[M_34] * m.e[M_42];
	f -= m.e[M_13] * m.e[M_22] * m.e[M_31] * m.e[M_44];
	f += m.e[M_13] * m.e[M_22] * m.e[M_34] * m.e[M_41];
	f += m.e[M_13] * m.e[M_24] * m.e[M_31] * m.e[M_42];
	f -= m.e[M_13] * m.e[M_24] * m.e[M_32] * m.e[M_41];
	f -= m.e[M_14] * m.e[M_21] * m.e[M_32] * m.e[M_43];
	f += m.e[M_14] * m.e[M_21] * m.e[M_33] * m.e[M_42];
	f += m.e[M_14] * m.e[M_22] * m.e[M_31] * m.e[M_43];
	f -= m.e[M_14] * m.e[M_22] * m.e[M_33] * m.e[M_41];
	f -= m.e[M_14] * m.e[M_23] * m.e[M_31] * m.e[M_42];
	f += m.e[M_14] * m.e[M_23] * m.e[M_32] * m.e[M_41];
	return (f);
}
