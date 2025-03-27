/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:23:15 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/27 00:44:16 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ray.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_3D.h"
#include "ksx_vec3_math.h"
#include <stdio.h>
#include <math.h>

#ifdef BONUS

void	ksx_ray_thrd_init(t_mondata	*p_mondata, t_thrddata *p_thrddata,
			t_graphics *p_grph)
{
	int32_t	idx;

	idx = 0;
	while (idx < THREADS)
	{
		p_thrddata[idx].flags = 0;
		p_thrddata[idx].p_grph = p_grph;
		idx++;
	}
	p_mondata->p_thrddata = p_thrddata;
}

void	*ksx_ray_thrd_mon(void *p_data)
{
	t_mondata	*p_mondata;
	int32_t		idx;
	int32_t		count;

	p_mondata = (t_mondata *)p_data;
	while (1)
	{
		idx = 0;
		count = 0;
		while (idx < THREADS)
		{
			if (p_mondata->p_thrddata[idx].flags & F_TH_FINISH)
				count++;
			idx++;
		}
		if (count == THREADS)
			return (p_data);
	}
	return (p_data);
}

#endif
