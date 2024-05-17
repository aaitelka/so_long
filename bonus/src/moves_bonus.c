/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:44:52 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 17:46:19 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	should_move(t_game *g, char dest)
{
	if (dest == 'U')
		return (g->map.data[g->map.player_pos.y - 1][g->map.player_pos.x] == '0'
			|| g->map.data[g->map.player_pos.y - 1][g->map.player_pos.x] =='C'
			|| g->map.data[g->map.player_pos.y - 1][g->map.player_pos.x] == 'N');
	else if (dest == 'L')
		return (g->map.data[g->map.player_pos.y][g->map.player_pos.x - 1] == '0'
			|| g->map.data[g->map.player_pos.y][g->map.player_pos.x - 1] =='C'
			|| g->map.data[g->map.player_pos.y][g->map.player_pos.x - 1] == 'N');
	else if (dest == 'D')
		return (g->map.data[g->map.player_pos.y + 1][g->map.player_pos.x] == '0'
			|| g->map.data[g->map.player_pos.y + 1][g->map.player_pos.x] =='C'
			|| g->map.data[g->map.player_pos.y + 1][g->map.player_pos.x] == 'N');
	else if (dest == 'R')
		return (g->map.data[g->map.player_pos.y][g->map.player_pos.x + 1] == '0'
			|| g->map.data[g->map.player_pos.y][g->map.player_pos.x + 1] =='C'
			|| g->map.data[g->map.player_pos.y][g->map.player_pos.x + 1] =='N');
	else
		return(false);
	
}

void	move_up(t_game *g)
{
	if (should_move(g,'U'))
	{
		if (g->map.data[g->map.player_pos.y][g->map.player_pos.x] == 'E')
			mlx_close_window(g->mlx);
		if (g->map.data[g->map.player_pos.y - 1][g->map.player_pos.x] == 'C')
			g->map.coins--;
		g->map.data[g->map.player_pos.y][g->map.player_pos.x] = '0';
		put_img(g, g->tex.main_img[0], g->map.player_pos.x * 60, g->map.player_pos.y * 60);
		g->map.data[g->map.player_pos.y - 1][g->map.player_pos.x] = 'P';
		g->map.player_pos.y -= 1;
		put_img(g, g->tex.player_img[1], g->map.player_pos.x * 60, g->map.player_pos.y * 60);
	}
	else if (g->map.data[g->map.player_pos.y - 1][g->map.player_pos.x] == DOOR && !(g->map.coins))
	{
		mlx_close_window(g->mlx);
	}
}

void	move_left(t_game *g)
{
	if (should_move(g, 'L'))
	{
		if (g->map.data[g->map.player_pos.y][g->map.player_pos.x - 1] == 'C')
			g->map.coins--;
		g->map.data[g->map.player_pos.y][g->map.player_pos.x] = '0';
		put_img(g, g->tex.main_img[0], g->map.player_pos.x * 60, g->map.player_pos.y * 60);
		g->map.data[g->map.player_pos.y][g->map.player_pos.x - 1] = 'P';
		g->map.player_pos.x -= 1;
		put_img(g, g->tex.player_img[2], g->map.player_pos.x * 60, g->map.player_pos.y * 60);
	}
	else if (g->map.data[g->map.player_pos.y][g->map.player_pos.x - 1] == DOOR && !(g->map.coins))
	{
		mlx_close_window(g->mlx);
	}
}

void	move_down(t_game *g)
{
	if (should_move(g, 'D'))
	{
		if (g->map.data[g->map.player_pos.y + 1][g->map.player_pos.x] == 'C')
			g->map.coins--;
		g->map.data[g->map.player_pos.y][g->map.player_pos.x] = '0';
		put_img(g, g->tex.main_img[0], g->map.player_pos.x * 60, g->map.player_pos.y * 60);
		g->map.data[g->map.player_pos.y + 1][g->map.player_pos.x] = 'P';
		g->map.player_pos.y += 1;
		put_img(g, g->tex.player_img[0], g->map.player_pos.x * 60, g->map.player_pos.y * 60);
	}
	else if (g->map.data[g->map.player_pos.y + 1][g->map.player_pos.x] == DOOR && !(g->map.coins))
		mlx_close_window(g->mlx);
	// else if (g->map.data[g->map.player_pos.y + 1][g->map.player_pos.x] == 'N')
	// 	mlx_close_window(g->mlx);
}

void	move_right(t_game *g)
{
	if (should_move(g, 'R'))
	{
		if (g->map.data[g->map.player_pos.y][g->map.player_pos.x] =='N')
			mlx_close_window(g->mlx);
		if (g->map.data[g->map.player_pos.y][g->map.player_pos.x + 1] == 'C')
			g->map.coins--;
		g->map.data[g->map.player_pos.y][g->map.player_pos.x] = '0';
		put_img(g, g->tex.main_img[0], g->map.player_pos.x * 60, g->map.player_pos.y * 60);
		g->map.data[g->map.player_pos.y][g->map.player_pos.x + 1] = 'P';
		g->map.player_pos.x += 1;
		put_img(g, g->tex.player_img[3], g->map.player_pos.x * 60, g->map.player_pos.y * 60);
	}
	else if (g->map.data[g->map.player_pos.y][g->map.player_pos.x + 1] == DOOR && !(g->map.coins))
	{
		mlx_close_window(g->mlx);
	}
}
