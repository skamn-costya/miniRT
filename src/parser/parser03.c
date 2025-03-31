/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 23:56:51 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

void	create_obj_list01(t_fline *p_fline,
			t_list **pp_line_list, t_list **pp_obj_list)
{
	if (!ft_strcmp(p_fline->words[0], AMBIENT_ID))
		par_create_ambient(pp_line_list, pp_obj_list, p_fline);
	else if (!ft_strcmp(p_fline->words[0], CAMERA_ID))
		par_create_camera(pp_line_list, pp_obj_list, p_fline);
	else if (!ft_strcmp(p_fline->words[0], LIGHT_ID))
		par_create_light(pp_line_list, pp_obj_list, p_fline);
	else if (!ft_strcmp(p_fline->words[0], LIGHT2_ID))
		par_create_light(pp_line_list, pp_obj_list, p_fline);
	else if (!ft_strcmp(p_fline->words[0], SPHERE_ID))
		par_create_sphere(pp_line_list, pp_obj_list, p_fline);
	else if (!ft_strcmp(p_fline->words[0], OCTAHEDRON_ID))
		par_create_octahedron(pp_line_list, pp_obj_list, p_fline);
	else if (!ft_strcmp(p_fline->words[0], PLANE_ID))
		par_create_plane(pp_line_list, pp_obj_list, p_fline);
	else if (!ft_strcmp(p_fline->words[0], CYLINDER_ID))
		par_create_cylinder(pp_line_list, pp_obj_list, p_fline);
	else if (!ft_strcmp(p_fline->words[0], CONE_ID))
		par_create_cone(pp_line_list, pp_obj_list, p_fline);
	else if (!ft_strcmp(p_fline->words[0], OBJ_ID))
		par_create_obj(pp_line_list, pp_obj_list, p_fline);
}

t_obj_descr	*par_create_sphere(t_list **pp_line_list,
	t_list **pp_obj_list, t_fline *p_fline)
{
	t_obj_descr	*p_obj;

	p_obj = create_obj(pp_line_list, pp_obj_list);
	p_obj->id = SPHERE;
	if (!get_coord(p_fline->words, 1, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (p_fline->words[2] && !is_f_number(p_fline->words[2]))
		parser_crash_exit(pp_line_list, pp_obj_list);
	p_obj->d = ft_atof(p_fline->words[2]);
	if (!get_rgb(p_fline->words, 3, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (p_fline->words[4])
		parser_crash_exit(pp_line_list, pp_obj_list);
	return (p_obj);
}

t_obj_descr	*par_create_plane(t_list **pp_line_list,
	t_list **pp_obj_list, t_fline *p_fline)
{
	t_obj_descr	*p_obj;

	p_obj = create_obj(pp_line_list, pp_obj_list);
	p_obj->id = PLANE;
	if (!get_coord(p_fline->words, 1, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (!get_vector(p_fline->words, 2, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (!get_rgb(p_fline->words, 3, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (p_fline->words[4])
		parser_crash_exit(pp_line_list, pp_obj_list);
	return (p_obj);
}

t_obj_descr	*par_create_cylinder(t_list **pp_line_list,
	t_list **pp_obj_list, t_fline *p_fline)
{
	t_obj_descr	*p_obj;

	p_obj = create_obj(pp_line_list, pp_obj_list);
	p_obj->id = CYLINDER;
	if (!get_coord(p_fline->words, 1, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (!get_vector(p_fline->words, 2, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (p_fline->words[3] && !is_f_number(p_fline->words[3]))
		parser_crash_exit(pp_line_list, pp_obj_list);
	p_obj->d = ft_atof(p_fline->words[3]);
	if (p_fline->words[4] && !is_f_number(p_fline->words[4]))
		parser_crash_exit(pp_line_list, pp_obj_list);
	p_obj->h = ft_atof(p_fline->words[4]);
	if (!get_rgb(p_fline->words, 5, p_obj))
		parser_crash_exit(pp_line_list, pp_obj_list);
	if (p_fline->words[6])
		parser_crash_exit(pp_line_list, pp_obj_list);
	return (p_obj);
}

t_obj_descr	*par_create_obj(t_list **pp_line_list,
	t_list **pp_obj_list, t_fline *p_fline)
{
	t_obj_descr	*p_obj;

	p_obj = create_obj(pp_line_list, pp_obj_list);
	p_obj->id = OBJ;
	p_obj->obj_file = ft_strdup(p_fline->words[1]);
	if (p_fline->words[2])
		parser_crash_exit(pp_line_list, pp_obj_list);
	return (p_obj);
}
