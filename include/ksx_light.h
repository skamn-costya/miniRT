/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_light.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:15:17 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/05 13:09:45 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_LIGHT_H
# define KSX_LIGHT_H

# include "ksx_graphics.h"

t_light	*ksx_create_light(t_vector3 center, float bright, t_color color);
t_light	**ksx_lgt2world(t_light *p_light, t_world *p_world);

#endif // KSX_LIGHT_H
