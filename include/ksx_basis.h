/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:21:05 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/10 13:27:18 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_BASIS_H
# define KSX_BASIS_H

# include "ksx_graphics.h"

t_basis		ksx_get_basis(const t_vector3 *p_norm, const t_vector3 *p_center);
void		ksx_create_vm(t_matrix4 *p_vm, const t_basis *p_basis);

#endif	// KSX_BASIS_H