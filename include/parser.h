/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:13:36 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/03 13:03:28 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

# define AMBIENT_ID		"A"
# define CAMERA_ID		"C"
# define LIGHT_ID		"L"
# define SPHERE_ID		"sp"
# define PLANE_ID		"pl"
# define CYLINDER_ID	"cy"

# define OCTAHEDRON_ID	"oc"
# define CONE_ID		"co"
# define HYPERBOLOID_ID	"hy"
# define PARABOLOID_ID	"pa"
# define OBJ_ID			"obj"

# define TRIM_SYMBOLS	" \\\a\b\f\n\r\t\v"

typedef enum e_obj
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	OCTAHEDRON,
	CONE,
	HYPERBOLOID,
	PARABOLOID,
	OBJ
}	t_obj_id;

typedef struct s_fline
{
	char	*str;
	char	**words;
}	t_fline;

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
	char		*obj_file;
}	t_obj_descr;

// parser01.c
t_list		*check_file(char *f_name);
void		free_t_fline(void *p_fline);
t_list		*create_line_list(int fd);

// parser02.c
t_list		*create_obj_list(t_list **pp_line_list);
t_obj_descr	*create_obj(t_list **pp_line_list, t_list **pp_obj_list);

// parser03.c
t_obj_descr	*par_create_sphere(t_list **pp_line_list,
				t_list **pp_obj_list, t_fline *p_fline);
t_obj_descr	*par_create_octahedron(t_list **pp_line_list,
				t_list **pp_obj_list, t_fline *p_fline);
t_obj_descr	*par_create_plane(t_list **pp_line_list,
				t_list **pp_obj_list, t_fline *p_fline);
t_obj_descr	*par_create_cylinder(t_list **pp_line_list,
				t_list **pp_obj_list, t_fline *p_fline);
t_obj_descr	*par_create_obj(t_list **pp_line_list,
				t_list **pp_obj_list, t_fline *p_fline);

// parser04.c
int			is_f_number(char *str);
int			is_i_number(char *str);
int			get_rgb(char **pp_str, size_t idx, t_obj_descr *p_obj_descr);
int			get_coord(char **pp_str, size_t idx, t_obj_descr *p_obj_descr);
int			get_vector(char **pp_str, size_t idx, t_obj_descr *p_obj_descr);

// parser05.c
char		*comma_trim(char *str);
void		free_t_obj_descr(void *p_obj_descr);
void		parser_crash_exit(t_list **pp_line_list, t_list **pp_obj_list);

#endif	// PARSER_H //
