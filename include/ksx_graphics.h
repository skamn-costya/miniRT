/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:57:57 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/31 09:43:42 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_GRAPHICS_H
# define KSX_GRAPHICS_H

# define KSX_TRUE 1
# define KSX_FALSE 0

# define PI 3.14159265358979323846
# define PRECISION	0.0001f

// Size if color structure 3 for RGB, 4 for ARGB
# define COLOR_SIZE 3

// Indexes of color in argb structure
# define A 0
# define R 1
# define G 2
# define B 3

// Indexes of coordinate in xyz structure
# define X 0
# define Y 1
# define Z 2

// Data type for colors, 32 bites: 8 - alfa, 8 - red, 8 - green, 8 - blue
typedef struct s_argb
{
	union
	{
		struct
		{
			unsigned char	a;
			unsigned char	r;
			unsigned char	g;
			unsigned char	b;
		};
		unsigned char	argb[4];
	};
}	t_argb;

typedef struct s_pixel
{
	union
	{
		struct
		{
			int	x;
			int	y;
		};
		int	xy[2];
	};
	t_argb	color;
}	t_pixel;

typedef struct s_point
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
}	t_point;

typedef struct s_vector
{
	t_point	start;
	t_point	dir;
}	t_vector;

typedef struct s_matrix2
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

typedef struct s_matrix3
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

typedef struct s_matrix4
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

typedef struct s_triangle
{
	union
	{
		struct
		{
			t_point	p1;
			t_point	p2;
			t_point	p3;
		};
		t_point	points[3];
	};
	union
	{
		struct
		{
			t_point	g_p1;
			t_point	g_p2;
			t_point	g_p3;
		};
		t_point	g_points[3];
	};
	t_argb		color;
	t_vector	norm;
	int			generation;

}	t_triangle;

// # include "ksx_camera.h"
// # include "mlx.h"

// // Vector3D
// typedef struct s_vec3f
// {
// 	float	x;
// 	float	y;
// 	float	z;
// }	t_vec3f;

// typedef struct s_rgb
// {
// 	unsigned char	r;
// 	unsigned char	g;
// 	unsigned char	b;
// }	t_rgb;

// // Ambient lightning
// typedef struct s_ambient
// {
// 	// ambient lighting ratio in range [0.0,1.0]
// 	float	ratio;
// 	// R,G,B colors in range [0-255]
// 	t_rgb	color;
// }	t_ambient;

// // Camera
// typedef struct s_camera
// {
// 	// x,y,z coordinates of the view point
// 	t_vec3f			view_point;
// 	// 3d normalized orientation vector. In range [-1,1] for each x,y,z axis
// 	t_vec3f			normal;
// 	// Horizontal field of view in degrees in range [0,180]
// 	unsigned char	fov;
// }	t_camera;

// // Light
// typedef struct s_light
// {
// 	// x,y,z coordinates of the light point
// 	t_vec3f	view_point;
// 	// the light brightness ratio in range
// 	float	ratio;
// 	// (unused in mandatory part)R,G,B colors in range [0-255]
// 	t_rgb	color;
// }	t_light;

// // Sphere
// typedef struct s_sphere
// {
// 	// x,y,z coordinates of the sphere center
// 	t_vec3f	centre;
// 	// the sphere diameter
// 	float	diameter;
// 	// R,G,B colors in range [0-255]
// 	t_rgb	color;
// }	t_sphere;

// // Plane
// typedef struct s_plane
// {
// 	// x,y,z coordinates of a point in the plane
// 	t_vec3f	point;
// 	// 3d normalized normal vector. In range [-1,1] for each x,y,z axis
// 	t_vec3f	normal;
// 	// R,G,B colors in range [0-255]
// 	t_rgb	color;
// }	t_plane;

// // Cylinder
// typedef struct s_cylinder
// {
// 	// x,y,z coordinates of the center of the cylinder
// 	t_vec3f	centre;
// 	// 3d normalized vector of axis of cylinder.
// 	// In range [-1,1] for each x,y,z axis
// 	t_vec3f	normal;
// 	// the cylinder diameter
// 	float	diameter;
// 	// the cylinder height
// 	float	height;
// 	// R,G,B colors in range [0-255]
// 	t_rgb	color;
// }	t_cylinder;

// typedef struct s_vars
// {
// 	void			*mlx;
// 	void			*win;
// 	// t_img			img;
// 	int				xy[2];
// 	int				as_xyz[7];
// 	float			zoom;
// 	unsigned char	flags;
// 	t_cammtrx		cm;
// }	t_vars;

// // init.c
// void	init(t_vars *vars);
// int		close_x(t_vars *vars);

// // fdf_hook.c
// int		key_hook(int keycode, t_vars *vars);
// void	set_flag(t_vars *vars, unsigned char flag);

// // fdf_utils.c
// void	fdf_draw_image(t_vars *vars);
// float	fraction(t_point p, t_point p1, t_point p2);

// // fdf_prep_p.c
// void	ksx_prep(t_vars *vars);

// // fdf_<obj>.c
// // t_point	get_point(t_fdf *fdf, int as_xyz[]);
// t_point	get_point(int xyz[], unsigned char flags);
// // void	fdf_point(t_img img, t_point float	elem_11;point);
// // void	fdf_line(t_img	img, t_point point1, t_point point2);

// // fdf_draw.c
// void	fdf_draw(t_vars *vars);
// // void	fdf_move_x(t_vars *vars, int d);
// // void	fdf_move_y(t_vars *vars, int d);
// void	print_statuses(t_vars *vars);

// // fdf_zoom.c
// void	fdf_zoom(t_vars *vars, int d);
// void	fdf_zoom_p(t_vars *vars);
// void	fdf_zoom_c(t_vars *vars);

// // void	fdf_min_nax(t_fdf ***fdf, int xy[], int mm[]);

// // // fdf_rotation.c
// // void	fdf_rotation(t_fdf ***fdf, int xy[], int a[]);

// // // fdf_rotation_x.c
// // void	rotation_x(t_fdf ***fdf, int xy[], float a);
// // void	rotation_x_p(t_fdf *fdf, float a);
// // void	rotation_x_c(t_fdf *fdf, float a);

// // // fdf_rotation_y.c
// // void	rotation_y(t_fdf ***fdf, int xy[], float a);
// // void	rotation_y_p(t_fdf *fdf, float a);
// // void	rotation_y_c(t_fdf *fdf, float a);

// // // fdf_rotation_z.c
// // void	rotation_z(t_fdf ***fdf, int xy[], float a);
// // void	rotation_z_p(t_fdf *fdf, float a);
// // void	rotation_z_c(t_fdf *fdf, float a);

#endif
