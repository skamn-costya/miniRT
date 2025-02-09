/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_sphere02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/09 00:45:06 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Sphere: "sp", coord, d, rgb

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_sphere.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// static void	ksx_sphere_split_(t_object *p_object, float *p_radius,
// 				t_triangle **p_tris, t_vector3 *p_v);

void	ksx_sphere_split(t_object *p_object, float *p_radius)
{
	t_triangle	*p_tris[5];
	uint32_t	idx[2];
	t_vector3	v[3];

	idx[0] = 0;
	idx[1] = p_object->size_otri;
	while (idx[0] < idx[1])
	{
		p_tris[1] = (t_triangle *) malloc (sizeof(t_triangle));
		p_tris[2] = (t_triangle *) malloc (sizeof(t_triangle));
		p_tris[3] = (t_triangle *) malloc (sizeof(t_triangle));
		p_tris[4] = (t_triangle *) malloc (sizeof(t_triangle));
		if (!p_tris[1] || !p_tris[2] || !p_tris[3] || !p_tris[4])
		{
			printf("Error: %s:%d in func: %s\n", __FILE__, __LINE__, __func__);
			return ;
		}
		p_tris[0] = p_object->pp_otri[idx[0]];
		v[0] = ksx_mid_point(&p_tris[0]->p1, &p_tris[0]->p2);
		v[1] = ksx_mid_point(&p_tris[0]->p2, &p_tris[0]->p3);
		v[2] = ksx_mid_point(&p_tris[0]->p3, &p_tris[0]->p1);

		ksx_vec3_resize(&v[0], *p_radius);
		ksx_vec3_resize(&v[1], *p_radius);
		ksx_vec3_resize(&v[2], *p_radius);
		p_tris[1]->p1 = p_tris[0]->p1;
		p_tris[1]->p2 = v[0];
		p_tris[1]->p3 = v[2];
		p_tris[2]->p1 = v[0];
		p_tris[2]->p2 = p_tris[0]->p2;
		p_tris[2]->p3 = v[1];
		p_tris[3]->p1 = v[1];
		p_tris[3]->p2 = p_tris[0]->p3;
		p_tris[3]->p3 = v[2];
		p_tris[4]->p1 = v[0];
		p_tris[4]->p2 = v[1];
		p_tris[4]->p3 = v[2];
		ksx_tri2obj (p_tris[1], p_object);
		ksx_tri2obj (p_tris[2], p_object);
		ksx_tri2obj (p_tris[3], p_object);
		ksx_tri2obj (p_tris[4], p_object);
		// ksx_sphere_split_(p_object, p_radius, p_tris, v);
		idx[0]++;
	}
}

// static void	ksx_sphere_split_(t_object *p_object, float *p_radius,
// 				t_triangle **p_tris, t_vector3 *p_v)
// {
// 	ksx_vec3_resize(&p_v[0], *p_radius);
// 	ksx_vec3_resize(&p_v[1], *p_radius);
// 	ksx_vec3_resize(&p_v[2], *p_radius);
// 	p_tris[1]->c_p1 = p_tris[0]->c_p1;
// 	p_tris[1]->c_p2 = p_v[0];
// 	p_tris[1]->c_p3 = p_v[2];
// 	p_tris[2]->c_p1 = p_v[0];
// 	p_tris[2]->c_p2 = p_tris[0]->c_p2;
// 	p_tris[2]->c_p3 = p_v[1];
// 	p_tris[3]->c_p1 = p_v[1];
// 	p_tris[3]->c_p2 = p_tris[0]->c_p3;
// 	p_tris[3]->c_p3 = p_v[2];
// 	p_tris[4]->c_p1 = p_v[0];
// 	p_tris[4]->c_p2 = p_v[1];
// 	p_tris[4]->c_p3 = p_v[2];
// 	ksx_tri2obj (p_tris[1], p_object);
// 	ksx_tri2obj (p_tris[2], p_object);
// 	ksx_tri2obj (p_tris[3], p_object);
// 	ksx_tri2obj (p_tris[4], p_object);
// }
