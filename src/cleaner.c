/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:31:14 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/09 18:50:32 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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

void	clear_images(mlx_t *mlx, t_texture *tex)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(tex->img) / sizeof(tex->img[0]);
	while (i < size)
	{
		mlx_delete_image(mlx, tex->img[i]);
		mlx_delete_texture(tex->texture[i]);
		i++;
	}
	free(tex);
}

void	destroy(t_game *game)
{
	clear_map(game->map->data);
	clear_images(game->mlx, game->textures);
	clear_images(game->mlx, game->player);
	mlx_terminate(game->mlx);
	free(game->map);
	free(game);
}
