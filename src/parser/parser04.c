/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/28 22:11:49 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include <sys/stat.h>
#include <fcntl.h>

char	*comma_trim(char *str)
{
	char	**p_str;
	size_t	size;
	char	*str_;
	size_t	idx;

	if (!str)
		return (NULL);
	p_str = ft_split(str, ',');
	size = ft_parrsize((void **) p_str);
	if (size < 2)
		return (ft_parrclear((void **) p_str), ft_strdup(str));
	idx = 0;
	str_ = ft_strtrim(p_str[idx], TRIM_SYMBOLS);
	while (++idx < size)
	{
		str_ = ft_new_strcmp(str_, ",", 1);
		str_ = ft_new_strcmp(str_, ft_strtrim(p_str[idx], TRIM_SYMBOLS), 3);
	}
	return (ft_parrclear((void **) p_str), str_);
}

void	free_t_object(void *p_obj)
{
	t_object	*p_obj_;

	if (!p_obj)
		return ;
	p_obj_ = (t_object *) p_obj;
	free (p_obj_->texture);
	free (p_obj);
}

void	parser_crash_exit(t_list **pp_line_list, t_list **pp_obj_list)
{
	printf("\033[0;31mError:\033[0m\n\tWrong file format or "); 
	printf("Memory allocation failed\n\tExit from the process\n");
	if (pp_line_list)
		ft_lstclear(pp_line_list, &free_t_fline);
	if (pp_obj_list)
		ft_lstclear(pp_obj_list, &free_t_object);
	exit (EXIT_FAILURE);
}