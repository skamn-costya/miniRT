/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:13:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/25 22:04:50 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft.h"

# define AMBIENT_ID		"A"
# define CAMERA_ID		"C"
# define LIGHT_ID		"L"
# define SPHERE_ID		"sp"
# define PLANE_ID		"pl"
# define CYLINDER_ID	"cy"

# define CONE_ID		"co"
# define HYPERBOLOID_ID	"hy"
# define PARABOLOID_ID	"pa"

#define TRIM_SYMBOLS	" \\\a\b\f\n\r\t\v"

struct s_fline
{
	char	*str;
	char	**words;
}
typedef t_fline;

// parser01.c
int		check_file(char	*f_name);

#endif	// PARSER_H