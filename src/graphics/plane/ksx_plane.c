/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/12 16:23:42 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_basis.h"
#include "ksx_utils.h"
#include <stdlib.h>

t_plane	*ksx_create_plane(t_vector3 point, t_vector3 norm, t_color color)
{
	t_plane	*p_plane;

	p_plane = (t_plane *) malloc(sizeof(t_plane));
	if (!p_plane)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	p_plane->point = point;
	p_plane->norm = norm;
	p_plane->color = color;
	return (p_plane);
}

t_plane	**ksx_pln2world(t_plane *p_plane, t_world *p_world)
{
	t_plane		**pp_plane;
	int32_t		idx;

	if (!p_plane || !p_world)
		return (NULL);
	pp_plane = (t_plane **) malloc
		(sizeof(t_plane *) * (p_world->size_pln + 2));
	if (!pp_plane)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	ksx_null_pointers((void **) pp_plane, p_world->size_pln + 2);
	idx = 0;
	while (idx < p_world->size_pln)
	{
		pp_plane[idx] = p_world->pp_pln[idx];
		idx++;
	}
	pp_plane[idx] = p_plane;
	p_world->size_pln++;
	free (p_world->pp_pln);
	p_world->pp_pln = pp_plane;
	return (pp_plane);
}

// А(х-a) + В(y-b) + C(z-c)=0 
// (A,B,C) - вектор нормали
// (a,b,c) - точка принадлежащая плоскости

float	ksx_plane_check(t_vector3 *p_vec, t_plane *p_plane)
{
	float	result;

	result = p_plane->norm.x * (p_vec->x - p_plane->point.x)
		+ p_plane->norm.y * (p_vec->y - p_plane->point.y)
		+ p_plane->norm.z * (p_vec->z - p_plane->point.z);
	return (result);
}
