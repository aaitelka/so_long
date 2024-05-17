/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:01:49 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 20:28:35 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


int	lstsize(t_point *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst && ++size)
	{
		if (!(lst))
			break;
		lst = lst->next;
	}
	return (size);
}

void l()
{
	system("leaks so_long_bonus");
}

void animate_coin(t_game *game)
{
	static int i = 0;
	static int index = 0;
	int size = sizeof(game->tex.coin_img) / sizeof(game->tex.coin_img[0]);

	t_point *pos = game->map.coins_pos;
	if (!(++i % DELAY))
	{
		while (pos)
		{
			if (game->map.data[pos->x][pos->y] == 'C')
				put(game, game->tex.coin_img[index], pos->y * 60, pos->x * 60);
			pos = pos->next;
		}
		index++;
		if (index == size)
			index = 0;
	}
}

void animate_door(t_game *game)
{

	static int i = 0;
	static int index = 0;
	int size = sizeof(game->tex.door_img) / sizeof(game->tex.door_img[0]);
	
	if (!(game->map.coins) && index < size)
	{
		if (!(++i % DELAY))
		{
			put(game, game->tex.door_img[index], game->map.door_pos.x * 60, game->map.door_pos.y * 60);
			index++;
		}
	}
}


void	events_listener(void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	animate_coin(game);
	animate_door(game);
	animate_enemy(game);
}

void print_coins_pos(int x, int y)
{
	ft_printf("x : %d | y : %d\n", x, y);
}

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
	mlx_loop_hook(game.mlx, events_listener, &game);
	mlx_loop(game.mlx);
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
