/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:22:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/31 15:18:34 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"

#ifndef KSX_UTILS_H
# define KSX_UTILS_H

// ksx_utils01.c
float	get_dist_xyz(const float xyz1[], const float xyz2[]);
float	get_dist_vector(const t_vector v1, const t_vector v2);
float	get_dist_point(const t_point p1, const t_point p2);
void	get_middle_point(const t_point p1, const t_point p2, t_point *p);
void	vector_resize(t_vector v1, float new_size, t_vector *v);

// ksx_utils02.c
void	get_cross_product(const t_vector v1, const t_vector v2, t_vector *v);
float	get_magnitude(const t_vector v);
void	get_normal(t_vector v1, t_vector *v);
int		is_point_on_ray(const t_point p, const t_vector v);

// ksx_utils03.c
float	determinant2(t_matrix2 m);
float	determinant3(t_matrix3 m);
float	determinant4(t_matrix4 m);

// ksx_utils04.c
float	fraction(t_pixel p, t_pixel p1, t_pixel p2);
int32_t	ksx_abs(int32_t num);

#endif
