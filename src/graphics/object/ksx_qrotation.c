/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_qrotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/19 11:47:05 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m3_math.h"
#include "ksx_object.h"
#include <math.h>

// https://www.mathworks.com/help/nav/ug/rotations-orientation-and-quaternions.html

static t_vector4	ksx_quat_multi(t_vector4 *p_q1, t_vector4 *p_q2);

void	ksx_qrotation(t_vector3 *point, float angle, t_vector3 *p_v)
{
	float		f[2];
	t_vector4	v4[4];

	if (!angle)
		return ;
	f[0] = angle * PI180;
	f[1] = sinf(f[0] * .5f);
	v4[0] = ksx_vec4_set(f[1] * p_v->x, f[1] * p_v->y, f[1] * p_v->z, cosf(f[0] * .5f));
	v4[1] = ksx_vec4_set(point->x, point->y, point->z, 0);
	v4[2] = ksx_vec4_set(-v4[0].x, -v4[0].y, -v4[0].z, v4[0].w);
	// v4[2] = ksx_vec4_set(-f[1] * p_v->x, -f[1] * p_v->y, -f[1] * p_v->z, cosf(f[0] * .5f));
	v4[3] = ksx_quat_multi(&v4[0], &v4[1]);
	v4[3] = ksx_quat_multi(&v4[3], &v4[2]);
	*point = ksx_vec3_set(v4[3].x, v4[3].y, v4[3].z);
}

static t_vector4	ksx_quat_multi(t_vector4 *p_q1, t_vector4 *p_q2)
{
	t_vector4	v4;

	v4.w = p_q1->w * p_q2->w - p_q1->x * p_q2->x - p_q1->y * p_q2->y - p_q1->z * p_q2->z;
	v4.x = p_q1->w * p_q2->x + p_q1->x * p_q2->w + p_q1->y * p_q2->z - p_q1->z * p_q2->y;
	v4.y = p_q1->w * p_q2->y - p_q1->x * p_q2->z + p_q1->y * p_q2->w + p_q1->z * p_q2->x;
	v4.z = p_q1->w * p_q2->z + p_q1->x * p_q2->y - p_q1->y * p_q2->x + p_q1->z * p_q2->w;
	return (v4);
}

void	ksx_qrotation_obj(t_object *p_object, float angle, t_vector3 v)
{
	uint32_t	idx;

	if (!angle)
		return ;
	idx = 0;
	while (idx < p_object->size_over)
	{
		ksx_qrotation(&p_object->pp_over[idx]->p_p, angle, &v);
		idx++;
	}
	// ksx_qrotation(&p_object->axis.p_ver1->p_p, angle, &v);
	// ksx_qrotation(&p_object->axis.p_ver2->p_p, angle, &v);
	// ksx_qrotation(&p_object->axis.p_ver3->p_p, angle, &v);
	idx = 0;
	while (idx < 8)
	{
		ksx_qrotation(&p_object->box_ver[idx].p_p, angle, &v);
		idx++;
	}
}
