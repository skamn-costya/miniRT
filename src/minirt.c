/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/29 18:19:14 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <stdlib.h>
#include "minirt.h"
#include "parser.h"
#include "libft.h"

int	main(int argc, char *argv[])
{
	t_list	*p_obj_list;
	// t_vars vars;

	t_vector	v[3];

	v[0].xyz[X] = 1;
	v[0].xyz[Y] = 1;
	v[0].xyz[Z] = 1;
	v[1].xyz[X] = -1;
	v[1].xyz[Y] = 1;
	v[1].xyz[Z] = 1;
	v[2].xyz[X] = 0;
	v[2].xyz[Y] = 0;
	v[2].xyz[Z] = 0;
	get_cross_product(v[0], v[1], v[2]);

	t_matrix_f3 m;
	m.e[M_11] = 0;
	m.e[M_12] = 12;
	m.e[M_13] = 13;
	// m.e[M_14] = 14;
	m.e[M_21] = 21;
	m.e[M_22] = 22;
	m.e[M_23] = 23;
	// m.e[M_24] = 24;
	m.e[M_31] = 31;
	m.e[M_32] = 32;
	m.e[M_33] = 33;
	// m.e[M_34] = 34;
	// m.e[M_41] = 41;
	// m.e[M_42] = 42;
	// m.e[M_43] = 43;
	// m.e[M_44] = 44;
	float f = determinant3 (m);
	(void) f;

	if (argc !=2)
		return (printf("Warning: Incorrect number of arguments.\n"), EXIT_SUCCESS);
	p_obj_list = check_file(argv[1]);
	if (!p_obj_list)
		return (printf("Warning: Incorrect the scene description file.\n"), EXIT_SUCCESS);
	ft_lstclear(&p_obj_list, &free_t_object);
	// init(&vars);
	return (EXIT_SUCCESS);
}
