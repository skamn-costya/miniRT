/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/26 13:43:35 by ksorokol         ###   ########.fr       */
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

void	ray_txtr_uv_plan(t_vector3 *p_point, float *p_u, float *p_v)
{
	*p_u = p_point->x;
	*p_v = p_point->y;
}

// /= .85f;  // Scale UV -> [0, 1]
void	ray_txtr_uv_spheres(t_vector3 *p_point, float *p_u, float *p_v)
{
	float	len;

	len = ksx_vec3_mag(p_point);
	p_point->x = p_point->x / len;
	p_point->y = p_point->y / len;
	p_point->z = p_point->z / len;
	// p_point->x /= .85f;
	// p_point->y /= .85f;
	*p_u = .5f + atan2f(p_point->z, p_point->x) * PI_12;
	*p_v = .5f - asinf(p_point->y) * PI_1;
}

void	ray_txtr_uv_cylinder(t_vector3 *p_point, float *p_u, float *p_v)
{
	*p_u = .5f + atan2f(p_point->z, p_point->x) * PI_12;
	*p_v = p_point->y * .5f;
}

void ray_txtr_free_data(void *p_txtr)
{
	t_texture	*p_txtr_;

	p_txtr_ = (t_texture *)p_txtr;
	free(p_txtr_->name);
	mlx_delete_texture(p_txtr_->p_data);
}
