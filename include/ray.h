/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:57:45 by username          #+#    #+#             */
/*   Updated: 2025/03/27 00:59:19 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "ksx_graphics.h"

# ifdef BONUS

#  include <pthread.h>

# endif

# define BIAS		1e-3f
// # define EPSILON 0.0001f
# define MAX_LEN 3.402823466e+38F
# define THREADS 80

typedef struct s_brcntrc
{
	union
	{
		struct
		{
			float	lambda1;
			float	lambda2;
			float	lambda3;
		};
		float	lambda[3];
	};
}	t_brcntrc;

# ifndef BONUS

typedef struct s_ray
{
	t_vector3	origin;
	t_vector3	direction;
	t_vector3	copy_direction;
	float		length;
	float		min_length;
	t_triangle	*p_tri;
	t_plane		*p_pln;
	t_light		*p_lgt;
	t_vertex	point;
	t_brcntrc	brcntrc;
	t_vector3	norm;
	t_pixel		pixel;
	t_color		color;
}	t_ray;

# else

#  define F_TH_START	0b00000001
#  define F_TH_STOP		0b00000010
#  define F_TH_FINISH	0b10000000

typedef struct s_thrddata
{
	t_graphics	*p_grph;
	int32_t		start;
	int32_t		finish;
	int8_t		flags;
}	t_thrddata;

typedef struct s_mondata
{
	t_thrddata	*p_thrddata;
}	t_mondata;

typedef struct s_ray
{
	t_vector3		origin;
	t_vector3		direction;
	t_vector3		copy_direction;
	float			length;
	float			min_length;
	t_triangle		*p_tri;
	t_plane			*p_pln;
	t_light			*p_lgt;
	t_vertex		point;
	t_brcntrc		brcntrc;
	t_vector3		norm;
	t_pixel			pixel;
	t_color			color;
	pthread_mutex_t	th_count;
}	t_ray;

void		ksx_ray_thrd_init(t_mondata	*p_mondata, t_thrddata *p_thrddata,
				t_graphics *p_grph);
void		*ksx_ray_thrd_mon(void *p_data);

# endif

void		ray_cast(t_graphics *grph);
t_ray		ray_generate(int32_t x, int32_t y, t_camera *p_camera);

void		ray_p2boxes(t_world *p_world, t_ray *p_ray);
void		ray_p2tri(t_triangle *p_tri, t_ray *p_ray);
void		ray_p2planes(t_world *p_world, t_ray *p_ray);
void		ray_p2pln(t_plane *p_plane, t_ray *p_ray);
void		ray_p2lights(t_world *p_world, t_ray *p_ray);
void		ray_p2lgt(t_world *p_world, t_light *p_light, t_ray *p_ray);
void		ray_p2lgt_boxes(t_world *p_world, t_ray *p_ray);

t_vector3	triangle_normal_barycentric(t_triangle *p_tri, t_ray *p_ray);
void		rey_get_barycentric(t_vector3 *p_point,
				t_triangle *p_tri, t_ray *p_ray);
t_vector3	triangle_normal_euler(t_vector3 *p_point, t_triangle *p_tri);

void		ray_colors_add(t_color *p_color1, t_color *p_color2);
void		ray_colors_multiply(t_color *p_color1, const t_color *p_color2);
void		ray_colors_scale(t_color *p_color, float scale);
void		ray_colors_8bit(t_color *p_color);
void		ray_colors_calc(t_ray *p_ray);

// t_color 	compute_lightings(t_ray *p_ray, t_graphics *p_grph);
t_color		compute_lighting(t_vector3 *p_point, t_vector3 *p_norm,
				t_color *p_color);
// t_color		ray_colors_blending(t_color *p_color1, t_color *p_color2,
// 				float ratio);
void		ray_colors_calc(t_ray *p_ray);
t_color		compute_light_contribution(t_ray *p_ray);

// t_color		add_ambient_to_color(t_color base_color, float ambient_ratio,
// 				t_color ambient_color);

// t_vector3	triangle_intersection(t_triangle *p_tri, t_ray *p_ray);
// t_vector3	plane_intersection(t_plane *p_plane, t_ray *p_ray);
// t_vector3	triangle_normal(t_vector3 *p_point,
// 				t_triangle *p_tri, t_vector3 *p_v3);
// t_vector3	triangle_normal(t_vector3 *p_point, t_triangle *p_tri);
// t_vector3	triangle_normal_euler(t_vector3 *p_point, t_triangle *p_tri);

// t_ray		ray_generate_w(int32_t x, int32_t y, t_camera *p_camera);
// void		ray_cast(t_graphics *p_grph);
// void 		ray_check_boxes(t_ray *p_ray, t_box **pp_box);
// void		ray_check_boxes(t_ray *p_ray, t_graphics *p_grph);
// void		ray_check_planes(t_ray *p_ray, t_graphics *p_grph);

// float		pixel_bright(t_vector3 *p_normal, t_vector3 *p_light_dir);
// t_color		color_bright(t_color *p_color, float brightness);

#endif
