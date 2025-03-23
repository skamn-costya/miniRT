/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:41:01 by username          #+#    #+#             */
/*   Updated: 2025/03/22 12:17:46 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

void	bvh_draw_box(t_bvhnode *bvh_node, t_graphics *grph, uint32_t color)
{
	t_vector3 a, b, c, d, e, f, g, h;
	t_pixel	pa, pb, pc, pd, pe, pf, pg, ph;
	t_vector3 *min = &bvh_node->aabb_min;
	t_vector3 *max = &bvh_node->aabb_max;
	a = *min;
	b = ksx_vec3_set(max->x, min->y, min->z);
	c = ksx_vec3_set(max->x, min->y, max->z);
	d = ksx_vec3_set(min->x, min->y, max->z);
	e = ksx_vec3_set(min->x, max->y, min->z);
	f = ksx_vec3_set(max->x, max->y, min->z);
	g = *max;
	h = ksx_vec3_set(min->x, max->y, max->z);

	pa = ksx_draw_get_pixel(&grph->camera, &a, color);
	pb = ksx_draw_get_pixel(&grph->camera, &b, color);
	pc = ksx_draw_get_pixel(&grph->camera, &c, color);
	pd = ksx_draw_get_pixel(&grph->camera, &d, color);
	pe = ksx_draw_get_pixel(&grph->camera, &e, color);
	pf = ksx_draw_get_pixel(&grph->camera, &f, color);
	pg = ksx_draw_get_pixel(&grph->camera, &g, color);
	ph = ksx_draw_get_pixel(&grph->camera, &h, color);

	ksx_line(grph->img_ray, &pa, &pb);
	ksx_line(grph->img_ray, &pb, &pc);
	ksx_line(grph->img_ray, &pc, &pd);
	ksx_line(grph->img_ray, &pd, &pa);

	ksx_line(grph->img_ray, &pa, &pe);
	ksx_line(grph->img_ray, &pb, &pf);
	ksx_line(grph->img_ray, &pc, &pg);
	ksx_line(grph->img_ray, &pd, &ph);

	ksx_line(grph->img_ray, &pe, &pf);
	ksx_line(grph->img_ray, &pf, &pg);
	ksx_line(grph->img_ray, &pg, &ph);
	ksx_line(grph->img_ray, &ph, &pe);
}
