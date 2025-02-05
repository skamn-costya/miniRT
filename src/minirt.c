/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/05 23:11:03 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "parser.h"
#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <stdlib.h>
#include <stdio.h>

static int	ksx_init_grph(t_graphics *p_grph);
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
	if (!ksx_init_grph(&grph))
		return (ft_lstclear(&p_list, &free_t_obj_descr), EXIT_FAILURE);
	ksx_init_world(&grph, p_list);
	ft_lstclear(&p_list, &free_t_obj_descr);
	ksx_set_camera_pm(&grph.camera, 1.f, 200.f);
	ksx_draw(&grph);
	mlx_loop(grph.mlx);
	ksx_clean_world(&grph.world);
	mlx_delete_image(grph.mlx, grph.img);
	// mlx_close_window(grph.mlx);
	mlx_terminate(grph.mlx);
	return (EXIT_SUCCESS);
}

static int	ksx_init_grph(t_graphics *p_grph)
{
	p_grph->world.p_tris = NULL;
	p_grph->world.pp_wobj = NULL;
	p_grph->world.size_wobj = 0;
	p_grph->mlx = ksx_init();
	if (!p_grph->mlx)
		return (printf("MLX init failed!\n"), FALSE);
	p_grph->img = ksx_create_image(p_grph->mlx);
	if (!p_grph->img)
		return (printf("Create image failed!\n"), FALSE);
	if (mlx_image_to_window(p_grph->mlx, p_grph->img, 0, 0) < 0)
		return (printf("Image to window failed!\n"), FALSE);
	return (TRUE);
}

static void	ksx_init_world(t_graphics *p_grph, t_list *p_list)
{
	t_list		*p_list_;
	t_obj_descr	*p_obj_descr;
	t_object	*p_object;

	p_list_ = p_list;
	while (p_list_)
	{
		p_obj_descr = (t_obj_descr *) p_list_->content;
		p_object = NULL;
		if (p_obj_descr->id == CAMERA)
			p_grph->camera = ksx_create_camera (p_obj_descr->coord,
					p_obj_descr->norm, p_obj_descr->fov);
		if (p_obj_descr->id == SPHERE)
			p_object = ksx_create_sphere (p_obj_descr->coord,
					p_obj_descr->d, p_obj_descr->color);
		if (p_object)
			ksx_obj2world(p_object, &p_grph->world);
		p_list_ = p_list_->next;
	}
}
