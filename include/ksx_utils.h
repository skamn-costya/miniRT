/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:22:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/29 18:12:11 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_UTILS_H
# define KSX_UTILS_H

# include "ksx_graphics.h"
# include <math.h>

// ksx_utils01.c
float	get_distance(const t_point p1, const t_point p2);
void	get_middle_point(const t_point p1, const t_point p2, t_point p);
void	get_cross_product(const t_vector v1, const t_vector v2, t_vector v);
float	get_magnitude(const t_vector v);
int		is_point_on_ray(const t_point p, const t_vector v);

// ksx_utils02.c
float	determinant2(t_matrix_f2 m);
float	determinant3(t_matrix_f3 m);
float	determinant4(t_matrix_f4 m);

#endif
