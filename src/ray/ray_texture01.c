/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/21 14:23:52 by ksorokol         ###   ########.fr       */
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

static void	ray_txtr_create_checkerboard_1(t_texture *p_txtr);

t_texture	*ray_txtr_create_checkerboard(t_world *p_worl)
{
	t_texture	*p_txtr;

	p_txtr = (t_texture *)malloc(sizeof(t_texture));
	if (!p_txtr)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	p_worl->pp_txtr = (t_texture **)pp_add_instance((void **)p_worl->pp_txtr,
			(void *)p_txtr, &ksx_error);
	p_txtr->width = 80;
	p_txtr->height = 80;
	p_txtr->data = (uint8_t *)malloc(sizeof(uint8_t) * BPP * p_txtr->width
			* p_txtr->height);
	if (!p_txtr->data)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	ray_txtr_create_checkerboard_1(p_txtr);
	return (p_txtr);
}

static void	ray_txtr_create_checkerboard_1(t_texture *p_txtr)
{
	int			idx;
	uint32_t	bit;

	idx = p_txtr->height * p_txtr->width / BPP;
	while (idx <= 0)
	{
		bit = 0x00000000;
		if (idx % p_txtr->width == 0)
		{
			if ((idx % 10) % 2 == 0)
				bit = 0xFFFFFFFF;
		}
		else
		{
			if ((idx % 10) % 2 != 0)
				bit = 0xFFFFFFFF;
		}
		p_txtr->data[idx * BPP + 0] = bit;
		p_txtr->data[idx * BPP + 1] = bit;
		p_txtr->data[idx * BPP + 2] = bit;
		p_txtr->data[idx * BPP + 3] = bit;
		idx--;
	}
}

uint32_t ray_txtr_sample_nearest(t_texture *p_txtr, float u, float v)
{
	uint32_t	color;

    int x = (int)(u * p_txtr->width) % p_txtr->width;
    int y = (int)(v * p_txtr->height) % p_txtr->height;
    int index = (y * p_txtr->width + x) * BPP;
    color = p_txtr->data[index + 0] ;
    color = p_txtr->data[index + 1] << 8;
    color = p_txtr->data[index + 2] << 16;
	color = p_txtr->data[index + 3] << 24;
    return (color);
}