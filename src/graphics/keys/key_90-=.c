/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_90-=.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/27 20:21:26 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_camera.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"

void	key_90__(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->key == MLX_KEY_9)
		key_9(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_0)
		key_0(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_MINUS)
		key_minus(p_keydata, p_grph);
	else if (p_keydata->key == MLX_KEY_EQUAL)
		key_equal(p_keydata, p_grph);
}

void	key_9(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	(void) p_grph;
}

void	key_0(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	p_grph->camera.flags ^= CAM_PM;
	ksx_camera_refresh_pm(&p_grph->camera, p_grph->camera.fov);
	p_grph->camera.flags |= CHANGE;
}

void	key_minus(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	(void) p_grph;
}

void	key_equal(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	(void) p_grph;
}
