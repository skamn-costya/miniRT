/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils08.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/21 12:48:53 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t	ksx_count_pointers(void **pointers)
{
	uint32_t	idx;

	if (!pointers || !pointers[0])
		return (0);
	idx = 1;
	while (pointers[idx])
		idx++;
	return (idx);
}

void	ksx_free_pointers(void ***ppp_mem)
{
	uint32_t	idx;

	if (!ppp_mem || !*ppp_mem)
		return ;
	idx = 0;
	while ((*ppp_mem)[idx])
	{
		free ((*ppp_mem)[idx]);
		idx++;
	}
	free (*ppp_mem);
	*ppp_mem = NULL;
}

void	ksx_null_pointers(void **pp_mem, uint32_t size)
{
	uint32_t	idx;

	idx = 0;
	while (idx < size)
	{
		pp_mem[idx] = NULL;
		idx++;
	}
}

// function is_point_on_ray in debug ...
int32_t	ksx_point_on_ray(const t_vector3 *p_p, const t_vector3 *p_v)
{
	t_vector3	v1;
	float		f[2];

	v1 = ksx_vec3_cross(p_p, p_v);
	f[0] = ksx_vec3_mag(&v1);
	f[1] = ksx_vec3_mag(p_v);
	if (f[0] / f[1] > PRECISION * 0.5f)
		return (KSX_FALSE);
	return (KSX_TRUE);
}

// t_vector3	ksx_translate_vec3(t_vector3 v1, const t_vector3 v2)
// {
// 	t_vector3	result;

// 	result = ksx_vec3_add(v1, v2);
// 	return (result);
// }

// void	ksx_translate_tri(t_triangle *p_tri, const t_vector3 *p_v)
// {
// 	p_tri->w_p1 = ksx_vec3_add(&p_tri->p1, p_v);
// 	p_tri->w_p2 = ksx_vec3_add(&p_tri->p2, p_v);
// 	p_tri->w_p3 = ksx_vec3_add(&p_tri->p3, p_v);
// }
