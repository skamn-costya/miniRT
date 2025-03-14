/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils04.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/14 14:31:05 by ksorokol         ###   ########.fr       */
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

/**
 * @brief returns coordinates of the midpoint (between p1 and p2)
 * 
 * @param p_p1 a pointer to the first point
 * @param p_p2 a pointer to the second point
 * @param p point
 */
t_vector3	ksx_mid_point(const t_vector3 *p_p1, const t_vector3 *p_p2)
{
	t_vector3	result;

	result.x = (p_p1->x + p_p2->x) * .5f;
	result.y = (p_p1->y + p_p2->y) * .5f;
	result.z = (p_p1->z + p_p2->z) * .5f;
	return (result);
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
