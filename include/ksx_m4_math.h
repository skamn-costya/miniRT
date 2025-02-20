/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_m4_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:24:31 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/20 19:03:22 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_M4_MATH_H
# define KSX_M4_MATH_H

# include "ksx_graphics.h"

/**
 * @brief set every elements of the matrix 4x4 to 0.0f.
 * 
 * @param[in] p_m a pointer to the matrix, which will reset.
 */
void		ksx_m4_reset(t_matrix4 *p_m);

/**
 * @brief 4x4 matrixes multiplication.
 * 
 * @param[in] p_m1 a pointer to the first matrix for multiplication.
 * @param[in] p_m2 a pointer to the second matrix for multiplication.
 * @returns result of multiplication - a matrix 4x4.
 */
t_matrix4	ksx_m4_multi(const t_matrix4 *p_m1, const t_matrix4 *p_m2);

/**
 * @brief 4x4 matrix multiplication by vector 4.
 * 
 * @param[in] p_m a pointer to the matrix for multiplication.
 * @param[in] p_v a pinter to the vector for multiplication.
 * @returns result of multiplication - a matrix 4x4.
 */
t_vector4	ksx_m4_vec4(const t_matrix4 *p_m, const t_vector4 *p_v);

/**
 * @brief gets determinant of matrix 4x4
 * 
 * @param[in] p_m a pointer to the matrix for determinantion.
 * @returns determinant
 */
float		ksx_m4_det(const t_matrix4 *p_m);

/**
 * @brief calculates invertible matrix of matrix 4x4
 * 
 * @param[in] p_m1 a pointer to the matrix for invertible matrix.
 * @param[in] p_m2 a pointer to the matrix result matrix.
 */
void		ksx_m4_invert(const t_matrix4 *p_m1, t_matrix4 *p_m2);

void		ksx_m4_transpose(const t_matrix4 *p_m1, t_matrix4 *p_m2);

#endif	// KSX_M4_MATH_H
