/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:50:40 by username          #+#    #+#             */
/*   Updated: 2025/03/07 17:07:10 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "ksx_3D.h"
#include "ksx_utils.h"
#include "stdio.h"
#include "ksx_triangle.h"

void print_vertex(t_vertex ver)
{
	printf("[%f, %f, %f]\n", ver.cp.x, ver.cp.y, ver.cp.z);
}

void print_tri(t_triangle tri)
{
	print_vertex(*tri.p_ver1);
	print_vertex(*tri.p_ver2);
	print_vertex(*tri.p_ver3);
}

static void ray_scan_scene(t_ray *ray, t_graphics grph)
{
	uint32_t	i;
	int	j;

	i = 0;
	t_triangle	tri;
	t_triangle	tri2;
	t_vertex a;
	t_vertex b;
	t_vertex c;

	// Create custom triangle over whole screen
	//float distance = 10;
	a.cp = ksx_vec3_set(0, 100, 1072);
	b.cp = ksx_vec3_set(-100, -100, 1072);
	c.cp = ksx_vec3_set(100, -100, 1072);
	ksx_tri_set_vertexes(&tri, &a, &b, &c);
	t_vertex d, e, f;
	d.cp = ksx_vec3_set(0, -200, 1072);
	e.cp = ksx_vec3_set(-150, -50, 1072);
	f.cp = ksx_vec3_set(50, -150, 1072);
	ksx_tri_set_vertexes(&tri2, &d, &e, &f);
	while (i < grph.world.size_box)
	{
		j = 0;
		while (grph.world.pp_box[i]->pp_tris[j])
		{
			//print_tri(*grph.world.pp_box[i]->pp_tris[j]);
			//printf("\n");
			//if (grph.world.pp_box[i]->pp_tris[j]->p_ver1->cp.z < 0)
			//	print_tri(*grph.world.pp_box[i]->pp_tris[j]);
			intersect_tri(ray, *grph.world.pp_box[i]->pp_tris[j]);
			j++;
		}
		i++;
	}
	//intersect_tri(ray, tri);
	// int random_tri = 50;
	//if (*grph.world.pp_box[0]->pp_tris[])
	//print_tri(*grph.world.pp_box[0]->pp_tris[0]);
	// intersect_tri(ray, *grph.world.pp_box[0]->pp_tris[random_tri]);
}

void	ray_cast(t_graphics *grph)
{
	float		x;
	float		y;
	t_ray		ray;
	t_vector3	pixelPos;
	float	sh = (float)HEIGHT;
	float	sw = (float)WIDTH;

	mlx_image_t *p_img = ksx_create_image(grph->mlx);
	// Canvas points
	float canvas_z = grph->camera.near;
	t_vector3 p0 = ksx_vec3_set(-sw /2, sh /2, canvas_z);
	t_vector3 p1 = ksx_vec3_set(sw / 2, sh / 2, canvas_z);
	t_vector3 p2 = ksx_vec3_set(-sw / 2, -sh / 2, canvas_z);
	printf("P0: [%f, %f, %f]\n", p0.x, p0.y, p0.z);
	printf("P1: [%f, %f, %f]\n", p1.x, p1.y, p1.z);
	printf("P2: [%f, %f, %f]\n", p2.x, p2.y, p2.z);
	
	ray.origin = grph->camera.basis.o; // Origin of ray = origin of camera
	printf("CAMERA ORIGIN: [%f, %f, %f]\n", ray.origin.x, ray.origin.y, ray.origin.z);
	y = 0;	
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			t_vector3	sub01 = ksx_vec3_sub(&p1, &p0);
			t_vector3	mult1 = ksx_vec3_smulti(&sub01, (x / (float)WIDTH));
			t_vector3	sub20 = ksx_vec3_sub(&p2, &p0);
			t_vector3	mult2 = ksx_vec3_smulti(&sub20, (y / (float)HEIGHT));
			pixelPos = ksx_vec3_add(&mult1, &mult2);
			pixelPos = ksx_vec3_add(&p0, &pixelPos);
			//printf("PIXPOS: [%f, %f, %f]\n", pixelPos.x, pixelPos.y, pixelPos.z);
			t_vector3	direction = ksx_vec3_sub(&pixelPos, &ray.origin);
			//printf("DIR: [%f, %f, %f]\n", direction.x, direction.y, direction.z);
			ray.direction = ksx_vec3_unit(&direction);
			printf("RAY DIR: [%f, %f, %f]\n", ray.direction.x, ray.direction.y, ray.direction.z);
			ray.length = 1e30f;
			ray_scan_scene(&ray, *grph);
			x++;
			if (ray.length >= 1e30f)
				continue ;
			t_pixel pix = ksx_draw_get_pixel(&grph->camera, &pixelPos, 0xFFFFFFFF);
			//printf("SETTING PIXEL: [%i, %i, %i]\n", (int)pix.x, (int)pix.y, pix.color.a);
			ksx_set_pixel(p_img, &pix);
		}
		y++;
	}
	printf("Finished\n");
	mlx_image_to_window(grph->mlx, p_img, 0, 0);
}
