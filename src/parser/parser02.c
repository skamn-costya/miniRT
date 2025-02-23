/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/23 00:37:41 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

static t_obj_descr	*par_create_ambient(t_list **pp_line_list,
						t_list **pp_obj_list, t_fline *p_fline);
static t_obj_descr	*par_create_camera(t_list **pp_line_list,
						t_list **pp_obj_list, t_fline *p_fline);
static t_obj_descr	*par_create_light(t_list **pp_line_list,
						t_list **pp_obj_list, t_fline *p_fline);

t_list	*create_obj_list(t_list **pp_line_list)
{
	t_list	*p_obj_list;
	t_list	*p_list;
	t_fline	*p_fline;

	p_obj_list = NULL;
	p_list = *pp_line_list;
	while (p_list)
	{
		p_fline = (t_fline *) p_list->content;
		if (!ft_strcmp(p_fline->words[0], AMBIENT_ID))
			par_create_ambient(pp_line_list, &p_obj_list, p_fline);
		else if (!ft_strcmp(p_fline->words[0], CAMERA_ID))
			par_create_camera(pp_line_list, &p_obj_list, p_fline);
		else if (!ft_strcmp(p_fline->words[0], LIGHT_ID))
			par_create_light(pp_line_list, &p_obj_list, p_fline);
		else if (!ft_strcmp(p_fline->words[0], SPHERE_ID))
			par_create_sphere(pp_line_list, &p_obj_list, p_fline);
		else if (!ft_strcmp(p_fline->words[0], PLANE_ID))
			par_create_plane(pp_line_list, &p_obj_list, p_fline);
		else if (!ft_strcmp(p_fline->words[0], CYLINDER_ID))
			par_create_cylinder(pp_line_list, &p_obj_list, p_fline);
		else if (!ft_strcmp(p_fline->words[0], OBJ_ID))
			par_create_obj(pp_line_list, &p_obj_list, p_fline);
		p_list = p_list->next;
	}
	return (p_obj_list);
}

t_obj_descr	*create_obj(t_list **pp_line_list, t_list **pp_obj_list)
{
	t_obj_descr	*p_obj;
	t_list		*p_list;

	p_obj = (t_obj_descr *) malloc (sizeof (t_obj_descr));
	if (!p_obj)
		parser_crash_exit(pp_line_list, pp_obj_list);
	p_list = ft_lstnew (p_obj);
	if (!p_list)
	{
		free (p_obj);
		parser_crash_exit(pp_line_list, pp_obj_list);
	}
	p_obj->texture = NULL;
	if (!*pp_obj_list)
		*pp_obj_list = p_list;
	else
		ft_lstadd_back (pp_obj_list, p_list);
	return (p_obj);
}

static t_obj_descr	*par_create_ambient(t_list **pp_line_list,
	t_list **pp_obj_list, t_fline *p_fline)
{
	t_obj_descr	*p_obj;

	p_obj = create_obj(pp_line_list, pp_obj_list);
	p_obj->id = AMBIENT;
	if (p_fline->words[1] && !is_f_number(p_fline->words[1]))
		parser_crash_exit(pp_line_list, pp_obj_list);
	p_obj->ratio = ft_atof(p_fline->words[1]);
	if (p_obj->ratio < 0 || p_obj->ratio > 1)
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (!get_rgb(p_fline->words, 2, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (p_fline->words[3])
		parser_crash_exit(pp_line_list, pp_obj_list);
	return (p_obj);
}

static t_obj_descr	*par_create_camera(t_list **pp_line_list,
	t_list **pp_obj_list, t_fline *p_fline)
{
	t_obj_descr	*p_obj;

	p_obj = create_obj(pp_line_list, pp_obj_list);
	p_obj->id = CAMERA;
	if (!get_coord(p_fline->words, 1, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (!get_vector(p_fline->words, 2, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (p_fline->words && p_fline->words[3] && !is_f_number(p_fline->words[3]))
		parser_crash_exit(pp_line_list, pp_obj_list);
	p_obj->fov = ft_atof(p_fline->words[3]);
	if (p_obj->fov < 0 || p_obj->fov > 180)
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (p_fline->words[4])
		parser_crash_exit(pp_line_list, pp_obj_list);
	return (p_obj);
}

static t_obj_descr	*par_create_light(t_list **pp_line_list,
	t_list **pp_obj_list, t_fline *p_fline)
{
	t_obj_descr	*p_obj;

	p_obj = create_obj(pp_line_list, pp_obj_list);
	p_obj->id = LIGHT;
	if (!get_coord(p_fline->words, 1, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (p_fline->words[2] && !is_f_number(p_fline->words[2]))
		parser_crash_exit(pp_line_list, pp_obj_list);
	p_obj->ratio = ft_atof(p_fline->words[2]);
	if (p_obj->ratio < 0 || p_obj->ratio > 1)
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (!get_rgb(p_fline->words, 3, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (p_fline->words[4])
		parser_crash_exit(pp_line_list, pp_obj_list);
	return (p_obj);
}
