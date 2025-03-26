/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/25 23:39:53 by ksorokol         ###   ########.fr       */
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

t_texture	*ray_txtr_load(t_world *p_world, char *p_filename)
{
	t_texture *p_texture;

	p_texture = (t_texture *)malloc(sizeof(t_texture));
	if (!p_texture)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	p_texture->p_data = mlx_load_png(p_filename);
	if (!p_texture)
		return (p_texture);
	p_texture->name = ft_strdup(p_filename);
	p_world->pp_txtr = (t_texture **)pp_add_instance((void **)
			p_world->pp_txtr, (void *)p_texture, &ksx_error);
	return (p_texture);
}

// uint32_t	ray_txtr_sample_nearest(t_texture *p_txtr, float u, float v)
t_color	ray_txtr_sample(t_texture *p_txtr, float u, float v)
{
	t_color color;
    int width = p_txtr->p_data->width;
    int height = p_txtr->p_data->height;
    int x = (int)floorf(fmodf(u * width, width));
    int y = (int)floorf(fmodf(v * height, height));
    if (x < 0) x += width;
    if (y < 0) y += height;
    int index = (y * width + x) * BPP;
    // if (index + 3 >= width * height * BPP)
    //     return 0;  // Предотвращаем выход за границы памяти
    color.r = p_txtr->p_data->pixels[index + 0]; 
    color.g = p_txtr->p_data->pixels[index + 1];
    color.b = p_txtr->p_data->pixels[index + 2];
    color.a = p_txtr->p_data->pixels[index + 3];
    return (color);
}

// // uint32_t ray_txtr_sample_bilinear(t_texture *p_txtr, float u, float v)
// t_color ray_txtr_sample(t_texture *p_txtr, float u, float v)
// {
//     u = u * p_txtr->p_data->width - 0.5f;
//     v = v * p_txtr->p_data->height - 0.5f;
// 	t_color c00;
// 	t_color c10;
// 	t_color c01;
// 	t_color c11;


//     int x = (int)u;
//     int y = (int)v;
//     float dx = u - x;
//     float dy = v - y;

//     int index00 = ((y % p_txtr->p_data->height) * p_txtr->p_data->width + (x % p_txtr->p_data->width)) * BPP;
//     int index10 = ((y % p_txtr->p_data->height) * p_txtr->p_data->width + ((x + 1) % p_txtr->p_data->width)) * BPP;
//     int index01 = (((y + 1) % p_txtr->p_data->height) * p_txtr->p_data->width + (x % p_txtr->p_data->width)) * BPP;
//     int index11 = (((y + 1) % p_txtr->p_data->height) * p_txtr->p_data->width + ((x + 1) % p_txtr->p_data->width)) * BPP;

//     c00.r = p_txtr->p_data->pixels[index00];
// 	c00.g = p_txtr->p_data->pixels[index00 + 1];
// 	c00.b = p_txtr->p_data->pixels[index00 + 2];
// 	c00.a = p_txtr->p_data->pixels[index00 + 3];
	
// 	c10.r = p_txtr->p_data->pixels[index10];
// 	c10.g = p_txtr->p_data->pixels[index10 + 1];
// 	c10.b = p_txtr->p_data->pixels[index10 + 2];
// 	c10.a = p_txtr->p_data->pixels[index10 + 3];

// 	c01.r = p_txtr->p_data->pixels[index01];
// 	c01.g = p_txtr->p_data->pixels[index01 + 1];
// 	c01.b = p_txtr->p_data->pixels[index01 + 2];
// 	c01.a = p_txtr->p_data->pixels[index01 + 3];

// 	c11.r = p_txtr->p_data->pixels[index11];
// 	c11.g = p_txtr->p_data->pixels[index11 + 1];
// 	c11.b = p_txtr->p_data->pixels[index11 + 2];
// 	c11.a = p_txtr->p_data->pixels[index11 + 3];

//     // c10.r = p_txtr->p_data->pixels[index10], p_txtr->p_data->pixels[index10 + 1], p_txtr->p_data->pixels[index10 + 2];
//     // c01.r = p_txtr->p_data->pixels[index01], p_txtr->p_data->pixels[index01 + 1], p_txtr->p_data->pixels[index01 + 2];
//     // c11.r = p_txtr->p_data->pixels[index11], p_txtr->p_data->pixels[index11 + 1], p_txtr->p_data->pixels[index11 + 2];

//     t_color result;
//     result.r = (uint8_t)((1 - dx) * (1 - dy) * c00.r + dx * (1 - dy) * c10.r +
//                           (1 - dx) * dy * c01.r + dx * dy * c11.r);
//     result.g = (uint8_t)((1 - dx) * (1 - dy) * c00.g + dx * (1 - dy) * c10.g +
//                           (1 - dx) * dy * c01.g + dx * dy * c11.g);
//     result.b = (uint8_t)((1 - dx) * (1 - dy) * c00.b + dx * (1 - dy) * c10.b +
//                           (1 - dx) * dy * c01.b + dx * dy * c11.b);
// 	result.b = (uint8_t)((1 - dx) * (1 - dy) * c00.a + dx * (1 - dy) * c10.a +
//                           (1 - dx) * dy * c01.a + dx * dy * c11.a);

//     return result;
// }
