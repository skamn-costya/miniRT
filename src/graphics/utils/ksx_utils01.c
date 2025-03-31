/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 23:06:35 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	ksx_print_vector(t_vector3 *p_vec)
{
	printf("vector3: [%f, %f, %f]\n", p_vec->x, p_vec->y, p_vec->z);
}

void	ksx_print_vertex(t_vertex *p_ver, int32_t idx)
{
	printf("vertex: [%f, %f, %f]\n", p_ver->olwc[idx].x,
		p_ver->olwc[idx].y, p_ver->olwc[idx].z);
}

void	ksx_print_tri(t_triangle *p_tri, int32_t idx)
{
	printf("triangle:\n");
	ksx_print_vertex(p_tri->p_ver1, idx);
	ksx_print_vertex(p_tri->p_ver2, idx);
	ksx_print_vertex(p_tri->p_ver3, idx);
	if (p_tri->p_norm1)
	{
		printf("morm:\n");
		ksx_print_vertex(p_tri->p_norm1, idx);
		ksx_print_vertex(p_tri->p_norm2, idx);
		ksx_print_vertex(p_tri->p_norm3, idx);
	}
}

void	ksx_print_basis(t_basis *p_basis)
{
	printf("basis:\n");
	printf("o: ");
	ksx_print_vector(&p_basis->o);
	printf("u: ");
	ksx_print_vector(&p_basis->i);
	printf("j: ");
	ksx_print_vector(&p_basis->j);
	printf("k: ");
	ksx_print_vector(&p_basis->k);
	printf("w_o: ");
	ksx_print_vector(&p_basis->w_o);
}
