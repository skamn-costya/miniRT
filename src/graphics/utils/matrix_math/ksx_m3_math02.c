/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_mmath01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:22:40 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/09 01:12:18 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include <math.h>

void	ksx_m3_identity(t_matrix3 *p_m)
{
	p_m->e_11 = 1.f;
	p_m->e_12 = 0.f;
	p_m->e_13 = 0.f;
	p_m->e_21 = 0.f;
	p_m->e_22 = 1.f;
	p_m->e_23 = 0.f;
	p_m->e_31 = 0.f;
	p_m->e_32 = 0.f;
	p_m->e_33 = 1.f;
}
