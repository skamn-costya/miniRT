/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:57:57 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 17:01:49 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_GRAPHICS_H
# define KSX_GRAPHICS_H

# include "MLX42.h"
# include <stdint.h>

# define AXIS_LEN 	25.f
# define NORM_LEN 	15.f
# define UNIT	 	1.f
// # define FAR	 	750

// # define WIDTH 1920
// # define HEIGHT 1044
# define WIDTH 1000
# define HEIGHT 750

# define KSX_TRUE 1
# define KSX_FALSE 0

// # define PI 3.141592653589793115997963468544185161590576171875f
# define PI 3.1415926535897931f

// PI / 180.f
# define PI180 0.01745329251f
// # define PI180 0.017453292519943

# define PRECISION	0.00001f
# define EPSILON	1.19209e-07
// # define EPSILON	1e-6f

/* Only support RGBA */
# define BPP 4
# define TRANSPARENT	0x00000000
# define BACKGROUND		0xFF000000
# define TRI_COLOR		0xFFFFFFFF
// # define OBJ_COLOR		0xFFFFFFFF

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

// Indexes of point in t_vertex
# define ORIP	0
# define LOCP	1
# define WORP	2
# define CAMP	3
// Indexes of point in t_vertex
# define ORIN	4
# define LOCN	5
# define WORN	6
# define CAMN	7

// FLAGS
// 1
# define CHANGE		0b00000001
// 2
# define DRAW_BOX	0b00000010
// 4
# define DRAW_AXIS	0b00000100
// 8
# define DRAW_LINE	0b00001000
// 16
# define DRAW_OBJ	0b00010000
// 32
# define DRAW_NORM	0b00100000
// 64
# define CAM_PM		0b01000000

// # define RORATE_X 0b00000100
// # define RORATE_Y 0b00001000
// # define RORATE_Z 0b00010000
// # define CHANGE_CENTER 0x00010000

# define EDGE_SIZE	10.f
// Sphere generation
# define SPHERE_GEN 4
// Cylinder step angle
# define CYLINDER_ANGLE 4.5f

# define ANGLE 2.5f
# define STEP 5.f
# define SCALE .05f
# define MIN_AXIS .051f
# define MAX_AXIS 5.f

// MTL material format (Lightwave, OBJ)
/*
Ka: specifies ambient color, to account for light that is scattered about the
	entire scene [see Wikipedia entry for Phong Reflection Model] using values
	between 0 and 1 for the RGB components.

Kd: specifies diffuse color, which typically contributes most of the color to
	an object [see Wikipedia entry for Diffuse Reflection]. In this example,
	Kd represents a grey color, which will get modified by a colored texture map
	specified in the map_Kd statement

Ks: specifies specular color, the color seen where the surface is shiny
	and mirror-like [see Wikipedia entry for Specular Reflection].

Ns: defines the focus of specular highlights in the material. Ns values normally
	range from 0 to 1000, with a high value resulting in a tight, concentrated
	highlight.

Ni: defines the optical density (aka index of refraction) in the current
	material. The values can range from 0.001 to 10. A value of 1.0 means that
	light does not bend as it passes through an object.

d: specifies a factor for dissolve, how much this material dissolves into
	the background. A factor of 1.0 is fully opaque. A factor of 0.0 is
	completely transparent.

illum: specifies an illumination model, using a numeric value. See Notes below
	for more detail on the illum keyword. The value 0 represents the simplest
	illumination model, relying on the Kd for the material modified by a texture
	map specified in a map_Kd statement if present. The compilers of this
	resource believe that the choice of illumination model is irrelevant for
	3D printing use and is ignored on import by some software applications.
	For example, the MTL Loader in the threejs Javascript library appears to
	ignore illum statements. Comments welcome.

map_Kd: specifies a color texture file to be applied to the diffuse reflectivity
	of the material. During rendering, map_Kd values are multiplied by the Kd
	values to derive the RGB components.
*/
typedef struct s_material
{
	float	ka;
	float	kd;
	float	ks;
	float	ns;
}	t_material;

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
	union
	{
		struct
		{
			float	ur;
			float	ug;
			float	ub;
			float	ua;			
		};
		float		urgba[4];
	};
	t_material	material;
}	t_color;

typedef struct s_pixel
{
	union
	{
		struct
		{
			int64_t	x;
			int64_t	y;
		};
		int64_t	xy[2];
	};
	t_color	color;
	float	z;
	float	w;
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
		t_vector3	ijko[3];
	};
	// union
	// {
	// 	struct
	// 	{
	// 		// t_vector3	w_i;
	// 		t_vector3	w_j;
	// 		t_vector3	w_k;
	// 		t_vector3	w_o;
	// 	};
	// 	t_vector3	w_ijko[4];
	// };
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
	float		tng;
	float		aspect;
	float		half_width;
	float		half_height;
	// float		vfov;
	uint8_t		flags;
	t_matrix4	vm;
	t_matrix4	ivm;
	t_matrix4	pm;
	// float		focal_len;
	float		near;
	float		far;
	float		left;
	float		right;
	float		top;
	float		bottom;
}	t_camera;

