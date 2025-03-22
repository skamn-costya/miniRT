/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:35:07 by username          #+#    #+#             */
/*   Updated: 2025/03/22 12:20:11 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

static void	grow_bvh(uint32_t	idx, t_bvh *bvh)
{
	t_triangle	*curr_tri;
	uint32_t	curr_tri_idx;
	uint32_t	i;
	t_bvhnode	*all_nodes;

	all_nodes = bvh->all_nodes;
	all_nodes[idx].aabb_min = ksx_vec3_set(1e30f, 1e30f, 1e30f);
	all_nodes[idx].aabb_max = ksx_vec3_set(-1e30f, -1e30f, -1e30f);
	i = 0;
	//printf("TRI COUNT %i\n", all_nodes[idx].tri_count);
	while (i < all_nodes[idx].tri_count)
	{
		//printf("FIRST TRI %i\n", all_nodes[idx].first_tri + i);
		curr_tri_idx = bvh->tri_index[all_nodes[idx].first_tri + i];
		curr_tri = bvh->pp_tri[curr_tri_idx];
		all_nodes[idx].aabb_min = min_vec(all_nodes[idx].aabb_min, curr_tri->p_ver1->cp);
		all_nodes[idx].aabb_min = min_vec(all_nodes[idx].aabb_min, curr_tri->p_ver2->cp);
		all_nodes[idx].aabb_min = min_vec(all_nodes[idx].aabb_min, curr_tri->p_ver3->cp);
		all_nodes[idx].aabb_max = max_vec(all_nodes[idx].aabb_max, curr_tri->p_ver1->cp);
		all_nodes[idx].aabb_max = max_vec(all_nodes[idx].aabb_max, curr_tri->p_ver2->cp);
		all_nodes[idx].aabb_max = max_vec(all_nodes[idx].aabb_max, curr_tri->p_ver3->cp);
		i++;
	}
	//printf("MIN: [%f, %f, %f]\n", all_nodes[idx].aabb_min.x, all_nodes[idx].aabb_min.y, all_nodes[idx].aabb_min.z);
	//printf("MAX: [%f, %f, %f]\n", all_nodes[idx].aabb_max.x, all_nodes[idx].aabb_max.y, all_nodes[idx].aabb_max.z);
}

static void	subdivide(uint32_t idx, t_bvh *bvh, t_graphics *grph)
{
	t_vector3	extent;
	uint32_t	axis;
	float	split_pos;
	int32_t	i;
	int32_t	j;
	uint32_t	left_count;
	uint32_t	l_ch_idx;
	uint32_t	r_ch_idx;
	t_bvhnode	*all_nodes;

	all_nodes = bvh->all_nodes;
	if (all_nodes[idx].tri_count <= BVH_LEAF_TRI)
		return ;
	extent = ksx_vec3_sub(&all_nodes[idx].aabb_max, &all_nodes[idx].aabb_min);
	axis = 0;
	if (extent.y > extent.x)
		axis = 1;
	if (extent.z > extent.xyz[axis])
		axis = 2;
	split_pos = all_nodes[idx].aabb_min.xyz[axis] + extent.xyz[axis] * 0.5f;
	i = all_nodes[idx].first_tri;
	j = i + all_nodes[idx].tri_count - 1;
	//printf("AXIS: [%f, %i]\n", split_pos, axis);
	//printf("CENTROID: [%f, %f, %f]\n", bvh->pp_tri[0]->centr.x, bvh->pp_tri[0]->centr.y, bvh->pp_tri[0]->centr.z);
	//printf("EXTENT: [%f, %f, %f]\n", extent.x, extent.y, extent.z);
	while (i <= j)
	{
		//printf("CENTR: %f, tri_idx: %i\n", bvh->pp_tri[bvh->tri_index[i]]->centr.xyz[axis], bvh->tri_index[i]);
		if (bvh->pp_tri[bvh->tri_index[i]]->centr.xyz[axis] < split_pos)
			i++;
		else
			swap(&(bvh->tri_index[i]), &(bvh->tri_index[j--]));	
	}
	left_count = i - all_nodes[idx].first_tri;
	if (left_count == 0 || left_count == all_nodes[idx].tri_count)
		return ;
	l_ch_idx = bvh->nodes_used++;
	r_ch_idx = bvh->nodes_used++;
	all_nodes[l_ch_idx].first_tri = all_nodes[idx].first_tri;
	all_nodes[l_ch_idx].tri_count = left_count;
	all_nodes[r_ch_idx].first_tri = i;
	all_nodes[r_ch_idx].tri_count = all_nodes[idx].tri_count - left_count;
	all_nodes[idx].left_ch = l_ch_idx;
	all_nodes[idx].tri_count = 0;
	grow_bvh(l_ch_idx, bvh);
	grow_bvh(r_ch_idx, bvh);
	//printf("LCH: %i, %i\n", all_nodes[l_ch_idx].first_tri, all_nodes[l_ch_idx].tri_count);
	//printf("RCH: %i, %i\n", all_nodes[r_ch_idx].first_tri, all_nodes[r_ch_idx].tri_count);
	subdivide(l_ch_idx, bvh, grph);
	subdivide(r_ch_idx, bvh, grph);
}

t_bvh	*build_bvh(t_triangle **pp_tri, uint32_t tri_n, t_graphics *grph)
{
	t_bvhnode	*all_nodes;
	uint32_t	*tri_index;
	t_bvh	*res;

	res = malloc(sizeof(t_bvh));
	if (!res)
		return (NULL);
	all_nodes = malloc(sizeof(t_bvhnode) * (tri_n * 2 - 1));
	if (!all_nodes)
		return (free(res), NULL);
	ft_bzero(all_nodes, sizeof(t_bvhnode) * (tri_n * 2 - 1));
	tri_index = malloc(sizeof(uint32_t) * tri_n);
	if (!tri_index)
		return (free(all_nodes), free(res), NULL);
	set_centroids(pp_tri, tri_index);
	all_nodes[0].left_ch = 0;
	all_nodes[0].first_tri = 0;
	all_nodes[0].tri_count = tri_n;
	res->all_nodes = all_nodes;
	res->tri_index = tri_index;
	res->pp_tri = pp_tri;
	res->nodes_used = 2;
	grow_bvh(0, res);
	subdivide(0, res, grph);
	
	// Draw debug boxes
	uint32_t i = 0;
	uint32_t color = 0xFFFFFFFF;
	while (i < res->nodes_used) {
		bvh_draw_box(&all_nodes[i], grph, color);
		color -= 32;
		i++;
	}
	return (res);
}
