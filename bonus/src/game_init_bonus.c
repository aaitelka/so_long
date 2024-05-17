/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:13:03 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 17:31:42 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_reachable(t_map *map)
{
	if (!map->data)
		return ;
	get_player_position(map);
	flood_fill(map->data, map->player_pos.y, map->player_pos.x);
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
	map->x = (int) ft_strlen(map->data[0]);
	map->y = 0;
	while (map->data[map->y])
		map->y++;
}

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
	load_textures(game);
	return (true);
}
