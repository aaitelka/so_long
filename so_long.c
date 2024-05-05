/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:01:49 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/05 12:52:58 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdbool.h>

#define EXT ".ber"

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

char *get_file_name(char *agrv[])
{
	return (agrv[1]);
}

bool is_valid_ext(char *filename)
{
    char *ext;

    ext = ft_strrchr(filename, '.');
    if (!ft_strcmp(ext, EXT))
        return (true);
    return (false);
}

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

char *read_map(char *filename)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*map;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
		return (NULL);
    while (true)
    {
		line = get_next_line(fd);
        if (!line)
			break;
		temp = ft_strjoin(map, line);
		free(map);
		map = temp;
		free(line);
	}
	close(fd);
	return (map);
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

#define BPP sizeof(int32_t)
char	**load_map(char *av[])
{
	char	*filename;
    char	*map;
    char	**map2d;

	filename = get_file_name(av);
    if (!is_valid_ext(filename))
		printf("invalid\n");
	map  = read_map(filename);
	map2d = ft_split(map, '\n');
	free(map);
	return (map2d);
}

void l()
{
    system("leaks so_long");
}

void clear_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void clear_images(t_game *game)
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

void	key_listener(mlx_key_data_t keydata, void *param)
{
	t_game  *game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        move_up(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        move_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        move_down(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        move_right(game);
}

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

void	destroy_game(t_game *game)
{
	clear_map(game->map->data);
    clear_images(game);
    mlx_terminate(game->mlx);
	free(game->textures);
	free(game->map);
	free(game);
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
	(*game)->mlx = mlx_init((*game)->width * IMG_WH, (*game)->height * IMG_WH, "SO_LONG", false);
	(*game)->textures = init_textures(*game, paths);
	return (true);
}

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

	if (ac == 2)
    {
		init_game(&game, av, paths);
		run(game);
		mlx_set_window_pos(game->mlx, 0, 0);
        mlx_key_hook(game->mlx, key_listener, game);
        mlx_loop(game->mlx);
    }
    else
    {
        printf("Please add data!\n");
    }
    destroy_game(game);
    return (EXIT_SUCCESS);
}
