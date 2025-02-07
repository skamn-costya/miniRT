/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_utils09.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:45 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/07 13:15:15 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "MLX42.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_3D.h"
#include "ksx_rotation.h"
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

t_triangle	**ksx_tri2obj(t_triangle *p_tri, t_object *p_object)
{
	t_triangle	**pp_tris;
	uint32_t	idx;

	pp_tris = (t_triangle **) malloc (sizeof(t_triangle *)
			* (p_object->size_otri + 1));
	if (!pp_tris)
		return (printf("Error: memory allocation failed!\n"), NULL);
	idx = 0;
	while (idx < p_object->size_otri)
	{
		pp_tris[idx] = p_object->pp_otri[idx];
		idx++;
	}
	pp_tris[idx] = p_tri;
	free(p_object->pp_otri);
	p_object->pp_otri = pp_tris;
	p_object->size_otri++;
	return (pp_tris);
}

t_triangle	**ksx_tris2obj(t_triangle *p_tris[],
			uint32_t size, t_object *p_object)
{
	t_triangle	**pp_tri;
	uint32_t	idx;

	if (!p_tris || !p_tris[0])
		return (p_object->pp_otri);
	pp_tri = NULL;
	idx = 0;
	while (idx < size)
	{
		pp_tri = ksx_tri2obj(p_tris[idx], p_object);
		idx++;
	}
	return (pp_tri);
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

t_object	*ksx_create_object(t_vector3 center)
{
	t_object	*p_object;

	p_object = (t_object *) malloc (sizeof(t_object));
	if (!p_object)
		return (printf("Error: memory allocation failed!\n"), NULL);
	p_object->center = center;
	p_object->c_center = center;
	p_object->pp_otri = NULL;
	p_object->size_otri = 0;
	p_object->last_gen = 0;
	p_object->basis = ksx_get_basis(ksx_vec3_set(0, 0, 0), center);
	// p_object->axis.p1 = ksx_vec3_add(center, ksx_vec3_set(AXIS_LEN, 0, 0));
	// p_object->axis.p2 = ksx_vec3_add(center, ksx_vec3_set(0, AXIS_LEN, 0));
	// p_object->axis.p3 = ksx_vec3_add(center, ksx_vec3_set(0, 0, AXIS_LEN));
	p_object->axis.p1 = ksx_vec3_set(AXIS_LEN, 0, 0);
	p_object->axis.p2 = ksx_vec3_set(0, AXIS_LEN, 0);
	p_object->axis.p3 = ksx_vec3_set(0, 0, AXIS_LEN);
	return (p_object);
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
