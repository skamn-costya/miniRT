/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:08:16 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/20 16:19:00 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include "ANSI_color_codes.h"
#include <stdio.h>

void	garbage_collector(void *p_mtc)
{
	static t_list	**pp_list;

	if (p_mtc)
	{
		pp_list = (t_list **) p_mtc;
		return ;
	}
	ft_lstclear(pp_list, &free_t_obj_descr);
	exit (EXIT_SUCCESS);
}

void	error(char *error, char *file_name, int str_num)
{
	printf("%sERROR:%s %s.\nFile: %s\nString: %d\n\n", RED, RESET, error, file_name, str_num);
	garbage_collector(NULL);
}