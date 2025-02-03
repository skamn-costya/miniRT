/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:44:09 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/03 17:56:16 by ksorokol         ###   ########.fr       */
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

	pp_obj = (t_obj **) malloc (sizeof(t_obj *) * (p_world->size_wobj + 1));
	if (!pp_obj)
		return (printf("Error: memory allocation failed!\n"), NULL);
	idx = 0;
	while (idx < p_world->size_wobj)
	{
		pp_obj[idx] = p_world->pp_wobj[idx];
		idx++;
	}
	pp_obj[idx] = p_obj;
	free (p_world->pp_wobj);
	p_world->pp_wobj = pp_obj;
	p_world->size_wobj++;
	return (pp_obj);
}
