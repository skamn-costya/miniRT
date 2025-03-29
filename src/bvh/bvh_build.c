/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:35:07 by username          #+#    #+#             */
/*   Updated: 2025/03/29 10:56:11 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

static void	subdivide(uint32_t idx, t_bvh *bvh);

static void	grow_bvh(uint32_t idx, t_bvh *bvh)
{
	t_triangle	*curr_t;
	uint32_t	curr_tri_idx;
	uint32_t	i;
	t_bvhnode	*nodes;

	nodes = bvh->nodes;
	nodes[idx].aabb_min = ksx_vec3_set(1e30f, 1e30f, 1e30f);
	nodes[idx].aabb_max = ksx_vec3_set(-1e30f, -1e30f, -1e30f);
	i = 0;
	while (i < nodes[idx].tri_num)
	{
		curr_tri_idx = bvh->tri_index[nodes[idx].first_tri + i];
		curr_t = bvh->pp_tri[curr_tri_idx];
		nodes[idx].aabb_min = min_vec(nodes[idx].aabb_min, curr_t->p_ver1->cp);
		nodes[idx].aabb_min = min_vec(nodes[idx].aabb_min, curr_t->p_ver2->cp);
		nodes[idx].aabb_min = min_vec(nodes[idx].aabb_min, curr_t->p_ver3->cp);
		nodes[idx].aabb_max = max_vec(nodes[idx].aabb_max, curr_t->p_ver1->cp);
		nodes[idx].aabb_max = max_vec(nodes[idx].aabb_max, curr_t->p_ver2->cp);
		nodes[idx].aabb_max = max_vec(nodes[idx].aabb_max, curr_t->p_ver3->cp);
		i++;
	}
}

static void	create_children(uint32_t idx, int32_t i, t_bvh *bvh)
{
	uint32_t	left_count;
	uint32_t	l_ch_idx;
	uint32_t	r_ch_idx;
	t_bvhnode	*nodes;

	nodes = bvh->nodes;
	left_count = i - nodes[idx].first_tri;
	if (left_count == 0 || left_count == nodes[idx].tri_num)
		return ;
	l_ch_idx = bvh->used_n++;
	r_ch_idx = bvh->used_n++;
	nodes[l_ch_idx].first_tri = nodes[idx].first_tri;
	nodes[l_ch_idx].tri_num = left_count;
	nodes[r_ch_idx].first_tri = i;
	nodes[r_ch_idx].tri_num = nodes[idx].tri_num - left_count;
	nodes[idx].left_ch = l_ch_idx;
	nodes[idx].tri_num = 0;
	grow_bvh(l_ch_idx, bvh);
	grow_bvh(r_ch_idx, bvh);
	subdivide(l_ch_idx, bvh);
	subdivide(r_ch_idx, bvh);
}

static void	subdivide(uint32_t idx, t_bvh *bvh)
{
	t_vector3	ext;
	uint32_t	axis;
	float		split_pos;
	int32_t		i;
	int32_t		j;

	if (bvh->nodes[idx].tri_num <= 2)
		return ;
	ext = ksx_vec3_sub(&bvh->nodes[idx].aabb_max, &bvh->nodes[idx].aabb_min);
	axis = 0;
	if (ext.y > ext.x)
		axis = 1;
	if (ext.z > ext.xyz[axis])
		axis = 2;
	split_pos = bvh->nodes[idx].aabb_min.xyz[axis] + ext.xyz[axis] * 0.5f;
	i = bvh->nodes[idx].first_tri;
	j = i + bvh->nodes[idx].tri_num - 1;
	while (i <= j)
	{
		if (bvh->pp_tri[bvh->tri_index[i]]->centr.xyz[axis] < split_pos)
			i++;
		else
			swap(&(bvh->tri_index[i]), &(bvh->tri_index[j--]));
	}
	create_children(idx, i, bvh);
}

t_bvh	*build_bvh(t_triangle **pp_tri, uint32_t tri_n)
{
	t_bvhnode	*nodes;
	uint32_t	*tri_index;
	t_bvh		*res;

	res = malloc(sizeof(t_bvh));
	if (!res)
		return (NULL);
	nodes = malloc(sizeof(t_bvhnode) * (tri_n * 2 - 1));
	if (!nodes)
		return (free(res), NULL);
	ft_bzero(nodes, sizeof(t_bvhnode) * (tri_n * 2 - 1));
	tri_index = malloc(sizeof(uint32_t) * tri_n);
	if (!tri_index)
		return (free(nodes), free(res), NULL);
	set_centroids(pp_tri, tri_index);
	nodes[0].left_ch = 0;
	nodes[0].first_tri = 0;
	nodes[0].tri_num = tri_n;
	res->nodes = nodes;
	res->tri_index = tri_index;
	res->pp_tri = pp_tri;
	res->used_n = 1;
	grow_bvh(0, res);
	subdivide(0, res);
	return (res);
}

void	bvh_build_world(t_graphics *grph)
{
	static int	count = 1;
	int32_t		i;
	t_object	*obj;

	i = 0;
	while (i < grph->world.size_obj)
	{
		printf("Buliding BVH No.%i\n", count++);
		obj = grph->world.pp_obj[i];
		obj->bvh = build_bvh(obj->pp_tri, obj->size_tri);
		i++;
	}
}
