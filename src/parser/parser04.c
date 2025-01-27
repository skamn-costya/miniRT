/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/27 19:50:13 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include <sys/stat.h>
#include <fcntl.h>

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