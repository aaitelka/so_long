/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:28:21 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 19:27:14 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put(t_game *game, mlx_image_t *img, int32_t x, int32_t y)
{
	int	ret;

	if (!img)
		assert_error("putting image to window\n");
	ret = mlx_image_to_window(game->mlx, img, x, y);
	if (ret == -1)
	{
		mlx_close_window(game->mlx);
		destroy(*game);
		assert_error("puting image to window\n");
	}
}

void	check_window_size(t_game game)
{
	int	width;
	int	height;

	mlx_get_monitor_size(0, &width, &height);
	if (game.width > width || game.height > height)
	{
		destroy(game);
		assert_error(ERR_WINDOW);
	}
}

static void	organize(t_game *game, int *i, int *j)
{
	int	l;

	l = -1;
	while (game->keys[++l])
	{
		if (game->map.data[*i][*j] == game->keys[l])
			put(game, game->tex.main_img[l], game->row, game->col);
		if (game->map.data[*i][*j] == 'P')
			put(game, game->tex.player_img[0], game->row, game->col);
		else if (game->map.data[*i][*j] == 'C')
			put(game, game->tex.coin_img[0], game->row, game->col);
		else if (game->map.data[*i][*j] == 'N')
			put(game, game->tex.enemy_img[0], game->row, game->col);
	}
}

void	fill_window(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map.data[i] != NULL)
	{
		j = 0;
		while (g->map.data[i][j])
		{
			organize(g, &i, &j);
			g->row += W;
			j++;
		}
		g->row = 0;
		g->col += W;
		i++;
	}
}
