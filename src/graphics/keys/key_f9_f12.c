/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f9_f12.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:20:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/09 11:49:33 by ksorokol         ###   ########.fr       */
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
	(void) p_grph;
}

void	key_f11(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	(void) p_grph;
}

void	key_f12(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	(void) p_grph;
	ray_cast_boxes(p_grph);
}
