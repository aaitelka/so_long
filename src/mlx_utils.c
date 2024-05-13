/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:28:43 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/12 18:16:34 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_pressed(mlx_key_data_t data, keys_t key)
{
	return (data.key == key && data.action != MLX_RELEASE);
}

void	key_events(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (is_pressed(keydata, MLX_KEY_W))
		move_up(game);
	else if (is_pressed(keydata, MLX_KEY_A))
		move_left(game);
	else if (is_pressed(keydata, MLX_KEY_S))
		move_down(game);
	else if (is_pressed(keydata, MLX_KEY_D))
		move_right(game);
	else
		return ;
}
