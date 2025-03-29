/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:08:23 by username          #+#    #+#             */
/*   Updated: 2025/03/29 21:51:10 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

void	bvh_free_world(t_world *world)
{
	int32_t	i;

	i = -1;
	while (++i < world->size_obj)
	{
		if (!world->pp_obj[i]->bvh)
			continue ;
		free(world->pp_obj[i]->bvh->nodes);
		free(world->pp_obj[i]->bvh->tri_index);
		free(world->pp_obj[i]->bvh);
	}
}
