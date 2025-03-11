/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:28:32 by username          #+#    #+#             */
/*   Updated: 2025/03/10 00:48:55 by ksorokol         ###   ########.fr       */
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

void barycentric_coordinates(t_vector3 *p, t_triangle *tri, float *lambda)
{
    t_vector3 v0 = ksx_vec3_sub(&tri->p_ver2->cp, &tri->p_ver1->cp);
    t_vector3 v1 = ksx_vec3_sub(&tri->p_ver3->cp, &tri->p_ver1->cp);
    t_vector3 v2 = ksx_vec3_sub(p, &tri->p_ver1->cp);

    float d00 = ksx_vec3_dot(&v0, &v0);
    float d01 = ksx_vec3_dot(&v0, &v1);
    float d11 = ksx_vec3_dot(&v1, &v1);
    float d20 = ksx_vec3_dot(&v2, &v0);
    float d21 = ksx_vec3_dot(&v2, &v1);

    float denom = d00 * d11 - d01 * d01;
    if (fabsf(denom) < EPSILON) {
        lambda[0] = lambda[1] = lambda[2] = 0.f; // Ошибка, точка вне треугольника
        return;
    }

    float inv_denom = 1.0f / denom;
    lambda[1] = (d11 * d20 - d01 * d21) * inv_denom;
    lambda[2] = (d00 * d21 - d01 * d20) * inv_denom;
    lambda[0] = 1.0f - lambda[1] - lambda[2];
}

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
		p_ray->p_tri = p_tri;
		v3[5] = ksx_vec3_smulti(&p_ray->direction, f[4]);
		v3[6] = ksx_vec3_add(&p_ray->origin, &v3[5]);
		p_ray->point = v3[6];
		p_ray->norm = triangle_normal(&v3[6], p_tri);
		return v3[6];
	}
	return ksx_vec3_set(0.f, 0.f, 0.f);
}

// t_vector3	triangle_intersection(t_triangle *p_tri, t_ray *p_ray)
// {
// 	t_vector3	edge1, edge2, h, s, q, intersection, vector;
// 	float		a, f, u, v, t;

// 	// Вычисляем ребра треугольника
// 	edge1 = ksx_vec3_sub(&p_tri->p_ver2->cp, &p_tri->p_ver1->cp);
// 	edge2 = ksx_vec3_sub(&p_tri->p_ver3->cp, &p_tri->p_ver1->cp);

// 	// Вычисляем векторное произведение направления луча и второго ребра
// 	h = ksx_vec3_cross(&p_ray->direction, &edge2);
// 	a = ksx_vec3_dot(&edge1, &h);

// 	// Если a близко к 0, значит луч параллелен треугольнику
// 	if (fabsf(a) < EPSILON)
// 		return ksx_vec3_set(0.f, 0.f, 0.f);
	
// 	f = 1.0f / a;
// 	s = ksx_vec3_sub(&p_ray->origin, &p_tri->p_ver1->cp);

// 	// Барицентрические координаты
// 	u = f * ksx_vec3_dot(&s, &h);
// 	if (u < 0.0f || u > 1.0f)
// 		return ksx_vec3_set(0.f, 0.f, 0.f);

// 	q = ksx_vec3_cross(&s, &edge1);
// 	v = f * ksx_vec3_dot(&p_ray->direction, &q);
// 	if (v < 0.0f || (u + v) > 1.0f)
// 		return ksx_vec3_set(0.f, 0.f, 0.f);

// 	// Найдено пересечение
// 	t = f * ksx_vec3_dot(&edge2, &q);
// 	if (t > EPSILON && t < p_ray->length)  
// 	{
// 		p_ray->length = t;
// 		p_ray->p_tri = p_tri;

// 		// Точка пересечения
// 		vector = ksx_vec3_smulti(&p_ray->direction, t);
// 		intersection = ksx_vec3_add(&p_ray->origin, &vector);
// 		p_ray->point = intersection;

// 		// Интерполированная нормаль в точке
// 		p_ray->norm = triangle_normal(&intersection, p_tri);

// 		return intersection;
// 	}
// 	return ksx_vec3_set(0.f, 0.f, 0.f);
// }

