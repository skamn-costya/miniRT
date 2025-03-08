/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:28:32 by username          #+#    #+#             */
/*   Updated: 2025/03/08 19:29:03 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "math.h"
#include <stdio.h>

//Möller–Trumbore intersection algorithm
void	intersect_tri(t_ray *ray, t_triangle tri)
{
	t_vector3	edge1;
	t_vector3 edge2;
	t_vector3	h;
	float	a;
	t_vector3	s;
	float	f;
	t_vector3	q;
	float	v;
	float	t;
	float	u;

	edge1 = ksx_vec3_sub(&tri.p_ver2->cp, &tri.p_ver1->cp);
	edge2 = ksx_vec3_sub(&tri.p_ver3->cp, &tri.p_ver1->cp);
	h = ksx_vec3_cross(&ray->direction, &edge2);
	a = ksx_vec3_dot(&edge1, &h);
	if (a > -0.0001f && a < 0.0001f)
		return;
	f = 1 / a;
	s = ksx_vec3_sub(&ray->origin, &tri.p_ver1->cp);
	u = f * ksx_vec3_dot(&s, &h);
	if (u < 0 || u > 1)
		return ;
	q = ksx_vec3_cross(&s, &edge1);
	v = f * ksx_vec3_dot(&ray->direction, &q);
	if (v < 0 || u + v > 1)
		return ;
	t = f * ksx_vec3_dot(&edge2, &q);
	if (t > 0.0001f && t < ray->length)
		ray->length = t;
}


// t_vector3	edge1, edge2, pvec, tvec, qvec, intersection;
// float		det, inv_det, u, v, t;

/*
v3[0] → edge1
v3[1] → edge2
v3[2] → pvec
v3[3] → tvec
v3[4] → qvec
v3[5] and v3[6] are used to store the final intersection

f[0] → det
f[1] → inv_det
f[2] → u
f[3] → v
f[4] → t
*/

t_vector3	triangle_intersection(t_triangle *p_tri, t_ray *p_ray)
{
	t_vector3	v3[7];
	float		f[5];

	v3[0] = ksx_vec3_sub(&p_tri->p_ver2->cp, &p_tri->p_ver1->cp);
	v3[1] = ksx_vec3_sub(&p_tri->p_ver3->cp, &p_tri->p_ver1->cp);
	v3[2] = ksx_vec3_cross(&p_ray->direction, &v3[1]);
	f[0] = ksx_vec3_dot(&v3[0], &v3[2]);
	if (fabsf(f[0]) < EPSILON)  
		return ksx_vec3_set(0.f, 0.f, 0.f);
	f[1] = 1.f / f[0];
	v3[3] = ksx_vec3_sub(&p_ray->origin, &p_tri->p_ver1->cp);
	f[2] = ksx_vec3_dot(&v3[3], &v3[2]) * f[1];
	if (f[2] < -BIAS || f[2] > 1.0f + BIAS)  
		return ksx_vec3_set(0.f, 0.f, 0.f);
	v3[4] = ksx_vec3_cross(&v3[3], &v3[0]);
	f[3] = ksx_vec3_dot(&p_ray->direction, &v3[4]) * f[1];
	if (f[3] < -BIAS || f[2] + f[3] > 1.0f + BIAS)  
		return ksx_vec3_set(0.f, 0.f, 0.f);
	f[4] = ksx_vec3_dot(&v3[1], &v3[4]) * f[1];
	if (f[4] > EPSILON && p_ray->length > f[4])
	{
		p_ray->length = f[4];
		p_ray->p_tri = p_tri;
		v3[5] = ksx_vec3_smulti(&p_ray->direction, f[4]);
		v3[6] = ksx_vec3_add(&p_ray->origin, &v3[5]);
		p_ray->point = v3[6];
		// p_ray->norm = triangle_normal(&v3[6], p_tri, v3); // segmentation fault (NO norms ...)
		return v3[6];
	}
	return ksx_vec3_set(0.f, 0.f, 0.f);
}

t_vector3	triangle_normal(t_vector3 *p_point,
		t_triangle *p_tri, t_vector3 *p_v3)
{
	t_vector3	vec3[4];
	float		f;
	float		lambda[3];
	
	p_v3[2] = ksx_vec3_sub(p_point, &p_tri->p_ver1->cp); // point - p1
	vec3[0] = ksx_vec3_cross(&p_v3[2], &p_v3[1]);
	f = ksx_vec3_dot(&p_v3[0], &vec3[0]);
	f = 1.f / f;
	lambda[0] = ksx_vec3_dot(&p_v3[2], &vec3[0]) * f;
	lambda[1] = ksx_vec3_dot(&p_v3[0], &vec3[0]) * f;
	lambda[2] = 1.f - lambda[0] - lambda[1];
	vec3[0] = ksx_vec3_smulti(&p_tri->p_norm1->cp, lambda[0]);
	vec3[1] = ksx_vec3_smulti(&p_tri->p_norm2->cp, lambda[1]);
	vec3[2] = ksx_vec3_smulti(&p_tri->p_norm3->cp, lambda[2]);
	vec3[3] = ksx_vec3_add(&vec3[0], &vec3[1]);
	vec3[3] = ksx_vec3_add(&vec3[3], &vec3[2]);
	return ksx_vec3_unit(&vec3[3]);
}
