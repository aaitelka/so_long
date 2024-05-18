/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:01:49 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/18 01:07:34 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	start_game(char *av[])
{
	t_game	game;

	init_textures(&(game.tex));
	if (!init_game(&game, av))
		assert_error(ERR_GAME_INIT);
	check_window_size(game);
	get_player_position(&game.map);
	get_coins_position(&game.map);
	get_enemies_position(&game.map);
	fill_window(&game);
	game.step = ft_itoa(game.moves);
	mlx_put_string(game.mlx, game.step, 30, 30);
	free(game.step);
	mlx_key_hook(game.mlx, key_events, &game);
	mlx_loop_hook(game.mlx, animator, &game);
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
