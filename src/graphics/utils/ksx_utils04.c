/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils04.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/19 22:49:02 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "MLX42.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float	ksx_fraction(const t_pixel *p_p, const t_pixel *p_p1,
	const t_pixel *p_p2)
{
	int		dx;
	int		dy;
	float	result;

	dx = (p_p2->x - p_p1->x);
	dy = (p_p2->y - p_p1->y);
	if (ksx_abs(dx) > ksx_abs(dy))
	{
		if (p_p1->x != p_p2->x)
			result = (float)(p_p->x - p_p1->x) / dx;
		else
			result = 0;
	}
	else
	{
		if (p_p1->y != p_p2->y)
			result = (float)(p_p->y - p_p1->y) / dy;
		else
			result = 0;
	}
	return (result);
}

int32_t	ksx_abs(const int32_t num)
{
	int32_t	result;

	result = num;
	if (num < 0)
		result *= -1;
	return (result);
}

void	ksx_color_unit_fraction(t_color *p_color)
{
	p_color->ur = p_color->r / 255.f;
	p_color->ug = p_color->g / 255.f;
	p_color->ub = p_color->b / 255.f;
}

void	ksx_time_print()
{
	// ksx_time_print - Remove before evaluation
	time_t		timer;
    char		buffer[26];
    struct tm*	tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(buffer);
}
