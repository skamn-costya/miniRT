/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/28 17:59:08 by ksorokol         ###   ########.fr       */
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

	idx = 0;
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

int	get_rgb(char **pp_str, size_t idx, unsigned char *argb, int idx_rgb)
{
	char	*str;
	char	**pp_str_;
	size_t	size;
	int		i;

	if (!pp_str || !pp_str[idx])
		return (-1);
	if (idx_rgb < 0)
		return (TRUE);
	pp_str_ = ft_split(pp_str[idx], ',');
	size = ft_parrsize((void **) pp_str_);
	if (size > 3)
		return (ft_parrclear((void **)pp_str_), FALSE);
	while (size--)
	{
		str = ft_strtrim(pp_str_[size], TRIM_SYMBOLS);
		if (!is_i_number(str))
			return (free (str), ft_parrclear((void **)pp_str_), FALSE);
		i = ft_atoi(str);
		free (str);
		if (i < 0 || i > 255)
			return (free (str), ft_parrclear((void **)pp_str_), FALSE);
		argb[idx_rgb] = i;
		idx_rgb--;
	}
	if (idx_rgb != 0)
		get_rgb(pp_str, idx + 1, argb, idx_rgb);
	return (ft_parrclear((void **)pp_str_), TRUE);
}

// int	get_coord(t_list *p_list, t_vector)
// {
// }
