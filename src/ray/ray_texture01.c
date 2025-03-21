/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/21 16:25:55 by ksorokol         ###   ########.fr       */
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

// uint32_t ray_txtr_sample_bilinear(t_texture *p_txtr, float u, float v) {
//     u = u * p_txtr->width - 0.5f;
//     v = v * p_txtr->height - 0.5f;

//     int x = (int)u;
//     int y = (int)v;
//     float dx = u - x;
//     float dy = v - y;

//     int index00 = ((y % p_txtr->height) * p_txtr->width + (x % p_txtr->width)) * BPP;
//     int index10 = ((y % p_txtr->height) * p_txtr->width + ((x + 1) % p_txtr->width)) * BPP;
//     int index01 = (((y + 1) % p_txtr->height) * p_txtr->width + (x % p_txtr->width)) * BPP;
//     int index11 = (((y + 1) % p_txtr->height) * p_txtr->width + ((x + 1) % p_txtr->width)) * BPP;

//     t_color c00 = {p_txtr->data[index00], p_txtr->data[index00 + 1], p_txtr->data[index00 + 2]};
//     t_color c10 = {p_txtr->data[index10], p_txtr->data[index10 + 1], p_txtr->data[index10 + 2]};
//     t_color c01 = {p_txtr->data[index01], p_txtr->data[index01 + 1], p_txtr->data[index01 + 2]};
//     t_color c11 = {p_txtr->data[index11], p_txtr->data[index11 + 1], p_txtr->data[index11 + 2]};

//     t_color result;
//     result.r = (uint8_t)((1 - dx) * (1 - dy) * c00.r + dx * (1 - dy) * c10.r +
//                           (1 - dx) * dy * c01.r + dx * dy * c11.r);
//     result.g = (uint8_t)((1 - dx) * (1 - dy) * c00.g + dx * (1 - dy) * c10.g +
//                           (1 - dx) * dy * c01.g + dx * dy * c11.g);
//     result.b = (uint8_t)((1 - dx) * (1 - dy) * c00.b + dx * (1 - dy) * c10.b +
//                           (1 - dx) * dy * c01.b + dx * dy * c11.b);

//     return result;
// }
