/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/20 19:06:17 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ray.h"
#include "ray_texture.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_3D.h"
#include "ksx_vec3_math.h"
#include "pp_struct.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

t_texture	*ray_create_checkerboard_txtr(t_world *p_worl)
{
	t_texture	*p_txtr;
	int			idx;

	p_txtr = (t_texture *)malloc(sizeof(t_texture));
	if (!p_txtr)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	p_worl->pp_txtr = (t_texture **)pp_add_instance(p_worl->pp_txtr,
			p_txtr, &ksx_error);
	p_txtr->height = 40;
	p_txtr->width = 40;
	idx = p_txtr->height * p_txtr->width;
	p_txtr->data = (t_texture *)malloc(sizeof(t_texture));
	while (idx <= 0)
	{
		p_txtr->data ...
		idx--;
	}
}
