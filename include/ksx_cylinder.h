/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_cylinder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:56:26 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/28 17:31:21 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_CYLINDER_H
# define KSX_CYLINDER_H

# include "ksx_graphics.h"

void	ksx_init_cylinder_tri(t_object *p_object,
			int32_t size, int32_t count);
void	ksx_init_cylinder_0(t_object *p_object, int32_t size,
			int32_t idx, float *xz);

#endif	// KSX_CYLINDER_H
