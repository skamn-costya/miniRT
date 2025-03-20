/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:55:53 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/20 18:14:17 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PP_STRUCT_H
# define PP_STRUCT_H

int		pp_get_size(void **pp_instance);
void	pp_null_pointers(void **pp_instance, int size);
void	**pp_add_instance(void **pp_instance, void *p_instance,
			void *p_f_error(char*, char*, int));
int		pp_search_instance(void **pp_instance, void *p_instance);
void	**pp_del_idx(void **pp_instance, int del_idx,
			void *p_f_error(char*, char*, int));

void	**pp_del_instance(void **pp_instance, void *p_instance,
			void *p_f_error(char*, char*, int));
void	**pp_del_all(void **pp_instance);

#endif	// PP_STRUCT_H
