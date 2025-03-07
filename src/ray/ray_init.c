/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:18:33 by username          #+#    #+#             */
/*   Updated: 2025/03/07 12:16:47 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"

t_ray	new_ray(t_vector3 o, t_vector3 d, float t)
{
	t_ray	res;

	res.length = t;
	res.origin = o;
	res.direction = d;
	return (res);
}

t_vector3 ray_end(t_ray ray)
{
	t_vector3	mult;

	mult = ksx_vec3_smulti(&ray.direction, ray.length);
	return ksx_vec3_add(&ray.origin, &mult);
}
