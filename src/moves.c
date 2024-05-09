/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:44:52 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/08 22:32:35 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	move_up(t_game *game)
{
	int32_t		x;
	int32_t		y;
	t_texture	*texture;
	mlx_image_t	*player;

	texture = game->textures;
	player = game->player->img[0];
	x = player->instances[0].x / IMG_WH;
	y = (player->instances[0].y - IMG_WH) / IMG_WH;
	game->map->data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = game->keys[GROUND];
	if (game->map->data[y][x] == '0' || game->map->data[y][x] == 'C')
	{
		if (game->map->data[y][x] == 'C')
			game->map->coins--;
		mlx_image_to_window(game->mlx, texture->img[GROUND], player->instances[0].x, player->instances[0].y);
		player->instances[0].y -= IMG_WH;
		mlx_image_to_window(game->mlx, game->player->img[1], player->instances[0].x, player->instances[0].y);
		ft_printf("Player moves : %d\n", ++(game->moves));
	}
	else if (game->map->data[y][x] == 'E' && !(game->map->coins))
	{
		ft_printf("Player moves : %d\n", ++(game->moves));
		mlx_close_window(game->mlx);
	}
}

void	move_left(t_game *game)
{
	int32_t		x;
	int32_t		y;
	t_texture	*texture;
	mlx_image_t	*player;
	mlx_image_t	*ground;

	texture = game->textures;
	player = game->player->img[0];
	ground = texture->img[GROUND];
	x = (player->instances[0].x - IMG_WH) / IMG_WH;
	y = player->instances[0].y  / IMG_WH;
	game->map->data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = '0';
	if (game->map->data[y][x] == '0' || game->map->data[y][x] == 'C')
	{
		if (game->map->data[y][x] == 'C')
			game->map->coins--;
		mlx_image_to_window(game->mlx, ground, player->instances[0].x, player->instances[0].y);
		player->instances[0].x -= IMG_WH;
		mlx_image_to_window(game->mlx, game->player->img[2], player->instances[0].x, player->instances[0].y);
		ft_printf("Player moves : %d\n", ++(game->moves));
	}
	else if (game->map->data[y][x] == 'E' && !(game->map->coins))
	{
		ft_printf("Player moves : %d\n", ++(game->moves));
		mlx_close_window(game->mlx);
	}
}

void move_down(t_game *game)
{
	int32_t		x;
	int32_t		y;
	t_texture	*texture;
	mlx_image_t	*player;

	texture = game->textures;
	player = game->player->img[0];
	x = player->instances[0].x / IMG_WH;
	y = (player->instances[0].y + IMG_WH) / IMG_WH;
	game->map->data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = '0';
	if (game->map->data[y][x] == '0' || game->map->data[y][x] == 'C')
	{
		if (game->map->data[y][x] == 'C')
			game->map->coins--;
		mlx_image_to_window(game->mlx, texture->img[0], player->instances[0].x, player->instances[0].y);
		player->instances[0].y += IMG_WH;
		mlx_image_to_window(game->mlx, game->player->img[0], player->instances[0].x, player->instances[0].y);
		ft_printf("Player moves : %d\n", ++(game->moves));
	}
	else if (game->map->data[y][x] == 'E' && !(game->map->coins))
	{
		ft_printf("Player moves : %d\n", ++(game->moves));
		mlx_close_window(game->mlx);
	}
}

void move_right(t_game *game)
{
	int32_t		x;
	int32_t		y;
	t_texture	*texture;
	mlx_image_t	*player;

	texture = game->textures;
	player = game->player->img[0];
	x = (player->instances[0].x + IMG_WH) / IMG_WH;
	y = player->instances[0].y / IMG_WH;
	game->map->data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = '0';
	if (game->map->data[y][x] == '0' || game->map->data[y][x] == 'C')
	{
		if (game->map->data[y][x] == 'C')
			game->map->coins--;
		mlx_image_to_window(game->mlx, texture->img[0], player->instances[0].x, player->instances[0].y);
		player->instances[0].x += IMG_WH;
		mlx_image_to_window(game->mlx, game->player->img[3], player->instances[0].x, player->instances[0].y);
		ft_printf("Player moves : %d\n", ++(game->moves));
	}
	else if (game->map->data[y][x] == 'E' && !(game->map->coins))
	{
		ft_printf("Player moves : %d\n", ++(game->moves));
		mlx_close_window(game->mlx);
	}
}
