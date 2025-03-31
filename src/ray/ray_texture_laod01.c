/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture_laod01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/04/01 00:48:19 by ksorokol         ###   ########.fr       */
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

static void	ray_txtr_file00_load(t_world *p_world);
static void	ray_txtr_file01_load(t_world *p_world);
static void	ray_txtr_file02_load(t_world *p_world);
static void	ray_txtr_file03_load(t_world *p_world);
void		ray_txtr_file04_load(t_world *p_world);
void		ray_txtr_file05_load(t_world *p_world);
void		ray_txtr_file06_load(t_world *p_world);
void		ray_txtr_file07_load(t_world *p_world);

void	ray_txtr_files_load(t_world *p_world)
{
	ray_txtr_file00_load(p_world);
	ray_txtr_file01_load(p_world);
	ray_txtr_file02_load(p_world);
	ray_txtr_file03_load(p_world);
	ray_txtr_file04_load(p_world);
	ray_txtr_file05_load(p_world);
	ray_txtr_file06_load(p_world);
	ray_txtr_file07_load(p_world);
}

static void	ray_txtr_file00_load(t_world *p_world)
{
	int32_t	idx;

	idx = 0;
	ray_txtr_load(p_world, "./textures/2k_sun.png", NULL);
	if (p_world->pp_txtr && p_world->pp_txtr[idx])
	{
		p_world->pp_txtr[idx]->color.material.ka = 1.f;
		p_world->pp_txtr[idx]->color.material.kd = 1.f;
		p_world->pp_txtr[idx]->color.material.ks = 0.f;
		p_world->pp_txtr[idx]->color.material.ns = 0.f;
	}
}

static void	ray_txtr_file01_load(t_world *p_world)
{
	int32_t	idx;

	idx = 1;
	ray_txtr_load(p_world, "./textures/earthmap1k.png",
		"./textures/earthbump1k.png");
	if (p_world->pp_txtr && p_world->pp_txtr[idx])
	{
		p_world->pp_txtr[idx]->color.material.ka = 1.f;
		p_world->pp_txtr[idx]->color.material.kd = .75f;
		p_world->pp_txtr[idx]->color.material.ks = 0.5f;
		p_world->pp_txtr[idx]->color.material.ns = 32.f;
	}
}

static void	ray_txtr_file02_load(t_world *p_world)
{
	int32_t	idx;

	idx = 2;
	ray_txtr_load(p_world, "./textures/moonmap4k.png",
		"./textures/moonbump4k.png");
	if (p_world->pp_txtr && p_world->pp_txtr[idx])
	{
		p_world->pp_txtr[idx]->color.material.ka = 1.f;
		p_world->pp_txtr[idx]->color.material.kd = .64f;
		p_world->pp_txtr[idx]->color.material.ks = 0.5f;
		p_world->pp_txtr[idx]->color.material.ns = 3.f;
	}
}

static void	ray_txtr_file03_load(t_world *p_world)
{
	int32_t	idx;

	idx = 3;
	ray_txtr_load(p_world, "./textures/plutomap2k.png",
		"./textures/plutobump2k.png");
	if (p_world->pp_txtr && p_world->pp_txtr[idx])
	{
		p_world->pp_txtr[idx]->color.material.ka = 1.f;
		p_world->pp_txtr[idx]->color.material.kd = .64f;
		p_world->pp_txtr[idx]->color.material.ks = 0.75f;
		p_world->pp_txtr[idx]->color.material.ns = 64.f;
	}
}
