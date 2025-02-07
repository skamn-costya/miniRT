/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils08.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/07 12:57:09 by ksorokol         ###   ########.fr       */
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

void	ksx_free_pointers(void **pointers)
{
	uint32_t	idx;

	if (!pointers)
		return ;
	idx = 0;
	while (pointers[idx])
	{
		free (pointers[idx]);
		idx++;
	}
	free (pointers);
}

// function is_point_on_ray in debug ...
int	ksx_point_on_ray(const t_vector3 p, const t_vector3 v)
{
	t_vector3	v1;
	float		f[2];

	v1 = ksx_vec3_cross(p, v);
	f[0] = ksx_vec3_mag(v1);
	f[1] = ksx_vec3_mag(v);
	if (f[0] / f[1] > PRECISION * 0.5f)
		return (KSX_FALSE);
	return (KSX_TRUE);
}

t_vector3	ksx_translate_vec3(t_vector3 v1, const t_vector3 v2)
{
	t_vector3	result;

	result = ksx_vec3_add(v1, v2);
	return (result);
}

void	ksx_translate_tri(t_triangle *tri, const t_vector3 norm)
{
	tri->w_p1 = ksx_vec3_add(tri->p1, norm);
	tri->w_p2 = ksx_vec3_add(tri->p2, norm);
	tri->w_p3 = ksx_vec3_add(tri->p3, norm);
}
