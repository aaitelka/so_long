/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:28:21 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/11 19:47:20 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_window_size(t_game game)
{
	int	width;
	int	height;

	mlx_get_monitor_size(0, &width, &height);
	if (game.map.x * IMG_WH > width || game.map.y * IMG_WH > height)
		assert_error(ERR);
}

void	fill_window(t_game game)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (game.map.data[i] != NULL)
	{
		j = 0;
		while (game.map.data[i][j])
		{
			l = 0;
			while (game.keys[l])
			{
				if (game.map.data[i][j] == game.keys[l])
					mlx_image_to_window(game.mlx, game.tex.img[l], game.row, game.col);
				else if (game.map.data[i][j] == 'P')
					mlx_image_to_window(game.mlx, game.tex.img[4], game.row, game.col);
				l++;
			}
			game.row += IMG_WH;
			j++;
		}
		game.row = 0;
		game.col += IMG_WH;
		i++;
	}
}
