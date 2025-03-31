/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 01:44:06 by ksorokol         ###   ########.fr       */
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
	t_vector3 vec3[3];

    // Choose a reference vector that is not parallel to the plane's normal.
    // If the normal is nearly vertical (e.g., (0,0,1) or (0,0,-1)), choose (1, 0, 0).
    if (fabs(p_plane->norm.cp.z) > 0.999f)
        vec3[0] = ksx_vec3_set(1, 0, 0);
    else
        vec3[0] = ksx_vec3_set(0, 0, 1);

    // Now compute tangent by crossing the normal with the reference vector.
    vec3[0] = ksx_vec3_cross(&p_plane->norm.cp, &vec3[0]);
    vec3[0] = ksx_vec3_unit(&vec3[0]);

    // Compute bitangent.
    vec3[1] = ksx_vec3_cross(&p_plane->norm.cp, &vec3[0]);
    vec3[1] = ksx_vec3_unit(&vec3[1]);

    // Compute the local offset vector from the plane's reference point.
    vec3[2] = ksx_vec3_sub(p_point, &p_plane->point.cp);

    // Project the offset vector onto the tangent and bitangent.
    *p_u = ksx_vec3_dot(&vec3[2], &vec3[0]);
    *p_v = ksx_vec3_dot(&vec3[2], &vec3[1]);
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
	mlx_delete_texture(p_txtr_->p_bumpdata);
}
