/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/25 12:06:16 by ksorokol         ###   ########.fr       */
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


void	ray_txtr_uv_spheres(t_vector3 *p_point, float *p_u, float *p_v)
{
	static const float INV_PI = 1.f / PI;
    static const float INV_2PI = 1.f / (2.f * PI);
	
    *p_u = .5f + atan2f(p_point->z, p_point->x) * INV_2PI;
    *p_v = .5f - asinf(p_point->y) * INV_PI;
	// *p_u = .5f + atan2f(p_point->z, p_point->x) * PI_12;
	// *p_v = .5f - asinf(p_point->y) * PI_1;
}

void	ray_txtr_uv_cylinder(t_vector3 *p_point, float *p_u, float *p_v)
{
	static const float INV_2PI = 1.f / (2.f * PI);

	*p_u = .5f + atan2f(p_point->z, p_point->x) * INV_2PI;
	// *p_u = .5f + atan2f(p_point->z, p_point->x) * PI_12;
	*p_v = p_point->y * .5f;
}

void ray_txtr_free_data(void *p_txtr)
{
	t_texture	*p_txtr_;

	p_txtr_ = (t_texture *)p_txtr;
	free(p_txtr_->name);
	mlx_delete_texture(p_txtr_->p_data);
}
