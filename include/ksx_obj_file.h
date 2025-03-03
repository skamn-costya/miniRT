/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_obj_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:26:38 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/03 14:05:02 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_OBJ_FILE_H
# define KSX_OBJ_FILE_H

# include "ksx_graphics.h"
# include "ksx_object.h"
# include "parser.h"

# define OBJ_G	"g"
# define OBJ_V	"v"
# define OBJ_VN	"vn"
# define OBJ_F	"f"

void		read_of(t_world *p_world, char *file_name);
t_vertex	*get_v_of(t_fline *p_fline, t_object *p_object, int *p_idx);
t_vertex	*get_vn_of(t_fline *p_fline, t_object *p_object, int *p_idx);
t_triangle	*get_f_of(t_fline *p_fline, t_object *p_object, int *p_idx);
void		write_of(t_world *p_world, t_object p_object);
void		create_object_of(t_object p_object);
void		triangle_object_of(t_object p_object);

#endif	// KSX_OBJ_FILE_H