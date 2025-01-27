/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/27 19:34:38 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include <sys/stat.h>
#include <fcntl.h>

int	is_f_number(char *str)
{
	size_t	idx;
	int		dot;

	idx = 0;
	dot = 0;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]) && str[idx] != '.')
			return (FALSE);
		if (str[idx] == '.')
			dot++;
		if (dot > 1)
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

int	is_i_number(char *str)
{
	size_t	idx;
	int		dot;

	idx = 0;
	dot = 0;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

int	get_rgb(char **pp_str, size_t idx, t_argb *argb, int idx_rgb)
{
	char	*str;
	char	**pp_str_;

	if (!pp_str || !pp_str[idx])
		return (FALSE);
	str = ft_strtrim(pp_str[idx], ',');
	if (is_i_number(str))
	{
		argb->argb[idx_rgb] = ft_atoi(str);
		if (argb->argb[idx_rgb] < 0 || argb->argb[idx_rgb] > 255)
			return (free (str), FALSE);
	}
	else
	{
		pp_str_ = ft_split (str, ',');
		get_rgb ()
		ft_free_pp_obj (pp_str_);
	}
}

// int	get_coord(t_list *p_list, t_vector)
// {
	
// }
