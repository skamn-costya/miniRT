/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/28 00:25:26 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <stdlib.h>
#include "minirt.h"
#include "parser.h"
#include "libft.h"

int	main(int argc, char *argv[])
{
	t_list	*p_obj_list;
	// t_vars vars;

	if (argc !=2)
		return (printf("Warning: Incorrect number of arguments.\n"), EXIT_SUCCESS);
	p_obj_list = check_file(argv[1]);
	if (!p_obj_list)
		return (printf("Warning: Incorrect the scene description file.\n"), EXIT_SUCCESS);
	ft_lstclear(&p_obj_list, &free_t_object);
	// init(&vars);
	return (EXIT_SUCCESS);
}
