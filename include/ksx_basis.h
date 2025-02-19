/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_basis.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:21:05 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/19 13:20:31 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_BASIS_H
# define KSX_BASIS_H

# include "ksx_graphics.h"

// ksx_basis.c
t_basis		ksx_basis_get(const t_vector3 *p_norm);
void		ksx_basis_set_norm(t_basis *p_basis, t_vector3 *p_norm);
void		ksx_basis_camera(t_camera *p_camera, const t_vector3 *p_norm);

// ksx_basis_move.c
// void		ksx_camera_move_basis(t_camera *p_camera, const t_vector3 *p_v);

// ksx_basis_rotation.c
void		ksx_qrotation_basis(t_basis *p_basis, float angle, t_vector3 v);

#endif	// KSX_BASIS_H