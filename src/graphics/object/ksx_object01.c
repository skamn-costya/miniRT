/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_object01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:37:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/20 16:51:18 by ksorokol         ###   ########.fr       */
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

inline static void	ksx_create_object_1(t_object	*p_object);

t_object	*ksx_create_object(t_vector3 *p_center)
{
	t_object	*p_object;

	p_object = (t_object *) malloc (sizeof(t_object));
	if (!p_object)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	p_object->flags = DRAW_OBJ | DRAW_BOX | DRAW_AXIS | DRAW_LINE | DRAW_NORM;
	p_object->edge = EDGE_SIZE;
	p_object->size1 = 0;
	p_object->size2 = 0;
	p_object->basis.o = ksx_vec3_set(0, 0, 0);
	ksx_basis_set_norm(&p_object->basis, &p_object->basis.o);
	p_object->basis.w_o = p_object->basis.o;
	if (p_center)
		p_object->basis.w_o = *p_center;
	ksx_obj_set_axis(p_object->axis, &p_object->basis);
	ksx_create_object_1(p_object);
	p_object->color.material.ka = 1.f;
	p_object->color.material.kd = .5f; // .2
	p_object->color.material.ks = .9f; // .9
	p_object->color.material.shininess = 128.f;
	p_object->p_texture = NULL;
	return (p_object);
}

inline static void	ksx_create_object_1(t_object	*p_object)
{
	p_object->pp_box = NULL;
	p_object->pp_vrtx = NULL;
	p_object->size_vrtx = 0;
	p_object->pp_vnrm = NULL;
	p_object->size_vnrm = 0;
	p_object->pp_tri = NULL;
	p_object->size_tri = 0;
}

void	ksx_obj_set_axis(t_vertex *p_ver, t_basis *p_basis)
{
	p_ver[X].lp = p_basis->i;
	p_ver[Y].lp = p_basis->j;
	p_ver[Z].lp = p_basis->k;
	p_ver[O].lp = p_basis->o;
	ksx_vec3_resize(&p_ver[X].lp, AXIS_LEN);
	ksx_vec3_resize(&p_ver[Y].lp, AXIS_LEN);
	ksx_vec3_resize(&p_ver[Z].lp, AXIS_LEN);
}

void	ksx_obj_copy_vrts(t_object *p_object, uint32_t idx_src,
			uint32_t idx_des)
{
	uint32_t	idx;

	idx = -1;
	while (++idx < p_object->size_vrtx)
		p_object->pp_vrtx[idx]->olwc[idx_des]
			= p_object->pp_vrtx[idx]->olwc[idx_src];
	idx = -1;
	while (++idx < p_object->size_vnrm)
		p_object->pp_vnrm[idx]->olwc[idx_des]
			= p_object->pp_vnrm[idx]->olwc[idx_src];
}

void	ksx_obj_copy_boxvrts(t_vertex *p_vrt, uint32_t idx1,
	uint32_t idx2, uint32_t size)
{
	uint32_t	idx;

	idx = -1;
	while (++idx < size)
		p_vrt[idx].olwc[idx2] = p_vrt[idx].olwc[idx1];
}
