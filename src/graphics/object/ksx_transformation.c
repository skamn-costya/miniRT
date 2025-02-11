/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_transformation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:32:03 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 17:50:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include "ksx_object.h"
#include <math.h>

void	ksx_transform(t_vector3 *p_point, t_basis *p_basis,
		t_vector3 *p_result)
{
	(void) p_point;
	(void) p_basis;
	(void) p_result;
}

void	ksx_transform_obj(t_object *p_object)
{
	uint32_t	idx;

	idx = 0;
	while (idx < p_object->size_over)
	{
		ksx_transform(&p_object->pp_over[idx]->p_p, &p_object->center);
		idx++;
	}
	ksx_transform(&p_object->axis., &p_object->center);
	idx = 0;
	while (idx < 8)
	{
		ksx_transformi(&p_object->box[idx], &p_object->center);
		idx++;
	}
}
