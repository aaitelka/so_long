/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:13:03 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/16 19:31:18 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_reachable(t_map *map)
{
	if (!map->data)
		return ;
	get_player_position(map);
	flood_fill(map->data, map->py, map->px);
	if (!should_stay(map->data, map->y))
	{
		clear_map(map->data);
		assert_error("exit or collectible is unreachable\n");
	}
	clear_map(map->data);
}

static void	init_map(t_map *map, char *filename)
{
	char	**map2d;

	map2d = load_map(filename);
	if (!map2d)
		assert_error("loading map\n");
	map->data = map2d;
	map->coins = count_coins(map2d);
	map->px = 0;
	map->py = 0;
	map->x = (int) ft_strlen(map->data[0]);
	map->y = 0;
	while (map->data[map->y])
		map->y++;
}

static void	load_main(t_game *game)
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
}

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

// static void	load_enemies(t_game game, t_texture *tex)
// {
// 	int	i;
// 	int	size;

// 	i = 0;
// 	size = sizeof(tex->player_uris) / sizeof(tex->player_uris[0]) - 1;
// 	while (i < size)
// 	{
// 		tex->texture = mlx_load_png(tex->player_uris[i]);
// 		if (!(tex->texture))
// 			exit(EXIT_FAILURE);
// 		tex->player_img[i] = mlx_texture_to_image(game.mlx, tex->texture);
// 		mlx_delete_texture(tex->texture);
// 		i++;
// 	}
// }

static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init(game->width, game->height, TITLE, false);
	if (!game->mlx)
		assert_error(ERR_MLX_INIT);
}

bool	init_game(t_game *game, char *av[])
{
	t_map		map;

	init_map(&map, av[1]);
	check_reachable(&map);
	init_map(&map, av[1]);
	game->map = map;
	game->width = game->map.x * IMG_WH;
	game->height = game->map.y * IMG_WH;
	game->moves = 0;
	game->keys = "01E";
	game->row = 0;
	game->col = 0;
	init_mlx(game);
	load_main(game);
	load_door(game);
	load_player(game);
	load_coins(game);
	// load_enemies(*game, &tex);
	return (true);
}
