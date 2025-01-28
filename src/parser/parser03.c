/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/28 21:52:51 by ksorokol         ###   ########.fr       */
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

int	get_rgb(char **pp_str, size_t idx, t_object *p_obj, int idx_rgb)
{
	char	**pp_str_;
	size_t	size;
	int		i;

	if (!pp_str || !pp_str[idx])
		return (FALSE);
	pp_str_ = ft_split(pp_str[idx], ',');
	size = ft_parrsize((void **) pp_str_);
	if (size != 3)
		return (ft_parrclear((void **)pp_str_), FALSE);
	while (size--)
	{
		if (!is_i_number(pp_str_[size]))
			return (ft_parrclear((void **)pp_str_), FALSE);
		i = ft_atoi(pp_str_[size]);
		if (i < 0 || i > 255)
			return (ft_parrclear((void **)pp_str_), FALSE);
		p_obj->color.argb[idx_rgb] = i;
		idx_rgb--;
	}
	return (ft_parrclear((void **)pp_str_), TRUE);
}

// int	get_coord(t_list *p_list, t_vector)
// {
// }
