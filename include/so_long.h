/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:00:18 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/09 20:39:46 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "MLX42/MLX42.h"

# define EXT ".ber"

# define ERROR -1
# define IMG_WH 60

# define GROUND 0
# define WALL 1
# define PLAYER 2
# define COIN 3
# define DOOR 4
# define ENEMY 5

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
	mlx_texture_t	    *texture[4];
    mlx_image_t			*img[4];
}	t_texture;

typedef struct s_game
{
	int			width;
	int			height;
	int			moves;
	char		*keys;
	int32_t		row;
	int32_t		col;
	mlx_t		*mlx;
	t_map		*map;
	t_texture	*textures;
	t_texture	*player;
}		t_game;

/**
 *	MOVES
*/

void    move_up(t_game *game);

void    move_down(t_game *game);

void    move_left(t_game *game);

void    move_right(t_game *game);

/**
 *	MAP
*/

bool	is_valid_ext(char *filename);

bool	is_valid_wall(char *map2d[]);

bool	should_stay(char *map[], int size);

int		is_double_or_null(char *map);

int		count_collectibles(char *map2d[]);

void	check_map(char *map);

void	get_player_position(t_map *map);

char	*read_map(char *filename);

char	**load_map(char *filename);

void	flood_fill(char *map[], int y, int x);

/**
 *	MLX UTILS
*/

void	check_textures(char *paths[], int size);

void	key_events(mlx_key_data_t keydata, void *param);


/**
 *	CLEANER
*/

void	clear_map(char **map);

void	destroy(t_game *game);

#endif
