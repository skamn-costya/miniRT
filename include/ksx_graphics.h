/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:57:57 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/09 15:16:34 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_GRAPHICS_H
# define KSX_GRAPHICS_H

# include "MLX42.h"
# include <stdint.h>

// # define WIDTH 1920
// # define HEIGHT 1044
# define WIDTH 1000
# define HEIGHT 750

# define KSX_TRUE 1
# define KSX_FALSE 0

# define PI 3.14159265358979323846f
# define PRECISION	0.00001f
/* Only support RGBA */
# define BPP 4

// Size if color structure 3 for RGB, 4 for RGBA
# define COLOR_SIZE 3

// Indexes of color in colot structure
# define A 0
# define B 1
# define G 2
# define R 3

// Indexes of coordinate in xyz structure
# define X 0
# define Y 1
# define Z 2

// Data type for colors, 32 bites: 8 - alfa, 8 - blue, 8 - green, 8 - red
typedef struct s_color
{
	union
	{
		struct
		{
			uint8_t	a;
			uint8_t	b;
			uint8_t	g;
			uint8_t	r;
		};
		uint8_t		abgr[4];
		uint32_t	mlx_color;
	};
}	t_color;

typedef struct s_pixel
{
	union
	{
		struct
		{
			uint64_t	x;
			uint64_t	y;
		};
		uint64_t	xy[2];
	};
	t_color	color;
}	t_pixel;

typedef struct s_vector2
{
	union
	{
		struct
		{
			float	x;
			float	y;
		};
		float	xy[2];
	};
	union
	{
		struct
		{
			float	start_x;
			float	start_y;
		};
		float	start_xy[2];
	};
}	t_vector2;

typedef struct s_vector3
{
	union
	{
		struct
		{
			float	x;
			float	y;
			float	z;
		};
		float	xyz[3];
	};
	union
	{
		struct
		{
			float	start_x;
			float	start_y;
			float	start_z;
		};
		float	start_xyz[3];
	};
}	t_vector3;

typedef struct s_vector4
{
	union
	{
		struct
		{
			float	x;
			float	y;
			float	z;
			float	w;
		};
		float	xyzw[4];
	};
	union
	{
		struct
		{
			float	start_x;
			float	start_y;
			float	start_z;
			float	start_w;
		};
		float	start_xyzw[4];
	};
}	t_vector4;

typedef struct s_basis
{
	union
	{
		struct
		{
			t_vector3	x_;
			t_vector3	y_;
			t_vector3	z_;
		};
		t_vector3	x_y_z_[3];
	};
	uint8_t		set;
	t_vector3	o;
}	t_basis;

typedef struct s_matrix22
{
	union
	{
		struct
		{
			float	e_11;
			float	e_12;
			float	e_21;
			float	e_22;
		};
		float	elems[4];
	};
}	t_matrix2;

typedef struct s_matrix33
{
	union
	{
		struct
		{
			float	e_11;
			float	e_12;
			float	e_13;
			float	e_21;
			float	e_22;
			float	e_23;
			float	e_31;
			float	e_32;
			float	e_33;
		};
		float	elems[9];
	};
}	t_matrix3;

typedef struct s_matrix44
{
	union
	{
		struct
		{
			float	e_11;
			float	e_12;
			float	e_13;
			float	e_14;
			float	e_21;
			float	e_22;
			float	e_23;
			float	e_24;
			float	e_31;
			float	e_32;
			float	e_33;
			float	e_34;
			float	e_41;
			float	e_42;
			float	e_43;
			float	e_44;
		};
		float	elems[16];
	};
}	t_matrix4;

typedef struct s_camera
{
	t_vector3	center;
	t_vector3	norm;
	t_basis		basis;
	float		fov;
	float		hfov;
	float		aspect;
	// float		vfov;
	t_matrix4	vm;
	t_matrix4	pm;
	// float		focal_len;
	union
	{
		float	near;
		float	n;
	};
	union
	{
		float	far;
		float	f;
	};
	union
	{
		float	left;
		float	l;
	};
	union
	{
		float	right;
		float	r;
	};
	union
	{
		float	top;
		float	t;
	};
	union
	{
		float	bottom;
		float	b;
	};
}	t_camera;

typedef struct s_triangle
{
	union
	{
		struct
		{
			t_vector3	p1;
			t_vector3	p2;
			t_vector3	p3;
		};
		t_vector3	points[3];
	};
	union
	{
		struct
		{
			t_vector3	w_p1;
			t_vector3	w_p2;
			t_vector3	w_p3;
		};
		t_vector3	w_points[3];
	};
	union
	{
		struct
		{
			t_vector3	c_p1;
			t_vector3	c_p2;
			t_vector3	c_p3;
		};
		t_vector3	c_points[3];
	};
	union
	{
		struct
		{
			t_vector3	norm1;
			t_vector3	norm2;
			t_vector3	norm3;
		};
		t_vector3	norms[3];
	};
	t_color		color;
	uint32_t	generation;
}	t_triangle;

typedef struct s_object
{
	t_vector3 	center;
	float	 	radius;
	t_vector3	angle;
	t_vector3 	c_center;
	t_basis		basis;
	t_triangle	axis;
	t_matrix4 	w_vm;
	t_triangle	**pp_otri;
	uint32_t	size_otri;
	uint32_t	last_gen;
}	t_object;

typedef struct s_world
{
	t_triangle	*p_tris;
	t_object	**pp_wobj;
	uint32_t	size_wobj;
}	t_world;

typedef struct s_graphics
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_world		world;
	t_camera	camera;
}	t_graphics;

mlx_t		*ksx_init(void);
int			ksx_prep(void *p_vars);
t_pixel		ksx_get_pixel(mlx_image_t *p_img, uint32_t x, uint32_t y);
void		ksx_set_pixel(mlx_image_t *p_img, t_pixel *p_pix);

void		ksx_line(mlx_image_t *img, t_pixel pix1, t_pixel pix2);
void		ksx_circle(mlx_image_t *img, t_pixel center, uint32_t radius);

t_object	**ksx_obj2world(t_object *p_object, t_world *p_world);
void		ksx_clean_world(t_world *p_world);

t_object	*ksx_create_sphere(t_vector3 center,
				uint32_t diameter, t_color color);
t_object	*ksx_create_cylinder(t_vector3 center, t_vector3 norm,
				float dia_ht[], t_color color);
void		ksx_draw(t_graphics *p_grph);

#endif	// KSX_GRAPHICS_H //
