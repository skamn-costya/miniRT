/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_pixel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:37:26 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/01 23:40:46 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_PIXEL_H
# define KSX_PIXEL_H

# include "ksx_graphics.h"

t_pixel	ksx_get_pixel(mlx_image_t *p_img, uint32_t x, uint32_t y);

#endif	// KSX_PIXEL_H //