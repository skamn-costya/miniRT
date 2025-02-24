/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_adsw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/24 16:28:42 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"

void	key_adswze(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->key == MLX_KEY_A)
		key_a(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_D)
		key_d(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_S)
		key_s(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_W)
		key_w(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_Z)
		key_z(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_E)
		key_e(p_keydata, p_grph);
	p_grph->world.pp_obj[p_grph->obj_idx]->flags |= CHANGE;
	ksx_translate_obj (p_grph->world.pp_obj[p_grph->obj_idx]);
}

void	key_a(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
	{
		ksx_qrotation_wbasis(&p_grph->world.pp_obj[p_grph->obj_idx]->basis,
			ANGLE, ksx_vec3_set(1, 0, 0));
		ksx_translate_obj(p_grph->world.pp_obj[p_grph->obj_idx]);
	}
	else
		p_grph->world.pp_obj[p_grph->obj_idx]->basis.w_o.x -= STEP;
}

void	key_d(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
	{
		ksx_qrotation_wbasis(&p_grph->world.pp_obj[p_grph->obj_idx]->basis,
			-ANGLE, ksx_vec3_set(1, 0, 0));
		ksx_translate_obj(p_grph->world.pp_obj[p_grph->obj_idx]);
	}
	else
		p_grph->world.pp_obj[p_grph->obj_idx]->basis.w_o.x += STEP;
}

void	key_s(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
	{
		ksx_qrotation_wbasis(&p_grph->world.pp_obj[p_grph->obj_idx]->basis,
			ANGLE, ksx_vec3_set(0, 1, 0));
		ksx_translate_obj(p_grph->world.pp_obj[p_grph->obj_idx]);
	}
	else
		p_grph->world.pp_obj[p_grph->obj_idx]->basis.w_o.y -= STEP;
}

void	key_w(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
	{
		ksx_qrotation_wbasis(&p_grph->world.pp_obj[p_grph->obj_idx]->basis,
			-ANGLE, ksx_vec3_set(0, 1, 0));
		ksx_translate_obj(p_grph->world.pp_obj[p_grph->obj_idx]);
	}
	else
		p_grph->world.pp_obj[p_grph->obj_idx]->basis.w_o.y += STEP;
}
