/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:48:40 by ksorokol          #+#    #+#             */
/*   Updated: 2024/12/26 18:01:27 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_camera.h"
#include <math.h>

void	set_camera_matrix(float a, float n, float f, t_cammtrx *cm)
{
	float	scale;
	int		idx[2];

	idx[1] = 0;
	while (idx[1] < 4)
	{
		idx[0] = 0;
		while (idx[0] < 4)
		{
			(*cm)[idx[0]][idx[1]] = 0;
			idx[0]++;
		}
		idx[1]++;
	}
	scale = 1 / tan(a * 0.5 * PI / 180);
	(*cm)[0][0] = scale;
	(*cm)[1][1] = scale;
	(*cm)[2][2] = CAMERA_Z / (f - n);
	(*cm)[3][2] = CAMERA_Z - (*cm)[2][2];
	(*cm)[2][3] = 1;
	(*cm)[3][3] = 0;
}

void	impl_matrix2arr(int xy[], t_fdf ***fdf, t_cammtrx cm)
{
	int		idx[2];
	t_fdf	*pfdf;

	idx[1] = 0;
	while (idx[1] < xy[1])
	{
		idx[0] = 0;
		while (idx[0] < xy[0])
		{
			pfdf = fdf[idx[0]][idx[1]];
			impl_matrix2xyz (pfdf->xyz_p, pfdf->xyzw_c, cm);
			idx[0]++;
		}
		idx[1]++;
	}
}

void	impl_matrix2xyz(float src[3], float dst[4], t_cammtrx cm)
{
	dst[0] = (cm[0][0] * src[0]) + (cm[1][0] * src[1])
		+ (cm[2][0] * src[2]) + (cm[3][0] * 1);
	dst[1] = (cm[0][1] * src[0]) + (cm[1][1] * src[1])
		+ (cm[2][1] * src[2]) + (cm[3][1] * 1);
	dst[2] = (cm[0][2] * src[0]) + (cm[1][2] * src[1])
		+ (cm[2][2] * src[2]) + (cm[3][2] * 1);
	dst[3] = (cm[0][3] * src[0]) + (cm[1][3] * src[1])
		+ (cm[2][3] * src[2]) + (cm[3][3] * 1);
	dst[0] /= dst[2];
	dst[1] /= dst[2];
	dst[2] /= dst[2];
}
