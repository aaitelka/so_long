/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:13:03 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/11 19:48:12 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map, char *filename)
{
	char	**map2d;
	(void)filename;
	map2d = load_map(filename);
	if (!map2d)
		assert_error(ERR);
	map->data = map2d;
	map->coins = count_coins(map2d);
	map->px = 0;
	map->py = 0;
	map->x = (int) ft_strlen(map->data[0]);
	map->y = 0;
	while (map->data[map->y])
		map->y++;
}

void	init_textures(t_game game, t_texture *tex, t_path paths)
{
	int	i;

	i = 0;
	while (i < SIZE(paths.uris))
	{
		tex->texture[i] = mlx_load_png(paths.uris[i]);
		if (!(tex->texture[i]))
			exit(EXIT_FAILURE);
		tex->img[i] =  mlx_texture_to_image(game.mlx, tex->texture[i]);
		i++;
	}
}

void	init_mlx(t_game *game)
{
	int	width;
	int	height;

	width = game->width * IMG_WH;
	height = game->height * IMG_WH;
	game->mlx = mlx_init(width, height, TITLE, false);
	if (!game->mlx)
		assert_error(ERR);
}

bool	init_game(t_game *game, t_path paths, char *av[])
{
	t_map		map;
	t_texture	tex;

	init_map(&map, av[1]);
	if (!map.data)
		return (false);
	get_player_position(&map);
	flood_fill(map.data, map.py, map.px);
	if (!should_stay(map.data, map.y))
		assert_error(ERR);
	clear_map(map.data);
	init_map(&map, av[1]);
	game->map = map;
	game->width = (game)->map.x;
	game->height = (game)->map.y;
	game->moves = 0;
	game->keys = "01CE";
	game->row = 0;
	game->col = 0;
	init_mlx(game);
	init_textures(*game, &tex, paths);
	game->tex = tex;
	return (true);
}
