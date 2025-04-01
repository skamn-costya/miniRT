/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:05:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/04/01 15:06:28 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "ksx_graphics.h"

# define RETURN_ERR -1
# define TRUE 1
# define FALSE 0

// gc.c
// void	clear_exit(char *str, uint8_t fd);
void	garbage_collector(void *p_grph);
// void	error(char *error, char *file_name, int str_num);

#endif	// MINIRT_H

// sudo apt updatesudo apt update
// sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
