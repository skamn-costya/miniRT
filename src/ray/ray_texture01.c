/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:44:14 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/31 21:52:07 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include "ray.h"
#include "ray_texture.h"
#include "ksx_object.h"
#include "ksx_utils.h"
#include "ksx_3D.h"
#include "ksx_vec3_math.h"
#include "pp_struct.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

t_texture	*ray_txtr_load(t_world *p_world, char *p_mapname, char *p_bumpname)
{
	t_texture	*p_texture;

	p_texture = (t_texture *)malloc(sizeof(t_texture));
	if (!p_texture)
		ksx_error("memory allocation failure", __FILE__, __LINE__);
	p_texture->p_mapdata = mlx_load_png(p_mapname);
	if (!p_texture->p_mapdata)
		return (free(p_texture), NULL);
	p_texture->p_bumpdata = NULL;
	if (p_bumpname)
		p_texture->p_bumpdata = mlx_load_png(p_bumpname);
	p_texture->name = ft_strdup(p_mapname);
	p_world->pp_txtr = (t_texture **)pp_add_instance((void **)
			p_world->pp_txtr, (void *)p_texture, &ksx_error);
	return (p_texture);
}

// uint32_t	ray_txtr_sample_nearest(t_texture *p_txtr, float u, float v)
t_color	ray_txtr_sample(t_texture *p_txtr, float u, float v)
{
	t_color	color;
	int32_t	wh[2];
	int32_t	xy[2];
	int		idx;

	color = p_txtr->color;
	wh[0] = p_txtr->p_mapdata->width;
	wh[1] = p_txtr->p_mapdata->height;
	xy[0] = (int)floorf(fmodf(u * wh[0], wh[0]));
	xy[1] = (int)floorf(fmodf(v * wh[1], wh[1]));
	idx = (xy[1] * wh[0] + xy[0]) * BPP;
	color.r = p_txtr->p_mapdata->pixels[idx + 0];
	color.g = p_txtr->p_mapdata->pixels[idx + 1];
	color.b = p_txtr->p_mapdata->pixels[idx + 2];
	color.a = p_txtr->p_mapdata->pixels[idx + 3];
	return (color);
}

float	ray_bump_sample(t_texture *p_txtr, float u, float v)
{
	int	x;
	int	y;
	int	idx;

	x = (int)(u * p_txtr->p_bumpdata->width) % p_txtr->p_bumpdata->width;
	y = (int)(v * p_txtr->p_bumpdata->height) % p_txtr->p_bumpdata->height;
	idx = (y * p_txtr->p_bumpdata->width + x) * BPP;
	return (p_txtr->p_bumpdata->pixels[idx] / 255.f);
}
