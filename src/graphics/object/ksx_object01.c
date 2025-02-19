/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_object01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:37:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/19 13:18:32 by ksorokol         ###   ########.fr       */
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

t_object	*ksx_create_object(t_vector3 *p_center)
{
	t_object	*p_object;
	t_vector3	v;

	p_object = (t_object *) malloc (sizeof(t_object));
	if (!p_object)
		return (printf("Error: memory allocation failed!\n"), NULL);
	p_object->flags = 0x00000000;
	p_object->edge = EDGE_SIZE;
	p_object->size1 = 0;
	p_object->size2 = 0;
	v = ksx_vec3_set(0, 1, 0);
	ksx_basis_set_norm(&p_object->basis, &v);
	p_object->basis.w_o = *p_center;
	p_object->basis.w_i = ksx_vec3_add(&p_object->basis.i, &p_object->basis.w_o);
	p_object->basis.w_j = ksx_vec3_add(&p_object->basis.j, &p_object->basis.w_o);
	p_object->basis.w_k = ksx_vec3_add(&p_object->basis.k, &p_object->basis.w_o);
	p_object->pp_over = NULL;
	p_object->size_over = 0;
	p_object->pp_otri = NULL;
	p_object->size_otri = 0;
	return (p_object);
}
