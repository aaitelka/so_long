/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:31:14 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/18 01:18:58 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clear_textures(t_texture tex)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(tex.texture) / sizeof(tex.texture[0]) - 1;
	while (i < size)
		mlx_delete_texture(tex.texture[i++]);
}

void	clear_images(mlx_t *mlx, t_texture tex)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(tex.img) / sizeof(tex.img[0]);
	while (i < size)
	{
		mlx_delete_image(mlx, tex.img[i]);
		i++;
	}
}

void	destroy(t_game game)
{
	clear_map(game.map.data);
	clear_images(game.mlx, game.tex);
	mlx_terminate(game.mlx);
}
