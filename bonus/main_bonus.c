/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:01:49 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/13 18:32:10 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void l()
{
	system("leaks so_long_bonus");
}
void	events_listener(void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
}

void	start_game(char *av[])
{
	t_game	game;
	t_path	paths;

	paths = init_paths();
	if (!init_game(&game, paths, av))
		assert_error(ERR_GAME_INIT);
	check_window_size(game);
	fill_window(game);
	mlx_put_string(game.mlx, ft_itoa(game.moves), 30, 30);
	mlx_key_hook(game.mlx, key_events, &game);
	mlx_loop(game.mlx);
	mlx_loop_hook(game.mlx, events_listener, &game);
	destroy(game);
}

int	main(int ac, char *av[])
{
	atexit(l);
	if (ac == 2)
		start_game(av);
	else
		assert_error(ERR_ARGS);
	return (EXIT_SUCCESS);
}
