/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_boxes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:17:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/29 13:31:37 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_BOXES_H
# define KSX_BOXES_H

# include "ksx_graphics.h"

void	ksx_box_triangles(t_box *p_box, t_object *p_object);
t_box	*ksx_box_add_new(t_box ***ppp_box);
t_box	*ksx_box_add(t_box ***ppp_box, t_box *p_box);
void	ksx_box_create(t_object *p_object);

#endif	// KSX_BOXES_H