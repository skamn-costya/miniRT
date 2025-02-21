/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_1234.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/21 11:31:17 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"

void	key_1234(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->key == MLX_KEY_1)
		key_1(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_2)
		key_2(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_3)
		key_3(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_4)
		key_4(p_keydata, p_grph);
}

void	key_1(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
		p_grph->world.pp_wobj[p_grph->obj_idx]->flags ^= DRAW_BOX;
	else
	{
		p_grph->camera.flags ^= DRAW_BOX;
		p_grph->camera.flags |= CHANGE;
	}
}

void	key_2(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
		p_grph->world.pp_wobj[p_grph->obj_idx]->flags ^= DRAW_AXIS;
	else
	{
		p_grph->camera.flags ^= DRAW_AXIS;
		p_grph->camera.flags |= CHANGE;
	}
}

void	key_3(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
		p_grph->world.pp_wobj[p_grph->obj_idx]->flags ^= DRAW_LINE;
	else
	{
		p_grph->camera.flags ^= DRAW_LINE;
		p_grph->camera.flags |= CHANGE;
	}
}

void	key_4(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
		p_grph->world.pp_wobj[p_grph->obj_idx]->flags ^= DRAW_OBJ;
	else
	{
		p_grph->camera.flags ^= DRAW_OBJ;
		p_grph->camera.flags |= CHANGE;
	}
}
