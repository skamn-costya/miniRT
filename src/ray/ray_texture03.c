/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/25 14:57:31 by ksorokol         ###   ########.fr       */
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

t_color	ray_txtr_object(t_world *p_world,
	t_object *p_object, t_vector3 *p_point)
{
	// t_vector4	v4;
	t_vector3	v3;
	float		uv[2];
	t_color		result;

	// v4 = ksx_vec3_vec4(p_point, 1);
	// v4 = ksx_m4_vec4(&p_world->p_camera->ivm, &v4);
	// v3 = ksx_vec4_vec3(&v4);
	// v3 = ksx_vec3_sub(&v3, &p_object->basis.w_o);
	(void)p_world;
	v3 = *p_point;
	ksx_vec3_resize(&v3, .5f);
	p_object->ray_txtr_uv(&v3, &uv[0], &uv[1]);
	result = ray_txtr_sample(p_object->p_texture, uv[0], uv[1]);
	return (result);
}
