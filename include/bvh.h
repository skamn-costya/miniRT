/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:44:00 by username          #+#    #+#             */
/*   Updated: 2025/03/22 12:22:05 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "minirt.h"
# include "ksx_vec3_math.h"
# include "ksx_utils.h"
# include "ksx_3D.h"
# include "math.h"
# include "stdio.h"

// Number of triangles in smallest BVH box
// - higher number = less boxes
// - don't set less than 2!
# define BVH_LEAF_TRI_COUNT 2

// Core
t_bvh		*build_bvh(t_triangle **pp_tri, uint32_t tri_n);
void		bvh_for_obj(t_object *obj);
void		bvh_build_world(t_graphics *grph);

// Utils
void		swap(uint32_t *a, uint32_t *b);
void		set_centroids(t_triangle **pp_tri, uint32_t *tri_index);
t_vector3	max_vec(t_vector3 a, t_vector3 b);
t_vector3	min_vec(t_vector3 a, t_vector3 b);

// Debug
void		bvh_draw_obj(t_object *obj, t_graphics *grph);
void		bvh_draw_box(t_bvhnode *bvh_node, t_graphics *grph, uint32_t color);
void		bvh_draw_world(t_graphics *grph);

#endif
