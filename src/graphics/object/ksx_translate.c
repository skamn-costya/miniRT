/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 11:49:48 by ksorokol         ###   ########.fr       */
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

void	ksx_translate_tri(t_triangle *p_tri, t_vector3 *p_center)
{
	ksx_translate(&p_tri->p1, p_center, &p_tri->w_p1);
	ksx_translate(&p_tri->p2, p_center, &p_tri->w_p2);
	ksx_translate(&p_tri->p3, p_center, &p_tri->w_p3);
}

void	ksx_translate_obj(t_object *p_object)
{
	uint32_t	idx;

	idx = 0;
	while (idx < p_object->size_otri)
	{
		ksx_translate_tri(p_object->pp_otri[idx], &p_object->center);
		idx++;
	}
	ksx_translate_tri(&p_object->axis, &p_object->center);
	idx = 0;
	while (idx < 12)
	{
		ksx_translate_tri(&p_object->box[idx], &p_object->center);
		idx++;
	}
}
