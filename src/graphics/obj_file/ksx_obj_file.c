/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_obj_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:26:20 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 22:55:09 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_obj_file.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_boxes.h"
#include "libft.h"
#include "parser.h"
#include <fcntl.h>
#include <stdio.h>

void	read_of(t_world *p_world, char *filename)
{
	int			fd;
	t_list		*p_list[2];
	t_object	*p_object;

	fd = open (filename, O_RDONLY);
	if (fd < 0)
		return ((void) printf("Warning: \"%s\" couldn't be open.\n", filename));
	p_list[0] = create_line_list(fd);
	close(fd);
	p_list[1] = p_list[0];
	p_object = ksx_create_object(NULL);
	p_object->color.mlx_color = 0xffffffff;
	ksx_color_unit_fraction(&p_object->color);
	create_of(p_list[1], p_object);
	ft_lstclear(&p_list[0], &free_t_fline);
	ksx_box_create(p_object);
	ksx_obj_tris2box(p_object);
	ksx_obj_transform(p_object);
	ksx_obj2world(p_object, p_world);
	ksx_obj_set_obj(p_object);
}

t_vertex	*get_v_of(t_fline *p_fline, t_object *p_object, int *p_idx)
{
	if (!p_fline->words[1] || !p_fline->words[2] || !p_fline->words[3])
		return (printf("Wrong float number.\n"), NULL);
	ksx_obj_add_vers(p_object, 1);
	p_object->pp_vrtx[*p_idx]->op.x = ft_atof(p_fline->words[1]);
	p_object->pp_vrtx[*p_idx]->op.y = ft_atof(p_fline->words[2]);
	p_object->pp_vrtx[*p_idx]->op.z = ft_atof(p_fline->words[3]);
	(*p_idx)++;
	return (p_object->pp_vrtx[*p_idx]);
}

static void	get_f_split(char *p_str, int *p_i);

t_triangle	*get_f_of(t_fline *p_fline, t_object *p_object, int *p_idx)
{
	int	i[4][3];

	get_f_split(p_fline->words[1], i[0]);
	get_f_split(p_fline->words[2], i[1]);
	get_f_split(p_fline->words[3], i[2]);
	if (i[0][0] < 0 || i[1][0] < 0 || i[2][0] < 0)
		return (NULL);
	if (!p_object->pp_tri)
		p_object->pp_tri = ksx_obj_new_tris(1);
	else
		ksx_obj_add_tris(p_object, 1);
	p_object->pp_tri[*p_idx]->p_ver1 = p_object->pp_vrtx[i[0][0] - 1];
	p_object->pp_tri[*p_idx]->p_ver2 = p_object->pp_vrtx[i[1][0] - 1];
	p_object->pp_tri[*p_idx]->p_ver3 = p_object->pp_vrtx[i[2][0] - 1];
	if (i[0][2] != -1 && i[1][2] != -1 && i[2][2] != -1)
		ksx_obj_nrm2tri(p_object, *p_idx, i, 2);
	else if (p_object->pp_vnrm)
		ksx_obj_nrm2tri(p_object, *p_idx, i, 0);
	(*p_idx)++;
	p_object->size_tri = *p_idx;
	return (p_object->pp_tri[*p_idx - 1]);
}

static void	get_f_split(char *p_str, int *p_i)
{
	char	**pp_str;

	p_i[0] = -1;
	p_i[1] = -1;
	p_i[2] = -1;
	if (!p_str)
		return ;
	pp_str = ft_split(p_str, '/');
	if (!is_i_number(pp_str[0]))
		return (ft_pparrclear((void **)pp_str));
	p_i[0] = ft_atoi(pp_str[0]);
	if (pp_str[1] && is_i_number(pp_str[1]))
		p_i[1] = ft_atoi(pp_str[1]);
	if (pp_str[1] && pp_str[2] && is_i_number(pp_str[2]))
		p_i[2] = ft_atoi(pp_str[2]);
	return (ft_pparrclear((void **)pp_str));
}

t_vertex	*get_vn_of(t_fline *p_fline, t_object *p_object, int *p_idx)
{
	if (!p_fline->words[1] || !p_fline->words[2] || !p_fline->words[3])
		return (printf("Wrong float number.\n"), NULL);
	ksx_obj_add_vnrm(p_object, 1);
	p_object->pp_vnrm[*p_idx]->op.x = ft_atof(p_fline->words[1]);
	p_object->pp_vnrm[*p_idx]->op.y = ft_atof(p_fline->words[2]);
	p_object->pp_vnrm[*p_idx]->op.z = ft_atof(p_fline->words[3]);
	(*p_idx)++;
	return (p_object->pp_vnrm[*p_idx]);
}
