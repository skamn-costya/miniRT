/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/31 12:39:34 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

static t_list	*create_line_list(int fd);
static t_fline	*create_fline(t_list **pp_list, char *str);
static int		is_obj(char *id);

t_list	*check_file(char *f_name)
{
	int		fd;
	t_list	*p_list[2];
	t_list	*result;
	t_fline	*p_fline;

	if (!f_name)
		return (printf("Warning: The filename is NULL.\n"), NULL);
	fd = open (f_name, O_RDONLY);
	if (fd < 0)
		return (printf("Warning: \"%s\" couldn't be open.\n", f_name), NULL);
	p_list[0] = create_line_list (fd);
	close (fd);
	p_list[1] = p_list[0];
	while (p_list[1])
	{
		p_fline = p_list[1]->content;
		if (!is_obj(p_fline->words[0]))
			parser_crash_exit(&p_list[0], NULL);
		p_list[1] = p_list[1]->next;
	}
	result = create_obj_list(&p_list[0]);
	ft_lstclear(&p_list[0], &free_t_fline);
	return (result);
}

static t_list	*create_line_list(int fd)
{
	char	*p_str[2];
	t_list	*p_line_list;

	p_line_list = NULL;
	p_str[0] = get_next_line(fd);
	while (p_str[0])
	{
		p_str[1] = ft_strtrim(p_str[0], TRIM_SYMBOLS);
		free (p_str[0]);
		p_str[0] = comma_trim(p_str[1]);
		free (p_str[1]);
		if (ft_strlen(p_str[0]) > 0)
		{
			if (!create_fline(&p_line_list, p_str[0]))
			{
				printf("Memory allocation failed\n");
				printf("Some object may be lost ...\n");
			}
		}
		else
			free (p_str[0]);
		p_str[0] = get_next_line(fd);
	}
	return (p_line_list);
}

static t_fline	*create_fline(t_list **pp_line_list, char *str)
{
	t_fline	*p_fline;
	t_list	*p_lst;

	p_fline = (t_fline *) malloc(sizeof (t_fline));
	if (!p_fline)
		return (NULL);
	p_fline->str = str;
	p_fline->words = ft_split(str, ' ');
	p_lst = ft_lstnew(p_fline);
	ft_lstadd_back(pp_line_list, p_lst);
	if (!*pp_line_list)
		*pp_line_list = p_lst;
	return (p_fline);
}

void	free_t_fline(void *p_fline)
{
	t_fline	*p_fline_;

	if (!p_fline)
		return ;
	p_fline_ = (t_fline *) p_fline;
	if (p_fline_->words)
		ft_parrclear((void **) p_fline_->words);
	free (p_fline_->str);
	free(p_fline);
}

static int	is_obj(char *id)
{
	static int	a = 0;
	static int	c = 0;
	static int	l = 0;

	if (!ft_strcmp(id, AMBIENT_ID) && a)
		return (FALSE);
	if (!ft_strcmp(id, CAMERA_ID) && c)
		return (FALSE);
	if (!ft_strcmp(id, LIGHT_ID) && l)
		return (FALSE);
	if (!ft_strcmp(id, AMBIENT_ID))
		return (a++, TRUE);
	if (!ft_strcmp(id, CAMERA_ID))
		return (c++, TRUE);
	if (!ft_strcmp(id, LIGHT_ID))
		return (l++, TRUE);
	if (!ft_strcmp(id, SPHERE_ID)
		|| !ft_strcmp(id, PLANE_ID)
		|| !ft_strcmp(id, CYLINDER_ID))
		return (TRUE);
	else
		return (FALSE);
}
