/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:50:46 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 19:10:47 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_door(t_game *g)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(g->tex.door_uris) / sizeof(g->tex.door_uris[0]) - 1;
	while (i < size)
	{
		g->tex.texture = mlx_load_png(g->tex.door_uris[i]);
		if (!(g->tex.texture))
			exit(EXIT_FAILURE);
		g->tex.door_img[i] = mlx_texture_to_image(g->mlx, g->tex.texture);
		mlx_delete_texture(g->tex.texture);
		i++;
	}
}

static void	load_player(t_game *g)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(g->tex.player_uris) / sizeof(g->tex.player_uris[0]) - 1;
	while (i < size)
	{
		g->tex.texture = mlx_load_png(g->tex.player_uris[i]);
		if (!(g->tex.texture))
			exit(EXIT_FAILURE);
		g->tex.player_img[i] = mlx_texture_to_image(g->mlx, g->tex.texture);
		mlx_delete_texture(g->tex.texture);
		i++;
	}
}

static void	load_coins(t_game *g)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(g->tex.coin_uris) / sizeof(g->tex.coin_uris[0]) - 1;
	while (i < size)
	{
		g->tex.texture = mlx_load_png(g->tex.coin_uris[i]);
		if (!(g->tex.texture))
			exit(EXIT_FAILURE);
		g->tex.coin_img[i] = mlx_texture_to_image(g->mlx, g->tex.texture);
		mlx_delete_texture(g->tex.texture);
		i++;
	}
}

static void	load_enemies(t_game *g)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(g->tex.enemy_uris) / sizeof(g->tex.enemy_uris[0]) - 1;
	while (i < size)
	{
		g->tex.texture = mlx_load_png(g->tex.enemy_uris[i]);
		if (!(g->tex.texture))
			exit(EXIT_FAILURE);
		g->tex.enemy_img[i] = mlx_texture_to_image(g->mlx, g->tex.texture);
		mlx_delete_texture(g->tex.texture);
		i++;
	}
}

void	load_textures(t_game *g)
{
	int	i;
	int	size;

	i = 0;
	size = sizeof(g->tex.main_uris) / sizeof(g->tex.main_uris[0]) - 1;
	while (i < size)
	{
		g->tex.texture = mlx_load_png(g->tex.main_uris[i]);
		if (!(g->tex.texture))
			exit(EXIT_FAILURE);
		g->tex.main_img[i] = mlx_texture_to_image(g->mlx, g->tex.texture);
		mlx_delete_texture(g->tex.texture);
		i++;
	}
	load_door(g);
	load_player(g);
	load_coins(g);
	load_enemies(g);
}
