/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:23:41 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/09 01:05:16 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_utils.h"
#include "ksx_vec3_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"
#include "ksx_rotation.h"
#include <math.h>
#include <stdio.h>

// void	ksx_draw(t_vars *vars);
// static void	ksx_draw_zord(t_vars *vars);
// static void	fdf_lines(t_vars *vars, int idx_xy[]);

void	ksx_draw(t_graphics *p_grph)
{
	t_object	**pp_object;
	t_object	*p_object;
	uint32_t	idx[2];
	t_pixel		pixel;
	t_pixel		pixel2;
	t_pixel		pixel3;
	t_vector4	vec4;

	if (!p_grph->world.pp_wobj)
		return ;
	mlx_delete_image(p_grph->mlx, p_grph->img);
	p_grph->img = ksx_create_image(p_grph->mlx);
	mlx_image_to_window(p_grph->mlx, p_grph->img, 0, 0);
	pixel.color.mlx_color = 0xffffffff;
	pixel.x= 25;
	pixel.y= 25;
	pixel2.color.mlx_color = 0xff0000ff;
	pixel2.x= WIDTH - 25;
	pixel2.y= 25;
	ksx_line (p_grph->img, pixel, pixel2);
	
	
	idx[0] = 0;
	pp_object = p_grph->world.pp_wobj;
	while (idx[0] < p_grph->world.size_wobj)
	{
		p_object = pp_object[idx[0]];
		// if(idx[0] == 0)
		ksx_rotation_obj_y(p_object, p_object->angle.y + 1);
		// else
		// 	ksx_rotation_obj(p_object, 0.f, 115.f, 135.f);
		// ksx_rotation_obj_x(p_object, 45.f);
		ksx_translate_tri(&p_object->axis, p_object->center);

		pixel.color.mlx_color = 0xffffffff;
		pixel2.color.mlx_color = 0xffffffff;
		pixel3.color.mlx_color = 0xffffffff;
		idx[1] = 0;
		while (idx[1] < p_object->size_otri)
		{
			ksx_translate_tri(p_object->pp_otri[idx[1]], p_object->center);
			// p_grph->camera
			// vec4.x = p_object->pp_otri[idx[1]]->w_p1.x;
			// vec4.y = p_object->pp_otri[idx[1]]->w_p1.y;
			// vec4.z = p_object->pp_otri[idx[1]]->w_p1.z;
			// vec4.w = 1;
			vec4 = ksx_vec3_vec4(p_object->pp_otri[idx[1]]->w_p1, 1);
			vec4 = ksx_m4_vec4(&p_grph->camera.pm, &vec4);
			// printf("w_p1: (%f, %f, %f); vec4: (%f, %f, %f, %f);\n",
			// 	p_obj->pp_otri[idx[1]]->w_p1.x,
			// 	p_obj->pp_otri[idx[1]]->w_p1.y,
			// 	p_obj->pp_otri[idx[1]]->w_p1.z,
			// 	vec4.x, vec4.y, vec4.z, vec4.w);
			pixel.x = round(vec4.x) + WIDTH / 2.f;
			pixel.y = round(vec4.y) + HEIGHT / 2.f;
			ksx_set_pixel(p_grph->img, pixel);

			// vec4.x = p_object->pp_otri[idx[1]]->w_p2.x;
			// vec4.y = p_object->pp_otri[idx[1]]->w_p2.y;
			// vec4.z = p_object->pp_otri[idx[1]]->w_p2.z;
			// vec4.w = 1;
			vec4 = ksx_vec3_vec4(p_object->pp_otri[idx[1]]->w_p2, 1);
			vec4 = ksx_m4_vec4(&p_grph->camera.pm, &vec4);
			pixel2.x = roundf(vec4.x) + WIDTH / 2;
			pixel2.y = roundf(vec4.y) + HEIGHT / 2;
			ksx_set_pixel(p_grph->img, pixel);

			// vec4.x = p_object->pp_otri[idx[1]]->w_p3.x;
			// vec4.y = p_object->pp_otri[idx[1]]->w_p3.y;
			// vec4.z = p_object->pp_otri[idx[1]]->w_p3.z;
			// vec4.w = 1;
			vec4 = ksx_vec3_vec4(p_object->pp_otri[idx[1]]->w_p3, 1);
			vec4 = ksx_m4_vec4(&p_grph->camera.pm, &vec4);
			pixel3.x = roundf(vec4.x) + WIDTH / 2;
			pixel3.y = roundf(vec4.y) + HEIGHT / 2;
			ksx_set_pixel(p_grph->img, pixel);
			ksx_line(p_grph->img, pixel, pixel2);
			ksx_line(p_grph->img, pixel, pixel3);
			ksx_line(p_grph->img, pixel3, pixel2);
			ksx_draw_axis(p_object, p_grph->img, &p_grph->camera);
			// // p_obj->pp_otri[idx[1]]->c_p1 =
			// // 	ksx_point_m4(p_obj->pp_otri[idx[1]]->w_p1, p_grph->camera.pm);
			// printf("w_p1: (%f, %f, %f); vec4: (%f, %f, %f);\n",
			// 	p_obj->pp_otri[idx[1]]->w_p1.x,
			// 	p_obj->pp_otri[idx[1]]->w_p1.y,
			// 	p_obj->pp_otri[idx[1]]->w_p1.z,
			// 	vec4.x,
			// 	vec4.y,
			// 	vec4.z);
			// 	// p_obj->pp_otri[idx[1]]->c_p1.x,
			// 	// p_obj->pp_otri[idx[1]]->c_p1.x,
			// 	// p_obj->pp_otri[idx[1]]->c_p1.x);
			// p_obj->pp_otri[idx[1]]->c_p2 =
			// 	ksx_point_m4(p_obj->pp_otri[idx[1]]->w_p2, p_grph->camera.pm);
			// printf("w_p2: (%f, %f, %f); c_p2: (%f, %f, %f);\n",
			// 	p_obj->pp_otri[idx[1]]->w_p2.x,
			// 	p_obj->pp_otri[idx[1]]->w_p2.y,
			// 	p_obj->pp_otri[idx[1]]->w_p2.z,
			// 	p_obj->pp_otri[idx[1]]->c_p2.x,
			// 	p_obj->pp_otri[idx[1]]->c_p2.x,
			// 	p_obj->pp_otri[idx[1]]->c_p2.x);
			// p_obj->pp_otri[idx[1]]->c_p3 =
			// 	ksx_point_m4(p_obj->pp_otri[idx[1]]->w_p3, p_grph->camera.pm);
			// printf("w_p3: (%f, %f, %f); c_p3: (%f, %f, %f);\n",
			// 	p_obj->pp_otri[idx[1]]->w_p3.x,
			// 	p_obj->pp_otri[idx[1]]->w_p3.y,
			// 	p_obj->pp_otri[idx[1]]->w_p3.z,
			// 	p_obj->pp_otri[idx[1]]->c_p3.x,
			// 	p_obj->pp_otri[idx[1]]->c_p3.x,
			// 	p_obj->pp_otri[idx[1]]->c_p3.x);			
			// pixel.x = roundf(p_obj->pp_otri[idx[1]]->w_p1.x) + WIDTH / 2;
			// pixel.y = roundf(p_obj->pp_otri[idx[1]]->w_p1.y) + HEIGHT / 2;
			// printf("pixel: (%lu, %lu);\n", pixel.x, pixel.y);
			// ksx_set_pixel(p_grph->img, pixel);
			// pixel.x = roundf(p_obj->pp_otri[idx[1]]->w_p2.x) + WIDTH / 2;
			// pixel.y = roundf(p_obj->pp_otri[idx[1]]->w_p2.y) + HEIGHT / 2;
			// printf("pixel: (%lu, %lu);\n", pixel.x, pixel.y);
			// ksx_set_pixel(p_grph->img, pixel);
			// pixel.x = roundf(p_obj->pp_otri[idx[1]]->w_p3.x) + WIDTH / 2;
			// pixel.y = roundf(p_obj->pp_otri[idx[1]]->w_p3.y) + HEIGHT / 2;
			// printf("pixel: (%lu, %lu);\n", pixel.x, pixel.y);
			// ksx_set_pixel(p_grph->img, pixel);
			idx[1]++;
		}
		idx[0]++;
	}
}

	// point[0] = ksx_point_m4(point[0], p_grph->camera.pm);
	// point[1] = ksx_point_m4(point[1], p_grph->camera.pm);
	// point[2] = ksx_point_m4(point[2], p_grph->camera.pm);

