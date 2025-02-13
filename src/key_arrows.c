/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/13 18:39:49 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_basis.h"

void	key_arrows(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->key == MLX_KEY_RIGHT)
		key_right(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_LEFT)
		key_left(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_UP)
		key_up(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_DOWN)
		key_down(p_keydata, p_grph);
}

void	key_right(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_basis(&p_grph->camera.basis, ANGLE, ksx_vec3_set(0, 1, 0));
	p_grph->camera.flags |= CHANGE;
}

void	key_left(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_basis(&p_grph->camera.basis, -ANGLE, ksx_vec3_set(0, 1, 0));
	p_grph->camera.flags |= CHANGE;
}

void	key_up(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_basis(&p_grph->camera.basis, ANGLE, ksx_vec3_set(1, 0, 0));
	p_grph->camera.flags |= CHANGE;
}

void	key_down(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ksx_qrotation_basis(&p_grph->camera.basis, -ANGLE, ksx_vec3_set(1, 0, 0));
	p_grph->camera.flags |= CHANGE;
}
