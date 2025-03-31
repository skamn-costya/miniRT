/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 17:27:39 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_basis.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ray_texture.h"
#include "ksx_basis.h"
#include <stdlib.h>

static void	ksx_plane_texture(t_plane *p_plane, t_world *p_world);

t_plane	*ksx_create_plane(t_vector3 point, t_vector3 norm, t_color color)
{
	t_plane	*p_plane;

	p_plane = (t_plane *) malloc(sizeof(t_plane));
	if (!p_plane)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	p_plane->norm.wp = ksx_vec3_unit(&norm);
	p_plane->basis.w_o = point;
	ksx_basis_set_norm(&p_plane->basis, &p_plane->norm.wp);
	p_plane->color = color;
	ksx_color_unit_fraction(&p_plane->color);
	p_plane->color.material.ka = 1.f;
	p_plane->color.material.kd = .8f;
	p_plane->color.material.ks = 0.f;
	p_plane->color.material.ns = 12.f;
	p_plane->p_texture = NULL;
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
	ksx_plane_texture(p_plane, p_world);
	return (pp_plane);
}

static void	ksx_plane_texture(t_plane *p_plane, t_world *p_world)
{
	if (!p_world->pp_txtr)
		return;
	if (p_plane->color.r == 0 && p_plane->color.g == 0)
	{
		if (p_plane->color.b < MAX_TXTR - 1)
			p_plane->p_texture = p_world->pp_txtr[p_plane->color.b - 1];
		if (p_plane->color.b == MAX_TXTR - 1)
			p_plane->p_texture = (t_texture *)MAX_TXTR - 1;
		else if (p_plane->color.b == MAX_TXTR)
			p_plane->p_texture = (t_texture *)MAX_TXTR;
	}
}

// А(х-a) + В(y-b) + C(z-c)=0 
// (A,B,C) - вектор нормали
// (a,b,c) - точка принадлежащая плоскости

// float	ksx_plane_check(t_vector3 *p_vec, t_plane *p_plane)
// {
// 	float	result;

// 	result = p_plane->norm.wp.x * (p_vec->x - p_plane->point.x)
// 		+ p_plane->norm.wp.y * (p_vec->y - p_plane->point.y)
// 		+ p_plane->norm.wp.z * (p_vec->z - p_plane->point.z);
// 	return (result);
// }
