/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_world01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:48:15 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 22:58:16 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_world.h"
#include "ksx_light.h"
#include "ksx_plane.h"
#include "ksx_camera.h"
#include "ksx_object.h"
#include "ksx_obj_file.h"
#include "ksx_vec3_math.h"
#include "ksx_basis.h"
#include "ksx_utils.h"
#include "parser.h"
#include "libft.h"
#include "ray_texture.h"

static void	ksx_set_world_defaults(t_graphics *p_grph);
static void	ksx_init_world_1(t_graphics *p_grph,
				t_object **pp_object, t_obj_descr *p_obj_descr);
static void	ksx_init_world_2(t_object **pp_object, t_obj_descr *p_obj_descr);
static void	ksx_init_world_3(t_graphics *p_grph, t_obj_descr *p_obj_descr);

void	ksx_init_world(t_graphics *p_grph, t_list *p_list)
{
	t_list		*p_list_;
	t_obj_descr	*p_obj_descr;
	t_object	*p_object;

	ksx_set_world_defaults(p_grph);
	p_list_ = p_list;
	while (p_list_)
	{
		p_obj_descr = (t_obj_descr *) p_list_->content;
		p_object = NULL;
		if (p_obj_descr->id == CAMERA || p_obj_descr->id == SPHERE
			|| p_obj_descr->id == OCTAHEDRON || p_obj_descr->id == OBJ)
			ksx_init_world_1(p_grph, &p_object, p_obj_descr);
		else if (p_obj_descr->id == CYLINDER || p_obj_descr->id == CONE)
			ksx_init_world_2(&p_object, p_obj_descr);
		else if (p_obj_descr->id == AMBIENT || p_obj_descr->id == LIGHT
			|| p_obj_descr->id == PLANE)
			ksx_init_world_3(p_grph, p_obj_descr);
		if (p_object)
		{
			ksx_world_obj_tm(&p_grph->world, p_object);
			ksx_obj2world(p_object, &p_grph->world);
		}
		p_list_ = p_list_->next;
	}
}

static void	ksx_set_world_defaults(t_graphics *p_grph)
{
	p_grph->world.flags = 0b00000000;
	p_grph->world.basis.o = ksx_vec3_set(0.f, 0.f, 0.f);
	ksx_basis_set_norm(&p_grph->world.basis, &p_grph->world.basis.o);
	p_grph->world.far = ksx_vec3_set(0.f, 0.f, 0.f);
	p_grph->world.pp_box = NULL;
	p_grph->world.size_box = 0;
	p_grph->world.pp_obj = NULL;
	p_grph->world.size_obj = 0;
	p_grph->world.pp_lgt = NULL;
	p_grph->world.size_lgt = 0;
	p_grph->world.pp_pln = NULL;
	p_grph->world.size_pln = 0;
	p_grph->world.pp_txtr = NULL;
	ray_txtr_files_load(&p_grph->world);
	p_grph->world.p_camera = &p_grph->camera;
}

static void	ksx_init_world_1(t_graphics *p_grph,
	t_object **pp_object, t_obj_descr *p_obj_descr)
{
	if (p_obj_descr->id == CAMERA)
		p_grph->camera = ksx_create_camera (p_obj_descr->coord,
				p_obj_descr->norm, p_obj_descr->fov);
	else if (p_obj_descr->id == SPHERE)
		*pp_object = ksx_create_sphere (p_obj_descr->coord,
				p_obj_descr->d, p_obj_descr->color, SPHERE_GEN);
	else if (p_obj_descr->id == OCTAHEDRON)
		*pp_object = ksx_create_sphere (p_obj_descr->coord,
				p_obj_descr->d, p_obj_descr->color, 0);
	else if (p_obj_descr->id == OBJ)
		read_of(&p_grph->world, p_obj_descr->obj_file);
}

static void	ksx_init_world_2(t_object **pp_object, t_obj_descr *p_obj_descr)
{
	float		f[2];

	if (p_obj_descr->id == CYLINDER)
	{
		f[0] = p_obj_descr->d;
		f[1] = p_obj_descr->h;
		*pp_object = ksx_create_cylinder(p_obj_descr->coord,
				p_obj_descr->norm, f, p_obj_descr->color);
	}
	if (p_obj_descr->id == CONE)
	{
		f[0] = p_obj_descr->d;
		f[1] = p_obj_descr->h;
		*pp_object = ksx_create_cone(p_obj_descr->coord,
				p_obj_descr->norm, f, p_obj_descr->color);
	}
}

static void	ksx_init_world_3(t_graphics *p_grph, t_obj_descr *p_obj_descr)
{
	t_light	*p_light;
	t_plane	*p_plane;

	if (p_obj_descr->id == AMBIENT)
	{
		p_grph->world.ambient.bright = p_obj_descr->ratio;
		p_grph->world.ambient.color = p_obj_descr->color;
		ksx_color_unit_fraction(&p_grph->world.ambient.color);
	}
	if (p_obj_descr->id == LIGHT)
	{
		p_light = ksx_create_light(p_obj_descr->coord, p_obj_descr->ratio,
				p_obj_descr->color);
		ksx_lgt2world(p_light, &p_grph->world);
	}
	if (p_obj_descr->id == PLANE)
	{
		p_plane = ksx_create_plane(p_obj_descr->coord, p_obj_descr->norm,
				p_obj_descr->color);
		ksx_pln2world(p_plane, &p_grph->world);
	}
}
