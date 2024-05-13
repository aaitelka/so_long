/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:28:21 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/12 18:27:31 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	fill_window(t_game g)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (g.map.data[i] != NULL)
	{
		j = 0;
		while (g.map.data[i][j])
		{
			l = -1;
			while (g.keys[++l])
			{
				if (g.map.data[i][j] == g.keys[l])
					mlx_image_to_window(g.mlx, g.tex.img[l], g.row, g.col);
				else if (g.map.data[i][j] == 'P')
					mlx_image_to_window(g.mlx, g.tex.img[4], g.row, g.col);
			}
			g.row += IMG_WH;
			j++;
		}
		g.row = 0;
		g.col += IMG_WH;
		i++;
	}
}
