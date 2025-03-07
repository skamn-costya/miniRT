/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:57:45 by username          #+#    #+#             */
/*   Updated: 2025/03/07 18:29:59 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "ksx_graphics.h"

# define EPSILON 1.19209e-07
// # define EPSILON 0.000001f

typedef struct s_ray
{
	t_vector3	origin;
	t_vector3	direction;
	float		length;
	t_triangle	**pp_box;
	t_triangle	*p_tri;
	t_pixel		pixel;
}	t_ray;

void		intersect_tri(t_ray *ray, t_triangle tri);
t_ray		new_ray(t_vector3 o, t_vector3 d, float t);
t_vector3	ray_end(t_ray ray);
void		ray_cast(t_graphics *grph);

float		triangle_intersection1(t_triangle *p_tri, t_ray *p_ray);
t_vector3	triangle_intersection2(t_triangle *p_tri, t_ray *p_ray);

void		ray_cast_boxes(t_graphics *p_grph);
// void 		ray_check_boxes(t_ray *p_ray, t_box **pp_box);
void		ray_check_boxes(t_ray *p_ray, t_box **pp_box, t_camera *p_camere);

#endif
