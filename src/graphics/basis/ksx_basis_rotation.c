/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/20 01:23:52 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include <math.h>
#include <stdio.h>

void	ksx_qrotation_basis(t_basis *p_basis, float angle, t_vector3 v)
{
	float	len[3];

	len[X] = ksx_vec3_mag(&p_basis->i);
	len[Y] = ksx_vec3_mag(&p_basis->j);
	len[Z] = ksx_vec3_mag(&p_basis->k);
	ksx_qrotation(&p_basis->i, angle, &v);
	ksx_qrotation(&p_basis->j, angle, &v);
	ksx_qrotation(&p_basis->k, angle, &v);
	ksx_vec3_resize(&p_basis->i, len[X]);
	ksx_vec3_resize(&p_basis->j, len[Y]);
	ksx_vec3_resize(&p_basis->k, len[Z]);
}

void	ksx_qrotation_wbasis(t_basis *p_basis, float angle, t_vector3 v)
{
	float	len[3];

	len[X] = ksx_vec3_mag(&p_basis->w_i);
	len[Y] = ksx_vec3_mag(&p_basis->w_j);
	len[Z] = ksx_vec3_mag(&p_basis->w_k);
	ksx_qrotation(&p_basis->w_i, angle, &v);
	ksx_qrotation(&p_basis->w_j, angle, &v);
	ksx_qrotation(&p_basis->w_k, angle, &v);
	ksx_vec3_resize(&p_basis->w_i, len[X]);
	ksx_vec3_resize(&p_basis->w_j, len[Y]);
	ksx_vec3_resize(&p_basis->w_k, len[Z]);
}
