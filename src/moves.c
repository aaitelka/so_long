/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:44:52 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/06 19:26:18 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	print_moves(t_game *game)
{
	game->moves++;
	ft_putstr_fd("Player moves : ", STDOUT_FILENO);
	ft_putnbr_fd(game->moves, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void	move_up(t_game *game)
{
	int32_t		x;
	int32_t		y;
	t_texture	*texture;
	mlx_image_t	*player;

	texture = game->textures;
	player = game->textures->img[PLAYER];
	x = player->instances[0].x / IMG_WH;
	y = (player->instances[0].y - IMG_WH) / IMG_WH;
	game->map->data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = '0';
	if (game->map->data[y][x] == '0' || game->map->data[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx, texture->img[0], player->instances[0].x, player->instances[0].y);
		player->instances[0].y -= IMG_WH;
		mlx_image_to_window(game->mlx, player, player->instances[0].x, player->instances[0].y);
	} else if (game->map->data[y][x] == 'E')
	{
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
	player = texture->img[PLAYER];
	ground = texture->img[GROUND];
	x = (player->instances[0].x - IMG_WH) / IMG_WH;
	y = player->instances[0].y  / IMG_WH;
	game->map->data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = '0';
	if (game->map->data[y][x] == '0' || game->map->data[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx, ground, player->instances[0].x, player->instances[0].y);
		player->instances[0].x -= IMG_WH;
		mlx_image_to_window(game->mlx, player, player->instances[0].x, player->instances[0].y);
	} else if (game->map->data[y][x] == 'E')
	{
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
	player = game->textures->img[PLAYER];
	x = player->instances[0].x / IMG_WH;
	y = (player->instances[0].y + IMG_WH) / IMG_WH;
	game->map->data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = '0';
	if (game->map->data[y][x] == '0' || game->map->data[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx, texture->img[0], player->instances[0].x, player->instances[0].y);
		player->instances[0].y += IMG_WH;
		mlx_image_to_window(game->mlx, player, player->instances[0].x, player->instances[0].y);
	} else if (game->map->data[y][x] == 'E')
	{
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
	player = game->textures->img[PLAYER];
	x = (player->instances[0].x + IMG_WH) / IMG_WH;
	y = player->instances[0].y / IMG_WH;
	game->map->data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = '0';
	if (game->map->data[y][x] == '0' || game->map->data[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx, texture->img[0], player->instances[0].x, player->instances[0].y);
		player->instances[0].x += IMG_WH;
		mlx_image_to_window(game->mlx, player, player->instances[0].x, player->instances[0].y);
	} else if (game->map->data[y][x] == 'E')
	{
		mlx_close_window(game->mlx);
	}
}
