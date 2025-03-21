/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_norms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:39:47 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/17 13:26:04 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include "ksx_basis.h"
#include "ksx_object.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

t_vector3	transform_normal(const t_vector3 *p_normal,
	const t_basis *p_src_basis, const t_basis *p_tgt_basis)
{
	float		comp[3];
	t_vector3	result;
	t_vector3	temp[3];

	comp[0] = ksx_vec3_dot(p_normal, &p_src_basis->i);
	comp[1] = ksx_vec3_dot(p_normal, &p_src_basis->j);
	comp[2] = ksx_vec3_dot(p_normal, &p_src_basis->k);
	temp[0] = ksx_vec3_smulti(&p_tgt_basis->i, comp[0]);
	temp[1] = ksx_vec3_smulti(&p_tgt_basis->j, comp[1]);
	temp[2] = ksx_vec3_smulti(&p_tgt_basis->k, comp[2]);
	result = ksx_vec3_add(&temp[0], &temp[1]);
	result = ksx_vec3_add(&result, &temp[2]);
	return (ksx_vec3_unit(&result));
}

// void	transform_normals(t_object *p_object, uint32_t idx1, uint32_t idx2,
// 	t_basis *p_src_basis, t_basis *p_tgt_basis)
// {
// 	uint32_t	idx;
// 	t_basis		basis;
// 	t_basis		*p_basis;

// 	if (!p_src_basis)
// 	{
// 		p_basis = &basis;
// 		p_basis->o = ksx_vec3_set(0.f, 0.f, 0.f);
// 		ksx_basis_set_norm(p_basis, &p_basis->o);
// 	}
// 	else
// 		p_basis = p_src_basis;
// 	idx = 0;
// 	while (idx < p_object->size_vnrm)
// 	{
// 		p_object->pp_vnrm[idx]->olwc[idx2] = transform_normal(
// 				&p_object->pp_vnrm[idx]->olwc[idx1], p_basis, p_tgt_basis);
// 		idx++;
// 	}
// }
