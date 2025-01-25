/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/25 16:26:06 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include <sys/stat.h>
#include <fcntl.h>

static t_list	*create_list(int fd);
static t_fline	*create_fline(t_list **pp_list, char *str);
static void		free_t_fline(void *p_fline);

int	check_file(char	*f_name)
{
	int		fd;
	t_list	*p_list;

	if (!f_name)
		return (printf("Warning: The filename is NULL.\n"), FALSE);
	fd = open (f_name, O_RDONLY);
	if (fd < 0)
		return (printf("Warning: \"%s\" couldn't be open.\n", f_name), FALSE);
	p_list = create_list (fd);
	close (fd);
	ft_lstclear(&p_list, &free_t_fline);
	return (TRUE);
}

static t_list	*create_list(int fd)
{
	char	*p_str[2];
	t_list	*p_list;

	p_list = NULL;
	p_str[0] = get_next_line(fd);
	while (p_str[0])
	{
		p_str[1] = ft_strtrim(p_str[0], TRIM_SYMBOLS);
		free (p_str[0]);
		if (ft_strlen(p_str[1]) > 0)
			create_fline(&p_list, p_str[1]);
		else
			free (p_str[1]);
		p_str[0] = get_next_line(fd);
	}
	return (p_list);
}

static t_fline	*create_fline(t_list **pp_list, char *str)
{
	t_fline	*p_fline;
	t_list	*p_lst;

	p_fline = (t_fline *) malloc(sizeof (t_fline));
	if (!p_fline)
	{
		ft_lstclear(pp_list, &free_t_fline);
		return (printf("Error: Memory allocation failed!\n"), NULL);
	}
	p_fline->str = str;
	p_fline->words = ft_split(str, ' ');
	p_lst = ft_lstnew(p_fline);
	ft_lstadd_back(pp_list, p_lst);
	if (!*pp_list)
		*pp_list = p_lst;
	return (p_fline);
}

static void	free_t_fline(void *p_fline)
{
	t_fline	*p_fline_;

	if (!p_fline)
		return;
	p_fline_ = (t_fline	*) p_fline;
	if (p_fline_->words)
		free_pp_obj((void **) p_fline_->words);
	free (p_fline_->str);
	free(p_fline);
}
