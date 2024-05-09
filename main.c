/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:01:49 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/09 20:39:31 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdbool.h>
#include <time.h>

void l()
{
    system("leaks so_long");
}

void    run(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (game->map->data[i])
	{
        j = 0;
        while (game->map->data[i][j])
        {
			int l = 0;
			while (game->keys[l])
			{
				if (game->map->data[i][j] == game->keys[l])
					mlx_image_to_window(game->mlx, game->textures->img[l], game->row, game->col);
				else if (game->map->data[i][j] == 'P')
					mlx_image_to_window(game->mlx, game->player->img[0], game->row, game->col);
				l++;
			}
            game->row += IMG_WH;
			j++;
        }
        game->row = 0;
		game->col += IMG_WH;
		i++;
    }
}

t_map	*init_map(char *filename)
{
	t_map	*map;
	char	**map2d;
	
	map2d = load_map(filename);
	if (!map2d)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->data = map2d;
	map->coins = count_collectibles(map2d);
	map->px = 0;
	map->py = 0;
	map->x = (int) ft_strlen(map->data[0]);
	map->y = 0;
	while (map->data[map->y])
		map->y++;
	return (map);
}

t_texture	*init_textures(t_game *game, char *paths[])
{
	t_texture   *texture;

    texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	int i = 0;
	while (paths[i])
	{
        texture->texture[i] = mlx_load_png(paths[i]);
        texture->img[i] = mlx_texture_to_image(game->mlx, texture->texture[i]);
		i++;
	}
	return (texture);
}

void print_map(char *map[])
{
	int i = 0;
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	
}

bool	init_game(t_game **game, char *av[], char *paths[], char *player[])
{
	t_map	*map;

	map = init_map(av[1]);
	if (!map)
		return (false);
	get_player_position(map);
	flood_fill(map->data, map->py, map->px);
	if (!should_stay(map->data, map->y))
	{
		ft_printf("Error : one or more of the collectibles will not be accessible.\n");
		exit(EXIT_FAILURE);
	}
	clear_map(map->data);
	free(map);
	map = init_map(av[1]);
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (false);
	(*game)->map = map;
	(*game)->width = (*game)->map->x;
	(*game)->height = (*game)->map->y;
	(*game)->moves = 0;
	(*game)->keys = "01CE";
	(*game)->row = 0;
	(*game)->col = 0;
	(*game)->mlx = mlx_init((*game)->width * IMG_WH, (*game)->height * IMG_WH, "SO_LONG", false);
	(*game)->textures = init_textures(*game, paths);
	(*game)->player = init_textures(*game, player);
	return (true);
}

int	main(int ac, char *av[])
{
	atexit(l);
	t_game		*game;

	char *paths[] = {
		"textures/ground.png",
		"textures/wall.png",
		"textures/ball.png",
		"textures/door.png",
		NULL
	};

	char *player[] = {
		"textures/player_front.png",
		"textures/player_back.png",
		"textures/player_left.png",
		"textures/player_right.png",
		NULL
	};


	int	size;

	size = (sizeof(paths) / sizeof(paths[0])) - 1;
	check_textures(paths, size);
	check_textures(player, size);
	
	char *coins[] = {
		"textures/coin_1.png",
		"textures/coin_2.png",
		"textures/coin_3.png",
		"textures/coin_4.png",
		"textures/coin_5.png",
		"textures/coin_6.png",
		"textures/coin_7.png",
		"textures/coin_8.png",
		"textures/coin_9.png",
		"textures/coin_10.png",
		NULL
	};
	
	if (ac == 2)
    {
		if (!init_game(&game, av, paths, player))
			exit(EXIT_FAILURE);
		
		int32_t width;
		int32_t height;
		mlx_get_monitor_size(0, &width, &height);
		// if (game->map->x )
		if (game->map->x * IMG_WH > width || game->map->y * IMG_WH > height)
		{
			printf("Window size bigger than monitor size\n");
			exit(EXIT_FAILURE);
		}
		
		run(game);
		// char *moves = ft_itoa(game->moves);
		// mlx_put_string(game->mlx, moves, 30, 30);
        mlx_key_hook(game->mlx, key_events, game);
        mlx_loop(game->mlx);
		mlx_close_window(game->mlx);
    }
    else
        ft_printf("Please add data!\n");
	// free(coins);
    destroy(game);
    return (EXIT_SUCCESS);
}
