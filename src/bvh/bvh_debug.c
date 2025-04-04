/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:41:01 by username          #+#    #+#             */
/*   Updated: 2025/03/29 10:56:53 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

static void	bvh_init_vertices(t_bvhnode *bvh_node, t_vector3 v[8])
{
	v[0] = bvh_node->aabb_min;
	v[1] = ksx_vec3_set(
			bvh_node->aabb_max.x, bvh_node->aabb_min.y, bvh_node->aabb_min.z);
	v[2] = ksx_vec3_set(
			bvh_node->aabb_max.x, bvh_node->aabb_min.y, bvh_node->aabb_max.z);
	v[3] = ksx_vec3_set(
			bvh_node->aabb_min.x, bvh_node->aabb_min.y, bvh_node->aabb_max.z);
	v[4] = ksx_vec3_set(
			bvh_node->aabb_min.x, bvh_node->aabb_max.y, bvh_node->aabb_min.z);
	v[5] = ksx_vec3_set(
			bvh_node->aabb_max.x, bvh_node->aabb_max.y, bvh_node->aabb_min.z);
	v[6] = bvh_node->aabb_max;
	v[7] = ksx_vec3_set(
			bvh_node->aabb_min.x, bvh_node->aabb_max.y, bvh_node->aabb_max.z);
}

static void	bvh_project_vertices(t_vector3 v[8], t_pixel p[8],
	t_graphics *grph, uint32_t color)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		p[i] = ksx_draw_get_pixel(&grph->camera, &v[i], color);
		i++;
	}
}

void	bvh_draw_box(t_bvhnode *bvh_node, t_graphics *grph,
			uint32_t color, mlx_image_t *p_img)
{
	t_vector3	v[8];
	t_pixel		p[8];
	const int	edges[12][2] = {
	{0, 1}, {1, 2}, {2, 3}, {3, 0},
	{0, 4}, {1, 5}, {2, 6}, {3, 7},
	{4, 5}, {5, 6}, {6, 7}, {7, 4}
	};
	int			i;

	bvh_init_vertices(bvh_node, v);
	bvh_project_vertices(v, p, grph, color);
	i = 0;
	while (i < 12)
	{
		ksx_line(p_img, &p[edges[i][0]], &p[edges[i][1]]);
		i++;
	}
}

void	bvh_draw_obj(t_object *obj, t_graphics *grph, mlx_image_t *p_img)
{
	uint32_t	i;
	uint32_t	color;

	i = 0;
	color = 0x70C795E8;
	while (i < obj->bvh->used_n)
	{
		bvh_draw_box(&obj->bvh->nodes[i], grph, color, p_img);
		i++;
	}
}

void	bvh_draw_world(t_graphics *grph, mlx_image_t *p_img)
{
	int32_t	i;

	i = -1;
	while (++i < grph->world.size_obj)
		bvh_draw_obj(grph->world.pp_obj[i], grph, p_img);
}
