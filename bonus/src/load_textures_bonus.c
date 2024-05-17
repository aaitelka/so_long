/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:50:46 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 17:55:17 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_door(t_game *game)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(game->tex.door_uris) / sizeof(game->tex.door_uris[0]) - 1;
	while (i < size)
	{
		game->tex.texture = mlx_load_png(game->tex.door_uris[i]);
		if (!(game->tex.texture))
			exit(EXIT_FAILURE);
		game->tex.door_img[i] = mlx_texture_to_image(game->mlx, game->tex.texture);
		mlx_delete_texture(game->tex.texture);
		i++;
	}
}

static void	load_player(t_game *game)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(game->tex.player_uris) / sizeof(game->tex.player_uris[0]) - 1;
	while (i < size)
	{
		game->tex.texture = mlx_load_png(game->tex.player_uris[i]);
		if (!(game->tex.texture))
			exit(EXIT_FAILURE);
		game->tex.player_img[i] = mlx_texture_to_image(game->mlx, game->tex.texture);
		mlx_delete_texture(game->tex.texture);
		i++;
	}
}

static void	load_coins(t_game *game)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(game->tex.coin_uris) / sizeof(game->tex.coin_uris[0]) - 1;
	while (i < size)
	{
		game->tex.texture = mlx_load_png(game->tex.coin_uris[i]);
		if (!(game->tex.texture))
			exit(EXIT_FAILURE);
		game->tex.coin_img[i] = mlx_texture_to_image(game->mlx, game->tex.texture);
		mlx_delete_texture(game->tex.texture);
		i++;
	}
}

static void	load_enemies(t_game *game)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(game->tex.enemy_uris) / sizeof(game->tex.enemy_uris[0]) - 1;
	while (i < size)
	{
		game->tex.texture = mlx_load_png(game->tex.enemy_uris[i]);
		if (!(game->tex.texture))
			exit(EXIT_FAILURE);
		game->tex.enemy_img[i] = mlx_texture_to_image(game->mlx, game->tex.texture);
		mlx_delete_texture(game->tex.texture);
		i++;
	}
}
void	load_textures(t_game *game)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(game->tex.main_uris) / sizeof(game->tex.main_uris[0]) - 1;
	while (i < size)
	{
		game->tex.texture = mlx_load_png(game->tex.main_uris[i]);
		if (!(game->tex.texture))
			exit(EXIT_FAILURE);
		game->tex.main_img[i] = mlx_texture_to_image(game->mlx, game->tex.texture);
		mlx_delete_texture(game->tex.texture);
		i++;
	}
	load_door(game);
	load_player(game);
	load_coins(game);
	load_enemies(game);
}