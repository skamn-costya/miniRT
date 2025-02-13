/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:03:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/13 18:44:48 by ksorokol         ###   ########.fr       */
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
void	key_adsw(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_a(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_d(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_s(mlx_key_data_t *p_keydata, t_graphics *p_grph);
void	key_w(mlx_key_data_t *p_keydata, t_graphics *p_grph);

#endif	// KEYS_H