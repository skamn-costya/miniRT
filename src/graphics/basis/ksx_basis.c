/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/17 16:08:19 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_object.h"
#include <math.h>
#include <stdio.h>

static void	ksx_set_basis111(t_basis *p_basis);

t_basis	ksx_get_basis_obj(const t_vector3 *p_norm)
{
	t_basis		basis;
	t_vector3	tmp_v3;

	basis.o = ksx_vec3_set(0, 0, 0);
	if (!p_norm->x && !p_norm->z)
		return (ksx_set_basis111(&basis), basis);
	basis.j = ksx_vec3_unit(p_norm);
	if (p_norm->x > 0)
	{
		tmp_v3 = ksx_vec3_set(0, 0, 1);
		tmp_v3 = ksx_vec3_cross(&tmp_v3, &basis.j);
		basis.i = ksx_vec3_unit(&tmp_v3);
		basis.k = ksx_vec3_cross(&basis.j, &basis.i);
	}
	else
	{
		tmp_v3 = ksx_vec3_set(1, 0, 0);
		tmp_v3 = ksx_vec3_cross(&tmp_v3, &basis.j);
		basis.k = ksx_vec3_unit(&tmp_v3);
		basis.i = ksx_vec3_cross(&basis.j, &basis.k);
	}
	return (basis);
}

void ksx_camera_set_basis(t_camera *p_camera, t_vector3 *p_norm)
{
    t_vector3 tmp_v3;

	if (!p_norm->x && !p_norm->y && !p_norm->z)
		p_norm->z = 1;
    p_camera->basis.k = ksx_vec3_unit(p_norm);
	
    // Choose a reference vector that is not nearly parallel to k.
    if (fabsf(p_camera->basis.k.x) < fabsf(p_camera->basis.k.y) && fabsf(p_camera->basis.k.x) < fabsf(p_camera->basis.k.z))
        tmp_v3 = ksx_vec3_set(1, 0, 0);
    else if (fabsf(p_camera->basis.k.y) < fabsf(p_camera->basis.k.z))
        tmp_v3 = ksx_vec3_set(0, 1, 0);
    else
        {tmp_v3 = ksx_vec3_set(0, 0, 1);}
    // Compute the right vector.
	tmp_v3 = ksx_vec3_cross(&tmp_v3, &p_camera->basis.k);
    p_camera->basis.i = ksx_vec3_unit(&tmp_v3);
    // Compute the up vector.
    p_camera->basis.j = ksx_vec3_cross(&p_camera->basis.k, &p_camera->basis.i);
}

// void	ksx_camera_set_basis(t_camera *p_camera, const t_vector3 *p_norm)
// {
// 	t_vector3	tmp_v3;

// 	if (!p_norm->x && !p_norm->y)
// 		return (ksx_set_basis111(&p_camera->basis));
// 	p_camera->basis.k = ksx_vec3_unit(p_norm);
// 	if (p_norm->x > 0)
// 	{
// 		tmp_v3 = ksx_vec3_set(0, 1, 0);
// 		tmp_v3 = ksx_vec3_cross(&tmp_v3, &p_camera->basis.k);
// 		p_camera->basis.i = ksx_vec3_unit(&tmp_v3);
// 		p_camera->basis.j = ksx_vec3_cross(&p_camera->basis.k,
// 				&p_camera->basis.i);
// 	}
// 	else
// 	{
// 		tmp_v3 = ksx_vec3_set(1, 0, 0);
// 		tmp_v3 = ksx_vec3_cross(&tmp_v3, &p_camera->basis.k);
// 		p_camera->basis.j = ksx_vec3_unit(&tmp_v3);
// 		p_camera->basis.i = ksx_vec3_cross(&p_camera->basis.k,
// 				&p_camera->basis.j);
// 	}
// }

static void	ksx_set_basis111(t_basis *p_basis)
{
	p_basis->i = ksx_vec3_set(1, 0, 0);
	p_basis->j = ksx_vec3_set(0, 1, 0);
	p_basis->k = ksx_vec3_set(0, 0, 1);
}

void	ksx_qrotation_basis(t_basis *p_basis, float angle, t_vector3 v)
{
	ksx_qrotation(&p_basis->i, angle, &v);
	ksx_qrotation(&p_basis->j, angle, &v);
	ksx_qrotation(&p_basis->k, angle, &v);
	p_basis->i = ksx_vec3_unit(&p_basis->i);
	p_basis->j = ksx_vec3_unit(&p_basis->j);
	p_basis->k = ksx_vec3_unit(&p_basis->k);
	// printf("ksx_vec3_mag(&p_basis->i) = %f\n", ksx_vec3_mag(&p_basis->i));
	// printf("ksx_vec3_mag(&p_basis->j) = %f\n", ksx_vec3_mag(&p_basis->j));
	// printf("ksx_vec3_mag(&p_basis->k) = %f\n\n", ksx_vec3_mag(&p_basis->k));
	printf("ksx_vec3_angle(&p_basis->i, &p_basis->j) = %f\n", ksx_vec3_angle(&p_basis->i, &p_basis->j) / PI180);
	printf("ksx_vec3_angle(&p_basis->j, &p_basis->k) = %f\n", ksx_vec3_angle(&p_basis->j, &p_basis->k) / PI180);
	printf("ksx_vec3_angle(&p_basis->k, &p_basis->i) = %f\n\n", ksx_vec3_angle(&p_basis->k, &p_basis->i) / PI180);
}
