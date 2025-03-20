/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_struct01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:55:31 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/20 17:55:54 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "pp_struct.h"

int	pp_get_size(void **pp_instance)
{
	int	idx;

	idx = 0;
	if (!pp_instance)
		return (idx);
	while (pp_instance[idx])
		idx++;
	return (idx);
}

void	pp_null_pointers(void **pp_instance, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		pp_instance[idx] = NULL;
		idx++;
	}
}

void	**pp_add_instance(void **pp_instance, void *p_instance,
	void *p_f_error(char*, char*, int))
{
	void	**pp_instance_new;
	int		size;
	int		idx;

	size = pp_get_size(pp_instance);
	pp_instance_new = (void **) malloc (sizeof(void *) * (size + 2));
	if (!pp_instance_new)
	{
		if (p_f_error)
			p_f_error("memory allocation failure", __FILE__, __LINE__);
		return (NULL);
	}
	idx = 0;
	while (idx < size)
	{
		pp_instance_new[idx] = pp_instance[idx];
		idx++;
	}
	free(pp_instance);
	pp_instance_new[idx] = p_instance;
	pp_instance_new[idx + 1] = NULL;
	return (pp_instance_new);
}

int	pp_search_instance(void **pp_instance, void *p_instance)
{
	int	idx;

	idx = 0;
	if (!pp_instance)
		return (-1);
	while (pp_instance[idx])
	{
		if (pp_instance[idx] == p_instance)
			return (idx);
		idx++;
	}
	return (-1);
}

void	**pp_del_idx(void **pp_instance, int del_idx,
	void *p_f_error(char*, char*, int))
{
	void	**pp_instance_new;
	int		size;
	int		idx;

	size = pp_get_size(pp_instance);
	pp_instance_new = (void **) malloc (sizeof(void *) * (size));
	if (!pp_instance_new)
	{
		if (p_f_error)
			p_f_error("memory allocation failure", __FILE__, __LINE__);
		return (NULL);
	}
	idx = 0;
	while (idx < size - 1)
	{
		if (idx != del_idx)
			pp_instance_new[idx] = pp_instance[idx];
		idx++;
	}
	free(pp_instance[del_idx]);
	free(pp_instance);
	pp_instance_new[idx] = NULL;
	return (pp_instance_new);
}
