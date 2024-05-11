/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:00:18 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/11 20:01:42 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>
# include <MLX42/MLX42.h>

# define EXT ".ber"

# define ERROR -1
# define IMG_WH 60

# define I_GROUND 0
# define I_WALL 1
# define I_COIN 2
# define I_DOOR 3
# define I_PF 4
# define I_PB 5
# define I_PL 6
# define I_PR 7

# define TITLE "SOO_______L______ONG"
// # define ERR_WINDOW	"window size bigger than monitor size\n"
// # define ERR_ARGS "missing map! should run game as follow ./so_long [map].ber.\n"
// # define ERR_EXIT "Error : map has no (or double) exit.\n"
// # define ERR_PLAYER "Error : map has no (or double) player.\n"
// # define ERR_MALLOC "malloc failed.\n"
// # define ERR_TEXTURE "failed to load png files.\n"
// # define ERR_MLX_INIT "mlx init failed.\n"
// # define ERR_GAME_INIT "game init failed.\n"
// # define ERR_MAP_WALL "map has non valid char in wall.\n"
// # define ERR_MAP_HNOC "Error : map has no collectible.\n"
// # define ERR_MAP_EMLIN "Error : map has one empty line or more.\n"
// # define ERR_MAP_NRECT "Error : map not rectangulare.\n"
// # define ERR_MAP_HUNKC "Error : map has unknown character.\n"
// # define ERR_MAP_EORNE "map empty or map file not exists.\n"
// # define ERR_MAP_LOAD "loading map.\n"
// # define ERR_EXTENSION "invalid extention, should use [.ber] map file.\n"
// # define ERR_ACCESS_EC "the door or collectibles will not be accessible.\n"
# define ERR "Error\n"
# define PLAYER_FRONT "textures/player_front.png"
# define PLAYER_BACK "textures/player_back.png"
# define PLAYER_LEFT "textures/player_left.png"
# define PLAYER_RIGHT "textures/player_right.png"
# define TEXTURE_WALL "textures/wall_n.png"
# define TEXTURE_COIN "textures/ball.png"
# define TEXTURE_DOOR "textures/door.png"
# define TEXTURE_GROUND "textures/ground.png"

# define SIZE(arr) ((int) (sizeof (arr) / sizeof (arr)[0]) - 1)

typedef struct s_path
{
	char	*uris[9];
}	t_path;

typedef struct s_map
{
	int		x;
	int		y;
	int		px;
	int		py;
	int		coins;
	char	**data;
}		t_map;

typedef struct s_texture
{
	mlx_texture_t	*texture[8];
	mlx_image_t		*img[8];
}	t_texture;

typedef struct s_game
{
	int			width;
	int			height;
	int			moves;
	int			row;
	int			col;
	char		*keys;
	mlx_t		*mlx;
	t_map		map;
	t_texture	tex;
	t_texture	player;
}		t_game;

/**
 *	GAME
*/

bool	init_game(t_game *game, t_path paths, char *av[]);
void	check_window_size(t_game game);
void    fill_window(t_game game);

/**
 *	MOVES
*/

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

/**
 *	MAP
*/

bool	is_valid_ext(char *filename);
bool	should_stay(char *map[], int size);
int		count_coins(char *map2d[]);
void	check_map(char *map);
void	get_player_position(t_map *map);
char	*read_map(char *filename);
char	**load_map(char *filename);
void	flood_fill(char *map[], int y, int x);

/**
 *	TEXTURE
*/

t_path	init_paths();
bool	valid_textures(t_path paths);

/**
 *	MLX UTILS
*/

void	key_events(mlx_key_data_t keydata, void *param);

/**
 *	CLEANER
*/

void	assert_error(char *msg);

/**
 *	CLEANER
*/

void	clear_map(char **map);
void	destroy(t_game game);

#endif
