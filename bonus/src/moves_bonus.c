/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:44:52 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/18 13:38:22 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	should_move(t_game *g, char dest)
{
	if (dest == UP)
		return (g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] == '0'
				|| g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] == 'C'
				|| g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] == 'N');
	else if (dest == LEFT)
		return (g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] == '0'
				|| g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] == 'C'
				|| g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] == 'N');
	else if (dest == DOWN)
		return (g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] == '0'
				|| g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] == 'C'
				|| g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] == 'N');
	else if (dest == RIGHT)
		return (g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] == '0'
				|| g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] == 'C'
				|| g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] == 'N');
	else
		return (false);
}

void	move_up(t_game *g)
{
	if (should_move(g, UP))
	{
		if (g->map.data[g->map.p_pos.y][g->map.p_pos.x] == 'N')
			mlx_close_window(g->mlx);
		if (g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] == 'C')
			g->map.coins--;
		g->map.data[g->map.p_pos.y][g->map.p_pos.x] = '0';
		put(g, g->tex.main_img[0], g->map.p_pos.x * W, g->map.p_pos.y * W);
		g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] = 'P';
		g->map.p_pos.y -= 1;
		put(g, g->tex.player_img[1], g->map.p_pos.x * W, g->map.p_pos.y * W);
		put(g, g->tex.main_img[1], 0, 0);
		put(g, g->tex.main_img[1], W, 0);
		g->step = ft_itoa(++(g->moves));
		mlx_put_string(g->mlx, g->step, 30, 30);
		free(g->step);
		g->map.index = 1;
	}
	else if (g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] == DOOR
		&& !(g->map.coins))
		mlx_close_window(g->mlx);
}

void	move_left(t_game *g)
{
	if (should_move(g, LEFT))
	{
		if (g->map.data[g->map.p_pos.y][g->map.p_pos.x] == 'N')
			mlx_close_window(g->mlx);
		if (g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] == 'C')
			g->map.coins--;
		g->map.data[g->map.p_pos.y][g->map.p_pos.x] = '0';
		put(g, g->tex.main_img[0], g->map.p_pos.x * W, g->map.p_pos.y * W);
		g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] = 'P';
		g->map.p_pos.x -= 1;
		put(g, g->tex.player_img[2], g->map.p_pos.x * W, g->map.p_pos.y * W);
		put(g, g->tex.main_img[1], 0, 0);
		put(g, g->tex.main_img[1], W, 0);
		g->step = ft_itoa(++(g->moves));
		mlx_put_string(g->mlx, g->step, 30, 30);
		free(g->step);
		g->map.index = 2;
	}
	else if (g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] == DOOR
		&& !(g->map.coins))
		mlx_close_window(g->mlx);
}

void	move_down(t_game *g)
{
	if (should_move(g, DOWN))
	{
		if (g->map.data[g->map.p_pos.y][g->map.p_pos.x] == 'N')
			mlx_close_window(g->mlx);
		if (g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] == 'C')
			g->map.coins--;
		g->map.data[g->map.p_pos.y][g->map.p_pos.x] = '0';
		put(g, g->tex.main_img[0], g->map.p_pos.x * W, g->map.p_pos.y * W);
		g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] = 'P';
		g->map.p_pos.y += 1;
		put(g, g->tex.player_img[0], g->map.p_pos.x * W, g->map.p_pos.y * W);
		put(g, g->tex.main_img[1], 0, 0);
		put(g, g->tex.main_img[1], W, 0);
		g->step = ft_itoa(++(g->moves));
		mlx_put_string(g->mlx, g->step, 30, 30);
		free(g->step);
		g->map.index = 0;
	}
	else if (g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] == DOOR
		&& !(g->map.coins))
		mlx_close_window(g->mlx);
}

void	move_right(t_game *g)
{
	if (should_move(g, RIGHT))
	{
		if (g->map.data[g->map.p_pos.y][g->map.p_pos.x] == 'N')
			mlx_close_window(g->mlx);
		if (g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] == 'C')
			g->map.coins--;
		g->map.data[g->map.p_pos.y][g->map.p_pos.x] = '0';
		put(g, g->tex.main_img[0], g->map.p_pos.x * W, g->map.p_pos.y * W);
		g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] = 'P';
		g->map.p_pos.x += 1;
		put(g, g->tex.player_img[3], g->map.p_pos.x * W, g->map.p_pos.y * W);
		put(g, g->tex.main_img[1], 0, 0);
		put(g, g->tex.main_img[1], W, 0);
		g->step = ft_itoa(++(g->moves));
		mlx_put_string(g->mlx, g->step, 30, 30);
		free(g->step);
		g->map.index = 3;
	}
	else if (g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] == DOOR
		&& !(g->map.coins))
		mlx_close_window(g->mlx);
}
