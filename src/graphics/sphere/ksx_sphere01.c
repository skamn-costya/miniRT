/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_sphere01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/09 11:41:12 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Sphere: "sp", coord, d, rgb

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_sphere.h"
#include "ksx_sphere.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void			ksx_init_sphere(t_object *p_object, float radius);
static void			ksx_init_sphere_1(t_object *p_object, t_vector3 points[]);
static void			ksx_init_sphere_2(t_object *p_object, t_color color);
static t_triangle	**ksx_init_sphere_tri(t_object *p_object);

t_object	*ksx_create_sphere(t_vector3 center,
			uint32_t diameter, t_color color)
{
	t_object	*p_object;

	p_object = ksx_create_object(center);
	if (!p_object)
		return (NULL);
	if (!ksx_init_sphere_tri(p_object))
		return (NULL);
	p_object->radius = diameter * .5f;
	ksx_init_sphere(p_object, diameter * .5f);
	ksx_init_sphere_2(p_object, color);
	ksx_sphere_split (p_object);	// 32
	ksx_sphere_split (p_object);	// 128
	ksx_sphere_split (p_object);	// 512
	ksx_sphere_split (p_object);	// 2048
	ksx_sphere_split (p_object);	// 8192
	// ksx_sphere_split (p_object);	// 32768
	// ksx_sphere_split (p_object);	// 131072
	return (p_object);
}

static void	ksx_init_sphere(t_object *p_object, float radius)
{
	t_vector3	points[6];

	points[0].x = 0;
	points[0].y = radius;
	points[0].z = 0;
	points[1].x = radius;
	points[1].y = 0;
	points[1].z = 0;
	points[2].x = 0;
	points[2].y = 0;
	points[2].z = radius;
	points[3].x = 0;
	points[3].y = -radius;
	points[3].z = 0;
	points[4].x = -radius;
	points[4].y = 0;
	points[4].z = 0;
	points[5].x = 0;
	points[5].y = 0;
	points[5].z = -radius;
	ksx_init_sphere_1(p_object, points);
}

static void	ksx_init_sphere_1(t_object *p_object, t_vector3 points[])
{
	p_object->pp_otri[0]->p1 = points[0];
	p_object->pp_otri[0]->p2 = points[1];
	p_object->pp_otri[0]->p3 = points[2];
	p_object->pp_otri[1]->p1 = points[0];
	p_object->pp_otri[1]->p2 = points[2];
	p_object->pp_otri[1]->p3 = points[4];
	p_object->pp_otri[2]->p1 = points[0];
	p_object->pp_otri[2]->p2 = points[4];
	p_object->pp_otri[2]->p3 = points[5];
	p_object->pp_otri[3]->p1 = points[0];
	p_object->pp_otri[3]->p2 = points[5];
	p_object->pp_otri[3]->p3 = points[1];
	p_object->pp_otri[4]->p1 = points[3];
	p_object->pp_otri[4]->p2 = points[1];
	p_object->pp_otri[4]->p3 = points[2];
	p_object->pp_otri[5]->p1 = points[3];
	p_object->pp_otri[5]->p2 = points[2];
	p_object->pp_otri[5]->p3 = points[4];
	p_object->pp_otri[6]->p1 = points[3];
	p_object->pp_otri[6]->p2 = points[4];
	p_object->pp_otri[6]->p3 = points[5];
	p_object->pp_otri[7]->p1 = points[3];
	p_object->pp_otri[7]->p2 = points[5];
	p_object->pp_otri[7]->p3 = points[1];
}

static void	ksx_init_sphere_2(t_object *p_object, t_color color)
{
	p_object->pp_otri[0]->color = color;
	p_object->pp_otri[1]->color = color;
	p_object->pp_otri[2]->color = color;
	p_object->pp_otri[3]->color = color;
	p_object->pp_otri[4]->color = color;
	p_object->pp_otri[5]->color = color;
	p_object->pp_otri[6]->color = color;
	p_object->pp_otri[7]->color = color;
}

static t_triangle	**ksx_init_sphere_tri(t_object *p_object)
{
	uint32_t	idx;
	t_triangle	*p_tri;
	t_triangle	**pp_tri;

	idx = 0;
	while (idx < 8)
	{
		p_tri = (t_triangle *) malloc (sizeof(t_triangle));
		if (!p_tri)
			return (printf("Error: memory allocation failed!\n"), NULL);
		p_tri->generation = 1;
		pp_tri = ksx_tri2obj(p_tri, p_object);
		idx++;
	}
	p_object->last_gen = 1;
	return (pp_tri);
}
