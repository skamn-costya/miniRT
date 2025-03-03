/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/03 21:35:39 by ksorokol         ###   ########.fr       */
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
		p_basis->k = ksx_vec3_set(0.f, 0.f, 1.f);
	else
		p_basis->k = ksx_vec3_unit(p_norm);
	if (fabsf(p_basis->k.x) < fabsf(p_basis->k.y)
		&& fabsf(p_basis->k.x) < fabsf(p_basis->k.z))
		tmp_v3 = ksx_vec3_set(1.f, 0.f, 0.f);
	else if (fabsf(p_basis->k.y) < fabsf(p_basis->k.z))
		tmp_v3 = ksx_vec3_set(0.f, 1.f, 0.f);
	else
		tmp_v3 = ksx_vec3_set(0.f, 0.f, 1.f);
	tmp_v3 = ksx_vec3_cross(&tmp_v3, &p_basis->k);
	p_basis->i = ksx_vec3_unit(&tmp_v3);
	p_basis->j = ksx_vec3_cross(&p_basis->k, &p_basis->i);
}

void	ksx_basis_copy_len(t_basis *p_basis_src, t_basis *p_basis_des)
{
	ksx_vec3_resize(&p_basis_des->i, ksx_vec3_mag(&p_basis_src->i));
	ksx_vec3_resize(&p_basis_des->j, ksx_vec3_mag(&p_basis_src->j));
	ksx_vec3_resize(&p_basis_des->k, ksx_vec3_mag(&p_basis_src->k));
}

// void	ksx_basis_copy(t_basis *p_basis_src, t_basis *p_basis_des)
// {
// 	p_basis_des->i = p_basis_src->i;
// 	p_basis_des->j = p_basis_src->j;
// 	p_basis_des->k = p_basis_src->k;
// }

uint32_t	ksx_basis_check(t_basis *p_basis, uint32_t axis)
{
	if (p_basis->ijko[axis].x < 0 || p_basis->ijko[axis].y < 0
		|| p_basis->ijko[axis].z < 0)
		return (0);
	return (1);
}

void	ksx_basis_unit(t_basis *p_basis)
{
	ksx_vec3_resize(&p_basis->i, 1.f);
	ksx_vec3_resize(&p_basis->j, 1.f);
	ksx_vec3_resize(&p_basis->k, 1.f);
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
