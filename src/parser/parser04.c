/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 19:23:20 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

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
	if (size != COLOR_SIZE)
		return (ft_parrclear((void **)pp_str_), FALSE);
	while (size--)
	{
		if (!is_i_number(pp_str_[size]))
			return (ft_parrclear((void **)pp_str_), FALSE);
		i = ft_atoi(pp_str_[size]);
		if (i < 0 || i > 255)
			return (ft_parrclear((void **)pp_str_), FALSE);
		p_obj->color.abgr[idx_rgb] = i;
		idx_rgb--;
	}
	return (ft_parrclear((void **)pp_str_), TRUE);
}

int	get_coord(char **pp_str, size_t idx, t_object *p_obj)
{
	char	**pp_str_;
	size_t	size;
	float	f;

	if (!pp_str || !pp_str[idx])
		return (FALSE);
	pp_str_ = ft_split(pp_str[idx], ',');
	size = ft_parrsize((void **) pp_str_);
	if (size != 3)
		return (ft_parrclear((void **)pp_str_), FALSE);
	while (size--)
	{
		if (!is_f_number(pp_str_[size]))
			return (ft_parrclear((void **)pp_str_), FALSE);
		f = ft_atof(pp_str_[size]);
		p_obj->coord.xyz[size] = f;
	}
	return (ft_parrclear((void **)pp_str_), TRUE);
}

int	get_vector(char **pp_str, size_t idx, t_object *p_obj)
{
	char	**pp_str_;
	size_t	size;
	float	f;
	size_t	idx_;

	if (!pp_str || !pp_str[idx])
		return (FALSE);
	pp_str_ = ft_split(pp_str[idx], ',');
	size = ft_parrsize((void **) pp_str_);
	if (size != 3)
		return (ft_parrclear((void **)pp_str_), FALSE);
	idx_ = 0;
	while (size--)
	{
		if (!is_f_number(pp_str_[size]))
			return (ft_parrclear((void **)pp_str_), FALSE);
		f = ft_atof(pp_str_[size]);
		if (f < -1 || f > 1)
			return (ft_parrclear((void **)pp_str_), FALSE);
		p_obj->norm.xyz[idx_] = f;
		idx_++;
	}
	return (ft_parrclear((void **)pp_str_), TRUE);
}
