/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:57:57 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/22 11:36:38 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_GRAPHICS_H
# define KSX_GRAPHICS_H

# include "MLX42.h"
# include <stdint.h>

# define PM_DEBUG	1
# define AXIS_LEN 	100
# define FAR	 	1000

// # define WIDTH 1920
// # define HEIGHT 1044
# define WIDTH 1000
# define HEIGHT 750

# define KSX_TRUE 1
# define KSX_FALSE 0

// # define PI 3.141592653589793115997963468544185161590576171875

// PI / 180.f
# define PI180 0.01745329251f
// # define PI180 0.017453292519943

# define PRECISION	0.00001f
/* Only support RGBA */
# define BPP 4

// Size if color structure 3 for RGB, 4 for RGBA
# define COLOR_SIZE 3

// Indexes of color in colot structure
# define R 0
# define G 1
# define B 2
# define A 3

// Indexes of coordinate in xyz structure
# define X 0
# define Y 1
# define Z 2
# define O 3

// FLAGS
# define CHANGE		0b00000001
# define DRAW_BOX	0b00000100
# define DRAW_AXIS	0b00001000
# define DRAW_LINE	0b00010000
# define DRAW_OBJ	0b00100000

// # define RORATE_X 0b00000100
// # define RORATE_Y 0b00001000
// # define RORATE_Z 0b00010000
// # define CHANGE_CENTER 0x00010000

# define EDGE_SIZE	10.f
// Sphere generation
# define SPHERE_GEN 3
// Cylinder step angle
# define CYLINDER_ANGLE 18.f

# define ANGLE 2.5f
# define STEP 5.f
# define SCALE .05f
# define MIN_AXIS .051f
# define MAX_AXIS 5.f

// Data type for colors, 32 bites: 8 - alfa, 8 - blue, 8 - green, 8 - red
typedef struct s_color
{
	union
	{
		struct
		{
			uint8_t	r;
			uint8_t	g;
			uint8_t	b;
			uint8_t	a;			
		};
		uint8_t		rgba[4];
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
	// union
	// {
	// 	struct
	// 	{
	// 		float	start_x;
	// 		float	start_y;
	// 		float	start_z;
	// 	};
	// 	float	start_xyz[3];
	// };
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
	// union
	// {
	// 	struct
	// 	{
	// 		float	start_x;
	// 		float	start_y;
	// 		float	start_z;
	// 		float	start_w;
	// 	};
	// 	float	start_xyzw[4];
	// };
}	t_vector4;

typedef struct s_basis
{
	union
	{
		struct
		{
			t_vector3	i;
			t_vector3	j;
			t_vector3	k;
		};
		t_vector3	ijk[3];
	};
	union
	{
		struct
		{
			t_vector3	w_i;
			t_vector3	w_j;
			t_vector3	w_k;
		};
		t_vector3	w_ijk[3];
	};
	union
	{
		struct
		{
			t_vector3	c_i;
			t_vector3	c_j;
			t_vector3	c_k;
		};
		t_vector3	c_ijk[3];
	};
	// uint8_t		set;
	t_vector3	o;
	t_vector3	w_o;
	t_vector3	c_o;
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
	// t_vector3	center;
	// t_vector3	move;
	// t_vector3	norm;
	t_basis		basis;
	float		fov;
	float		hfov;
	float		aspect;
	// float		vfov;
	uint8_t		flags;
	t_matrix4	vm;
	t_matrix4	ivm;
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

typedef struct s_vertex
{
	t_vector3	p;
	t_vector3	wp;
	t_vector3	cp;
	t_vector3	norm;
}	t_vertex;

typedef struct s_triangle
{
	union
	{
		struct
		{
			t_vertex	*p_ver1;
			t_vertex	*p_ver2;
			t_vertex	*p_ver3;
		};
		t_vertex	*p_ver[3];
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
	t_vector3	norm;
	t_color		color;
	// uint32_t	generation;
}	t_triangle;

typedef struct s_object
{
	uint8_t		flags;
	t_color		color;
	float		size1;
	float		size2;
	float		edge;
	t_basis		basis;
	t_vertex	w_axis[4];
	t_vertex	box_ver_origin[8];
	t_vertex	box_ver[8];
	t_triangle	box[12];
	t_vertex	**pp_vrtx_origin;
	t_vertex	**pp_vrtx;
	uint32_t	size_vrtx;
	t_triangle	**pp_tri;
	uint32_t	size_tri;
	// void		(*f_transform)(void *, t_basis *);
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
	uint32_t	obj_idx;
	void		(*f_gc)(void *);
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
				uint32_t diameter, t_color color, uint8_t gen);
t_object	*ksx_create_cylinder(t_vector3 center, t_vector3 norm,
				float dia_ht[], t_color color);
void		ksx_draw(t_graphics *p_grph);

// garbage_collector
void		ksx_garbage_collector(t_graphics *p_grph);
void		ksx_error(char *error, char *file_name, int str_num);

#endif	// KSX_GRAPHICS_H //
