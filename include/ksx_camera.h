/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_camera.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:54:53 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/06 23:13:23 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_CAMERA_H
# define KSX_CAMERA_H

# define MGC_NUM 5.5

typedef float	t_cammtrx[4][4];

void	set_camera_matrix(float a, float n, float f, t_cammtrx *cm);
void	impl_matrix2arr(int xy[], t_cammtrx cm);
void	impl_matrix2xyz(float src[3], float dst[4], t_cammtrx cm);

#endif