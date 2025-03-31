/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f9_f12.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:20:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 23:21:40 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"
#include "ray.h"

void	key_f9(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	(void) p_grph;
}

void	key_f10(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	p_grph->img_bg->enabled = !p_grph->img_bg->enabled;
}

void	key_f11(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	p_grph->img_ray->enabled = !p_grph->img_ray->enabled;
}

void	key_f12(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	ray_cast(p_grph);
}
