/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:01:49 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/13 17:51:04 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(char *av[])
{
	t_game	game;
	t_path	paths;

	paths = init_paths();
	if (!init_game(&game, paths, av))
		assert_error(ERR_GAME_INIT);
	check_window_size(game);
	fill_window(game);
	mlx_key_hook(game.mlx, key_events, &game);
	mlx_loop(game.mlx);
	destroy(game);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		start_game(av);
	else
		assert_error(ERR_ARGS);
	return (EXIT_SUCCESS);
}
