/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/04/01 00:10:39 by ksorokol         ###   ########.fr       */
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

void	ray_txtr_uv_plan(t_vector3 *p_point, float *p_u, float *p_v,
			t_plane *p_plane)
{
	t_vector3	vec3;
	float		u_local;
	float		v_local;

	vec3 = ksx_vec3_sdiv(p_point, 10);
	vec3 = ksx_vec3_sub(&vec3, &p_plane->basis.c_o);
	u_local = ksx_vec3_dot(&vec3, &p_plane->basis.i);
	v_local = ksx_vec3_dot(&vec3, &p_plane->basis.k);
	u_local = u_local - (int32_t)u_local;
	v_local = v_local - (int32_t)v_local;
	if (u_local < 0)
		u_local += 1;
	if (v_local < 0)
		v_local += 1;
	*p_u = u_local;
	*p_v = v_local;
}

// /= .85f;  // Scale UV -> [0, 1]
void	ray_txtr_uv_spheres(t_vector3 *p_point, float *p_u, float *p_v)
{
	float	len;

	len = ksx_vec3_mag(p_point);
	p_point->x = p_point->x / len;
	p_point->y = p_point->y / len;
	p_point->z = p_point->z / len;
	*p_u = .5f + atan2f(p_point->z, p_point->x) * PI_12;
	*p_v = .5f - asinf(p_point->y) * PI_1;
}

void	ray_txtr_uv_cylinder(t_vector3 *p_point, float *p_u, float *p_v)
{
	float	len;

	len = ksx_vec3_mag(p_point);
	p_point->x = p_point->x / len;
	p_point->y = p_point->y / len;
	p_point->z = p_point->z / len;
	*p_u = .5f + atan2f(p_point->z, p_point->x) * PI_12;
	*p_v = 1.f - ((p_point->y + 1.f) / 2.f);
}

void	ray_txtr_free_data(void *p_txtr)
{
	t_texture	*p_txtr_;

	p_txtr_ = (t_texture *)p_txtr;
	free(p_txtr_->name);
	mlx_delete_texture(p_txtr_->p_mapdata);
	if (p_txtr_->p_bumpdata)
		mlx_delete_texture(p_txtr_->p_bumpdata);
}
