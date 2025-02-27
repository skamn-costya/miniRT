/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/27 20:27:16 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "parser.h"
#include "ksx_graphics.h"
#include "ksx_object.h"
#include "ksx_obj_file.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_utils.h"
#include "ksx_camera.h"
#include "keys.h"
#include <stdlib.h>
#include <stdio.h>

static int	ksx_init_grph(t_graphics *p_grph, void (*f)(void *));
static void	ksx_init_world(t_graphics *p_grph, t_list *p_list);
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		my_keyhook(mlx_key_data_t keydata, void *param);

int	main(int argc, char *argv[])
{
	t_graphics	grph;
	t_list		*p_list;

	if (argc != 2)
		return (printf("Incorrect number of arguments.\n"), EXIT_SUCCESS);
	p_list = check_file(argv[1]);
	if (!p_list)
		return (printf("Incorrect the scene file.\n"), EXIT_SUCCESS);
	garbage_collector((void **) &p_list);
	ksx_init_grph(&grph, &garbage_collector);
	ksx_init_world(&grph, p_list);
	grph.obj_idx = 0;
	ft_lstclear(&p_list, &free_t_obj_descr);
	ksx_camera_set_pm2(&grph.camera, grph.camera.fov);
	ksx_draw(&grph);
	mlx_key_hook(grph.mlx, &my_keyhook, &grph);
	mlx_scroll_hook(grph.mlx, &my_scrollhook, &grph);
	mlx_loop(grph.mlx);
	ksx_garbage_collector(NULL);
	return (EXIT_SUCCESS);
}

static int	ksx_init_grph(t_graphics *p_grph, void (*f)(void *))
{
	ksx_garbage_collector(p_grph);
	p_grph->f_gc = f;
	// p_grph->world.p_tris = NULL;
	p_grph->world.pp_box = NULL;
	p_grph->world.size_box = 0;
	p_grph->world.pp_obj = NULL;
	p_grph->world.size_obj = 0;
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
	float		f[2];

	p_list_ = p_list;
	while (p_list_)
	{
		p_obj_descr = (t_obj_descr *) p_list_->content;
		p_object = NULL;
		if (p_obj_descr->id == CAMERA)
			p_grph->camera = ksx_create_camera (p_obj_descr->coord,
					p_obj_descr->norm, p_obj_descr->fov);
		else if (p_obj_descr->id == SPHERE)
			p_object = ksx_create_sphere (p_obj_descr->coord,
					p_obj_descr->d, p_obj_descr->color, SPHERE_GEN);
		else if (p_obj_descr->id == CYLINDER)
		{
			f[0] = p_obj_descr->d;
			f[1] = p_obj_descr->h;
			p_object = ksx_create_cylinder(p_obj_descr->coord,
					p_obj_descr->norm, f, p_obj_descr->color);
		}
		else if (p_obj_descr->id == OBJ)
			read_of(&p_grph->world, p_obj_descr->obj_file);
		if (p_object)
			ksx_obj2world(p_object, &p_grph->world);
		p_list_ = p_list_->next;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_graphics	*p_grph;

	p_grph = (t_graphics *) param;
	if (keydata.key >= MLX_KEY_KP_0 && keydata.key <= MLX_KEY_KP_EQUAL)
		key_kp(&keydata, p_grph);
	else if (keydata.key >= MLX_KEY_RIGHT && keydata.key <= MLX_KEY_UP)
		key_arrows(&keydata, p_grph);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D
		|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_W
		|| keydata.key == MLX_KEY_E || keydata.key == MLX_KEY_Z)
		key_adswze(&keydata, p_grph);
	else if ((keydata.key == MLX_KEY_1 || keydata.key == MLX_KEY_2
		|| keydata.key == MLX_KEY_3 || keydata.key == MLX_KEY_4)
		&& keydata.action == MLX_RELEASE)
		key_1234(&keydata, p_grph);
	else if ((keydata.key == MLX_KEY_5 || keydata.key == MLX_KEY_6
		|| keydata.key == MLX_KEY_7 || keydata.key == MLX_KEY_8)
		&& keydata.action == MLX_RELEASE)
		key_5678(&keydata, p_grph);
	else if ((keydata.key == MLX_KEY_9 || keydata.key == MLX_KEY_0
		|| keydata.key == MLX_KEY_MINUS || keydata.key == MLX_KEY_EQUAL)
		&& keydata.action == MLX_RELEASE)
		key_90__(&keydata, p_grph);
	else if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_RELEASE)
	{
		p_grph->obj_idx++;
		if (p_grph->obj_idx >= p_grph->world.size_obj)
			p_grph->obj_idx = 0;
	}
	ksx_draw (p_grph);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_graphics	*p_grph;

	p_grph = (t_graphics *) param;
	if (ydelta > 0)
		scroll_zoom_in(p_grph);
	else if (ydelta < 0)
		scroll_zoom_out(p_grph);
	ksx_draw (p_grph);
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}
