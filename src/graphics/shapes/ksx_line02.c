/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_line02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:52:47 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/03 14:48:39 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>

t_color	ksx_get_color(t_pixel *p_p, t_pixel *p_p1, t_pixel *p_p2)
{
	t_color	color[3];
	float	f;

	color[0] = p_p1->color;
	color[1] = p_p2->color;
	f = ksx_fraction (p_p, p_p1, p_p2);
	color[2].r = color[0].r + (color[1].r - color[0].r) * f;
	color[2].g = color[0].g + (color[1].g - color[0].g) * f;
	color[2].b = color[0].b + (color[1].b - color[0].b) * f;
	color[2].a = color[0].a + (color[1].a - color[0].a) * f;
	return (color[2]);
}
