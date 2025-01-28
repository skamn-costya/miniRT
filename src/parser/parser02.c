/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/28 17:54:06 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include <sys/stat.h>
#include <fcntl.h>

static t_object	*create_ambient(t_list **pp_line_list,
					t_list **pp_obj_list, t_fline *p_fline);
static t_object	*create_camera(t_list **pp_line_list,
					t_list **pp_obj_list, t_fline *p_fline);
static t_object	*create_light(t_list **pp_line_list,
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
			create_ambient(pp_line_list, &p_obj_list, p_fline);
		else if (!ft_strcmp(p_fline->words[0], CAMERA_ID))
			create_camera(pp_line_list, &p_obj_list, p_fline);
		else if (!ft_strcmp(p_fline->words[0], LIGHT_ID))
			create_light(pp_line_list, &p_obj_list, p_fline);
		p_list = p_list->next;
	}
	return (p_obj_list);
}

t_object	*create_obj(t_list **pp_line_list, t_list **pp_obj_list)
{
	t_object	*p_obj;
	t_list		*p_list;

	p_obj = (t_object *) malloc (sizeof (t_object));
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

static t_object	*create_ambient(t_list **pp_line_list,
	t_list **pp_obj_list, t_fline *p_fline)
{
	t_object	*p_obj;

	p_obj = create_obj(pp_line_list, pp_obj_list);
	p_obj->id = AMBIENT;
	if (p_fline->words && p_fline->words[1] && !is_f_number(p_fline->words[1]))
		parser_crash_exit(pp_line_list, pp_obj_list);
	p_obj->ratio = ft_atof(p_fline->words[1]);
	if (p_obj->ratio < 0 || p_obj->ratio > 1)
		parser_crash_exit(pp_line_list, pp_obj_list);
	get_rgb(p_fline->words, 2, p_obj->argb.argb, R);
	return (p_obj);
}

static t_object	*create_camera(t_list **pp_line_list,
	t_list **pp_obj_list, t_fline *p_fline)
{
	(void) pp_line_list;
	(void) pp_obj_list;
	(void) p_fline;
	return (NULL);
}

static t_object	*create_light(t_list **pp_line_list,
	t_list **pp_obj_list, t_fline *p_fline)
{
	(void) pp_line_list;
	(void) pp_obj_list;
	(void) p_fline;
	return (NULL);
}
