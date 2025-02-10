/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/10 17:42:38 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

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
