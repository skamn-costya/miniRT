/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_kp01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/24 16:28:42 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_basis.h"
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
	p_grph->world.pp_obj[p_grph->obj_idx]->flags |= CHANGE;
	ksx_transform_obj(p_grph->world.pp_obj[p_grph->obj_idx]);
}

void	key_kp_4(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
	{
		if (ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.i)
			< MAX_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.i,
				ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.i)
				+ SCALE);
		if (ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.i)
			< MIN_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.i,
				MIN_AXIS);
	}
	else
		ksx_qrotation_basis(&p_grph->world.pp_obj[p_grph->obj_idx]->basis,
			-ANGLE, ksx_vec3_set(0, 1, 0));
}

void	key_kp_6(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
	{
		if (ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.i)
			> MIN_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.i,
				ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.i)
				- SCALE);
		if (ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.i)
			> MAX_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.i,
				MAX_AXIS);
	}
	else
		ksx_qrotation_basis(&p_grph->world.pp_obj[p_grph->obj_idx]->basis,
			ANGLE, ksx_vec3_set(0, 1, 0));
}

void	key_kp_2(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
	{
		if (ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.j)
			< MAX_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.j,
				ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.j)
				+ SCALE);
		if (ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.j)
			< MIN_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.j,
				MIN_AXIS);
	}
	else
		ksx_qrotation_basis(&p_grph->world.pp_obj[p_grph->obj_idx]->basis,
			-ANGLE, ksx_vec3_set(1, 0, 0));
}

void	key_kp_8(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
	{
		if (ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.j)
			> MIN_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.j,
				ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.j)
				- SCALE);
		if (ksx_vec3_mag(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.j)
			> MAX_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_obj[p_grph->obj_idx]->basis.j,
				MAX_AXIS);
	}
	else
		ksx_qrotation_basis(&p_grph->world.pp_obj[p_grph->obj_idx]->basis,
			ANGLE, ksx_vec3_set(1, 0, 0));
}
