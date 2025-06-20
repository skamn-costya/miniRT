/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_world03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:44:09 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 22:58:57 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_boxes.h"
#include "ksx_utils.h"
#include "libft.h"
#include "pp_struct.h"
#include "ray_texture.h"
#include <stdlib.h>
#include <stdio.h>

static void	ksx_obj_texture(t_object *p_object, t_world *p_world);
// static void	ksx_obj_clean(t_object *p_object);

t_object	**ksx_obj2world(t_object *p_object, t_world *p_world)
{
	t_object	**pp_object;
	int32_t		idx;

	if (!p_object || !p_world)
		return (NULL);
	pp_object = (t_object **) malloc
		(sizeof(t_object *) * (p_world->size_obj + 1));
	if (!pp_object)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	idx = 0;
	while (idx < p_world->size_obj)
	{
		pp_object[idx] = p_world->pp_obj[idx];
		idx++;
	}
	pp_object[idx] = p_object;
	if (p_object->pp_box && p_object->pp_box[0])
		ksx_box_add (&p_world->pp_box, p_object->pp_box[0]);
	p_world->size_box++;
	free (p_world->pp_obj);
	p_world->pp_obj = pp_object;
	p_world->size_obj++;
	ksx_obj_texture(p_object, p_world);
	return (pp_object);
}

static void	ksx_obj_texture(t_object *p_object, t_world *p_world)
{
	if (!p_world->pp_txtr)
		return ;
	if (p_object->color.r == 0 && p_object->color.g == 0)
	{
		if (p_object->color.b < MAX_TXTR - 1)
			p_object->p_texture = p_world->pp_txtr[p_object->color.b - 1];
		if (p_object->color.b == MAX_TXTR - 1)
			p_object->p_texture = (t_texture *)MAX_TXTR - 1;
		else if (p_object->color.b == MAX_TXTR)
			p_object->p_texture = (t_texture *)MAX_TXTR;
	}
}

void	ksx_world_clean(t_world *p_world)
{
	int32_t		idx[3];
	t_object	*p_object;

	idx[0] = 0;
	while (idx[0] < p_world->size_obj)
	{
		p_object = p_world->pp_obj[idx[0]];
		ksx_free_pointers((void ***) &p_object->pp_tri);
		ksx_free_pointers((void ***) &p_object->pp_vrtx);
		ksx_free_pointers((void ***) &p_object->pp_vnrm);
		ksx_free_pointers((void ***) &p_object->pp_box);
		free(p_object);
		p_world->pp_obj[idx[0]] = NULL;
		idx[0]++;
	}
	ksx_free_pointers((void ***) &p_world->pp_lgt);
	ksx_free_pointers((void ***) &p_world->pp_pln);
	p_world->pp_txtr = (t_texture **)pp_del_all((void **)p_world->pp_txtr,
			&ray_txtr_free_data);
	free(p_world->pp_box);
	free(p_world->pp_obj);
	p_world->pp_obj = NULL;
}

// static void	ksx_obj_clean(t_object *p_object)
// {
// 	int32_t	idx;

// 	idx = 0;
// 	while (idx < 12)
// 	{
// 		idx++;
// 	}
// }