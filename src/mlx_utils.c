/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:28:43 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/11 11:51:06 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_events(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W && keydata.action != MLX_RELEASE)
		move_up(game);
	else if (keydata.key == MLX_KEY_A && keydata.action != MLX_RELEASE)
		move_left(game);
	else if (keydata.key == MLX_KEY_S && keydata.action != MLX_RELEASE)
		move_down(game);
	else if (keydata.key == MLX_KEY_D && keydata.action != MLX_RELEASE)
		move_right(game);
}
