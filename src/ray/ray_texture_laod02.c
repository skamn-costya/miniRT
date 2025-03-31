/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture_laod02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 22:15:25 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ray.h"
#include "ray_texture.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_3D.h"
#include "ksx_vec3_math.h"
#include "pp_struct.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

// ray_txtr_load(p_world, "./textures/marble_map.png",
// "./textures/marble_bump.png");
void	ray_txtr_file04_load(t_world *p_world)
{
	int32_t	idx;

	idx = 4;
	ray_txtr_load(p_world, "./textures/marble_map.png", NULL);
	if (p_world->pp_txtr && p_world->pp_txtr[idx])
	{
		p_world->pp_txtr[idx]->color.material.ka = 1.f;
		p_world->pp_txtr[idx]->color.material.kd = .5f;
		p_world->pp_txtr[idx]->color.material.ks = 0.8f;
		p_world->pp_txtr[idx]->color.material.ns = 128.f;
	}
}

void	ray_txtr_file05_load(t_world *p_world)
{
	int32_t	idx;

	idx = 5;
	ray_txtr_load(p_world, "./textures/SQ_map.png", "./textures/SQ_bump.png");
	if (p_world->pp_txtr && p_world->pp_txtr[idx])
	{
		p_world->pp_txtr[idx]->color.material.ka = 1.f;
		p_world->pp_txtr[idx]->color.material.kd = .8f;
		p_world->pp_txtr[idx]->color.material.ks = 0.5f;
		p_world->pp_txtr[idx]->color.material.ns = 128.f;
	}
}

void	ray_txtr_file06_load(t_world *p_world)
{
	int32_t	idx;

	idx = 6;
	ray_txtr_load(p_world, "./textures/BR_map.png", "./textures/BR_bump.png");
	if (p_world->pp_txtr && p_world->pp_txtr[idx])
	{
		p_world->pp_txtr[idx]->color.material.ka = 1.f;
		p_world->pp_txtr[idx]->color.material.kd = .25f;
		p_world->pp_txtr[idx]->color.material.ks = 0.25f;
		p_world->pp_txtr[idx]->color.material.ns = 0.f;
	}
}

void	ray_txtr_file07_load(t_world *p_world)
{
	int32_t	idx;

	idx = 7;
	ray_txtr_load(p_world, "./textures/SW_map.png", "./textures/SW_bump.png");
	if (p_world->pp_txtr && p_world->pp_txtr[idx])
	{
		p_world->pp_txtr[idx]->color.material.ka = 1.f;
		p_world->pp_txtr[idx]->color.material.kd = .75f;
		p_world->pp_txtr[idx]->color.material.ks = 0.75f;
		p_world->pp_txtr[idx]->color.material.ns = 128.f;
	}
}
