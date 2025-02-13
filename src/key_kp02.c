/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_kp02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/13 15:39:53 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"

void	key_kp_1(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_obj(p_grph->world.pp_wobj[p_grph->obj_idx], -ANGLE, ksx_vec3_set(0, 0, 1));
}

void	key_kp_9(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_obj(p_grph->world.pp_wobj[p_grph->obj_idx], ANGLE, ksx_vec3_set(0, 0, 1));
}

void key_kp_minus(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_obj(p_grph->world.pp_wobj[p_grph->obj_idx], ANGLE, ksx_vec3_set(0, 0, 1));
}

void key_kp_plus(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_obj(p_grph->world.pp_wobj[p_grph->obj_idx], ANGLE, ksx_vec3_set(0, 0, 1));
}
