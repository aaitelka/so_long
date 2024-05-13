/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:00:18 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/13 17:52:24 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdbool.h>
# include <fcntl.h>
# include <string.h>
# include "types_bonus.h"
/**
 *	GAME
*/
bool	init_game(t_game *game, t_path paths, char *av[]);
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
char	**load_map(char *filename);
bool	should_stay(char *map[], int size);
void	get_player_position(t_map *map);
void	flood_fill(char *map[], int y, int x);
void	check_map(char *map);
int		count_coins(char *map2d[]);
/**
 *	TEXTURE
*/
t_path	init_paths(void);
/**
 *	WINDOW
*/
void	fill_window(t_game game);
void	check_window_size(t_game game);
/**
 *	MLX UTILS
*/
void	key_events(mlx_key_data_t keydata, void *param);
/**
 *	ASSERTION
*/
void	assert_error(char *msg);
/**
 *	CLEANER
*/
void	clear_map(char **map);
void	clear_textures(t_texture tex);
void	clear_all(mlx_t *mlx, t_texture tex);
void	destroy(t_game game);

#endif
