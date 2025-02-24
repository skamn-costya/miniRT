/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:44:09 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/24 16:10:25 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_boxes.h"
#include "ksx_utils.h"
#include <stdlib.h>
#include <stdio.h>

t_object	**ksx_obj2world(t_object *p_object, t_world *p_world)
{
	t_object	**pp_object;
	uint32_t	idx;

	if (!p_object || !p_world)
		return (NULL);
	pp_object = (t_object **) malloc
		(sizeof(t_object *) * (p_world->size_wobj + 1));
	if (!pp_object)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	idx = 0;
	while (idx < p_world->size_wobj)
	{
		pp_object[idx] = p_world->pp_wobj[idx];
		idx++;
	}
	pp_object[idx] = p_object;
	ksx_box_add (&p_world->pp_boxes, p_object->pp_box[0]);
	free (p_world->pp_wobj);
	p_world->pp_wobj = pp_object;
	p_world->size_wobj++;
	return (pp_object);
}

void	ksx_clean_world(t_world *p_world)
{
	uint32_t	idx[3];
	t_object	*p_object;

	// free(p_world->p_tris);
	// p_world->p_tris = NULL;
	idx[0] = 0;
	while (idx[0] < p_world->size_wobj)
	{
		p_object = p_world->pp_wobj[idx[0]];
		ksx_free_pointers((void ***) &p_object->pp_tri);
		ksx_free_pointers((void ***) &p_object->pp_vrtx);
		ksx_free_pointers((void ***) &p_object->pp_vrtx_origin);
		free(p_object);
		p_world->pp_wobj[idx[0]] = NULL;
		idx[0]++;
	}
	free(p_world->pp_wobj);
	p_world->pp_wobj = NULL;
}