// void	ksx_draw(t_vars *vars)
// {
// 	int	idx_xy[2];

// 	idx_xy[1] = 0;
// 	while (idx_xy[1] < vars->xy[1])
// 	{
// 		idx_xy[0] = 0;
// 		while (idx_xy[0] < vars->xy[0])
// 		{
// 			// fdf_lines (vars, idx_xy);
// 			idx_xy[0]++;
// 		}
// 		idx_xy[1]++;
// 	}
// }

// static void	ksx_draw_zord(t_vars *vars)
// {
// 	int	idx_xy[2];
// 	int	mm[6];

// 	fdf_min_nax (vars->fdf, vars->xy, mm);
// 	while (mm[4] <= mm[5])
// 	{
// 		idx_xy[1] = 0;
// 		while (idx_xy[1] < vars->xy[1])
// 		{
// 			idx_xy[0] = 0;
// 			while (idx_xy[0] < vars->xy[0])
// 			{
// 				if (round (vars->fdf[idx_xy[0]][idx_xy[1]]->xyz_p[2]) == mm[4])
// 					fdf_lines (vars, idx_xy);
// 				idx_xy[0]++;
// 			}
// 			idx_xy[1]++;
// 		}
// 		mm[4]++;
// 	}
// }

// static void	ksx_lines(t_vars *vars, int idx_xy[])
// {
// 	t_fdf	*fdf;

// 	fdf = vars->fdf[idx_xy[0]][idx_xy[1]];
// 	fdf_point (vars->img, get_point (fdf, vars->as_xyz, vars->flags));
// 	if (idx_xy[0] < vars->xy[0] - 1)
// 		fdf_line (vars->img, get_point (fdf, vars->as_xyz, vars->flags),
// 			get_point (vars->fdf[idx_xy[0] + 1][idx_xy[1]],
// 				vars->as_xyz, vars->flags));
// 	if (idx_xy[1] < vars->xy[1] - 1)
// 		fdf_line (vars->img, get_point (fdf, vars->as_xyz, vars->flags),
// 			get_point (vars->fdf[idx_xy[0]][idx_xy[1] + 1],
// 				vars->as_xyz, vars->flags));
// }
