/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_scroll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/24 11:57:55 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"

// ksx_camera_set_pm(&p_grph->camera, p_grph->camera.fov + 1, FAR);
void	scroll_zoom_in(t_graphics *p_grph)
{
	ksx_vec3_resize(&p_grph->camera.basis.i,
		ksx_vec3_mag(&p_grph->camera.basis.i) + SCALE);
	ksx_vec3_resize(&p_grph->camera.basis.j,
		ksx_vec3_mag(&p_grph->camera.basis.j) + SCALE);
	ksx_vec3_resize(&p_grph->camera.basis.k,
		ksx_vec3_mag(&p_grph->camera.basis.k) + SCALE);
	// if (ksx_vec3_mag(&p_grph->camera.basis.i) > MAX_AXIS)
	// 	ksx_vec3_resize(&p_grph->camera.basis.i, MAX_AXIS);
	// if (ksx_vec3_mag(&p_grph->camera.basis.j) > MAX_AXIS)
	// 	ksx_vec3_resize(&p_grph->camera.basis.j, MAX_AXIS);
	// if (ksx_vec3_mag(&p_grph->camera.basis.k) > MAX_AXIS)
	// 	ksx_vec3_resize(&p_grph->camera.basis.k, MAX_AXIS);
	p_grph->camera.flags |= CHANGE;
}

// ksx_camera_set_pm(&p_grph->camera, p_grph->camera.fov - 1, FAR);
void	scroll_zoom_out(t_graphics *p_grph)
{
	ksx_vec3_resize(&p_grph->camera.basis.i,
		ksx_vec3_mag(&p_grph->camera.basis.i) - SCALE);
	ksx_vec3_resize(&p_grph->camera.basis.j,
		ksx_vec3_mag(&p_grph->camera.basis.j) - SCALE);
	ksx_vec3_resize(&p_grph->camera.basis.k,
		ksx_vec3_mag(&p_grph->camera.basis.k) - SCALE);
	if (ksx_vec3_mag(&p_grph->camera.basis.i) < MIN_AXIS)
		ksx_vec3_resize(&p_grph->camera.basis.i, MIN_AXIS);
	if (ksx_vec3_mag(&p_grph->camera.basis.j) < MIN_AXIS)
		ksx_vec3_resize(&p_grph->camera.basis.j, MIN_AXIS);
	if (ksx_vec3_mag(&p_grph->camera.basis.k) < MIN_AXIS)
		ksx_vec3_resize(&p_grph->camera.basis.k, MIN_AXIS);
	p_grph->camera.flags |= CHANGE;
}
