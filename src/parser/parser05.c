/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/05 21:11:29 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include <stdio.h>

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

void	free_t_obj_descr(void *p_obj_descr)
{
	t_obj_descr	*p_obj_descr_;

	if (!p_obj_descr)
		return ;
	p_obj_descr_ = (t_obj_descr *) p_obj_descr;
	free (p_obj_descr_->texture);
	free (p_obj_descr);
}

void	parser_crash_exit(t_list **pp_line_list, t_list **pp_obj_list)
{
	printf("\033[0;31mError:\033[0m\n\tWrong file format or ");
	printf("Memory allocation failed\n\tExit from the process\n");
	if (pp_line_list)
		ft_lstclear(pp_line_list, &free_t_fline);
	if (pp_obj_list)
		ft_lstclear(pp_obj_list, &free_t_obj_descr);
	exit (EXIT_FAILURE);
}
