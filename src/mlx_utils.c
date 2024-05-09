/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:28:43 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/09 20:39:06 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_textures(char *textures[], int size)
{
	int				i;
	mlx_texture_t	*texture;

	i = 0;
	while (i < size)
	{
		texture = mlx_load_png(textures[i]);
		if (!texture)
			return (false);
		mlx_delete_texture(texture);
		i++;
	}
	return (true);
}

void	check_textures(char *paths[], int size)
{
	if (!valid_textures(paths, size))
	{
		printf("Error : missing or invalid textures.\n");
		exit (EXIT_FAILURE);
	}
}

void	key_events(mlx_key_data_t keydata, void *param)
{
	t_game  *game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        move_up(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        move_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        move_down(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        move_right(game);
}
