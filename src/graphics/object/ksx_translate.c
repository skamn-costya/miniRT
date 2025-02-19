/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/19 20:11:03 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include "ksx_object.h"
#include <math.h>

void	ksx_translate(t_vector3 *p_point, t_vector3 *p_center,
		t_vector3 *p_result)
{
	*p_result = ksx_vec3_add (p_point, p_center);
}

void	ksx_translate_obj(t_object *p_object)
{
	uint32_t	idx;

	ksx_translate(&p_object->basis.i, &p_object->basis.w_o, &p_object->basis.w_i);
	ksx_translate(&p_object->basis.j, &p_object->basis.w_o, &p_object->basis.w_j);
	ksx_translate(&p_object->basis.k, &p_object->basis.w_o, &p_object->basis.w_k);
	idx = -1;
	while (++idx < p_object->size_vrtx)
		ksx_translate(&p_object->pp_vrtx[idx]->p_p, &p_object->basis.w_o, &p_object->pp_vrtx[idx]->p_wp);
	idx = -1;
	while (++idx < 8)
		ksx_translate(&p_object->box_ver[idx].p_p, &p_object->basis.w_o, &p_object->box_ver[idx].p_wp);
	idx = -1;
	while (++idx < 3)
		ksx_translate(&p_object->w_axis[idx].p_p, &p_object->basis.w_o, &p_object->w_axis[idx].p_wp);
}
