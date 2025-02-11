/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_object03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:37:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 16:27:19 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m3_math.h"
#include "ksx_basis.h"
#include "ksx_object.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

t_triangle	**ksx_obj_new_tris(uint32_t size)
{
	t_triangle	**pp_tri;
	uint32_t	idx;

	pp_tri = (t_triangle **) malloc (sizeof(t_triangle *) * (size + 1));
	if (!pp_tri)
		return ((void) printf ("Error: memory allocation failed!\n"), NULL);
	ksx_null_pointers((void **) pp_tri, size + 1);
	idx = 0;
	while (idx < size)
	{
		pp_tri[idx] = (t_triangle *) malloc (sizeof(t_triangle));
		if (!pp_tri[idx])
			return (ksx_free_pointers((void ***) &pp_tri),
				(void) printf ("Error: memory allocation failed!\n"), NULL);
		idx++;
	}
	return (pp_tri);
}
