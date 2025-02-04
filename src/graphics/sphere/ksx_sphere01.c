/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_sphere01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/04 14:20:47 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_sphere.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void			ksx_init_sphere(t_obj *p_obj,
						t_vector3 center, float radius);
static void			ksx_init_sphere_1(t_obj *p_obj, t_vector3 points[]);
static void			ksx_init_sphere_2(t_obj *p_obj, t_vector3 center);
static t_triangle	**ksx_init_sphere_tri(t_obj *p_obj);

t_obj	*ksx_create_sphere(t_vector3 center, uint32_t diameter, t_color color)
{
	t_obj	*p_obj;
	float	radius;
	// uint32_t	gen;

	radius = diameter * .5f;
	p_obj = (t_obj *) malloc (sizeof(t_obj));
	if (!p_obj)
		return (printf("Error: memory allocation failed!\n"), NULL);
	if (!ksx_init_sphere_tri(p_obj))
		return (NULL);
	ksx_init_sphere(p_obj, center, radius);
	(void) color;
	return (p_obj);
}

static void	ksx_init_sphere(t_obj *p_obj, t_vector3 center, float radius)
{
	t_vector3	points[6];

	points[0].x = radius;
	points[0].y = 0;
	points[0].z = 0;
	points[1].x = 0;
	points[1].y = radius;
	points[1].z = 0;
	points[2].x = 0;
	points[2].y = 0;
	points[2].z = radius;
	points[3].x = -radius;
	points[4].y = 0;
	points[5].z = 0;
	points[4].x = 0;
	points[4].y = -radius;
	points[4].z = 0;
	points[5].x = 0;
	points[5].y = 0;
	points[5].z = -radius;
	ksx_init_sphere_1(p_obj, points);
	ksx_init_sphere_2(p_obj, center);
}

static void	ksx_init_sphere_1(t_obj *p_obj, t_vector3 points[])
{
	p_obj->pp_otri[0]->p1 = points[0];
	p_obj->pp_otri[0]->p2 = points[1];
	p_obj->pp_otri[0]->p3 = points[2];
	p_obj->pp_otri[1]->p1 = points[0];
	p_obj->pp_otri[1]->p2 = points[2];
	p_obj->pp_otri[1]->p3 = points[4];
	p_obj->pp_otri[2]->p1 = points[0];
	p_obj->pp_otri[2]->p2 = points[4];
	p_obj->pp_otri[2]->p3 = points[5];
	p_obj->pp_otri[3]->p1 = points[0];
	p_obj->pp_otri[3]->p2 = points[5];
	p_obj->pp_otri[3]->p3 = points[1];
	p_obj->pp_otri[4]->p1 = points[3];
	p_obj->pp_otri[4]->p2 = points[1];
	p_obj->pp_otri[4]->p3 = points[2];
	p_obj->pp_otri[5]->p1 = points[3];
	p_obj->pp_otri[5]->p2 = points[2];
	p_obj->pp_otri[5]->p3 = points[4];
	p_obj->pp_otri[6]->p1 = points[3];
	p_obj->pp_otri[6]->p2 = points[4];
	p_obj->pp_otri[6]->p3 = points[5];
	p_obj->pp_otri[7]->p1 = points[3];
	p_obj->pp_otri[7]->p2 = points[5];
	p_obj->pp_otri[7]->p3 = points[1];
}

static void	ksx_init_sphere_2(t_obj *p_obj, t_vector3 center)
{
	
	ksx_translate_tri(p_obj->pp_otri[0], center);
	ksx_translate_tri(p_obj->pp_otri[1], center);
	ksx_translate_tri(p_obj->pp_otri[2], center);
	ksx_translate_tri(p_obj->pp_otri[3], center);
	ksx_translate_tri(p_obj->pp_otri[4], center);
	ksx_translate_tri(p_obj->pp_otri[5], center);
	ksx_translate_tri(p_obj->pp_otri[6], center);
	ksx_translate_tri(p_obj->pp_otri[7], center);
}

static t_triangle	**ksx_init_sphere_tri(t_obj *p_obj)
{
	uint32_t	idx;
	t_triangle	*p_tri;
	t_triangle	**pp_tri;

	p_obj->last_gen = 1;
	p_obj->pp_otri = NULL;
	p_obj->size_otri = 0;
	idx = 0;
	while (idx < 8)
	{
		p_tri = (t_triangle *) malloc (sizeof(t_triangle));
		if (!p_tri)
			return (printf("Error: memory allocation failed!\n"), NULL);
		p_tri->generation = 1;
		pp_tri = ksx_tri2obj(p_tri, p_obj);
		idx++;
	}
	return (pp_tri);
}
