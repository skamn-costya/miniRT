/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/14 13:40:33 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "parser.h"
#include "ksx_graphics.h"
#include "ksx_world.h"
#include "ksx_object.h"
#include "ksx_obj_file.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_utils.h"
#include "ksx_camera.h"
#include "keys.h"
#include "ray.h"
#include <stdlib.h>
#include <stdio.h>

static int	ksx_init_grph(t_graphics *p_grph, void (*f)(void *));
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
	if (grph.world.size_obj < 1)
	{
		printf("There isn't any object.\n");
		ksx_garbage_collector(NULL);
	}	
	grph.obj_idx = 0;
	ft_lstclear(&p_list, &free_t_obj_descr);
	// ksx_camera_set_pm2(&grph.camera, grph.camera.fov);
	// ray_cast(&grph);
	ksx_draw(&grph);
	ray_cast_boxes(&grph);
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
	p_grph->mlx = ksx_init();
	if (!p_grph->mlx)
		return (printf("MLX init failed!\n"), FALSE);
	p_grph->img_bg = ksx_create_image(p_grph->mlx, BACKGROUND);
	if (!p_grph->img_bg)
		return (printf("Create background failed!\n"), FALSE);
	p_grph->img_proj = ksx_create_image(p_grph->mlx, TRANSPARENT);
	if (!p_grph->img_proj)
		return (printf("Create image failed!\n"), FALSE);
	p_grph->img_ray = NULL;
	if (mlx_image_to_window(p_grph->mlx, p_grph->img_bg, 0, 0) < 0)
		return (printf("background to window failed!\n"), FALSE);
	if (mlx_image_to_window(p_grph->mlx, p_grph->img_proj, 0, 0) < 0)
		return (printf("Image to window failed!\n"), FALSE);
	return (TRUE);
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
	else if (keydata.key >= MLX_KEY_F1 && keydata.key <= MLX_KEY_F12
			&& keydata.action == MLX_RELEASE)
		key_f(&keydata, p_grph);
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
	(void)xdelta;
}
