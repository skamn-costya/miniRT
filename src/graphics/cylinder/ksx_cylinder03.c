/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_cylinder03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:55:12 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/28 17:32:17 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Cylinder: "cy", coord, vector, d, h, rgb

#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_basis.h"
#include "ksx_boxes.h"
#include "ksx_vec3_math.h"
#include "ksx_3D.h"
#include "ksx_cylinder.h"
#include "ksx_triangle.h"
#include "ray_texture.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	ksx_init_cylinder_0(t_object *p_object, int32_t size,
	int32_t idx, float *xz)
{
	xz[0] = p_object->size1 * cosf(CYLINDER_ANGLE * (idx - 2) * PI180);
	xz[1] = p_object->size1 * sinf(CYLINDER_ANGLE * (idx - 2) * PI180);
	p_object->pp_vrtx[idx]->op = ksx_vec3_set(xz[0], p_object->size2, xz[1]);
	p_object->pp_vnrm[idx]->op = ksx_vec3_set(0, 1.f, 0);
	p_object->pp_vrtx[idx + size]->op = ksx_vec3_set(xz[0], -p_object->size2,
			xz[1]);
	p_object->pp_vnrm[idx + size]->op = ksx_vec3_set(0, -1.f, 0);
	p_object->pp_vrtx[idx + size * 2]->op = ksx_vec3_set(xz[0], p_object->size2,
			xz[1]);
	p_object->pp_vnrm[idx + size * 2]->op = ksx_vec3_set(xz[0], 0, xz[1]);
	p_object->pp_vnrm[idx + size * 2]->op = ksx_vec3_unit(&p_object->pp_vnrm[idx
			+ size * 2]->op);
	p_object->pp_vrtx[idx + size * 3]->op = ksx_vec3_set(xz[0],
			-p_object->size2, xz[1]);
	p_object->pp_vnrm[idx + size * 3]->op = ksx_vec3_set(xz[0], 0, xz[1]);
	p_object->pp_vnrm[idx + size * 3]->op = ksx_vec3_unit(&p_object->pp_vnrm[idx
			+ size * 3]->op);
}
