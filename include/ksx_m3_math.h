/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_m3_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:24:31 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/15 08:46:33 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_M3_MATH_H
# define KSX_M3_MATH_H

# include "ksx_graphics.h"

/**
 * @brief set every elements of the matrix 3x3 to 0.0f.
 * 
 * @param[in] p_m a pointer to the matrix, which will reset.
 */
void		ksx_m3_reset(t_matrix3 *p_m);

/**
 * @brief 3x3 matrixes multiplication.
 * 
 * @param[in] p_m1 a pointer to the first matrix for multiplication.
 * @param[in] p_m2 a pointer to the second matrix for multiplication.
 * @returns result of multiplication - a matrix 3x3.
 */
t_matrix3	ksx_m3_multi(const t_matrix3 *p_m1, const t_matrix3 *p_m2);

/**
 * @brief 3x3 matrix multiplication by vector 3.
 * 
 * @param[in] p_m a pointer to the matrix for multiplication.
 * @param[in] p_v a pinter to the vector for multiplication.
 * @returns result of multiplication - a matrix 3x3.
 */
t_vector3	ksx_m3_vec3(const t_matrix3 *p_m, const t_vector3 *p_v);

/**
 * @brief gets determinant of matrix 3x3
 * 
 * @param[in] p_m a pointer to the matrix for determinantion.
 * @returns determinant.
 */
float		ksx_m3_det(const t_matrix3 *p_m);

#endif	// KSX_M3_MATH_H
