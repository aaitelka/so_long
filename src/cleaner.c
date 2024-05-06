/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:31:14 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/06 18:46:47 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	clear_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clear_images(t_game *game)
{
	int			i;
	int			size;
	t_texture	*texture;

	i = 0;
	texture = game->textures;
	size = sizeof(texture->img) / sizeof(texture->img[0]);
	while (i < size)
	{
		mlx_delete_texture(game->textures->texture[i]);
		mlx_delete_image(game->mlx, game->textures->img[i]);
		i++;
	}
}

void	destroy(t_game *game)
{
	clear_map(game->map->data);
	clear_images(game);
	mlx_terminate(game->mlx);
	free(game->textures);
	free(game->map);
	free(game);
}
