/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:00:18 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/05 00:07:19 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERROR -1

# include "libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "MLX42/MLX42.h"

# define IMG_WH 60

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
	mlx_t		*mlx;
	t_map		*map;
	t_texture	*textures;
}		t_game;

void    move_up(t_game *game);

void    move_down(t_game *game);

void    move_left(t_game *game);

void    move_right(t_game *game);

#endif
