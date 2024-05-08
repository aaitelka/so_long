/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:00:18 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/07 01:51:19 by aaitelka         ###   ########.fr       */
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
	char	**data;
}		t_map;

typedef struct s_texture
{
	mlx_texture_t	    *texture[6];
    struct mlx_image    *img[6];
}	t_texture;

typedef struct s_game
{
	int			width;
	int			height;
	int			moves;
	int			coins;
	char		*keys;
	int32_t		row;
	int32_t		col;
	mlx_t		*mlx;
	t_map		*map;
	t_texture	*textures;
}		t_game;

/**
 *	MOVES
*/

void	print_moves(t_game *game);

void    move_up(t_game *game);

void    move_down(t_game *game);

void    move_left(t_game *game);

void    move_right(t_game *game);

/**
 *	MAP
*/

char	**load_map(char *filename);

/**
 *	CLEANER
*/

void	destroy(t_game *game);

#endif
