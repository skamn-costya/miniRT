/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_plane.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:33:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/06 00:50:15 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_PLANE_H
# define KSX_PLANE_H

# include "ksx_graphics.h"

t_plane	*ksx_create_plane(t_vector3 point, t_vector3 norm, t_color color);
t_plane	**ksx_pln2world(t_plane *p_plane, t_world *p_world);
float	ksx_plane_check(t_vector3 *p_vec, t_plane *p_plane);

#endif	// KSX_PLANE_H