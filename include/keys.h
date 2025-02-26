/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:03:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/26 11:31:07 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "ksx_graphics.h"

// key_kp01.c
void	key_kp(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_kp_4(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_kp_6(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_kp_2(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_kp_8(mlx_key_data_t *p_keydata, t_graphics *p_grph);

// key_kp02.c
void	key_kp_1(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_kp_9(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_kp_minus(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_kp_plus(mlx_key_data_t *p_keydata, t_graphics *p_grph);

// key_arrows.c
void	key_arrows(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_right(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_left(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_up(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_down(mlx_key_data_t *p_keydata, t_graphics *p_grph);

// key_adsw.c
void	key_adswze(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_a(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_d(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_s(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_w(mlx_key_data_t *p_keydata, t_graphics *p_grph);

// key_ze.c
void	key_z(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_e(mlx_key_data_t *p_keydata, t_graphics *p_grph);

// key_scroll.c
void	scroll_zoom_in(t_graphics *p_grph);
void	scroll_zoom_out(t_graphics *p_grph);

// key_1234.c
void	key_1234(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_1(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_2(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_3(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_4(mlx_key_data_t *p_keydata, t_graphics *p_grph);

// key_5678.c
void	key_5678(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_5(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_6(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_7(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_8(mlx_key_data_t *p_keydata, t_graphics *p_grph);

// key_90-=.c
void	key_90__(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_9(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_0(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_minus(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_equal(mlx_key_data_t *p_keydata, t_graphics *p_grph);

#endif	// KEYS_H