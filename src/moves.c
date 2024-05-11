/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:44:52 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/11 13:28:46 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	move_up(t_game *game)
{
	int32_t		x;
	int32_t		y;
	t_texture	texture;
	mlx_image_t	*player;

	texture = game->tex;
	player = texture.img[I_PF];
	x = player->instances[0].x / IMG_WH;
	y = (player->instances[0].y - IMG_WH) / IMG_WH;
	game->map.data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = game->keys[0];
	if (game->map.data[y][x] == '0' || game->map.data[y][x] == 'C')
	{
		if (game->map.data[y][x] == 'C')
			game->map.coins--;
		mlx_image_to_window(game->mlx, texture.img[I_GROUND], player->instances[0].x, player->instances[0].y);
		player->instances[0].y -= IMG_WH;
		mlx_image_to_window(game->mlx, texture.img[I_PB], player->instances[0].x, player->instances[0].y);
		ft_printf("Player moves : %d\n", ++(game->moves));
	}
	else if (game->map.data[y][x] == 'E' && !(game->map.coins))
	{
		ft_printf("Player moves : %d\n", ++(game->moves));
		mlx_close_window(game->mlx);
	}
}

void	move_left(t_game *game)
{
	int32_t		x;
	int32_t		y;
	t_texture	tex;
	mlx_image_t	*player;
	mlx_image_t	*ground;

	tex = game->tex;
	player = tex.img[I_PF];
	ground = tex.img[0];
	x = (player->instances[0].x - IMG_WH) / IMG_WH;
	y = player->instances[0].y  / IMG_WH;
	game->map.data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = '0';
	if (game->map.data[y][x] == '0' || game->map.data[y][x] == 'C')
	{
		if (game->map.data[y][x] == 'C')
			game->map.coins--;
		mlx_image_to_window(game->mlx, tex.img[I_GROUND], player->instances[0].x, player->instances[0].y);
		player->instances[0].x -= IMG_WH;
		mlx_image_to_window(game->mlx, tex.img[I_PL], player->instances[0].x, player->instances[0].y);
		ft_printf("Player moves : %d\n", ++(game->moves));
	}
	else if (game->map.data[y][x] == 'E' && !(game->map.coins))
	{
		ft_printf("Player moves : %d\n", ++(game->moves));
		mlx_close_window(game->mlx);
	}
}

void move_down(t_game *game)
{
	int32_t		x;
	int32_t		y;
	t_texture	tex;
	mlx_image_t	*player;

	tex = game->tex;
	player = tex.img[I_PF];
	x = player->instances[0].x / IMG_WH;
	y = (player->instances[0].y + IMG_WH) / IMG_WH;
	game->map.data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = '0';
	if (game->map.data[y][x] == '0' || game->map.data[y][x] == 'C')
	{
		if (game->map.data[y][x] == 'C')
			game->map.coins--;
		mlx_image_to_window(game->mlx, tex.img[I_GROUND], player->instances[0].x, player->instances[0].y);
		player->instances[0].y += IMG_WH;
		mlx_image_to_window(game->mlx, tex.img[I_PF], player->instances[0].x, player->instances[0].y);
		ft_printf("Player moves : %d\n", ++(game->moves));
	}
	else if (game->map.data[y][x] == 'E' && !(game->map.coins))
	{
		ft_printf("Player moves : %d\n", ++(game->moves));
		mlx_close_window(game->mlx);
	}
}

void move_right(t_game *game)
{
	int32_t		x;
	int32_t		y;
	t_texture	tex;
	mlx_image_t	*player;

	tex = game->tex;
	player = tex.img[I_PF];
	x = (player->instances[0].x + IMG_WH) / IMG_WH;
	y = player->instances[0].y / IMG_WH;
	game->map.data[player->instances[0].y / IMG_WH][player->instances[0].x / IMG_WH] = '0';
	if (game->map.data[y][x] == '0' || game->map.data[y][x] == 'C')
	{
		if (game->map.data[y][x] == 'C')
			game->map.coins--;
		mlx_image_to_window(game->mlx, tex.img[I_GROUND], player->instances[0].x, player->instances[0].y);
		player->instances[0].x += IMG_WH;
		mlx_image_to_window(game->mlx, tex.img[I_PR], player->instances[0].x, player->instances[0].y);
		ft_printf("Player moves : %d\n", ++(game->moves));
	}
	else if (game->map.data[y][x] == 'E' && !(game->map.coins))
	{
		ft_printf("Player moves : %d\n", ++(game->moves));
		mlx_close_window(game->mlx);
	}
}
