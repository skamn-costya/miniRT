/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils08.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/02 22:30:14 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t	ksx_get_count_pointers(void **pointers)
{
	uint32_t	idx;

	if (!pointers || !pointers[0])
		return (0);
	idx = 1;
	while (pointers[idx])
		idx++;
	return (idx);
}

void	ksx_free_pointers(void **pointers)
{
	uint32_t	idx;

	if (!pointers)
		return ;
	idx = 0;
	while (pointers[idx])
	{
		free (pointers[idx]);
		idx++;
	}
	free (pointers);
}
