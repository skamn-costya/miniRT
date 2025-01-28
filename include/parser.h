/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:13:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/28 19:06:30 by ksorokol         ###   ########.fr       */
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
t_list	*check_file(char *f_name);
void	free_t_fline(void *p_fline);

// parser02.c
t_list	*create_obj_list(t_list **pp_line_list);


// parser03.c
int		is_f_number(char *str);
int		is_i_number(char *str);
int		get_rgb(char **pp_str, size_t idx, unsigned char *argb, int idx_rgb);

// parser04.c
char	*comma_trim(char *str);
void	free_t_object(void *p_obj);
void	parser_crash_exit(t_list **pp_line_list, t_list **pp_obj_list);

#endif	// PARSER_H