// t_vector3	triangle_normal(t_vector3 *p_point,
// 		t_triangle *p_tri, t_vector3 *p_v3)
// {
// 	t_vector3	vec3[4];
// 	float		f;
// 	float		lambda[3];
	
// 	if (!p_tri->p_norm1)
// 		return (ksx_vec3_set(0.f, 0.f, 0.f));
// 	p_v3[2] = ksx_vec3_sub(p_point, &p_tri->p_ver1->cp);
// 	vec3[0] = ksx_vec3_cross(&p_v3[2], &p_v3[1]);
// 	f = ksx_vec3_dot(&p_v3[0], &vec3[0]);
// 	f = 1.f / f;
// 	lambda[0] = ksx_vec3_dot(&p_v3[2], &vec3[0]) * f;
// 	lambda[1] = ksx_vec3_dot(&p_v3[0], &vec3[0]) * f;
// 	lambda[2] = 1.f - lambda[0] - lambda[1];
// 	vec3[0] = ksx_vec3_smulti(&p_tri->p_norm1->lp, lambda[0]);
// 	vec3[1] = ksx_vec3_smulti(&p_tri->p_norm2->lp, lambda[1]);
// 	vec3[2] = ksx_vec3_smulti(&p_tri->p_norm3->lp, lambda[2]);
// 	vec3[3] = ksx_vec3_add(&vec3[0], &vec3[1]);
// 	vec3[3] = ksx_vec3_add(&vec3[3], &vec3[2]);
// 	return ksx_vec3_unit(&vec3[3]);
// }

t_vector3 triangle_normal(t_vector3 *p_point, t_triangle *p_tri)
{
    // Проверка на наличие нормалей в вершинах
    if (!p_tri->p_norm1)
        return ksx_vec3_set(0.f, 0.f, 0.f);

    // Вычисление барицентрических координат
    t_vector3 v0 = ksx_vec3_sub(&p_tri->p_ver2->cp, &p_tri->p_ver1->cp);  // Ребро 1
    t_vector3 v1 = ksx_vec3_sub(&p_tri->p_ver3->cp, &p_tri->p_ver1->cp);  // Ребро 2
    t_vector3 v2 = ksx_vec3_sub(p_point, &p_tri->p_ver1->cp);             // Вектор от первой вершины до точки

    // Перекрёстное произведение
    t_vector3 cross_v2_v1 = ksx_vec3_cross(&v2, &v1);
    float f = ksx_vec3_dot(&v0, &cross_v2_v1);  // Нахождение детерминанта

    // Если детерминант близок к нулю, значит точка вне треугольника
    if (fabsf(f) < EPSILON)
        return ksx_vec3_set(0.f, 0.f, 0.f);

    // Нормализуем барицентрические координаты
    float inv_f = 1.f / f;
    float lambda0 = ksx_vec3_dot(&v2, &cross_v2_v1) * inv_f;
    float lambda1 = ksx_vec3_dot(&v0, &cross_v2_v1) * inv_f;
    float lambda2 = 1.f - lambda0 - lambda1;

	t_vector3	vec3[5];
    // Интерполяция нормали
	vec3[0] = ksx_vec3_smulti(&p_tri->p_norm1->lp, lambda0);
	vec3[1] = ksx_vec3_smulti(&p_tri->p_norm2->lp, lambda1);
	vec3[2] = ksx_vec3_smulti(&p_tri->p_norm3->lp, lambda2);
    vec3[3] = ksx_vec3_add(&vec3[0], &vec3[1]);
    vec3[4] = ksx_vec3_add(&vec3[3], &vec3[2]);



    // Нормализуем итоговую нормаль
	return ksx_vec3_unit(&vec3[4]);
}


// printf("vec3[0] [%f,%f,%f]\n", vec3[0].x, vec3[0].y, vec3[0].z);
// printf("vec3[1] [%f,%f,%f]\n", vec3[1].x, vec3[1].y, vec3[1].z);
// printf("vec3[2] [%f,%f,%f]\n", vec3[2].x, vec3[2].y, vec3[2].z);
// printf("vec3[3] [%f,%f,%f]\n", vec3[3].x, vec3[3].y, vec3[3].z);
// printf("vec3[4] [%f,%f,%f]\n", vec3[4].x, vec3[4].y, vec3[4].z);