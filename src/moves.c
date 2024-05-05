/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:44:52 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/04 23:44:56 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void move_up(t_game *game)
{
    if (game->map->data[game->textures->img[2]->instances[0].y / IMG_WH][game->textures->img[2]->instances[0].x / IMG_WH] == 'C')
    {
        mlx_image_to_window(game->mlx, game->textures->img[0],
                            game->textures->img[2]->instances[0].x,
                            game->textures->img[2]->instances[0].y);
    }
    game->textures->img[2]->instances[0].y -= IMG_WH;

}

void move_left(t_game *game)
{
    game->textures->img[2]->instances[0].x -= IMG_WH;
    if (game->map->data[game->textures->img[2]->instances[0].y / IMG_WH][game->textures->img[2]->instances[0].x / IMG_WH] == 'C') {
        mlx_image_to_window(game->mlx, game->textures->img[0],
                            game->textures->img[2]->instances[0].x,
                            game->textures->img[2]->instances[0].y);
    }
}

void move_down(t_game *game)
{
    game->textures->img[2]->instances[0].y += IMG_WH;
    if (game->map->data[game->textures->img[2]->instances[0].y / IMG_WH][game->textures->img[2]->instances[0].x / IMG_WH] == 'C') {
        mlx_image_to_window(game->mlx, game->textures->img[0],
                            game->textures->img[2]->instances[0].x,
                            game->textures->img[2]->instances[0].y);
    }
}

void move_right(t_game *game)
{
    game->textures->img[2]->instances[0].x += IMG_WH;
    if (game->map->data[game->textures->img[2]->instances[0].y / IMG_WH][game->textures->img[2]->instances[0].x / IMG_WH] == 'C') {
        mlx_image_to_window(game->mlx, game->textures->img[0],
                            game->textures->img[2]->instances[0].x,
                            game->textures->img[2]->instances[0].y);
    }
}