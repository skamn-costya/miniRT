/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 19:29:08 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "parser.h"
#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_graphics	grph;

	if (argc != 2)
		return (printf("Incorrect number of arguments.\n"), EXIT_SUCCESS);
	grph.objs = check_file(argv[1]);
	if (!grph.objs)
		return (printf("Incorrect the scene file.\n"), EXIT_SUCCESS);
	grph.mlx = ksx_init();
	if (!grph.mlx)
	{
		ft_lstclear(&grph.objs, &free_t_object);
		return (EXIT_FAILURE);
	}
	if (!ksx_prep(&grph))
	{
		ft_lstclear(&grph.objs, &free_t_object);
		return (EXIT_FAILURE);
	}
	mlx_loop(grph.mlx);
	ft_lstclear(&grph.objs, &free_t_object);
	return (EXIT_SUCCESS);
}
