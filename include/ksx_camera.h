/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_camera.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:54:53 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/31 19:01:57 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_CAMERA_H
# define KSX_CAMERA_H

# include "ksx_graphics.h"

// ksx_camera01.c
void	set_camera_matrix(float angle, float near, float far, t_matrix4 *cm);

// typedef float	t_cammtrx[4][4];

// void	set_camera_matrix(float a, float n, float f, t_cammtrx *cm);
// void	impl_matrix2arr(int xy[], t_cammtrx cm);
// void	impl_matrix2xyz(float src[3], float dst[4], t_cammtrx cm);

#endif	// KSX_CAMERA_H //
