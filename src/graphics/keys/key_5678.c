/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_5678.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/25 00:30:34 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"

void	key_5678(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->key == MLX_KEY_5)
		key_5(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_6)
		key_6(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_7)
		key_7(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_8)
		key_8(p_keydata, p_grph);
}

void	key_5(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
		p_grph->world.pp_obj[p_grph->obj_idx]->flags ^= DRAW_NORM;
	else
		p_grph->camera.flags ^= DRAW_NORM;
}

void	key_6(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	(void) p_grph;
}

void	key_7(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	(void) p_grph;
}

void	key_8(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	(void) p_grph;
}
