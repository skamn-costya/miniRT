/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:45:28 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/23 11:29:48 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TEXTURE_H
# define RAY_TEXTURE_H

# include "ksx_graphics.h"

# define PI_1	0.31830988618379069
# define PI_12	0.15915494309189535

t_texture	*ray_txtr_create_checkerboard(t_world *p_worl);

void	ray_txtr_uv_plan(t_vector3 *p_point, float *p_u, float *p_v);
void	ray_txtr_uv_spheres(t_vector3 *p_point, float *p_u, float *p_v);
void	ray_txtr_uv_cylinder(t_vector3 *p_point, float *p_u, float *p_v);

void 	ray_txtr_free_data(void *p_txtr);

#endif // RAY_TEXTURE_H
