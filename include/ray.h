/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:57:45 by username          #+#    #+#             */
/*   Updated: 2025/03/13 17:44:50 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "ksx_graphics.h"

# define EPSILON	1.19209e-07
// # define EPSILON	1e-6f
// to eliminate artifacts on the borders
# define BIAS		1e-4f
// # define EPSILON 0.0001f
# define MAX_LEN 3.402823466e+38F

typedef struct s_ray
{
	t_vector3	origin;
	t_vector3	direction;
	float		length;
	// t_triangle	**pp_box;
	t_triangle	*p_tri;
	t_vector3	point;
	t_vector3	norm;
	t_pixel		pixel;
}	t_ray;

void		intersect_tri(t_ray *ray, t_triangle tri);
t_ray		new_ray(t_vector3 o, t_vector3 d, float t);
t_vector3	ray_end(t_ray ray);
void		ray_cast(t_graphics *grph);

t_vector3	triangle_intersection(t_triangle *p_tri, t_ray *p_ray);
// t_vector3	triangle_normal(t_vector3 *p_point,
// 				t_triangle *p_tri, t_vector3 *p_v3);
t_vector3	triangle_normal(t_vector3 *p_point, t_triangle *p_tri);

t_ray		ray_generate(int32_t x, int32_t y, t_camera *p_camera);
t_ray		ray_generate_w(int32_t x, int32_t y, t_camera *p_camera);
void		ray_cast_boxes(t_graphics *p_grph);
// void 		ray_check_boxes(t_ray *p_ray, t_box **pp_box);
void		ray_check_boxes(t_ray *p_ray, t_graphics *p_grph);
t_color		compute_lighting(t_vector3 *p_point, t_vector3 *p_norm,
				t_vector3 *p_light, t_color *p_color);

#endif
