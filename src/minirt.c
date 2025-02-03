/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/03 17:54:06 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "parser.h"
#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <stdlib.h>
#include <stdio.h>

static void	ksx_init_world(t_graphics *p_grph, t_list *p_list);

int	main(int argc, char *argv[])
{
	t_graphics	grph;
	t_list		*p_list;

	if (argc != 2)
		return (printf("Incorrect number of arguments.\n"), EXIT_SUCCESS);
	p_list = check_file(argv[1]);
	if (!p_list)
		return (printf("Incorrect the scene file.\n"), EXIT_SUCCESS);
	grph.mlx = ksx_init();
	grph.world.pp_wobj = NULL;
	grph.world.size_wobj = 0;
	if (!grph.mlx)
	{
		ft_lstclear(&p_list, &free_t_object);
		return (EXIT_FAILURE);
	}
	ksx_init_world(&grph, p_list);
	if (!ksx_prep(&grph))
	{
		ft_lstclear(&p_list, &free_t_object);
		return (EXIT_FAILURE);
	}
	ksx_draw(&grph);
	mlx_loop(grph.mlx);
	ft_lstclear(&p_list, &free_t_object);
	return (EXIT_SUCCESS);
}

static void	ksx_init_world(t_graphics *p_grph, t_list *p_list)
{
	t_list		*p_list_;
	t_object	*p_object;
	t_obj		*p_obj;

	p_list_ = p_list;
	while(p_list_)
	{
		p_object = (t_object *) p_list_->content;
		p_obj = NULL;
		if (p_object->id == SPHERE)
			p_obj = ksx_create_sphere (p_object->coord,
				p_object->d, p_object->color);
		if (p_obj)
			ksx_obj2world(p_obj, &p_grph->world);
		p_list_ = p_list_->next;
	}
}
