/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:28:32 by username          #+#    #+#             */
/*   Updated: 2025/03/07 18:30:17 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "math.h"

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

// orig и dir задают начало и направление луча. v0, v1, v2 - вершины треугольника.
// Функция возвращает расстояние от начала луча до точки пересечения или 0.
float	triangle_intersection1(t_triangle *p_tri, t_ray *p_ray)
{
	t_vector3	vec3[5];
	float		det[2];
	float		uv[2];

	vec3[0] = ksx_vec3_sub(&p_tri->p_ver2->cp, &p_tri->p_ver1->cp); // vec3 e1 = v1 - v0;
	vec3[1] = ksx_vec3_sub(&p_tri->p_ver3->cp, &p_tri->p_ver1->cp); // vec3 e2 = v2 - v0;
	// Вычисление вектора нормали к плоскости
	vec3[2] = ksx_vec3_cross(&p_ray->direction, &vec3[1]); // vec3 pvec = cross(dir, e2);
	det[0] = ksx_vec3_dot(&vec3[0], &vec3[2]); // float det = dot(e1, pvec);
	// Луч параллелен плоскости
	if (det[0] < 1e-8 && det[0] > -1e-8) // if (det < 1e-8 && det > -1e-8)
		return (p_ray->length);
	det[1] = 1.f / det[0]; // float inv_det = 1 / det;
	vec3[3] = ksx_vec3_sub(&p_ray->origin, &p_tri->p_ver1->cp); // vec3 tvec = orig - v0;
	uv[0] =  ksx_vec3_dot(&vec3[3], &vec3[2]) * det[1]; // float u = dot(tvec, pvec) * inv_det;
	if (uv[0] < 0 || uv[0] > 1) //if (u < 0 || u > 1)
		return (p_ray->length);
	vec3[4] = ksx_vec3_cross(&vec3[3], &vec3[0]); // vec3 qvec = cross(tvec, e1);
	uv[1] = ksx_vec3_dot(&p_ray->direction, &vec3[4]) * det[1]; // float v = dot(dir, qvec) * inv_det;
	if (uv[1] < 0 || uv[0] + uv[1] > 1) // if (v < 0 || u + v > 1)
		return (p_ray->length);
	uv[0] = ksx_vec3_dot(&vec3[1], &vec3[4]); // return dot(e2, qvec) * inv_det;
	if (p_ray->length < uv[0])
		return (p_ray->length);
	return (p_ray->length = uv[0], uv[0]);
}

// std::optional<vec3> ray_intersects_triangle( const vec3 &ray_origin,
//     const vec3 &ray_vector,
//     const triangle3& triangle)
t_vector3	triangle_intersection2(t_triangle *p_tri, t_ray *p_ray)
{
	t_vector3	vec3[5];
	float		det[2];
	float		uv[2];
	// constexpr float epsilon = std::numeric_limits<float>::epsilon();

	vec3[0] = ksx_vec3_sub(&p_tri->p_ver2->cp, &p_tri->p_ver1->cp); // vec3 edge1 = triangle.b - triangle.a;
	vec3[1] = ksx_vec3_sub(&p_tri->p_ver3->cp, &p_tri->p_ver1->cp); // vec3 edge2 = triangle.c - triangle.a;
	vec3[2] = ksx_vec3_cross(&p_ray->direction, &vec3[1]); // vec3 ray_cross_e2 = cross(ray_vector, edge2);
	det[0] = ksx_vec3_dot(&vec3[0], &vec3[2]); // float det = dot(edge1, ray_cross_e2);
	if (det[0] > -EPSILON && det[0] < EPSILON) // if (det > -epsilon && det < epsilon)
		return ksx_vec3_set(0.f, 0.f, 0.f); //	 return {};	// This ray is parallel to this triangle.
	det[1] = 1.f / det[0]; // float inv_det = 1.0 / det;
	vec3[3] = ksx_vec3_sub(&p_ray->origin, &p_tri->p_ver1->cp);// vec3 s = ray_origin - triangle.a;
	uv[0] = det[1] * ksx_vec3_dot(&vec3[3], &vec3[2]);// float u = inv_det * dot(s, ray_cross_e2);
	if ((uv[0] < 0 && fabs(uv[0]) > EPSILON) || (uv[0] > 1 && fabs(uv[0] - 1) > EPSILON))
	// if ((u < 0 && abs(u) > epsilon) || (u > 1 && abs(u-1) > epsilon))
		return ksx_vec3_set(0.f, 0.f, 0.f); //	 return {};
	vec3[4] = ksx_vec3_cross(&vec3[3], &vec3[0]); // vec3 s_cross_e1 = cross(s, edge1);
	uv[1] = det[1] * ksx_vec3_dot(&p_ray->direction, &vec3[4]); // float v = inv_det * dot(ray_vector, s_cross_e1);
	if ((uv[1] < 0 && fabs(uv[1]) > EPSILON) || (uv[0] + uv[1] > 1 && fabs(uv[0] + uv[1] - 1) > EPSILON))
	// if ((v < 0 && abs(v) > epsilon) || (u + v > 1 && abs(u + v - 1) > epsilon))
		return ksx_vec3_set(0.f, 0.f, 0.f); //	 return {};
	// At this stage we can compute t to find out where the intersection point is on the line.
	uv[0] = det[1] * ksx_vec3_dot(&vec3[1], &vec3[4]);// float t = inv_det * dot(edge2, s_cross_e1);
	// if (uv[0] > EPSILON) // if (t > epsilon) // ray intersection
	{
		vec3[0] = ksx_vec3_smulti(&p_ray->direction, uv[0]);
		vec3[1] = ksx_vec3_add(&p_ray->origin, &vec3[0]); //	 return  vec3(ray_origin + ray_vector * t);
		return (vec3[1]);
	}
	// else // This means that there is a line intersection but not a ray intersection.
	// return ksx_vec3_set(0.f, 0.f, 0.f); //	 return {};
}
