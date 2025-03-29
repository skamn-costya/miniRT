/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_obj_crearte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:26:20 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/29 14:29:19 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_obj_file.h"
#include "ksx_object.h"
#include "ksx_boxes.h"
#include "ksx_vec3_math.h"
#include "ksx_utils.h"
#include "libft.h"
#include "parser.h"
#include <fcntl.h>
#include <stdio.h>

void	create_of(t_list *p_list, t_object *p_object)
{
	int			i[3];
	t_fline		*p_fline;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (p_list)
	{
		p_fline = (t_fline *) p_list->content;
		if (!ft_strcmp(p_fline->words[0], OBJ_V))
			get_v_of(p_fline, p_object, &i[0]);
		if (!ft_strcmp(p_fline->words[0], OBJ_VN))
			get_vn_of(p_fline, p_object, &i[1]);
		if (!ft_strcmp(p_fline->words[0], OBJ_F))
			get_f_of(p_fline, p_object, &i[2]);
		p_list = p_list->next;
	}
}

void	ksx_obj_nrm2tri(t_object *p_object, int idx, int i[4][3], int ii)
{
	p_object->pp_tri[idx]->p_norm1 = p_object->pp_vnrm[i[0][ii] - 1];
	p_object->pp_tri[idx]->p_norm2 = p_object->pp_vnrm[i[1][ii] - 1];
	p_object->pp_tri[idx]->p_norm3 = p_object->pp_vnrm[i[2][ii] - 1];
}
