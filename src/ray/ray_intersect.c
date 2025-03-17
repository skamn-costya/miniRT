/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:28:32 by username          #+#    #+#             */
/*   Updated: 2025/03/18 00:40:40 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "math.h"
#include <stdio.h>

//Möller–Trumbore intersection algorithm

t_vector3	triangle_intersection(t_triangle *p_tri, t_ray *p_ray)
{
	t_vector3	v3[7];
	float		f[5];

	v3[0] = ksx_vec3_sub(&p_tri->p_ver2->cp, &p_tri->p_ver1->cp);
	v3[1] = ksx_vec3_sub(&p_tri->p_ver3->cp, &p_tri->p_ver1->cp);
	v3[2] = ksx_vec3_cross(&p_ray->direction, &v3[1]);
	f[0] = ksx_vec3_dot(&v3[0], &v3[2]);
	if (fabsf(f[0]) < EPSILON)  
		return (ksx_vec3_set(0.f, 0.f, 0.f));
	f[1] = 1.f / f[0];
	v3[3] = ksx_vec3_sub(&p_ray->origin, &p_tri->p_ver1->cp);
	f[2] = ksx_vec3_dot(&v3[3], &v3[2]) * f[1];
	if (f[2] < -BIAS || f[2] > 1.f + BIAS)  
		return ksx_vec3_set(0.f, 0.f, 0.f);
	v3[4] = ksx_vec3_cross(&v3[3], &v3[0]);
	f[3] = ksx_vec3_dot(&p_ray->direction, &v3[4]) * f[1];
	if (f[3] < -BIAS || f[2] + f[3] > 1.f + BIAS)  
		return ksx_vec3_set(0.f, 0.f, 0.f);
	f[4] = ksx_vec3_dot(&v3[1], &v3[4]) * f[1];
	if (f[4] > EPSILON && p_ray->length > f[4])
	{
		p_ray->length = f[4];
		if (p_tri->p_norm1 && p_ray->length < p_ray->min_length)
		{
			p_ray->min_length = p_ray->length;
			p_ray->pixel.color.mlx_color = p_tri->color.mlx_color;
			v3[5] = ksx_vec3_smulti(&p_ray->direction, f[4]);
			v3[6] = ksx_vec3_add(&p_ray->origin, &v3[5]);
			p_ray->point = v3[6];
			p_ray->p_tri = p_tri;
			p_ray->norm = triangle_normal_barycentric(&v3[6], p_tri);
		}
		return v3[6];
	}
	return ksx_vec3_set(0.f, 0.f, 0.f);
}

t_vector3	triangle_normal_barycentric(t_vector3 *p_point, t_triangle *p_tri)
{
    t_vector3	edge[3];
    t_vector3 normal, interpolated_normal;
    float area_inv, lambda0, lambda1, lambda2;
	t_vector3	vec3[2];

    edge[0] = ksx_vec3_sub(&p_tri->p_ver2->cp, &p_tri->p_ver1->cp);
    edge[1] = ksx_vec3_sub(&p_tri->p_ver3->cp, &p_tri->p_ver1->cp);
    edge[2] = ksx_vec3_sub(p_point, &p_tri->p_ver1->cp);
    normal = ksx_vec3_cross(&edge[0], &edge[1]);
    float area2 = ksx_vec3_mag(&normal);
    area_inv = 1.f / area2;
	vec3[0] = ksx_vec3_cross(&edge[2], &edge[0]);
	vec3[1] = ksx_vec3_cross(&edge[2], &edge[1]);
	
	lambda2 = fmax(ksx_vec3_mag(&vec3[0]) * area_inv, 0.f);
    lambda1 = fmax(ksx_vec3_mag(&vec3[1]) * area_inv, 0.f);
    lambda0 = 1.0f - lambda1 - lambda2;
	vec3[0] = ksx_vec3_smulti(&p_tri->p_norm1->wp, lambda0);
	vec3[1] = ksx_vec3_smulti(&p_tri->p_norm2->wp, lambda1);
	vec3[0] = ksx_vec3_add(&vec3[0], &vec3[1]);
	vec3[1] = ksx_vec3_smulti(&p_tri->p_norm3->wp, lambda2);
	interpolated_normal = ksx_vec3_add(&vec3[0], &vec3[1]);
    return ksx_vec3_unit(&interpolated_normal);
}

t_vector3	triangle_normal_euler(t_vector3 *p_point, t_triangle *p_tri)
{
	t_vector3	vec3[4];
	float		f;
	float		lambda[3];
	
	lambda[0] = ksx_vec3_dist(p_point, &p_tri->p_ver1->cp);
	lambda[1] = ksx_vec3_dist(p_point, &p_tri->p_ver2->cp);
	lambda[2] = ksx_vec3_dist(p_point, &p_tri->p_ver3->cp);
	f = 1 / (lambda[0] + lambda[1] + lambda[2]);
	lambda[0] *= f;
	lambda[1] *= f;
	lambda[2] *= f;
	lambda[0] = 1/lambda[0];
	lambda[1] = 1/lambda[1];
	lambda[2] = 1/lambda[2];
	vec3[0] = ksx_vec3_smulti(&p_tri->p_norm1->wp, lambda[0]);
	vec3[1] = ksx_vec3_smulti(&p_tri->p_norm2->wp, lambda[1]);
	vec3[2] = ksx_vec3_smulti(&p_tri->p_norm3->wp, lambda[2]);
	vec3[3] = ksx_vec3_add(&vec3[0], &vec3[1]);
	vec3[3] = ksx_vec3_add(&vec3[3], &vec3[2]);
	return (ksx_vec3_unit(&vec3[3]));
}

t_vector3	plane_intersection(t_plane *p_plane, t_ray *p_ray)
{
	t_vector3	result;
	float		denom;
	float		f;
	t_vector3	vec3;

	denom = ksx_vec3_dot(&p_ray->direction, &p_plane->norm.cp);
	if (fabsf(denom) < EPSILON)
		return ksx_vec3_set(0.f, 0.f, 0.f);
	vec3 = ksx_vec3_sub(&p_plane->point.cp, &p_ray->origin);
	f = ksx_vec3_dot(&vec3, &p_plane->norm.cp) / denom;
	if (f < 0)
		return ksx_vec3_set(0.f, 0.f, 0.f);
	result = ksx_vec3_smulti(&p_ray->direction, f);
	result = ksx_vec3_add(&p_ray->origin, &result);
	vec3 = ksx_vec3_sub(&result, &p_ray->origin);
	p_ray->length = ksx_vec3_mag(&vec3);
	if (p_ray->length > EPSILON && p_ray->length < p_ray->min_length)
	{
		p_ray->length = f;
		p_ray->min_length = p_ray->length;
			p_ray->pixel.color.mlx_color = p_plane->color.mlx_color;
			p_ray->point = result;
			p_ray->p_tri = NULL;
			p_ray->p_pln = p_plane;
			p_ray->norm = p_plane->norm.cp;
		return result;
	}
	return ksx_vec3_set(0.f, 0.f, 0.f);
}
