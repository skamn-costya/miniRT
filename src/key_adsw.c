/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_adsw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/16 13:48:24 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"

void	key_adsw(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->key == MLX_KEY_A)
		key_a(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_D)
		key_d(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_S)
		key_s(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_W)
		key_w(p_keydata, p_grph);
}

void	key_a(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	t_vector4	v4;

	(void) p_keydata;
	v4 = ksx_vec4_set(-STEP, 0, 0, 1);
	v4 = ksx_m4_vec4(&p_grph->camera.ivm, &v4);
	p_grph->camera.basis.o = ksx_vec4_vec3(&v4);
	p_grph->camera.flags |= CHANGE;
}

void	key_d(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	t_vector4	v4;

	(void) p_keydata;
	v4 = ksx_vec4_set(STEP, 0, 0, 1);
	v4 = ksx_m4_vec4(&p_grph->camera.ivm, &v4);
	p_grph->camera.basis.o = ksx_vec4_vec3(&v4);
	p_grph->camera.flags |= CHANGE;
}

void	key_s(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	t_vector4	v4;

	(void) p_keydata;
	v4 = ksx_vec4_set(0, -STEP, 0, 1);
	v4 = ksx_m4_vec4(&p_grph->camera.ivm, &v4);
	p_grph->camera.basis.o = ksx_vec4_vec3(&v4);
	p_grph->camera.flags |= CHANGE;
}

void	key_w(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	t_vector4	v4;

	(void) p_keydata;
	v4 = ksx_vec4_set(0, STEP, 0, 1);
	v4 = ksx_m4_vec4(&p_grph->camera.ivm, &v4);
	p_grph->camera.basis.o = ksx_vec4_vec3(&v4);
	p_grph->camera.flags |= CHANGE;
}
