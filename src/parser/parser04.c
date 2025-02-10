/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:02:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/10 17:49:46 by ksorokol         ###   ########.fr       */
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

int	get_rgb(char **pp_str, size_t idx, t_obj_descr *p_obj_descr)
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
	p_obj_descr->color.rgba[3] = 255;
	while (size--)
	{
		if (!is_i_number(pp_str_[size]))
			return (ft_parrclear((void **)pp_str_), FALSE);
		i = ft_atoi(pp_str_[size]);
		if (i < 0 || i > 255)
			return (ft_parrclear((void **)pp_str_), FALSE);
		p_obj_descr->color.rgba[size] = i;
	}
	return (ft_parrclear((void **)pp_str_), TRUE);
}

int	get_coord(char **pp_str, size_t idx, t_obj_descr *p_obj_descr)
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
		p_obj_descr->coord.xyz[size] = f;
	}
	return (ft_parrclear((void **)pp_str_), TRUE);
}

int	get_vector(char **pp_str, size_t idx, t_obj_descr *p_obj_descr)
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
		if (f < -1 || f > 1)
			return (ft_parrclear((void **)pp_str_), FALSE);
		p_obj_descr->norm.xyz[size] = f;
	}
	return (ft_parrclear((void **)pp_str_), TRUE);
}
