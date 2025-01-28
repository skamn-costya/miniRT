/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:05:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/27 23:55:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ksx_graphics.h"

# define RETURN_ERR -1
# define TRUE 1
# define FALSE 0

// # define WIDTH 1920
// # define HEIGHT 1044
# define WIDTH 800
# define HEIGHT 600

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
*	s_object:
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
typedef struct s_object
{
	t_obj_id	id;
	float		ratio;
	t_argb		argb;
	t_vector	coord;
	t_vector	vector;
	int			fov;
	float		d;
	float		h;
	char		*texture;
}	t_object;

// utils01.c
// void	ft_free_pp_obj(void **pp_obj);

#endif	// MINIRT_H