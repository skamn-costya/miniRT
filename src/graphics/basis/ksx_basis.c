/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/25 13:09:15 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_object.h"
#include <math.h>

// static void	ksx_basis111(t_basis *p_basis);

// t_basis	ksx_basis_get(const t_vector3 *p_norm)
// {
// 	t_basis		basis;
// 	t_vector3	tmp_v3;

// 	basis.o = ksx_vec3_set(0, 0, 0);
// 	if (!p_norm->x && !p_norm->z)
// 		return (ksx_basis111(&basis), basis);
// 	basis.j = ksx_vec3_unit(p_norm);
// 	if (p_norm->x > 0)
// 	{
// 		tmp_v3 = ksx_vec3_set(0, 0, 1);
// 		tmp_v3 = ksx_vec3_cross(&tmp_v3, &basis.j);
// 		basis.i = ksx_vec3_unit(&tmp_v3);
// 		basis.k = ksx_vec3_cross(&basis.j, &basis.i);
// 	}
// 	else
// 	{
// 		tmp_v3 = ksx_vec3_set(1, 0, 0);
// 		tmp_v3 = ksx_vec3_cross(&tmp_v3, &basis.j);
// 		basis.k = ksx_vec3_unit(&tmp_v3);
// 		basis.i = ksx_vec3_cross(&basis.j, &basis.k);
// 	}
// 	return (basis);
// }

void	ksx_basis_set_norm(t_basis *p_basis, t_vector3 *p_norm)
{
	t_vector3	tmp_v3;

	if (!p_norm->x && !p_norm->y && !p_norm->z)
		p_norm->z = 1.f;
	p_basis->k = ksx_vec3_unit(p_norm);
	if (fabsf(p_basis->k.x) < fabsf(p_basis->k.y)
		&& fabsf(p_basis->k.x) < fabsf(p_basis->k.z))
		tmp_v3 = ksx_vec3_set(1.f, 0, 0);
	else if (fabsf(p_basis->k.y) < fabsf(p_basis->k.z))
		tmp_v3 = ksx_vec3_set(0, 1.f, 0);
	else
		tmp_v3 = ksx_vec3_set(0, 0, 1.f);
	tmp_v3 = ksx_vec3_cross(&tmp_v3, &p_basis->k);
	p_basis->i = ksx_vec3_unit(&tmp_v3);
	p_basis->j = ksx_vec3_cross(&p_basis->k, &p_basis->i);
}

// void	ksx_basis_camera(t_camera *p_camera, t_vector3 *p_norm)
// {
// 	t_vector3	tmp_v3;

// 	if (!p_norm->x && !p_norm->y && !p_norm->z)
// 		p_norm->z = 1;
// 	p_camera->basis.k = ksx_vec3_unit(p_norm);
// 	if (fabsf(p_camera->basis.k.x) < fabsf(p_camera->basis.k.y)
// 		&& fabsf(p_camera->basis.k.x) < fabsf(p_camera->basis.k.z))
// 		tmp_v3 = ksx_vec3_set(1, 0, 0);
// 	else if (fabsf(p_camera->basis.k.y) < fabsf(p_camera->basis.k.z))
// 		tmp_v3 = ksx_vec3_set(0, 1, 0);
// 	else
// 		tmp_v3 = ksx_vec3_set(0, 0, 1);
// 	tmp_v3 = ksx_vec3_cross(&tmp_v3, &p_camera->basis.k);
// 	p_camera->basis.i = ksx_vec3_unit(&tmp_v3);
// 	p_camera->basis.j = ksx_vec3_cross(&p_camera->basis.k, &p_camera->basis.i);
// }

// static void	ksx_basis111(t_basis *p_basis)
// {
// 	p_basis->i = ksx_vec3_set(1, 0, 0);
// 	p_basis->j = ksx_vec3_set(0, 1, 0);
// 	p_basis->k = ksx_vec3_set(0, 0, 1);
// }