typedef struct s_vertex
{
	union
	{
		struct
		{
			t_vector3	op;
			t_vector3	lp;
			t_vector3	wp;
			t_vector3	cp;
		};
		t_vector3	olwc[4];
	};
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
			t_vertex	*p_norm1;
			t_vertex	*p_norm2;
			t_vertex	*p_norm3;
		};
		t_vector3	*p_norms[3];
	};
	//t_color		*p_color;
	void		*p_object;
	t_vector3	centr;
}	t_triangle;

typedef struct s_box
{
	t_vertex	ver[8];
	t_triangle	tris[12];
	t_triangle	**pp_tris;
	void		*p_object;
}	t_box;

typedef struct s_bvhnode
{
	t_vector3	aabb_min;
	t_vector3	aabb_max;
	uint32_t	left_ch;
	uint32_t	right_ch;
	uint8_t		is_leaf;
	uint32_t	first_tri;
	uint32_t	tri_num;
}	t_bvhnode;

typedef struct s_bvh
{
	t_bvhnode	*nodes;
	t_triangle	**pp_tri;
	uint32_t	*tri_index;
	uint32_t	used_n;
}	t_bvh;

typedef struct s_light
{
	t_vertex	point;
	t_color		color;
	float		bright;
}	t_light;

typedef struct s_texture
{
	char			*name;
	mlx_texture_t	*p_mapdata;
	mlx_texture_t	*p_bumpdata;
	t_color			color;
}	t_texture;

typedef struct s_plane
{
	t_vertex	point;
	t_vertex	norm;
	t_color		color;
	t_basis		basis;
	t_texture	*p_texture;
}	t_plane;

typedef struct s_object
{
	uint8_t		flags;
	t_color		color;
	float		size1;
	float		size2;
	float		edge;
	t_basis		basis;
	t_vertex	axis[4];
	t_box		**pp_box;
	t_vertex	**pp_vrtx;
	uint32_t	size_vrtx;
	t_vertex	**pp_vnrm;
	uint32_t	size_vnrm;
	t_triangle	**pp_tri;
	uint32_t	size_tri;
	t_texture	*p_texture;
	void		(*ray_txtr_uv)(t_vector3 *, float *, float *);
	// void		(*f_transform)(void *, t_basis *);
	t_bvh		*bvh;
}	t_object;

typedef struct s_world
{
	uint8_t		flags;
	t_basis		basis;
	t_vector3	far;
	t_matrix4	tm;
	t_box		**pp_box;
	int32_t		size_box;
	t_object	**pp_obj;
	int32_t		size_obj;
	t_light		**pp_lgt;
	int32_t		size_lgt;
	t_plane		**pp_pln;
	int32_t		size_pln;
	t_texture	**pp_txtr;
	t_light		ambient;
	t_camera	*p_camera;
}	t_world;

typedef struct s_graphics
{
	mlx_t		*mlx;
	mlx_image_t	*img_bg;
	mlx_image_t	*img_proj;
	mlx_image_t	*img_ray;
	t_world		world;
	t_camera	camera;
	int32_t		obj_idx;
	void		(*f_gc)(void *);
}	t_graphics;

mlx_t		*ksx_init(void);
int			ksx_prep(void *p_vars);
t_pixel		ksx_get_pixel(mlx_image_t *p_img, uint32_t x, uint32_t y);
void		ksx_set_pixel(mlx_image_t *p_img, t_pixel *p_pix);
void		applyDepthAttenuation(t_color *p_color, float depth, float k);

mlx_image_t	*ksx_create_image(mlx_t *mlx, uint32_t bg_color);
int32_t		ksx_image_to_window(mlx_t *p_mlx, mlx_image_t *p_img, int32_t z);

t_color		ksx_get_color(t_pixel *p_p, t_pixel *p_p1, t_pixel *p_p2);
void		ksx_line(mlx_image_t *p_img, t_pixel *p_pix1, t_pixel *p_pix2);
void		ksx_circle(mlx_image_t *img, t_pixel center, uint32_t radius);

t_object	**ksx_obj2world(t_object *p_object, t_world *p_world);
void		ksx_world_clean(t_world *p_world);

t_object	*ksx_create_sphere(t_vector3 center,
				float diameter, t_color color, uint8_t gen);
t_object	*ksx_create_cylinder(t_vector3 center, t_vector3 norm,
				float dia_ht[], t_color color);
t_object	*ksx_create_cone(t_vector3 center, t_vector3 norm,
				float dia_ht[], t_color color);
void		ksx_draw(t_graphics *p_grph);

void		ksx_change(t_graphics *p_grph);
void		ksx_change_obj(t_object *p_object, t_graphics *p_grph);
void		ksx_change_world(t_graphics *p_grph);
void		ksx_change_camera(t_graphics *p_grph);

// garbage_collector
void		ksx_garbage_collector(t_graphics *p_grph);
void		ksx_error(char *error, char *file_name, int str_num);

#endif	// KSX_GRAPHICS_H //
