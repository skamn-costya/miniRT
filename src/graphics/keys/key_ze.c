/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ze.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 23:19:01 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"

void	key_e(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier != MLX_SHIFT)
		p_grph->world.pp_obj[p_grph->obj_idx]->basis.w_o.z += STEP;
}

void	key_z(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	if (p_keydata->modifier != MLX_SHIFT)
		p_grph->world.pp_obj[p_grph->obj_idx]->basis.w_o.z -= STEP;
}
