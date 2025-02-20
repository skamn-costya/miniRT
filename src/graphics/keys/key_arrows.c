/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/20 18:55:10 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"

void	key_arrows(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->key == MLX_KEY_RIGHT && (p_keydata->action == MLX_PRESS
			|| p_keydata->action == MLX_REPEAT))
		key_right(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_LEFT && (p_keydata->action == MLX_PRESS
			|| p_keydata->action == MLX_REPEAT))
		key_left(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_UP && (p_keydata->action == MLX_PRESS
			|| p_keydata->action == MLX_REPEAT))
		key_up(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_DOWN && (p_keydata->action == MLX_PRESS
			|| p_keydata->action == MLX_REPEAT))
		key_down(p_keydata, p_grph);
	p_grph->camera.flags |= CHANGE;
}

void	key_right(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	t_vector4	v4;

	if (p_keydata->modifier == MLX_SHIFT)
	{
		v4 = ksx_vec4_set(STEP, 0, 0, 1);
		v4 = ksx_m4_vec4(&p_grph->camera.ivm, &v4);
		p_grph->camera.basis.o = ksx_vec4_vec3(&v4);
	}
	else
		ksx_qrotation_basis(&p_grph->camera.basis, ANGLE,
			p_grph->camera.basis.j);
}

void	key_left(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	t_vector4	v4;

	if (p_keydata->modifier == MLX_SHIFT)
	{
		v4 = ksx_vec4_set(-STEP, 0, 0, 1);
		v4 = ksx_m4_vec4(&p_grph->camera.ivm, &v4);
		p_grph->camera.basis.o = ksx_vec4_vec3(&v4);
	}
	else
		ksx_qrotation_basis(&p_grph->camera.basis, -ANGLE,
			p_grph->camera.basis.j);
}

void	key_up(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	t_vector4	v4;

	if (p_keydata->modifier == MLX_SHIFT)
	{
		v4 = ksx_vec4_set(0, STEP, 0, 1);
		v4 = ksx_m4_vec4(&p_grph->camera.ivm, &v4);
		p_grph->camera.basis.o = ksx_vec4_vec3(&v4);
	}
	else
		ksx_qrotation_basis(&p_grph->camera.basis, ANGLE,
			p_grph->camera.basis.i);
}

void	key_down(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	t_vector4	v4;

	if (p_keydata->modifier == MLX_SHIFT)
	{
		v4 = ksx_vec4_set(0, -STEP, 0, 1);
		v4 = ksx_m4_vec4(&p_grph->camera.ivm, &v4);
		p_grph->camera.basis.o = ksx_vec4_vec3(&v4);
	}
	else
		ksx_qrotation_basis(&p_grph->camera.basis, -ANGLE,
			p_grph->camera.basis.i);
}
