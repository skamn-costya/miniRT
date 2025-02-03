/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/02 23:32:26 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "parser.h"
#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <stdlib.h>
#include <stdio.h>

static void	ksx_init_world(t_graphics *p_grph);

int	main(int argc, char *argv[])
{
	t_graphics	grph;

	if (argc != 2)
		return (printf("Incorrect number of arguments.\n"), EXIT_SUCCESS);
	grph.objs = check_file(argv[1]);
	if (!grph.objs)
		return (printf("Incorrect the scene file.\n"), EXIT_SUCCESS);
	grph.mlx = ksx_init();
	grph.world.objs = NULL;
	if (!grph.mlx)
	{
		ft_lstclear(&grph.objs, &free_t_object);
		return (EXIT_FAILURE);
	}
	ksx_init_world(&grph);
	if (!ksx_prep(&grph))
	{
		ft_lstclear(&grph.objs, &free_t_object);
		return (EXIT_FAILURE);
	}
	mlx_loop(grph.mlx);
	ft_lstclear(&grph.objs, &free_t_object);
	return (EXIT_SUCCESS);
}

static void	ksx_init_world(t_graphics *p_grph)
{
	t_list		*p_list;
	t_object	*p_object;
	t_obj		*p_obj;

	p_list = p_grph->objs;
	while(p_list)
	{
		p_object = (t_object *) p_list->content;
		p_obj = NULL;
		if (p_object->id == SPHERE)
			p_obj = ksx_create_sphere (p_object->coord,
				p_object->d, p_object->color);
		if (p_obj)
			ksx_obj2world(p_obj, &p_grph->world);
		p_list = p_list->next;
	}
}
