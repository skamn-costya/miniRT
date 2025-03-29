/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_boxes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:18:43 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/29 13:12:19 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_boxes.h"
#include "ksx_triangle.h"
#include "ksx_utils.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	ksx_box_triangles_1(t_box *p_box);
static void	ksx_box_triangles_2(t_box *p_box);

void	ksx_box_triangles(t_box *p_box, t_object *p_object)
{
	uint32_t	idx;

	ksx_box_triangles_1(p_box);
	ksx_box_triangles_2(p_box);
	idx = 0;
	while (idx < 12)
	{
		p_box->tris[idx].p_object = (void *)p_object;
		idx++;
	}
}

static void	ksx_box_triangles_1(t_box *p_box)
{
	ksx_tri_set_vertexes(&p_box->tris[0], &p_box->ver[0],
		&p_box->ver[1], &p_box->ver[3]);
	ksx_tri_set_vertexes(&p_box->tris[1], &p_box->ver[1],
		&p_box->ver[2], &p_box->ver[3]);
	ksx_tri_set_vertexes(&p_box->tris[2], &p_box->ver[2],
		&p_box->ver[3], &p_box->ver[6]);
	ksx_tri_set_vertexes(&p_box->tris[3], &p_box->ver[3],
		&p_box->ver[6], &p_box->ver[7]);
	ksx_tri_set_vertexes(&p_box->tris[4], &p_box->ver[0],
		&p_box->ver[3], &p_box->ver[4]);
	ksx_tri_set_vertexes(&p_box->tris[5], &p_box->ver[3],
		&p_box->ver[4], &p_box->ver[7]);
	p_box->tris[0].p_norm1 = NULL;
	p_box->tris[1].p_norm1 = NULL;
	p_box->tris[2].p_norm1 = NULL;
	p_box->tris[3].p_norm1 = NULL;
	p_box->tris[4].p_norm1 = NULL;
	p_box->tris[5].p_norm1 = NULL;
}

static void	ksx_box_triangles_2(t_box *p_box)
{
	ksx_tri_set_vertexes(&p_box->tris[6], &p_box->ver[0],
		&p_box->ver[1], &p_box->ver[4]);
	ksx_tri_set_vertexes(&p_box->tris[7], &p_box->ver[1],
		&p_box->ver[4], &p_box->ver[5]);
	ksx_tri_set_vertexes(&p_box->tris[8], &p_box->ver[1],
		&p_box->ver[5], &p_box->ver[6]);
	ksx_tri_set_vertexes(&p_box->tris[9], &p_box->ver[1],
		&p_box->ver[2], &p_box->ver[6]);
	ksx_tri_set_vertexes(&p_box->tris[10], &p_box->ver[4],
		&p_box->ver[5], &p_box->ver[6]);
	ksx_tri_set_vertexes(&p_box->tris[11], &p_box->ver[4],
		&p_box->ver[6], &p_box->ver[7]);
	p_box->tris[6].p_norm1 = NULL;
	p_box->tris[7].p_norm1 = NULL;
	p_box->tris[8].p_norm1 = NULL;
	p_box->tris[9].p_norm1 = NULL;
	p_box->tris[10].p_norm1 = NULL;
	p_box->tris[11].p_norm1 = NULL;
}

t_box	*ksx_box_add_new(t_box ***ppp_box)
{
	t_box		**pp_box;
	uint32_t	idx[2];

	idx[0] = ft_pparrsize((void **) *ppp_box);
	pp_box = (t_box **) malloc (sizeof(t_box *) * (idx[0] + 2));
	if (!pp_box)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	ksx_null_pointers((void **) pp_box, idx[0] + 2);
	idx[1] = -1;
	while (++idx[1] < idx[0])
		pp_box[idx[1]] = (*ppp_box)[idx[1]];
	pp_box[idx[1]] = (t_box *) malloc (sizeof(t_box));
	if (!pp_box[idx[1]])
		return (ksx_free_pointers((void ***) &pp_box),
			ksx_error("memory allocation failure", __FILE__, __LINE__),
			NULL);
	free (*ppp_box);
	*ppp_box = pp_box;
	return (pp_box[idx[1]]);
}

t_box	*ksx_box_add(t_box ***ppp_box, t_box *p_box)
{
	t_box		**pp_box;
	uint32_t	idx[2];

	idx[0] = ft_pparrsize((void **) *ppp_box);
	pp_box = (t_box **) malloc (sizeof(t_box *) * (idx[0] + 2));
	if (!pp_box)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	ksx_null_pointers((void **) pp_box, idx[0] + 2);
	idx[1] = -1;
	while (++idx[1] < idx[0])
		pp_box[idx[1]] = (*ppp_box)[idx[1]];
	pp_box[idx[1]] = p_box;
	free (*ppp_box);
	*ppp_box = pp_box;
	return (pp_box[idx[1]]);
}
