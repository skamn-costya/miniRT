/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:45:28 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/27 16:29:04 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TEXTURE_H
# define RAY_TEXTURE_H

# include "ksx_graphics.h"
# include "ray.h"

# define PI_1	0.31830988618379069
# define PI_12	0.15915494309189535

t_texture	*ray_txtr_load(t_world *p_world, char *p_mapname, char *p_bumpname);

void		ray_txtr_uv_plan(t_vector3 *p_point, float *p_u, float *p_v);
void		ray_txtr_uv_spheres(t_vector3 *p_point, float *p_u, float *p_v);
void		ray_txtr_uv_cylinder(t_vector3 *p_point, float *p_u, float *p_v);
t_color		ray_txtr_sample(t_texture *p_txtr, float u, float v);
float		ray_bump_sample(t_texture *p_txtr, float u, float v);
void		ray_txtr_free_data(void *p_txtr);

void		ray_txtr_object(t_object *p_object, t_ray *p_ray);
t_vector3	ray_bump_object(t_vector3 *p_normal, t_texture *p_txtr,
				float u, float v);
// t_color		ray_txtr_object(t_object *p_object, t_vector3 *p_point,
// 				t_color	*p_color);

t_color		ray_uv_debug_color(float u, float v);
t_color		ray_uv_checker(float u, float v, int scale);

#endif // RAY_TEXTURE_H
