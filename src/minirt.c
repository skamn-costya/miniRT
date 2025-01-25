/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/25 14:10:39 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <stdlib.h>
#include "minirt.h"
#include "parser.h"
#include "libft.h"

int	main(int argc, char *argv[])
{
	// t_vars vars;

	if (argc !=2)
		return (printf("Warning: Incorrect number of arguments.\n"), EXIT_SUCCESS);
	if (!check_file(argv[1]))
		return (printf("Warning: Incorrect the scene description file.\n"), EXIT_SUCCESS);
	// init(&vars);
	return (EXIT_SUCCESS);
}
