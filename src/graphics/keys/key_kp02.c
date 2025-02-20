/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_kp02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/20 19:00:54 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_basis.h"
#include "ksx_vec3_math.h"

void	key_kp_1(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
	{
		if (ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k)
			> MIN_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k,
				ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k)
				- SCALE);
		if (ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k)
			> MAX_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k,
				MAX_AXIS);
	}
	else
		ksx_qrotation_basis(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis,
			ANGLE, ksx_vec3_set(0, 0, 1));
}

void	key_kp_9(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier == MLX_SHIFT)
	{
		if (ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k)
			< MAX_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k,
				ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k)
				+ SCALE);
		if (ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k)
			< MIN_AXIS)
			ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k,
				MIN_AXIS);
	}
	else
		ksx_qrotation_basis(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis,
			-ANGLE, ksx_vec3_set(0, 0, 1));
}

void	key_kp_minus(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.i,
		ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.i) - SCALE);
	ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.j,
		ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.j) - SCALE);
	ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k,
		ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k) - SCALE);
	if (ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.i)
		< MIN_AXIS)
		ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.i,
			MIN_AXIS);
	if (ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.j)
		< MIN_AXIS)
		ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.j,
			MIN_AXIS);
	if (ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k)
		< MIN_AXIS)
		ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k,
			MIN_AXIS);
}

void	key_kp_plus(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.i,
		ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.i) + SCALE);
	ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.j,
		ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.j) + SCALE);
	ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k,
		ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k) + SCALE);
	if (ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.i)
		> MAX_AXIS)
		ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.i,
			MAX_AXIS);
	if (ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.j)
		> MAX_AXIS)
		ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.j,
			MAX_AXIS);
	if (ksx_vec3_mag(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k)
		> MAX_AXIS)
		ksx_vec3_resize(&p_grph->world.pp_wobj[p_grph->obj_idx]->basis.k,
			MAX_AXIS);
}
