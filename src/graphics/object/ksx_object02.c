/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_object02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:37:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/06 15:18:04 by ksorokol         ###   ########.fr       */
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
			* (p_object->size_vrtx + size + 1));
	if (!pp_ver)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	ksx_null_pointers((void **) pp_ver, p_object->size_vrtx + size + 1);
	idx = -1;
	while (++idx < p_object->size_vrtx)
		pp_ver[idx] = p_object->pp_vrtx[idx];
	p_object->size_vrtx += size;
	while (idx < p_object->size_vrtx)
	{
		pp_ver[idx] = (t_vertex *) malloc (sizeof(t_vertex));
		if (!pp_ver[idx])
			return (ksx_free_pointers((void ***) &pp_ver),
				ksx_error("memory allocation failure", __FILE__, __LINE__),
				NULL);
		idx++;
	}
	free(p_object->pp_vrtx);
	return (p_object->pp_vrtx = pp_ver, &pp_ver[p_object->size_vrtx - size]);
}

t_vertex	**ksx_obj_add_vnrm(t_object *p_object, uint32_t size)
{
	t_vertex	**pp_vnrm;
	uint32_t	idx;

	pp_vnrm = (t_vertex **) malloc (sizeof(t_vertex *)
			* (p_object->size_vnrm + size + 1));
	if (!pp_vnrm)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	ksx_null_pointers((void **) pp_vnrm, p_object->size_vnrm + size + 1);
	idx = -1;
	while (++idx < p_object->size_vnrm)
		pp_vnrm[idx] = p_object->pp_vnrm[idx];
	p_object->size_vnrm += size;
	while (idx < p_object->size_vnrm)
	{
		pp_vnrm[idx] = (t_vertex *) malloc (sizeof(t_vertex));
		if (!pp_vnrm[idx])
			return (ksx_free_pointers((void ***) &pp_vnrm),
				ksx_error("memory allocation failure", __FILE__, __LINE__),
				NULL);
		idx++;
	}
	free(p_object->pp_vnrm);
	return (p_object->pp_vnrm = pp_vnrm, &pp_vnrm[p_object->size_vnrm - size]);
}
