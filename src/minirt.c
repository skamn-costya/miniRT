/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/25 00:16:20 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <stdlib.h>
#include "parser.h"
#include "libft.h"

int	main(int argc, char *argv[])
{
	// t_vars vars;

	(void) argc;
	(void) argv;
	if (check_file(NULL))
		return (EXIT_SUCCESS);
	// init(&vars);
	return (EXIT_SUCCESS);
}
