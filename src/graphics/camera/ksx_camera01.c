/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_camera01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:50:20 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/31 12:34:28 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include <math.h>

void	set_camera_matrix(float angle, float near, float far, t_matrix4 *cm)
{
	int		idx;
	float	scale;

	idx = 15;
	while (idx-- != -1)
		cm->elems[idx] = 0;
	scale = WIDTH / HEIGHT;
	cm->e_11 = 1 / (scale * tanf((angle * 0.5) * (PI / 180)));
	cm->e_22 = 1 / tanf((angle * 0.5) * (PI / 180));
	cm->e_33 = (-(far + near)) / (far - near);
	cm->e_34 = (-(2 * far * near)) / (far - near);
	cm->e_43 = 1;
}

