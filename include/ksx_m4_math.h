/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_m4_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:24:31 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/05 16:46:24 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_M4_MATH_H
# define KSX_M4_MATH_H

# include "ksx_graphics.h"

void		ksx_m4_reset(t_matrix4 *p_m4);
t_matrix4	ksx_m4_multi(const t_matrix4 m4_1, const t_matrix4 m4_2);
t_vector4	ksx_m4_vec4(const t_matrix4 m, const t_vector4 v);

#endif	// KSX_M4_MATH_H
