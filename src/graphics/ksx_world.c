/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:44:09 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/02 23:02:10 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <stdlib.h>
#include <stdio.h>

t_obj	**ksx_obj2world(t_obj *p_obj, t_world *p_world)
{
	t_obj		**pp_obj;
	uint32_t	idx;

	if (!p_world->objs)
		pp_obj = (t_obj **) malloc (sizeof(t_obj *) * 2);
	else
		pp_obj = (t_obj **) malloc (sizeof(t_obj *)
				* (ksx_get_count_pointers((void **) p_world->objs) + 1));
	if (!pp_obj)
		return (printf("Error: memory allocation failed!\n"), NULL);
	idx = 0;
	if (p_world->objs && p_world->objs[0])
	{
		while (p_world->objs[idx])
		{
			pp_obj[idx] = p_world->objs[idx];
			idx++;
		}
		free (p_world->objs);
	}
	pp_obj[idx] = p_obj;
	pp_obj[idx + 1] = NULL;
	p_world->objs = pp_obj;
	return (pp_obj);
}
