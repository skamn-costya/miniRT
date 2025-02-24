/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_boxes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:17:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/24 15:27:02 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_BOXES_H
# define KSX_BOXES_H

# include "ksx_graphics.h"

void	ksx_box_create(t_box *p_box, uint32_t mlx_color);
t_box	*ksx_box_add(t_box ***ppp_box);

#endif	// KSX_BOXES_H