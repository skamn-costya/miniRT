/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:57:57 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/29 23:05:17 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_GRAPHICS_H
# define KSX_GRAPHICS_H

# define PI 3.14159265358979323846
# define PRECISION	0.0001f

// Indexes of color in s_argb structure
# define A 3
# define R 2
# define G 1
# define B 0

// Indexes of coordinate in xyz structure
# define X 0
# define Y 1
# define Z 2

// // Indexes of position in matrix structure s_matrix_f2
// # define M2_11 0
// # define M2_12 1
// # define M2_21 2
// # define M2_22 3

// // Indexes of position in matrix structure s_matrix_f3
// # define M3_11 0
// # define M3_12 1
// # define M3_13 2
// # define M3_21 3
// # define M3_22 4
// # define M3_23 5
// # define M3_31 6
// # define M3_32 7
// # define M3_33 8

// // Indexes of position in matrix structure s_matrix_f4
// # define M4_11 0
// # define M4_12 1
// # define M4_13 2
// # define M4_14 3
// # define M4_21 4
// # define M4_22 5
// # define M4_23 6
// # define M4_24 7
// # define M4_31 8
// # define M4_32 9
// # define M4_33 10
// # define M4_34 11
// # define M4_41 12
// # define M4_42 13
// # define M4_43 14
// # define M4_44 15

// Indexes of position in matrix structure s_matrix_fn
# define M_11 0
# define M_12 1
# define M_21 2
# define M_22 3
# define M_13 4
# define M_23 5
# define M_31 6
# define M_32 7
# define M_33 8
# define M_14 9
# define M_24 10
# define M_34 11
# define M_41 12
# define M_42 13
# define M_43 14
# define M_44 15

// Data type for colors, 32 bites: 8 - alfa, 8 - red, 8 - green, 8 - blue
typedef struct	s_argb
{
	unsigned char	argb[4];
}	t_argb;

typedef struct s_pixel
{
	long	xy[2];
	t_argb	color;
}	t_pixel;

typedef struct s_point
{
	float	xyz[3];
	t_argb	color;
}	t_point;

typedef struct s_vector
{
	float	xyz[3];
}	t_vector;

typedef struct s_matrix_f2
{
	float	e[4];
}	t_matrix_f2;

typedef struct s_matrix_f3
{
	float	e[9];
}	t_matrix_f3;

typedef struct s_matrix_f4
{
	float	e[16];
}	t_matrix_f4;

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
// // void	fdf_point(t_img img, t_point point);
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