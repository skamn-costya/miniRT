/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:21:05 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/17 00:13:27 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_BASIS_H
# define KSX_BASIS_H

# include "ksx_graphics.h"

// ksx_basis.c
t_basis		ksx_get_basis_obj(const t_vector3 *p_norm);
void		ksx_camera_set_basis(t_camera *p_camera, const t_vector3 *p_norm);
// void		ksx_create_vm(t_matrix4 *p_vm, const t_basis *p_basis);
void		ksx_qrotation_basis(t_basis *p_basis, float angle, t_vector3 v);

// ksx_basis_move.c
// void		ksx_camera_move_basis(t_camera *p_camera, const t_vector3 *p_v);

#endif	// KSX_BASIS_H