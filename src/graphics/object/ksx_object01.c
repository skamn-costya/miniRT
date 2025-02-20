/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_object01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:37:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/20 18:46:02 by ksorokol         ###   ########.fr       */
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
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	p_object->flags = 0x00000000;
	p_object->edge = EDGE_SIZE;
	p_object->size1 = 0;
	p_object->size2 = 0;
	v = ksx_vec3_set(0, 0, 0);
	p_object->basis.o = v;
	ksx_basis_set_norm(&p_object->basis, &v);
	p_object->basis.w_o = *p_center;
	p_object->basis.w_i = p_object->basis.i;
	p_object->basis.w_j = p_object->basis.j;
	p_object->basis.w_k = p_object->basis.k;
	ksx_obj_set_axis(p_object->w_axis, &p_object->basis);
	p_object->pp_vrtx = NULL;
	p_object->size_vrtx = 0;
	p_object->pp_tri = NULL;
	p_object->size_tri = 0;
	return (p_object);
}

void	ksx_obj_set_axis(t_vertex *p_ver, t_basis *p_basis)
{
	p_ver[X].p_p = p_basis->i;
	p_ver[Y].p_p = p_basis->j;
	p_ver[Z].p_p = p_basis->k;
	p_ver[O].p_p = p_basis->o;
	ksx_vec3_resize(&p_ver[X].p_p, AXIS_LEN);
	ksx_vec3_resize(&p_ver[Y].p_p, AXIS_LEN);
	ksx_vec3_resize(&p_ver[Z].p_p, AXIS_LEN);
}

t_vertex	**ksx_obj_vrts_dup2origin(t_object *p_object)
{
	uint32_t	idx;

	p_object->pp_vrtx_origin = (t_vertex **) malloc(sizeof(t_vertex *)
			* (p_object->size_vrtx + 1));
	if (!p_object->pp_vrtx_origin)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	idx = 0;
	ksx_null_pointers((void **) p_object->pp_vrtx_origin,
		p_object->size_vrtx + 1);
	while (idx < p_object->size_vrtx)
	{
		p_object->pp_vrtx_origin[idx] = (t_vertex *) malloc(sizeof(t_vertex));
		if (!p_object->pp_vrtx_origin[idx])
			return (ksx_free_pointers((void ***) &p_object->pp_vrtx_origin),
				ksx_error("memory allocation failure", __FILE__, __LINE__),
				NULL);
		idx++;
	}
	ksx_obj_copy_vrts(p_object->pp_vrtx, p_object->pp_vrtx_origin,
		p_object->size_vrtx);
	return (p_object->pp_vrtx_origin);
}

void	ksx_obj_copy_vrts(t_vertex **pp_vrt1, t_vertex **pp_vrt2, uint32_t size)
{
	uint32_t	idx;

	idx = 0;
	while (idx < size)
	{
		pp_vrt2[idx]->p_p.x = pp_vrt1[idx]->p_p.x;
		pp_vrt2[idx]->p_p.y = pp_vrt1[idx]->p_p.y;
		pp_vrt2[idx]->p_p.z = pp_vrt1[idx]->p_p.z;
		idx++;
	}
}

void	ksx_obj_copy_boxvrts(t_vertex *p_vrt1, t_vertex *p_vrt2, uint32_t size)
{
	uint32_t	idx;

	idx = 0;
	while (idx < size)
	{
		p_vrt2[idx].p_p.x = p_vrt1[idx].p_p.x;
		p_vrt2[idx].p_p.y = p_vrt1[idx].p_p.y;
		p_vrt2[idx].p_p.z = p_vrt1[idx].p_p.z;
		idx++;
	}
}
