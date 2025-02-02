/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 23:44:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>

static float	ksx_determinant4_1(const t_matrix44 m);
static float	ksx_determinant4_2(const t_matrix44 m);

float	ksx_determinant2(const t_matrix22 m)
{
	float	f;

	f = m.e_11 * m.e_22;
	f -= m.e_12 * m.e_21;
	return (f);
}

float	ksx_determinant3(const t_matrix33 m)
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

float	ksx_determinant4(const t_matrix44 m)
{
	float	f;

	f = ksx_determinant4_1(m);
	f += ksx_determinant4_2(m);
	return (f);
}

static float	ksx_determinant4_1(const t_matrix44 m)
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

static float	ksx_determinant4_2(const t_matrix44 m)
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
