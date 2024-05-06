/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:01:49 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/06 19:25:33 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdbool.h>
#include <time.h>

bool is_double(char *map, char c)
{
    int i;

    i = 0;
    while (map[i])
    {
        if (map[i] == c)
            return (true);
        i++;
    }
    return (false);
}



void l()
{
    system("leaks so_long");
}

void	key_listener(mlx_key_data_t keydata, void *param)
{
	t_game  *game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        (move_up(game), print_moves(game));
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        (move_left(game), print_moves(game));
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        (move_down(game), print_moves(game));
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        (move_right(game), print_moves(game));
}

// void delay(int sec)
// {
//     int		millis;
//     clock_t	time;
	
// 	millis = (sec * 1000) * 500;
// 	time = clock();
//     while (clock() < (time + millis))
//         ;
// }

void    run(t_game *game)
{
    int x = 0, y = 0;
    int i = 0;

    while (game->map->data[i])
    {
        int j = 0;
        while (game->map->data[i][j])
        {
            if (game->map->data[i][j] == '0')
                mlx_image_to_window(game->mlx, game->textures->img[0], x, y);
            else if (game->map->data[i][j] == '1')
                mlx_image_to_window(game->mlx, game->textures->img[1], x, y);
            else if (game->map->data[i][j] == 'P')
                mlx_image_to_window(game->mlx, game->textures->img[2], x, y);
            else if (game->map->data[i][j] == 'C')
        		mlx_image_to_window(game->mlx, game->textures->img[3], x, y);
            else if (game->map->data[i][j] == 'E')
                mlx_image_to_window(game->mlx, game->textures->img[4], x, y);
            else if (game->map->data[i][j] == 'X')
                mlx_image_to_window(game->mlx, game->textures->img[5], x, y);
            x += IMG_WH;
            j++;
        }
        x = 0;
        y += IMG_WH;
        i++;
    }
}

t_map	*init_map(char *av[])
{
	t_map	*map;
	
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->data = load_map(av);
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

bool	init_game(t_game **game, char *av[], char *paths[])
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (false);
	(*game)->map = init_map(av);
	(*game)->width = (*game)->map->x;
	(*game)->height = (*game)->map->y;
	(*game)->moves = 0;
	(*game)->mlx = mlx_init((*game)->width * IMG_WH, (*game)->height * IMG_WH, "SO_LONG", false);
	(*game)->textures = init_textures(*game, paths);
	return (true);
}


// void animate_coin(void *param)
// {
// 	t_game *game;

// 	game = (t_game *)param;
	
// 	printf("%d\n", game->moves);
// }



int	main(int ac, char *av[])
{
	atexit(l);
	t_game		*game;

	char *paths[] = {
		"textures/ground.png",
		"textures/wall.png",
		"textures/player.png",
		"textures/coin.png",
		"textures/door.png",
		"textures/enemy.png",
		NULL
	};

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
		init_game(&game, av, paths);
		run(game);
        mlx_key_hook(game->mlx, key_listener, game);
        mlx_loop(game->mlx);
    }
    else
    {
        printf("Please add data!\n");
    }
    destroy(game);
    return (EXIT_SUCCESS);
}
