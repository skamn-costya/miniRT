/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/31 12:39:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "parser.h"
#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_list	*p_obj_list;
	// t_vars vars;

	t_vector	v[3];
	t_point		p;

	v[0].dir.x = 2;
	v[0].dir.y = 0;
	v[0].dir.z = 2;
	v[1].dir.x = 0;
	v[1].dir.y = 1;
	v[1].dir.z = 0;
	v[2].dir.x = 0;
	v[2].dir.y = 0;
	v[2].dir.z = 0;
	p.x = 2;
	p.y = 2;
	p.z = 2;
	vector_resize(v[0], 4, &v[1]);
	get_cross_product(v[0], v[1], &v[2]);
	is_point_on_ray(p, v[0]);

	t_matrix3 m;
	m.e_11 = 0;
	m.e_12 = 12;
	m.e_13 = 13;
	// m.e[M_14] = 14;
	m.e_21 = 21;
	m.e_22 = 22;
	m.e_23 = 23;
	// m.e[M_24] = 24;
	m.e_31 = 31;
	m.e_32 = 32;
	m.e_33 = 33;
	// m.e[M_34] = 34;
	// m.e[M_41] = 41;
	// m.e[M_42] = 42;
	// m.e[M_43] = 43;
	// m.e[M_44] = 44;
	float f = determinant3 (m);
	(void) f;

	ksx_init ();

	if (argc !=2)
		return (printf("Warning: Incorrect number of arguments.\n"), EXIT_SUCCESS);
	p_obj_list = check_file(argv[1]);
	if (!p_obj_list)
		return (printf("Warning: Incorrect the scene description file.\n"), EXIT_SUCCESS);
	ft_lstclear(&p_obj_list, &free_t_object);
	// init(&vars);
	return (EXIT_SUCCESS);
}
