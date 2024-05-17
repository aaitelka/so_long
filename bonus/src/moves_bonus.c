/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:44:52 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 19:02:40 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	should_move(t_game *g, char dest)
{
	if (dest == UP)
		return (g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] == '0'
			|| g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] =='C'
			|| g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] == 'N');
	else if (dest == LEFT)
		return (g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] == '0'
			|| g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] =='C'
			|| g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] == 'N');
	else if (dest == DOWN)
		return (g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] == '0'
			|| g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] =='C'
			|| g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] == 'N');
	else if (dest == RIGHT)
		return (g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] == '0'
			|| g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] =='C'
			|| g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] =='N');
	else
		return(false);
}

void	move_up(t_game *g)
{
	if (should_move(g, UP))
	{
		if (g->map.data[g->map.p_pos.y][g->map.p_pos.x] == 'E')
			mlx_close_window(g->mlx);
		if (g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] == 'C')
			g->map.coins--;
		g->map.data[g->map.p_pos.y][g->map.p_pos.x] = '0';
		put_img(g, g->tex.main_img[0], g->map.p_pos.x * 60, g->map.p_pos.y * 60);
		g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] = 'P';
		g->map.p_pos.y -= 1;
		put_img(g, g->tex.player_img[1], g->map.p_pos.x * 60, g->map.p_pos.y * 60);
	}
	else if (g->map.data[g->map.p_pos.y - 1][g->map.p_pos.x] == DOOR
		&& !(g->map.coins))
	{
		mlx_close_window(g->mlx);
	}
}

void	move_left(t_game *g)
{
	if (should_move(g, LEFT))
	{
		if (g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] == 'C')
			g->map.coins--;
		g->map.data[g->map.p_pos.y][g->map.p_pos.x] = '0';
		put_img(g, g->tex.main_img[0], g->map.p_pos.x * 60, g->map.p_pos.y * 60);
		g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] = 'P';
		g->map.p_pos.x -= 1;
		put_img(g, g->tex.player_img[2], g->map.p_pos.x * 60, g->map.p_pos.y * 60);
	}
	else if (g->map.data[g->map.p_pos.y][g->map.p_pos.x - 1] == DOOR && !(g->map.coins))
	{
		mlx_close_window(g->mlx);
	}
}

void	move_down(t_game *g)
{
	if (should_move(g, DOWN))
	{
		if (g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] == 'C')
			g->map.coins--;
		g->map.data[g->map.p_pos.y][g->map.p_pos.x] = '0';
		put_img(g, g->tex.main_img[0], g->map.p_pos.x * 60, g->map.p_pos.y * 60);
		g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] = 'P';
		g->map.p_pos.y += 1;
		put_img(g, g->tex.player_img[0], g->map.p_pos.x * 60, g->map.p_pos.y * 60);
	}
	else if (g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] == DOOR && !(g->map.coins))
		mlx_close_window(g->mlx);
	// else if (g->map.data[g->map.p_pos.y + 1][g->map.p_pos.x] == 'N')
	// 	mlx_close_window(g->mlx);
}

void	move_right(t_game *g)
{
	if (should_move(g, RIGHT))
	{
		if (g->map.data[g->map.p_pos.y][g->map.p_pos.x] =='N')
			mlx_close_window(g->mlx);
		if (g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] == 'C')
			g->map.coins--;
		g->map.data[g->map.p_pos.y][g->map.p_pos.x] = '0';
		put_img(g, g->tex.main_img[0], g->map.p_pos.x * 60, g->map.p_pos.y * 60);
		g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] = 'P';
		g->map.p_pos.x += 1;
		put_img(g, g->tex.player_img[3], g->map.p_pos.x * 60, g->map.p_pos.y * 60);
	}
	else if (g->map.data[g->map.p_pos.y][g->map.p_pos.x + 1] == DOOR && !(g->map.coins))
	{
		mlx_close_window(g->mlx);
	}
}
