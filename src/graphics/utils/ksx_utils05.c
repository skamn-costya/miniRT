/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils05.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/11 13:10:32 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	ksx_tri_set_vertexes(t_triangle *p_tri, t_vertex *p_ver1,
		t_vertex *p_ver2, t_vertex *p_ver3)
{
	p_tri->p_ver1 = p_ver1;
	p_tri->p_ver2 = p_ver2;
	p_tri->p_ver3 = p_ver3;
}

void	ksx_tri_set_norms(t_triangle *p_tri, t_vector3 *p_n1,
		t_vector3 *p_n2, t_vector3 *p_n3)
{
	p_tri->norm1 = *p_n1;
	p_tri->norm2 = *p_n2;
	p_tri->norm3 = *p_n3;
}
