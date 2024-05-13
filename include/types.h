/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 02:25:10 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/13 02:25:13 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <libft.h>
# include <MLX42/MLX42.h>

# define EXT ".ber"

# define ERROR (-1)
# define IMG_WH 60
/**
 * TEXTURES INDEXE'S
*/
# define I_GROUND 0
# define I_WALL 1
# define I_COIN 2
# define I_DOOR 3
# define I_PF 4
# define I_PB 5
# define I_PL 6
# define I_PR 7
/**
 * VALID MAP CHAR'S
*/
# define GROUND '0'
# define WALL '1'
# define COIN 'C'
# define DOOR 'E'
# define PLAYER 'P'
/**
 * WINDOW TITLE
*/
# define TITLE "SOO_______L______ONG"
/**
 * ERROR MSG
*/
# define ERR_ARGS "Missing map! should run game as follow ./so_long [map].ber!\n"
# define ERR_EXTENSION "invalid extention!\n"
# define ERR_GAME_INIT "initializing game\n"
# define ERR_MAP "invalid map!\n"
# define ERR_WALL "invalid wall!\n"
# define ERR_MAP_OPEN "opening map file, maybe file not found!\n"
# define ERR_WINDOW "window size is too large!\n"
# define PLAYER_STEPS "player moves"
# define ERR_MLX_INIT "MLX init failed.\n"
# define ERR_MAP_EL "Error : map has empty line\n"
# define ERR_MAP_IC "Error : map has invalid char\n"
# define ERR_MAP_NR "Error : map not rectangulare\n"
# define ERR_MAP_HNP "Error : map has no player\n"
# define ERR_MAP_HMP "Error : map has multiple players\n"
# define ERR_MAP_HNE "Error : map has no exit\n"
# define ERR_MAP_HME "Error : map has multiple exit\n"
# define ERR_MAP_HNC "Error : map has no collectible\n"
/**
 * TEXTURES
*/
# define PLAYER_FRONT "textures/player_front.png"
# define PLAYER_BACK "textures/player_back.png"
# define PLAYER_LEFT "textures/player_left.png"
# define PLAYER_RIGHT "textures/player_right.png"
# define TEXTURE_WALL "textures/wall.png"
# define TEXTURE_COIN "textures/ball.png"
# define TEXTURE_DOOR "textures/door.png"
# define TEXTURE_GROUND "textures/ground.png"
/**
 * CALCULATE SIZE OF ANY ARRAY
*/
# define SIZE(arr) ((int)(sizeof(arr) / sizeof(arr)[0]) - 1)

typedef struct s_parse
{
	int	door;
	int	invalid;
	int	is_rect;
	int	new_line;
	int	player;
	int	length;
	int	collectible;
}	t_parse;

typedef struct s_path
{
    char *uris[9];
} t_path;

typedef struct s_map
{
    int x;
    int y;
    int px;
    int py;
    int coins;
    char **data;
} t_map;

typedef struct s_texture
{
    mlx_texture_t *texture[8];
    mlx_image_t *img[8];
} t_texture;

typedef struct s_game
{
    int width;
    int height;
    int moves;
    int row;
    int col;
    char *keys;
    mlx_t *mlx;
    t_map map;
    t_texture tex;
} t_game;

#endif