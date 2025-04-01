/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tab_esc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:20:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/04/01 15:30:37 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"

void	key_tab(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	p_grph->obj_idx++;
	if (p_grph->obj_idx >= p_grph->world.size_obj)
		p_grph->obj_idx = 0;
}

void	key_esc(mlx_key_data_t *p_keydata, t_graphics *p_grph)
{
	(void) p_keydata;
	mlx_close_window(p_grph->mlx);
}
