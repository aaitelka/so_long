/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:45:15 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 17:39:03 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_door(t_texture	*tex)
{
	tex->door_uris[0] = DOOR_01;
	tex->door_uris[1] = DOOR_02;
	tex->door_uris[2] = DOOR_03;
	tex->door_uris[3] = DOOR_04;
	tex->door_uris[4] = NULL;
}

static void	init_player(t_texture	*tex)
{
	tex->player_uris[0] = PLAYER_FRONT;
	tex->player_uris[1] = PLAYER_BACK;
	tex->player_uris[2] = PLAYER_LEFT;
	tex->player_uris[3] = PLAYER_RIGHT;
	tex->player_uris[4] = NULL;
}

static void	init_coin(t_texture	*tex)
{
	tex->coin_uris[0] = COIN_01;
	tex->coin_uris[1] = COIN_02;
	tex->coin_uris[2] = COIN_03;
	tex->coin_uris[3] = COIN_04;
	tex->coin_uris[4] = COIN_05;
	tex->coin_uris[5] = COIN_06;
	tex->coin_uris[6] = COIN_07;
	tex->coin_uris[7] = COIN_08;
	tex->coin_uris[8] = COIN_09;
	tex->coin_uris[9] = COIN_10;
	tex->coin_uris[10] = NULL;
}

static void	init_enemy(t_texture	*tex)
{
	tex->enemy_uris[0] = ENEMY_01;
	tex->enemy_uris[1] = ENEMY_01;
	tex->enemy_uris[2] = ENEMY_01;
	tex->enemy_uris[3] = ENEMY_01;
	tex->enemy_uris[4] = ENEMY_01;
	tex->enemy_uris[5] = ENEMY_01;
	tex->enemy_uris[6] = ENEMY_01;
	tex->enemy_uris[7] = ENEMY_01;
	tex->enemy_uris[8] = ENEMY_01;
	tex->enemy_uris[9] = ENEMY_01;
	tex->enemy_uris[10] = NULL;
}

void	init_textures(t_texture	*tex)
{
	tex->main_uris[0] = TEXTURE_GROUND;
	tex->main_uris[1] = TEXTURE_WALL;
	tex->main_uris[2] = NULL;
	init_door(tex);
	init_player(tex);
	init_coin(tex);
	init_enemy(tex);
}
