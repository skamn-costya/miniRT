/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_sphere01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:13:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 16:50:21 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_sphere.h"
#include <math.h>

static t_tris	*init_sphere(t_tris *p_tris, uint32_t radius);
static t_tris	*init_sphere_(t_tris *p_tris, t_point points[]);


t_tris	*create_sphere(t_point center, uint32_t diameter, t_color color)
{
	uint32_t	radius;
	uint32_t	gen;
	t_tris		*p_tris;

	radius = diameter * 0.5f;
	p_tris = (t_tris *) malloc (sizeof(t_tris));
	if (!p_tris)
		return(printf("Error: memory allocation failed!\n"), NULL);
	p_tris->p = NULL;
	p_tris->size = 0;
	init_sphere(p_tris, radius);
}

static t_tris	*init_sphere(t_tris *p_tris, uint32_t radius)
{
	t_point	points[6];

	points[0].x = radius;
	points[0].y = 0;
	points[0].z = 0;
	points[1].x = 0;
	points[1].y = radius;
	points[1].z = 0;
	points[2].x = 0;
	points[2].y = 0;
	points[2].z = radius;
	points[3].x = - radius;
	points[4].y = 0;
	points[5].z = 0;
	points[4].x = 0;
	points[4].y = - radius;
	points[4].z = 0;
	points[5].x = 0;
	points[5].y = 0;
	points[5].z = - radius;
	add_triangels(p_tris, 8);
	init_sphere_1(p_tris, points);
	add_triangels(p_tris, 8 * 4);
}

static t_tris	*init_sphere_(t_tris *p_tris, t_point points[])
{
	p_tris->p[0].p1 = points[0];
	p_tris->p[0].p2 = points[1];
	p_tris->p[0].p3 = points[2];
	p_tris->p[1].p1 = points[0];
	p_tris->p[1].p2 = points[2];
	p_tris->p[1].p3 = points[4];
	p_tris->p[2].p1 = points[0];
	p_tris->p[2].p2 = points[4];
	p_tris->p[2].p3 = points[5];
	p_tris->p[3].p1 = points[0];
	p_tris->p[3].p2 = points[5];
	p_tris->p[3].p3 = points[1];
	p_tris->p[4].p1 = points[3];
	p_tris->p[4].p2 = points[1];
	p_tris->p[4].p3 = points[2];
	p_tris->p[5].p1 = points[3];
	p_tris->p[5].p2 = points[2];
	p_tris->p[5].p3 = points[4];
	p_tris->p[6].p1 = points[3];
	p_tris->p[6].p2 = points[4];
	p_tris->p[6].p3 = points[5];
	p_tris->p[7].p1 = points[3];
	p_tris->p[7].p2 = points[5];
	p_tris->p[7].p3 = points[1];
}
