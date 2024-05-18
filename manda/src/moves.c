/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:44:52 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/18 01:18:58 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *g)
{
	int32_t		x;
	int32_t		y;
	t_texture	t;
	mlx_image_t	*p;

	t = g->tex;
	p = t.img[I_PF];
	x = p->instances[0].x / W;
	y = (p->instances[0].y - W) / W;
	g->map.data[p->instances[0].y / W][p->instances[0].x / W] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		if (g->map.data[y][x] == 'C')
			g->map.coins--;
		put(g, t.img[I_GROUND], p->instances[0].x, p->instances[0].y);
		p->instances[0].y -= W;
		put(g, t.img[I_PB], p->instances[0].x, p->instances[0].y);
		ft_printf("%s : %d\n", PLAYER_STEPS, ++(g->moves));
	}
	else if (g->map.data[y][x] == DOOR && !(g->map.coins))
	{
		ft_printf("%s : %d\n", PLAYER_STEPS, ++(g->moves));
		mlx_close_window(g->mlx);
	}
}

void	move_left(t_game *g)
{
	int32_t		x;
	int32_t		y;
	t_texture	tex;
	mlx_image_t	*p;

	tex = g->tex;
	p = tex.img[I_PF];
	x = (p->instances[0].x - W) / W;
	y = p->instances[0].y / W;
	g->map.data[p->instances[0].y / W][p->instances[0].x / W] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		if (g->map.data[y][x] == 'C')
			g->map.coins--;
		put(g, tex.img[I_GROUND], p->instances[0].x, p->instances[0].y);
		p->instances[0].x -= W;
		put(g, tex.img[I_PL], p->instances[0].x, p->instances[0].y);
		ft_printf("%s : %d\n", PLAYER_STEPS, ++(g->moves));
	}
	else if (g->map.data[y][x] == 'E' && !(g->map.coins))
	{
		ft_printf("%s : %d\n", PLAYER_STEPS, ++(g->moves));
		mlx_close_window(g->mlx);
	}
}

void	move_down(t_game *g)
{
	int32_t		x;
	int32_t		y;
	t_texture	tex;
	mlx_image_t	*p;

	tex = g->tex;
	p = tex.img[I_PF];
	x = p->instances[0].x / W;
	y = (p->instances[0].y + W) / W;
	g->map.data[p->instances[0].y / W][p->instances[0].x / W] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		if (g->map.data[y][x] == 'C')
			g->map.coins--;
		put(g, tex.img[I_GROUND], p->instances[0].x, p->instances[0].y);
		p->instances[0].y += W;
		put(g, tex.img[I_PF], p->instances[0].x, p->instances[0].y);
		ft_printf("%s : %d\n", PLAYER_STEPS, ++(g->moves));
	}
	else if (g->map.data[y][x] == 'E' && !(g->map.coins))
	{
		ft_printf("%s : %d\n", PLAYER_STEPS, ++(g->moves));
		mlx_close_window(g->mlx);
	}
}

void	move_right(t_game *g)
{
	int32_t		x;
	int32_t		y;
	t_texture	tex;
	mlx_image_t	*p;

	tex = g->tex;
	p = tex.img[I_PF];
	x = (p->instances[0].x + W) / W;
	y = p->instances[0].y / W;
	g->map.data[p->instances[0].y / W][p->instances[0].x / W] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		if (g->map.data[y][x] == 'C')
			g->map.coins--;
		put(g, tex.img[I_GROUND], p->instances[0].x, p->instances[0].y);
		p->instances[0].x += W;
		put(g, tex.img[I_PR], p->instances[0].x, p->instances[0].y);
		ft_printf("%s : %d\n", PLAYER_STEPS, ++(g->moves));
	}
	else if (g->map.data[y][x] == 'E' && !(g->map.coins))
	{
		ft_printf("%s : %d\n", PLAYER_STEPS, ++(g->moves));
		mlx_close_window(g->mlx);
	}
}
