/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_rotation02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/10 12:03:25 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_m3_math.h"
#include "ksx_rotation.h"
#include <math.h>

void	ksx_rotation_tri_x(t_triangle *p_tri, float angle)
{
	ksx_rotation_x(&p_tri->p1, angle);
	ksx_rotation_x(&p_tri->p2, angle);
	ksx_rotation_x(&p_tri->p3, angle);
}

void	ksx_rotation_tri_y(t_triangle *p_tri, float angle)
{
	ksx_rotation_y(&p_tri->p1, angle);
	ksx_rotation_y(&p_tri->p2, angle);
	ksx_rotation_y(&p_tri->p3, angle);
}

void	ksx_rotation_tri_z(t_triangle *p_tri, float angle)
{
	ksx_rotation_z(&p_tri->p1, angle);
	ksx_rotation_z(&p_tri->p2, angle);
	ksx_rotation_z(&p_tri->p3, angle);
}

void	ksx_rotation_tri(t_triangle *p_tri, float angle_x,
			float angle_y, float angle_z)
{
	ksx_rotation(&p_tri->p1, angle_x, angle_y, angle_z);
	ksx_rotation(&p_tri->p2, angle_x, angle_y, angle_z);
	ksx_rotation(&p_tri->p3, angle_x, angle_y, angle_z);
}
