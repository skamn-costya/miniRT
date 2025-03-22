/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/22 17:26:02 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include "ksx_object.h"
#include <math.h>

static void	ksx_basis_compute_rm(t_vector3 *p_n, t_vector3 *p_nn,
				t_matrix3 *p_rm);

void	ksx_basis_set_norm(t_basis *p_basis, t_vector3 *p_norm)
{
	t_vector3	tmp_v3;
	t_matrix3	rm;

	if (!p_norm->x && !p_norm->y && !p_norm->z)
	{
		p_basis->i = ksx_vec3_set(1.f, 0.f, 0.f);
		p_basis->j = ksx_vec3_set(0.f, 1.f, 0.f);
		p_basis->k = ksx_vec3_set(0.f, 0.f, 1.f);
		return ;
	}
	p_basis->j = ksx_vec3_unit(p_norm);
	ksx_m3_identity(&rm);
	tmp_v3 = ksx_vec3_set(0.f, 1.f, 0.f);
	ksx_basis_compute_rm(&tmp_v3, &p_basis->j, &rm);
	tmp_v3 = ksx_vec3_set(1.f, 0.f, 0.f);
	p_basis->i = ksx_m3_vec3(&rm, &tmp_v3);
	tmp_v3 = ksx_vec3_set(0.f, 0.f, 1.f);
	p_basis->k = ksx_m3_vec3(&rm, &tmp_v3);
}

void	ksx_basis_set_norm_cam(t_basis *p_basis, t_vector3 *p_norm)
{
	t_vector3	tmp_v3;
	t_matrix3	rm;

	if (!p_norm->x && !p_norm->y && !p_norm->z)
	{
		p_basis->i = ksx_vec3_set(1.f, 0.f, 0.f);
		p_basis->j = ksx_vec3_set(0.f, 1.f, 0.f);
		p_basis->k = ksx_vec3_set(0.f, 0.f, 1.f);
		return ;
	}
	p_basis->k = ksx_vec3_unit(p_norm);
	ksx_m3_identity(&rm);
	tmp_v3 = ksx_vec3_set(0.f, 0.f, 1.f);
	ksx_basis_compute_rm(&tmp_v3, &p_basis->k, &rm);
	tmp_v3 = ksx_vec3_set(1.f, 0.f, 0.f);
	p_basis->i = ksx_m3_vec3(&rm, &tmp_v3);
	tmp_v3 = ksx_vec3_set(0.f, 1.f, 0.f);
	p_basis->j = ksx_m3_vec3(&rm, &tmp_v3);
}

static void	ksx_basis_compute_rm(t_vector3 *p_n, t_vector3 *p_nn,
		t_matrix3 *p_rm)
{
	t_vector3	axis;
	float		f[7];

	axis = ksx_vec3_cross(p_n, p_nn);
	f[0] = ksx_vec3_dot(p_n, p_nn) / (ksx_vec3_mag(p_n) * ksx_vec3_mag(p_nn));
	if (f[0] < -1.f || f[0] > 1.f)
		f[0] = fmaxf(-1.0f, fminf(f[0], 1.0f));
	f[1] = acosf(f[0]);
	if (fabsf(f[1]) < 1e-6 || ksx_vec3_mag(&axis) < 1e-6)
		return ;
	axis = ksx_vec3_unit(&axis);
	f[2] = axis.x;
	f[3] = axis.y;
	f[4] = axis.z;
	f[5] = sinf(f[1]);
	f[6] = 1.f - f[0];
	p_rm->e_11 = f[0] + f[2] * f[2] * f[6];
	p_rm->e_12 = f[2] * f[3] * f[6] - f[4] * f[5];
	p_rm->e_13 = f[2] * f[4] * f[6] + f[3] * f[5];
	p_rm->e_21 = f[3] * f[2] * f[6] + f[4] * f[5];
	p_rm->e_22 = f[0] + f[3] * f[3] * f[6];
	p_rm->e_23 = f[3] * f[4] * f[6] - f[2] * f[5];
	p_rm->e_31 = f[4] * f[2] * f[6] - f[3] * f[5];
	p_rm->e_32 = f[4] * f[3] * f[6] + f[2] * f[5];
	p_rm->e_33 = f[0] + f[4] * f[4] * f[6];
}

// j' (0.577, 0.577, 0.577)
// i' (0.789, 0.577, -0.211)
// k' (-0.211, 0.577, 0.789)

// [0.788675, 0.57735, -0.211325]
// [-0.57735, 0.57735, -0.57735]
// [-0.211325, 0.57735, 0.788675]

// (0.577,0.577,−0.577)
// (0.789,0.577,−0.211)
// (−0.211,0.577,0.789)

// R =
// [[0.789 0.577 −0.211]
// [​0.577 0.577 0.577]
// [​−0.211 0.577 0.789]]