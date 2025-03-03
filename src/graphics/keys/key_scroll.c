/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_scroll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:33 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/03 21:34:41 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ksx_camera.h"
#include "ksx_object.h"
#include "ksx_vec3_math.h"
#include "ksx_vec4_math.h"
#include "ksx_m4_math.h"
#include "ksx_basis.h"

void	scroll_zoom_out(t_graphics *p_grph)
{
	p_grph->camera.flags |= CHANGE;
	if (p_grph->camera.flags & CAM_PM)
		return (ksx_camera_set_pm2(&p_grph->camera, p_grph->camera.fov + 1));
	ksx_vec3_resize(&p_grph->camera.basis.i,
		ksx_vec3_mag(&p_grph->camera.basis.i) + SCALE);
	ksx_vec3_resize(&p_grph->camera.basis.j,
		ksx_vec3_mag(&p_grph->camera.basis.j) + SCALE);
	ksx_vec3_resize(&p_grph->camera.basis.k,
		ksx_vec3_mag(&p_grph->camera.basis.k) + SCALE);
}

void	scroll_zoom_in(t_graphics *p_grph)
{
	p_grph->camera.flags |= CHANGE;
	if (p_grph->camera.flags & CAM_PM)
		return (ksx_camera_set_pm2(&p_grph->camera, p_grph->camera.fov - 1));
	ksx_vec3_resize(&p_grph->camera.basis.i,
		ksx_vec3_mag(&p_grph->camera.basis.i) - SCALE);
	ksx_vec3_resize(&p_grph->camera.basis.j,
		ksx_vec3_mag(&p_grph->camera.basis.j) - SCALE);
	ksx_vec3_resize(&p_grph->camera.basis.k,
		ksx_vec3_mag(&p_grph->camera.basis.k) - SCALE);
	if (!ksx_basis_check(&p_grph->camera.basis, X))
		ksx_vec3_resize(&p_grph->camera.basis.i, MIN_AXIS);
	if (!ksx_basis_check(&p_grph->camera.basis, Y))
		ksx_vec3_resize(&p_grph->camera.basis.j, MIN_AXIS);
	if (!ksx_basis_check(&p_grph->camera.basis, Z))
		ksx_vec3_resize(&p_grph->camera.basis.k, MIN_AXIS);
	// if (ksx_vec3_mag(&p_grph->camera.basis.i) < MIN_AXIS)
	// 	ksx_vec3_resize(&p_grph->camera.basis.i, MIN_AXIS);
	// if (ksx_vec3_mag(&p_grph->camera.basis.j) < MIN_AXIS)
	// 	ksx_vec3_resize(&p_grph->camera.basis.j, MIN_AXIS);
	// if (ksx_vec3_mag(&p_grph->camera.basis.k) < MIN_AXIS)
	// 	ksx_vec3_resize(&p_grph->camera.basis.k, MIN_AXIS);
}
