/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_pixel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:37:26 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/31 14:39:14 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"

#ifndef KSX_PIXEL_H
# define KSX_PIXEL_H

t_pixel	get_pixel(mlx_image_t *p_img, uint32_t x, uint32_t y);

#endif