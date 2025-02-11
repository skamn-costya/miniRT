/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_object02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:37:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 16:21:15 by ksorokol         ###   ########.fr       */
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

t_vertex	**ksx_obj_add_vers(t_object *p_object, uint32_t size)
{
	t_vertex	**pp_ver;
	uint32_t	idx;

	pp_ver = (t_vertex **) malloc (sizeof(t_vertex *)
			* (p_object->size_over + size + 1));
	if (!pp_ver)
		return ((void) printf ("Error: memory allocation failed!\n"), NULL);
	ksx_null_pointers((void **) pp_ver, p_object->size_over + size + 1);
	idx = 0;
	while (idx < p_object->size_over)
	{
		pp_ver[idx] = p_object->pp_over[idx];
		idx++;
	}
	p_object->size_over += size;
	while (idx < p_object->size_over)
	{
		pp_ver[idx] = (t_vertex *) malloc (sizeof(t_vertex));
		if (!pp_ver[idx])
			return (ksx_free_pointers((void ***) &pp_ver),
				(void) printf ("Error: memory allocation failed!\n"), NULL);
		idx++;
	}
	free(p_object->pp_over);
	return (p_object->pp_over = pp_ver, &pp_ver[p_object->size_over - size]);
}
