/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:13:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/05 13:11:43 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <stdlib.h>

t_light	*ksx_create_light(t_vector3 center, float bright, t_color color)
{
	t_light	*p_light;

	p_light = (t_light *) malloc(sizeof(t_light));
	if (!p_light)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	p_light->center = center;
	p_light->bright = bright;
	p_light->color = color;
	return (p_light);
}

t_light	**ksx_lgt2world(t_light *p_light, t_world *p_world)
{
	t_light		**pp_light;
	uint32_t	idx;

	if (!p_light || !p_world)
		return (NULL);
	pp_light = (t_light **) malloc
		(sizeof(t_light *) * (p_world->size_lgt + 1));
	if (!pp_light)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	idx = 0;
	while (idx < p_world->size_lgt)
	{
		pp_light[idx] = p_world->pp_lgt[idx];
		idx++;
	}
	pp_light[idx] = p_light;
	p_world->size_lgt++;
	free (p_world->pp_lgt);
	p_world->pp_lgt = pp_light;
	return (pp_light);
}
