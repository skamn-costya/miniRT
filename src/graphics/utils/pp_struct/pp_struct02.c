/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_struct02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:55:31 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/21 13:30:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "pp_struct.h"

void	**pp_del_instance(void **pp_instance, void *p_instance,
	void (*p_f_error)(char *, char *, int))
{
	void	**pp_instance_new;
	int		size;
	int		idx;

	if (pp_instance == NULL)
		return (NULL);
	size = pp_get_size(pp_instance);
	if (size == 0)
		return (pp_instance);
	idx = pp_search_instance(pp_instance, p_instance);
	if (idx < 0)
		return (pp_instance);
	pp_instance_new = pp_del_idx(pp_instance, idx, p_f_error);
	return (pp_instance_new);
}

void	**pp_del_all(void **pp_instance)
{
	int	idx;

	idx = 0;
	if (!pp_instance)
		return (NULL);
	while (pp_instance[idx])
	{
		free(pp_instance[idx]);
		idx++;
	}
	free(pp_instance);
	return (NULL);
}
