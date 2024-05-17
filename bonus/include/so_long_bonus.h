/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:00:18 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 20:44:45 by aaitelka         ###   ########.fr       */
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
bool	init_game(t_game *game, char *av[]);
/**
 *	MOVES
*/
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
//ENEMY
void	animate_enemy(t_game *game);
void	animator(void *param);
/**
 *	MAP
*/
char	**load_map(char *filename);
void	get_player_position(t_map *map);
void	get_coins_position(t_map *map);
void	get_enemies_position(t_map *map);
void	flood_fill(char *map[], int y, int x);
void	check_map(char *map);
int		count_coins(char *map2d[]);
/**
 *	TEXTURE
*/
void	init_textures(t_texture	*tex);
void	load_textures(t_game *game);
/**
 *	WINDOW
*/
void	fill_window(t_game *game);
void	check_window_size(t_game game);
void	put(t_game *game, mlx_image_t *img, int32_t x, int32_t y);
/**
 *	MLX UTILS
*/
void	key_events(mlx_key_data_t keydata, void *param);
// void	put_image(t_game *game);
/**
 *	ASSERTION
*/
void	assert_error(char *msg);
/**
 *	ASSERTION
*/
t_point	*new_pos(int x, int y);
void	add_pos(t_point **lst, t_point *new);
/**
 *	CLEANER
*/
void	clear_map(char **map);
void	clear_textures(t_texture tex);
void	clear_images(mlx_t *mlx, t_texture tex);
void	clear_pos(t_point *point);
void	destroy(t_game game);

#endif
