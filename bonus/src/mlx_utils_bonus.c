/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:28:43 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 21:14:07 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_events(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	return ;
}

void	animate_coin(t_game *game)
{
	t_point		*pos;
	static int	i;
	static int	index;
	int			size;

	size = sizeof(game->tex.coin_img) / sizeof(game->tex.coin_img[0]);
	pos = game->map.coins_pos;
	if (!(++i % DELAY))
	{
		while (pos)
		{
			if (game->map.data[pos->x][pos->y] == 'C')
				put(game, game->tex.coin_img[index], pos->y * 60, pos->x * 60);
			pos = pos->next;
		}
		index++;
		if (index == size)
			index = 0;
	}
}

void	animate_door(t_game *game)
{
	static int	i;
	static int	index;
	int			size;

	size = sizeof(game->tex.door_img) / sizeof(game->tex.door_img[0]);
	if (!(game->map.coins) && index < size)
	{
		if (!(++i % DELAY))
		{
			put(game, game->tex.door_img[index],
				game->map.door_pos.x * 60, game->map.door_pos.y * 60);
			index++;
		}
	}
}

void	animator(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	animate_coin(game);
	animate_door(game);
	animate_enemy(game);
}
