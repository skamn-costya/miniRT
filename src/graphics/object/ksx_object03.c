/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_object03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:37:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/24 16:08:08 by ksorokol         ###   ########.fr       */
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

t_triangle	**ksx_obj_new_tris(uint32_t size)
{
	t_triangle	**pp_tri;
	uint32_t	idx;

	pp_tri = (t_triangle **) malloc (sizeof(t_triangle *) * (size + 1));
	if (!pp_tri)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	ksx_null_pointers((void **) pp_tri, size + 1);
	idx = 0;
	while (idx < size)
	{
		pp_tri[idx] = (t_triangle *) malloc (sizeof(t_triangle));
		if (!pp_tri[idx])
			return (ksx_free_pointers((void ***) &pp_tri),
				ksx_error("memory allocation failure", __FILE__, __LINE__),
				NULL);
		idx++;
	}
	return (pp_tri);
}

t_triangle	**ksx_obj_add_tris(t_object *p_object, uint32_t size)
{
	t_triangle	**pp_tri;
	uint32_t	idx[2];

	pp_tri = (t_triangle **) malloc (sizeof(t_triangle *)
			* (p_object->size_tri + size + 1));
	if (!pp_tri)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	ksx_null_pointers((void **) pp_tri, p_object->size_tri + size + 1);
	idx[0] = -1;
	while (++idx[0] < p_object->size_tri)
		pp_tri[idx[0]] = p_object->pp_tri[idx[0]];
	idx[1] = idx[0];
	while (idx[0] < p_object->size_tri + size)
	{
		pp_tri[idx[0]] = (t_triangle *) malloc (sizeof(t_triangle));
		if (!pp_tri[idx[0]])
			return (ksx_free_pointers((void ***) &pp_tri),
				ksx_error("memory allocation failure", __FILE__, __LINE__),
				NULL);
		idx[0]++;
	}
	free (p_object->pp_tri);
	p_object->pp_tri = pp_tri;
	return (p_object->size_tri += size, &p_object->pp_tri[idx[1]]);
}

void	ksx_obj_tris2box(t_object *p_object)
{
	p_object->pp_box[0]->pp_tris = p_object->pp_tri;
}
