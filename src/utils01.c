/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:38:54 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/25 15:58:14 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_pp_obj(void **pp_obj)
{
	size_t	idx;

	if (!pp_obj)
		return ;
	if (!pp_obj[0])
		return (free (pp_obj));
	idx = 0;
	while (pp_obj[idx])
	{
		free (pp_obj[idx]);
		idx++;
	}
	free (pp_obj);
}
