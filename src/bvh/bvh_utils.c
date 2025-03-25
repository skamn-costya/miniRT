/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:15:20 by username          #+#    #+#             */
/*   Updated: 2025/03/22 12:16:52 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

void	swap(uint32_t *a, uint32_t *b)
{
	uint32_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	set_centroids(t_triangle **pp_tri, uint32_t *tri_index)
{
	uint32_t	i;
	t_vector3	tmp;
	t_vector3	sum;

	i = 0;
	while (pp_tri[i])
	{
		sum = ksx_vec3_add(&pp_tri[i]->p_ver2->cp, &pp_tri[i]->p_ver3->cp);
		tmp = ksx_vec3_add(&pp_tri[i]->p_ver1->cp, &sum);
		tmp = ksx_vec3_smulti(&tmp, 0.3333f);
		pp_tri[i]->centr = ksx_vec3_set(tmp.x, tmp.y, tmp.z);
		tri_index[i] = i;
		i++;
	}
}

t_vector3	min_vec(t_vector3 a, t_vector3 b)
{
	t_vector3	res;

	res = ksx_vec3_set(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
	return (res);
}

t_vector3	max_vec(t_vector3 a, t_vector3 b)
{
	t_vector3	res;

	res = ksx_vec3_set(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
	return (res);
}
