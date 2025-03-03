/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksx_world.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:43:58 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/03 16:48:18 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KSX_WORLD_H
# define KSX_WORLD_H
# include "ksx_graphics.h"
# include "libft.h"

void	ksx_init_world(t_graphics *p_grph, t_list *p_list);
void	ksx_world_obj_tm(t_world *p_world, t_object *p_object);

void	ksx_world_set_tm(t_world *p_world, t_vector3 *p_o);

#endif	// KSX_WORLD_H