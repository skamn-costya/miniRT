/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:57:57 by ksorokol          #+#    #+#             */
/*   Updated: 2024/12/26 17:06:03 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_GRAPHICS_H
# define KSX_GRAPHICS_H

# include "ksx_camera.h"
# include "mlx.h"

# define WIDTH 1920
# define HEIGHT 1044
# define DRAW 1
# define NO_DRAW 0
# define D_STEP 150
# define SINGLE_COLOR 8
# define PI 3.14159265358979323846
# define A_X 35
# define A_Y 0
# define A_Z 45
# define Z_ORD 0b00000001
# define PERSPEC 0b00000010
# define CAMERA_A 90
# define CAMERA_Z 1

typedef struct s_ing
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		size;
}	t_img;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_fdf			***fdf;
	int				xy[2];
	int				as_xyz[7];
	float			zoom;
	unsigned char	flags;
	t_cammtrx		cm;
}	t_vars;

typedef struct s_point
{
	int				x;
	int				y;
	unsigned int	color;
}	t_point;

// init.c
void	init(t_vars *vars);
int		close_x(t_vars *vars);

// fdf_hook.c
int		key_hook(int keycode, t_vars *vars);
void	set_flag(t_vars *vars, unsigned char flag);

// fdf_utils.c
void	fdf_draw_image(t_vars *vars);
float	fraction(t_point p, t_point p1, t_point p2);

// fdf_prep_p.c
void	fdf_prep_p(t_vars *vars);

// fdf_<obj>.c
// t_point	get_point(t_fdf *fdf, int as_xyz[]);
t_point	get_point(t_fdf *fdf, int as_xyz[], unsigned char flags);
void	fdf_point(t_img img, t_point point);
void	fdf_line(t_img	img, t_point point1, t_point point2);

// fdf_draw.c
void	fdf_draw(t_vars *vars);
// void	fdf_move_x(t_vars *vars, int d);
// void	fdf_move_y(t_vars *vars, int d);
void	print_statuses(t_vars *vars);

// fdf_zoom.c
void	fdf_zoom(t_vars *vars, int d);
void	fdf_zoom_p(t_vars *vars);
void	fdf_zoom_c(t_vars *vars);

void	fdf_min_nax(t_fdf ***fdf, int xy[], int mm[]);

// fdf_rotation.c
void	fdf_rotation(t_fdf ***fdf, int xy[], int a[]);

// fdf_rotation_x.c
void	rotation_x(t_fdf ***fdf, int xy[], float a);
void	rotation_x_p(t_fdf *fdf, float a);
void	rotation_x_c(t_fdf *fdf, float a);

// fdf_rotation_y.c
void	rotation_y(t_fdf ***fdf, int xy[], float a);
void	rotation_y_p(t_fdf *fdf, float a);
void	rotation_y_c(t_fdf *fdf, float a);

// fdf_rotation_z.c
void	rotation_z(t_fdf ***fdf, int xy[], float a);
void	rotation_z_p(t_fdf *fdf, float a);
void	rotation_z_c(t_fdf *fdf, float a);

#endif