/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:05:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/05 21:34:33 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "ksx_graphics.h"

# define RETURN_ERR -1
# define TRUE 1
# define FALSE 0

typedef enum e_obj
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	HYPERBOLOID,
	PARABOLOID
}	t_obj_id;

/*
*	s_obj_descr:
*
*	Ambient lightning:	"A", ratio, rgb
*	Camera:				"C", coord, vector, fov
*	Light:				"L", coord, ratio, rgb
*	Sphere:				"sp", coord, d, rgb
*	Plane:				"pl", coord, vector,rgb
*	Cylinder:			"cy", coord, vector, d, h, rgb
*
*	ratio	lighting ratio in range [0.0,1.0]
*	rgb		r, g, b colors in range [0-255]
*	coord	x, y, z coordinates
*	vector	normalized orientation vector, in range [-1,1] for each x,y,z axis
*	fov		horizontal field of view in degrees in range [0,180]
*	d		the sphere & the cylinder diameter
*	h		the cylinder height
*/
typedef struct s_obj_descr
{
	t_obj_id	id;
	float		ratio;
	t_color		color;
	t_vector3	coord;
	t_vector3	norm;
	float		fov;
	float		d;
	float		h;
	char		*texture;
}	t_obj_descr;

#endif	// MINIRT_H

// sudo apt updatesudo apt update
// sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
