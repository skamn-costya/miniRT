/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_kp01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/13 15:39:46 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"

void	key_kp(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->key == MLX_KEY_KP_4)
		key_kp_4(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_KP_6)
		key_kp_6(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_KP_8)
		key_kp_2(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_KP_2)
		key_kp_8(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_KP_1)
		key_kp_1(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_KP_9)
		key_kp_9(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_KP_ADD)
		key_kp_plus(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_KP_SUBTRACT)
		key_kp_minus(p_keydata, p_grph);
}

void	key_kp_4(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_obj(p_grph->world.pp_wobj[p_grph->obj_idx], ANGLE, ksx_vec3_set(0, 1, 0));
}

void	key_kp_6(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_obj(p_grph->world.pp_wobj[p_grph->obj_idx], -ANGLE, ksx_vec3_set(0, 1, 0));
}

void	key_kp_2(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_obj(p_grph->world.pp_wobj[p_grph->obj_idx], -ANGLE, ksx_vec3_set(1, 0, 0));
}

void	key_kp_8(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_obj(p_grph->world.pp_wobj[p_grph->obj_idx], ANGLE, ksx_vec3_set(1, 0, 0));
}
