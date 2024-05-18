/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:54:35 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/18 00:56:17 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	should_mv(t_game *game, t_point *pos, char dest)
{
	if (dest == RIGHT)
	{
		if (game->map.data[pos->x][pos->y + 1] == 'P'
			|| game->map.data[pos->x][pos->y + 1] == '0')
			return (true);
		else
			return (pos->dir = false, false);
	}
	else if (dest == LEFT)
	{
		if (game->map.data[pos->x][pos->y - 1] == 'P'
			|| game->map.data[pos->x][pos->y - 1] == '0')
			return (true);
		else
			return (pos->dir = true, false);
	}
	else
		return (false);
}

static void	mv_right(t_game *game, t_point *pos)
{
	pos->step++;
	put(game, game->tex.main_img[0], (pos->y * 60), (pos->x * 60));
	put(game, game->tex.main_img[0], (pos->y * 60) + 60, (pos->x * 60));
	if (pos->index == 5)
		pos->index = 0;
	put(game, game->tex.enemy_img[pos->index++],
		(pos->y * 60) + (12 * (pos->step)), (pos->x * 60));
	if (pos->step == 5 && pos->y++)
	{
		game->map.data[pos->x][pos->y - 1] = '0';
		game->map.data[pos->x][pos->y] = 'N';
		pos->step = 0;
		if (game->map.data[pos->x][pos->y + 1] == '1')
			pos->dir = false;
	}
}

static void	mv_left(t_game *game, t_point *pos)
{
	pos->step++;
	put(game, game->tex.main_img[0], (pos->y * 60), (pos->x * 60));
	put(game, game->tex.main_img[0], (pos->y * 60) - 60, (pos->x * 60));
	if (pos->index == 5)
		pos->index = 0;
	put(game, game->tex.enemy_img[5 + pos->index++],
		(pos->y * 60) - (12 * (pos->step)), (pos->x * 60));
	if (pos->step == 5 && pos->y--)
	{
		game->map.data[pos->x][pos->y + 1] = '0';
		game->map.data[pos->x][pos->y] = 'N';
		pos->step = 0;
		if (game->map.data[pos->x][pos->y - 1] == '1')
			pos->dir = true;
	}
}

void	animate_enemy(t_game *game)
{
	t_point		*pos;
	static int	i;

	pos = game->map.enemies_pos;
	if (!(++i % 5))
	{
		while (pos)
		{
			if (pos->dir && should_mv(game, pos, RIGHT))
			{
				if (game->map.data[pos->x][pos->y + 1] == 'P')
				{
					ft_printf("You lose\n");
					mlx_close_window(game->mlx);
				}
				mv_right(game, pos);
			}
			else if (!pos->dir && should_mv(game, pos, LEFT))
			{
				if (game->map.data[pos->x][pos->y - 1] == 'P')
				{
					ft_printf("You lose\n");
					mlx_close_window(game->mlx);
				}
				mv_left(game, pos);
			}
			pos = pos->next;
		}
	}
}
