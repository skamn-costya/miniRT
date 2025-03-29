/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:10:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/29 19:26:32 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "ksx_utils.h"
#include "math.h"
#include "ray_texture.h"
#include <stdio.h>
#include "bvh.h"

void	ray_p2boxes(t_world *p_world, t_ray *p_ray)
{
	int32_t	idx[3];

	idx[0] = -1;
	while (++idx[0] < p_world->size_obj)
		intersect_bvh(p_ray, 0, p_world->pp_obj[idx[0]]->bvh, p_world);
}

void	ray_p2tri(t_triangle *p_tri, t_ray *p_ray)
{
	t_vector3	v3[5];
	float		f[5];

	v3[0] = ksx_vec3_sub(&p_tri->p_ver2->cp, &p_tri->p_ver1->cp);
	v3[1] = ksx_vec3_sub(&p_tri->p_ver3->cp, &p_tri->p_ver1->cp);
	v3[2] = ksx_vec3_cross(&p_ray->direction, &v3[1]);
	f[0] = ksx_vec3_dot(&v3[0], &v3[2]);
	if (fabsf(f[0]) < EPSILON)
		return ;
	f[1] = 1.f / f[0];
	v3[3] = ksx_vec3_sub(&p_ray->origin, &p_tri->p_ver1->cp);
	f[2] = ksx_vec3_dot(&v3[3], &v3[2]) * f[1];
	if (f[2] < -BIAS || f[2] > 1.f + BIAS)
		return ;
	v3[4] = ksx_vec3_cross(&v3[3], &v3[0]);
	f[3] = ksx_vec3_dot(&p_ray->direction, &v3[4]) * f[1];
	if (f[3] < -BIAS || f[2] + f[3] > 1.f + BIAS)
		return ;
	f[4] = ksx_vec3_dot(&v3[1], &v3[4]) * f[1];
	if (f[4] > EPSILON && p_ray->length > f[4])
		p_ray->length = f[4];
}

t_vector3	triangle_normal_barycentric(t_triangle *p_tri, t_ray *p_ray)
{
	t_vector3	vec3[2];
	t_vector3	normal;

	vec3[0] = ksx_vec3_smulti(&p_tri->p_norm1->cp,
			p_ray->brcntrc.lambda1);
	vec3[1] = ksx_vec3_smulti(&p_tri->p_norm2->cp,
			p_ray->brcntrc.lambda2);
	vec3[0] = ksx_vec3_add(&vec3[0], &vec3[1]);
	vec3[1] = ksx_vec3_smulti(&p_tri->p_norm3->cp,
			p_ray->brcntrc.lambda3);
	normal = ksx_vec3_add(&vec3[0], &vec3[1]);
	return (ksx_vec3_unit(&normal));
}

void	rey_get_barycentric(t_vector3 *p_point,
		t_triangle *p_tri, t_ray *p_ray)
{
	t_vector3	edge[3];
	t_vector3	normal;
	float		f;
	t_vector3	vec3[2];

	edge[0] = ksx_vec3_sub(&p_tri->p_ver2->cp, &p_tri->p_ver1->cp);
	edge[1] = ksx_vec3_sub(&p_tri->p_ver3->cp, &p_tri->p_ver1->cp);
	edge[2] = ksx_vec3_sub(p_point, &p_tri->p_ver1->cp);
	normal = ksx_vec3_cross(&edge[0], &edge[1]);
	f = 1.f / ksx_vec3_mag(&normal);
	vec3[0] = ksx_vec3_cross(&edge[2], &edge[0]);
	vec3[1] = ksx_vec3_cross(&edge[2], &edge[1]);
	p_ray->brcntrc.lambda3 = fmaxf(0.f, ksx_vec3_mag(&vec3[0]) * f);
	p_ray->brcntrc.lambda2 = fmaxf(0.f, ksx_vec3_mag(&vec3[1]) * f);
	p_ray->brcntrc.lambda1 = 1.f - p_ray->brcntrc.lambda2
		- p_ray->brcntrc.lambda3;
	p_ray->point.op.x = p_tri->p_ver1->op.x * p_ray->brcntrc.lambda1
		+ p_tri->p_ver2->op.x * p_ray->brcntrc.lambda2
		+ p_tri->p_ver3->op.x * p_ray->brcntrc.lambda3;
	p_ray->point.op.y = p_tri->p_ver1->op.y * p_ray->brcntrc.lambda1
		+ p_tri->p_ver2->op.y * p_ray->brcntrc.lambda2
		+ p_tri->p_ver3->op.y * p_ray->brcntrc.lambda3;
	p_ray->point.op.z = p_tri->p_ver1->op.z * p_ray->brcntrc.lambda1
		+ p_tri->p_ver2->op.z * p_ray->brcntrc.lambda2
		+ p_tri->p_ver3->op.z * p_ray->brcntrc.lambda3;
}

// t_vector3	triangle_normal_euler(t_vector3 *p_point, t_triangle *p_tri)
// {
// 	t_vector3	vec3[4];
// 	float		f;
// 	float		lambda[3];

// 	lambda[0] = ksx_vec3_dist(p_point, &p_tri->p_ver1->cp);
// 	lambda[1] = ksx_vec3_dist(p_point, &p_tri->p_ver2->cp);
// 	lambda[2] = ksx_vec3_dist(p_point, &p_tri->p_ver3->cp);
// 	f = 1 / (lambda[0] + lambda[1] + lambda[2]);
// 	lambda[0] *= f;
// 	lambda[1] *= f;
// 	lambda[2] *= f;
// 	lambda[0] = 1/lambda[0];
// 	lambda[1] = 1/lambda[1];
// 	lambda[2] = 1/lambda[2];
// 	vec3[0] = ksx_vec3_smulti(&p_tri->p_norm1->wp, lambda[0]);
// 	vec3[1] = ksx_vec3_smulti(&p_tri->p_norm2->wp, lambda[1]);
// 	vec3[2] = ksx_vec3_smulti(&p_tri->p_norm3->wp, lambda[2]);
// 	vec3[3] = ksx_vec3_add(&vec3[0], &vec3[1]);
// 	vec3[3] = ksx_vec3_add(&vec3[3], &vec3[2]);
// 	return (ksx_vec3_unit(&vec3[3]));
// }
