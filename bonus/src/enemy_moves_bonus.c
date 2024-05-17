/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:54:35 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 22:32:50 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	mv_right(t_game *game, t_point *pos, int *index)
{
	static int	i;

	(*index)++;
	put(game, game->tex.main_img[0], (pos->y * 60), (pos->x * 60));
	put(game, game->tex.main_img[0], (pos->y * 60) + 60, (pos->x * 60));
	if (i == 5)
		i = 0;
	put(game, game->tex.enemy_img[i++],
		(pos->y * 60) + (15 * (*index)), (pos->x * 60));
	if (*index == 4 && pos->y++)
	{
		ft_printf("%d:%d\n", pos->x, pos->y);
		game->map.data[pos->x][pos->y - 1] = '0';
		game->map.data[pos->x][pos->y] = 'N';
		*index = 0;
		if (game->map.data[pos->x][pos->y + 1] == '1')
			game->map.enemies_pos->dir = false;
	}
}

static void	mv_left(t_game *game, t_point *pos, int *index)
{
	static int	i;

	(*index)++;
	put(game, game->tex.main_img[0], (pos->y * 60), (pos->x * 60));
	put(game, game->tex.main_img[0], (pos->y * 60) - 60, (pos->x * 60));
	if (i == 5)
		i = 0;
	put(game, game->tex.enemy_img[5 + i++],
		(pos->y * 60) - (15 * (*index)), (pos->x * 60));
	if (*index == 4 && pos->y--)
	{
		game->map.data[pos->x][pos->y + 1] = '0';
		game->map.data[pos->x][pos->y] = 'N';
		*index = 0;
		if (game->map.data[pos->x][pos->y - 1] == '1')
			game->map.enemies_pos->dir = true;
	}
}

void	animate_enemy(t_game *game)
{
	t_point		*pos;
	static int	i;
	static int	index;

	pos = game->map.enemies_pos;
	if (!(++i % 5))
	{
		while (pos)
		{
			if (game->map.data[pos->x][pos->y - 1] == 'P')
			{
				ft_printf("You lose\n");
				mlx_close_window(game->mlx);
			}
			else if (game->map.data[pos->x][pos->y + 1] != '1'
				&& game->map.enemies_pos->dir)
				mv_right(game, pos, &index);
			else if (game->map.data[pos->x][pos->y - 1] != '1'
				&& !game->map.enemies_pos->dir)
				mv_left(game, pos, &index);
			pos = pos->next;
		}
	}
}
