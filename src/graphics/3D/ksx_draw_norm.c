/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_draw_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:38:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 21:31:37 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_3D.h"
#include "ksx_object.h"
#include <math.h>
#include <stdio.h>

static t_vector3	ksx_draw_norms_1(t_object *p_object, uint32_t idx);
static t_vector3	ksx_draw_norms_2(t_object *p_object, uint32_t idx);
static t_vector3	ksx_draw_norms_3(t_object *p_object, uint32_t idx);

void	ksx_draw_norms(t_object *p_object,
		mlx_image_t *p_image, t_camera *p_camera)
{
	uint32_t	idx;
	t_pixel		pixel[2];
	t_vector3	v3;

	idx = 0;
	while (idx < p_object->size_tri)
	{
		pixel[0] = ksx_draw_get_pixel(p_camera,
				&p_object->pp_tri[idx]->p_ver1->cp, PIXEL_RED);
		v3 = ksx_draw_norms_1(p_object, idx);
		pixel[1] = ksx_draw_get_pixel(p_camera, &v3, BACKGROUND);
		ksx_line(p_image, &pixel[0], &pixel[1]);
		pixel[0] = ksx_draw_get_pixel(p_camera,
				&p_object->pp_tri[idx]->p_ver2->cp, PIXEL_RED);
		v3 = ksx_draw_norms_2(p_object, idx);
		pixel[1] = ksx_draw_get_pixel(p_camera, &v3, BACKGROUND);
		ksx_line(p_image, &pixel[0], &pixel[1]);
		pixel[0] = ksx_draw_get_pixel(p_camera,
				&p_object->pp_tri[idx]->p_ver3->cp, PIXEL_RED);
		v3 = ksx_draw_norms_3(p_object, idx);
		pixel[1] = ksx_draw_get_pixel(p_camera, &v3, BACKGROUND);
		ksx_line(p_image, &pixel[0], &pixel[1]);
		idx++;
	}
}

static t_vector3	ksx_draw_norms_1(t_object *p_object, uint32_t idx)
{
	t_vector3	v3;

	v3 = p_object->pp_tri[idx]->p_norm1->lp;
	ksx_vec3_resize(&v3, NORM_LEN);
	v3 = ksx_vec3_add(&p_object->pp_tri[idx]->p_ver1->cp, &v3);
	return (v3);
}

static t_vector3	ksx_draw_norms_2(t_object *p_object, uint32_t idx)
{
	t_vector3	v3;

	v3 = p_object->pp_tri[idx]->p_norm2->lp;
	ksx_vec3_resize(&v3, NORM_LEN);
	v3 = ksx_vec3_add(&p_object->pp_tri[idx]->p_ver2->cp, &v3);
	return (v3);
}

static t_vector3	ksx_draw_norms_3(t_object *p_object, uint32_t idx)
{
	t_vector3	v3;

	v3 = p_object->pp_tri[idx]->p_norm3->lp;
	ksx_vec3_resize(&v3, NORM_LEN);
	v3 = ksx_vec3_add(&p_object->pp_tri[idx]->p_ver3->cp, &v3);
	return (v3);
}
