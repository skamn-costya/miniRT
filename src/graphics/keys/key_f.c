/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:20:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/09 11:43:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"

void	key_f(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->key == MLX_KEY_F1)
		key_f1(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_F2)
		key_f2(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_F3)
		key_f3(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_F4)
		key_f4(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_F5)
		key_f5(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_F6)
		key_f6(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_F7)
		key_f7(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_F8)
		key_f8(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_F9)
		key_f9(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_F10)
		key_f10(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_F11)
		key_f11(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_F12)
		key_f12(p_keydata, p_grph);
}

void	key_f1(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
		p_grph->world.pp_obj[p_grph->obj_idx]->flags ^= DRAW_BOX;
	else
		p_grph->camera.flags ^= DRAW_BOX;
}

void	key_f2(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
		p_grph->world.pp_obj[p_grph->obj_idx]->flags ^= DRAW_AXIS;
	else
		p_grph->camera.flags ^= DRAW_AXIS;
}

void	key_f3(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
		p_grph->world.pp_obj[p_grph->obj_idx]->flags ^= DRAW_NORM;
	else
		p_grph->camera.flags ^= DRAW_NORM;
}

void	key_f4(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
		p_grph->world.pp_obj[p_grph->obj_idx]->flags ^= DRAW_LINE;
	else
		p_grph->camera.flags ^= DRAW_LINE;
}
