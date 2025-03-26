/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/26 17:22:02 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ray.h"
#include "ray_texture.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_3D.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "pp_struct.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

t_color	ray_txtr_object(t_object *p_object, t_vector3 *p_point,
	t_color	*p_color)
{
	t_vector3	v3;
	float		uv[2];
	t_color		result;

	p_object->color.material.kd = .8f;
	p_object->color.material.ks = .7f;
	v3 = *p_point;
	p_object->ray_txtr_uv(&v3, &uv[0], &uv[1]);
	if (p_color->b < 4)
		result = ray_txtr_sample(p_object->p_texture, uv[0], uv[1]);
	else if (p_color->b == 4)
		result = ray_uv_checker(uv[0], uv[1], 20);
	else
		result = ray_uv_debug_color(uv[0], uv[1]);
	ksx_color_unit_fraction(&result);
	return (result);
}

t_color ray_uv_debug_color(float u, float v)
{
    t_color color;

    color.r = (uint8_t)(u * 255);
    color.g = (uint8_t)(v * 255);
	color.b = (uint8_t)((1 - v) * 255); 
    color.a = 255;
    return (color);
}

t_color ray_uv_checker(float u, float v, int scale)
{
	t_color color;

    int x = (int)(u * scale) % 2;
    int y = (int)(v / 2.f * scale) % 2;

    if (x == y)
		color.mlx_color = 0xFFFFFFFF;
    else
		color.mlx_color = 0xFF000000;
	return (color);
}

// t_vector3 apply_bump_map(t_vector3 normal, t_texture *bump_map, float u, float v) {
//     float du = 1.0 / bump_map->width;
//     float dv = 1.0 / bump_map->height;

//     float h0 = sample_texture(bump_map, u, v);
//     float hx = sample_texture(bump_map, u + du, v);
//     float hy = sample_texture(bump_map, u, v + dv);

//     float bump_strength = 0.1f; // Adjust for stronger or weaker effect

//     float dx = (hx - h0) * bump_strength;
//     float dy = (hy - h0) * bump_strength;

//     t_vector3 tangent = {1, 0, 0}; // Assume a tangent space
//     t_vector3 bitangent = {0, 1, 0};

//     t_vector3 perturbed_normal = ksx_vec3_add(normal,
//         ksx_vec3_scale(&tangent, dx),
//         ksx_vec3_scale(&bitangent, dy));

//     return ksx_vec3_unit(&perturbed_normal); // Normalize the result
// }
