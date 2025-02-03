/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils09.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/03 14:13:13 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "MLX42.h"
#include "ksx_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// t_obj	*ksx_add_triangels(t_obj *p_obj, uint32_t size)
// {
// 	t_triangle	*p_triangle;

// 	p_triangle = (t_triangle *) malloc (sizeof(t_triangle)
// 			* (p_obj->size + size));
// 	if (!p_triangle)
// 		return (printf("Error: memory allocation failed!\n"), NULL);
// 	if (!p_obj->p)
// 		return (p_obj->p = p_triangle, p_obj->size = size, p_obj);
// 	size += p_obj->size;
// 	while (p_obj->size > 0)
// 		p_triangle[--p_obj->size] = p_obj->p[p_obj->size];
// 	free (p_obj->p);
// 	return (p_obj->p = p_triangle, p_obj->size = size, p_obj);
// }

t_triangle	**ksx_tri2obj(t_triangle *p_tri, t_obj *p_obj)
{
	t_triangle	**pp_tris;
	uint32_t	idx;

	if (!p_obj->pp_tris)
		pp_tris = (t_triangle **) malloc (sizeof(t_triangle *) * 2);
	else
		pp_tris = (t_triangle **) malloc (sizeof(t_triangle *)
				* (ksx_get_count_pointers((void **) p_obj->pp_tris) + 1));
	if (!pp_tris)
		return (printf("Error: memory allocation failed!\n"), NULL);
	idx = 0;
	if (p_obj->pp_tris)
	{
		while (p_obj->pp_tris[idx])
		{
			pp_tris[idx] = p_obj->pp_tris[idx];
			idx++;
		}
		free (p_obj->pp_tris);
	}
	pp_tris[idx] = p_tri;
	pp_tris[idx + 1] = NULL;
	p_obj->pp_tris = pp_tris;
	p_obj->size++;
	return (pp_tris);
}

t_triangle	**ksx_tris2obj(t_triangle *p_tris[], uint32_t size, t_obj *p_obj)
{
	t_triangle	**pp_tris;
	uint32_t	idx;

	if (!p_tris || !p_tris[0])
		return (p_obj->pp_tris);
	pp_tris = NULL;
	idx = 0;
	while (idx < size)
	{
		pp_tris = ksx_tri2obj(p_tris[idx], p_obj);
		idx++;
	}
	return (pp_tris);
}

// set three point for calculate a transformation matrix
// (1,1,1)(-1,-1,-1)(2,-3,4)
t_triangle	ksx_init_tps(const t_vector3 center, const t_vector3 norm)
{
	t_triangle	tps;

	(void) norm;
	tps.p1.x = center.x + 1;
	tps.p1.y = center.y + 1;
	tps.p1.z = center.z + 1;
	tps.p2.x = center.x - 1;
	tps.p2.y = center.y - 1;
	tps.p2.z = center.z - 1;
	tps.p3.x = center.x + 2;
	tps.p3.y = center.y - 3;
	tps.p3.z = center.z + 4;
	tps.w_p1.x = center.x + 1;
	tps.w_p1.y = center.y + 1;
	tps.w_p1.z = center.z + 1;
	tps.w_p2.x = center.x - 1;
	tps.w_p2.y = center.y - 1;
	tps.w_p2.z = center.z - 1;
	tps.w_p3.x = center.x + 2;
	tps.w_p3.y = center.y - 3;
	tps.w_p3.z = center.z + 4;
	return (tps);
}

// t_triangle	*set_triangel_points(t_triangle *p_triangle,
// t_point p1, t_point p2, t_point p3)
// {
// 	p_triangle->p1 = p1;

// }

// t_point	get_poit_sphere(t_vector v, t_point p, float r)
// {
// 	t_point p_;
// 	float f;

// 	p_.x = v.dir.x * (p_.y / v.dir.y);

// 	p_.x
// }

// void	fdf_draw_image(t_vars *vars)
// {
// 	mlx_destroy_image (vars->mlx, vars->img.img);
// 	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
// 	vars->img.addr = mlx_get_data_addr (vars->img.img, &vars->img.bpp,
// 			&vars->img.line_len, &vars->img.endian);
// 	vars->img.size = HEIGHT * vars->img.line_len;
// 	fdf_draw (vars);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
// 	print_statuses (vars);
// }

// void	print_statuses(t_vars *vars)
// {
// 	mlx_string_put(vars->mlx, vars->win, 25, 25, 0X88888888,
// 		"This is an isometric projection");
// }
