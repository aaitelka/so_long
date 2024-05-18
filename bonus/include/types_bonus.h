/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 02:25:10 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/18 20:52:47 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_BONUS_H
# define TYPES_BONUS_H

# include <libft.h>
# include <MLX42/MLX42.h>

# define EXT ".ber"
# define W 60
# define UP 'U'
# define DOWN 'D'
# define LEFT 'L'
# define RIGHT 'R'
/**
 * TEXTURES INDEXE'S
*/
# define I_GR 0
# define I_WA 1
# define I_DO 2
# define I_PF 3
# define I_PB 4
# define I_PL 5
# define I_PR 6
# define I_CO 7
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
# define ERR_ARGS "Missing map! run game as follow ./so_long [map].ber!\n"
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
# define ERR_ENEMIES "map has double enemies in the same line\n"
/**
 * TEXTURES
*/
# define TEXTURE_GROUND "textures/ground.png"
# define TEXTURE_WALL "textures/wall.png"
# define TEXTURE_DOOR "textures/door.png"
//PLAYER
# define PLAYER_FRONT "textures/player_front.png"
# define PLAYER_BACK "textures/player_back.png"
# define PLAYER_LEFT "textures/player_left.png"
# define PLAYER_RIGHT "textures/player_right.png"
//DOOR
# define DOOR_01 "textures/door_1.png"
# define DOOR_02 "textures/door_2.png"
# define DOOR_03 "textures/door_3.png"
# define DOOR_04 "textures/door_4.png"
//COIN
# define DELAY 10
# define COIN_ST 7
# define COIN_EN 16
# define COIN_01 "textures/coin_1.png"
# define COIN_02 "textures/coin_2.png"
# define COIN_03 "textures/coin_3.png"
# define COIN_04 "textures/coin_4.png"
# define COIN_05 "textures/coin_5.png"
# define COIN_06 "textures/coin_6.png"
# define COIN_07 "textures/coin_7.png"
# define COIN_08 "textures/coin_8.png"
# define COIN_09 "textures/coin_9.png"
# define COIN_10 "textures/coin_10.png"
//ENEMY
# define ENEMY_01 "textures/enemy_1.png"
# define ENEMY_02 "textures/enemy_2.png"
# define ENEMY_03 "textures/enemy_3.png"
# define ENEMY_04 "textures/enemy_4.png"
# define ENEMY_05 "textures/enemy_5.png"
# define ENEMY_06 "textures/enemy_6.png"
# define ENEMY_07 "textures/enemy_7.png"
# define ENEMY_08 "textures/enemy_8.png"
# define ENEMY_09 "textures/enemy_9.png"
# define ENEMY_10 "textures/enemy_10.png"
/**
 * CALCULATE SIZE OF ANY ARRAY
*/

typedef struct s_point
{
	int				x;
	int				y;
	int				index;
	int				step;
	bool			dir;
	struct s_point	*next;
}	t_point;

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

typedef struct s_map
{
	int			x;
	int			y;
	int			coins;
	char		**data;
	int			index;
	t_point		door_pos;
	t_point		p_pos;
	t_point		*coins_pos;
	t_point		*enemies_pos;
}	t_map;

typedef struct s_texture
{
	char			*main_uris[3];
	char			*door_uris[5];
	char			*coin_uris[11];
	char			*player_uris[5];
	char			*enemy_uris[11];
	mlx_texture_t	*texture;
	mlx_image_t		*main_img[2];
	mlx_image_t		*door_img[4];
	mlx_image_t		*coin_img[10];
	mlx_image_t		*player_img[4];
	mlx_image_t		*enemy_img[10];
}	t_texture;

typedef struct s_game
{
	int			width;
	int			height;
	int			moves;
	int			row;
	int			col;
	char		*keys;
	char		*step;
	mlx_t		*mlx;
	t_map		map;
	t_texture	tex;
}	t_game;

#endif
