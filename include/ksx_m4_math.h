/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_m4_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:24:31 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/05 23:07:10 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_M4_MATH_H
# define KSX_M4_MATH_H

# include "ksx_graphics.h"

/**
 * @brief set every elements of the matrix 4x4 to 0.0f.
 * 
 * @param[in] p_m4 pointer to the matrix, which will reset.
 */
void		ksx_m4_reset(t_matrix4 *p_m4);

/**
 * @brief 4x4 matrixes multiplication.
 * 
 * @param[in] m4_1 The first matrix for multiplication.
 * @param[in] m4_2 The second matrix for multiplication.
 * @returns result of multiplication - the matrix 4x4.
 */
t_matrix4	ksx_m4_multi(const t_matrix4 m4_1, const t_matrix4 m4_2);

/**
 * @brief 4x4 matrix multiplication by vector 4.
 * 
 * @param[in] m4_1 The matrix for multiplication.
 * @param[in] v The vector for multiplication.
 * @returns result of multiplication - the matrix 4x4.
 */
t_vector4	ksx_m4_vec4(const t_matrix4 m, const t_vector4 v);

#endif	// KSX_M4_MATH_H
