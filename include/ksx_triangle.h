/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_triangle.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:46:58 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/21 13:18:18 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_TRIANGLE_H
# define KSX_TRIANGLE_H

#include "ksx_graphics.h"

void		ksx_tri_set_vertexes(t_triangle *p_tri, t_vertex *p_ver1,
				t_vertex *p_ver2, t_vertex *p_ver3);
void		ksx_tri_set_norms(t_triangle *p_tri, t_vector3 *p_n1,
				t_vector3 *p_n2, t_vector3 *p_n3);

#endif	// KSX_TRIANGLE_H