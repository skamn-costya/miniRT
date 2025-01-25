/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:05:29 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/25 14:17:55 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

# define RETURN_ERR -1
# define TRUE 1
# define FALSE 0

enum obj {AMBIENT, CAMERA, LIGHT, SPHERE, PLANE, CYLINDER};
// enum obj {AMBIENT = 'A', CAMERA = 'C', LIGHT = 'L', SPHERE = 'S', PLANE = 'P', CYLINDER = 'C'};
// CONE, HYPERBOLOID, PARABOLOID	// bonus part

// utils01.c
void	free_pp_obj(void **ppp_obj);

#endif	// MINIRT_H