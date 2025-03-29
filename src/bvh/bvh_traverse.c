/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_traverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:10:36 by username          #+#    #+#             */
/*   Updated: 2025/03/29 22:02:19 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

inline static void	ray_p_check_tri(t_triangle *p_tri,
						t_ray *p_ray);

static void	zero_less_dir(t_vector3 *vec, float *dir)
{
	uint32_t	i;

	i = 0;
	while (i < 3)
	{
		dir[i] = vec->xyz[i];
		if (fabsf(dir[i]) < EPSILON)
		{
			if (dir[i] >= 0)
				dir[i] = EPSILON;
			else
				dir[i] = -EPSILON;
		}
		i++;
	}
}

// Slab technique
// https://www.youtube.com/watch?v=GqwUHXvQ7oA
uint8_t	intersect_aabb(t_ray *ray, t_vector3 *min, t_vector3 *max)
{
	float	tx[2];
	float	ty[2];
	float	tz[2];
	float	te[2];
	float	dir[3];

	zero_less_dir(&ray->direction, dir);
	tx[0] = (min->x - ray->origin.x) / dir[0];
	tx[1] = (max->x - ray->origin.x) / dir[0];
	ty[0] = (min->y - ray->origin.y) / dir[1];
	ty[1] = (max->y - ray->origin.y) / dir[1];
	tz[0] = (min->z - ray->origin.z) / dir[2];
	tz[1] = (max->z - ray->origin.z) / dir[2];
	te[0] = fminf(tx[0], tx[1]);
	te[1] = fmaxf(tx[0], tx[1]);
	te[0] = fmaxf(te[0], fminf(ty[0], ty[1]));
	te[1] = fminf(te[1], fmaxf(ty[0], ty[1]));
	te[0] = fmaxf(te[0], fminf(tz[0], tz[1]));
	te[1] = fminf(te[1], fmaxf(tz[0], tz[1]));
	return (te[1] >= te[0] && te[0] < ray->length && te[1] > 0);
}

void	intersect_bvh(t_ray *ray, uint32_t idx, t_bvh *bvh, t_world *p_world)
{
	t_bvhnode	node;
	uint32_t	i;

	if (!bvh)
		return ;
	node = bvh->nodes[idx];
	if (!intersect_aabb(ray, &node.aabb_min, &node.aabb_max))
		return ;
	if (node.tri_num > 0)
	{
		i = 0;
		while (i < node.tri_num)
		{
			ray_p2tri(bvh->pp_tri[bvh->tri_index[node.first_tri + i]], ray);
			ray_p_check_tri(bvh->pp_tri[bvh->tri_index[node.first_tri + i]],
				ray);
			i++;
		}
	}
	else
	{
		intersect_bvh(ray, node.left_ch, bvh, p_world);
		intersect_bvh(ray, node.left_ch + 1, bvh, p_world);
	}
}

inline static void	ray_p_check_tri(t_triangle *p_tri,
	t_ray *p_ray)
{
	t_vector3	v3;

	if (p_ray->length < p_ray->min_length)
	{
		p_ray->min_length = p_ray->length;
		v3 = ksx_vec3_smulti(&p_ray->direction, p_ray->length);
		v3 = ksx_vec3_add(&p_ray->origin, &v3);
		p_ray->point.cp = v3;
		p_ray->p_tri = p_tri;
		rey_get_barycentric(&p_ray->point.cp, p_tri, p_ray);
		p_ray->norm = triangle_normal_barycentric(p_tri, p_ray);
		p_ray->pixel.color = ((t_object *)p_tri->p_object)->color;
		if (((t_object *)p_tri->p_object)->p_texture)
			ray_txtr_object((t_object *)p_tri->p_object, p_ray);
	}
}
