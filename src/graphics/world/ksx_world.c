/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:48:15 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/03 14:22:21 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_world.h"
#include "ksx_camera.h"
#include "ksx_object.h"
#include "ksx_obj_file.h"
#include "parser.h"
#include "libft.h"

static void	ksx_init_world_1(t_graphics *p_grph,
				t_object **pp_object, t_obj_descr *p_obj_descr);
static void	ksx_init_world_2(t_object **pp_object, t_obj_descr *p_obj_descr);

void	ksx_init_world(t_graphics *p_grph, t_list *p_list)
{
	t_list		*p_list_;
	t_obj_descr	*p_obj_descr;
	t_object	*p_object;

	p_list_ = p_list;
	while (p_list_)
	{
		p_obj_descr = (t_obj_descr *) p_list_->content;
		p_object = NULL;
		if (p_obj_descr->id == CAMERA || p_obj_descr->id == SPHERE
			|| p_obj_descr->id == OCTAHEDRON || p_obj_descr->id == OBJ)
			ksx_init_world_1(p_grph, &p_object, p_obj_descr);
		else if (p_obj_descr->id == CYLINDER)
			ksx_init_world_2(&p_object, p_obj_descr);
		if (p_object)
			ksx_obj2world(p_object, &p_grph->world);
		p_list_ = p_list_->next;
	}
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
}
