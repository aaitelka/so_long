/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:44:52 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/13 22:02:03 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	refresh(t_game *game, mlx_image_t *img, int32_t x, int32_t y)
{
	mlx_image_to_window(game->mlx, img, x, y);
}

void	move_up(t_game *g)
{
	int32_t		x;
	int32_t		y;
	t_texture	t;
	mlx_image_t	*p;

	t = g->tex;
	p = t.img[I_PF];
	x = p->instances[0].x / IMG_WH;
	y = (p->instances[0].y - IMG_WH) / IMG_WH;
	g->map.data[p->instances[0].y / IMG_WH][p->instances[0].x / IMG_WH] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		if (g->map.data[y][x] == 'C')
			g->map.coins--;
		refresh(g, t.img[I_GROUND], p->instances[0].x, p->instances[0].y);
		p->instances[0].y -= IMG_WH;
		refresh(g, t.img[I_PB], p->instances[0].x, p->instances[0].y);
		refresh(g, t.img[I_WALL], 0, 0);
		mlx_put_string(g->mlx, ft_itoa(++(g->moves)), 30, 30);
	}
	else if (g->map.data[y][x] == DOOR && !(g->map.coins))
	{
		mlx_put_string(g->mlx, ft_itoa(++(g->moves)), 30, 30);
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
	x = (p->instances[0].x - IMG_WH) / IMG_WH;
	y = p->instances[0].y / IMG_WH;
	g->map.data[p->instances[0].y / IMG_WH][p->instances[0].x / IMG_WH] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		if (g->map.data[y][x] == 'C')
			g->map.coins--;
		refresh(g, tex.img[I_GROUND], p->instances[0].x, p->instances[0].y);
		p->instances[0].x -= IMG_WH;
		refresh(g, tex.img[I_PL], p->instances[0].x, p->instances[0].y);
		refresh(g, tex.img[I_WALL], 0, 0);
		mlx_put_string(g->mlx, ft_itoa(++(g->moves)), 30, 30);
	}
	else if (g->map.data[y][x] == 'E' && !(g->map.coins))
	{
		mlx_put_string(g->mlx, ft_itoa(++(g->moves)), 30, 30);
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
	x = p->instances[0].x / IMG_WH;
	y = (p->instances[0].y + IMG_WH) / IMG_WH;
	g->map.data[p->instances[0].y / IMG_WH][p->instances[0].x / IMG_WH] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		if (g->map.data[y][x] == 'C')
			g->map.coins--;
		refresh(g, tex.img[I_GROUND], p->instances[0].x, p->instances[0].y);
		p->instances[0].y += IMG_WH;
		refresh(g, tex.img[I_PF], p->instances[0].x, p->instances[0].y);
		refresh(g, tex.img[I_WALL], 0, 0);
		mlx_put_string(g->mlx, ft_itoa(++(g->moves)), 30, 30);
	}
	else if (g->map.data[y][x] == 'E' && !(g->map.coins))
	{
		mlx_put_string(g->mlx, ft_itoa(++(g->moves)), 30, 30);
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
	x = (p->instances[0].x + IMG_WH) / IMG_WH;
	y = p->instances[0].y / IMG_WH;
	g->map.data[p->instances[0].y / IMG_WH][p->instances[0].x / IMG_WH] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		if (g->map.data[y][x] == 'C')
			g->map.coins--;
		refresh(g, tex.img[I_GROUND], p->instances[0].x, p->instances[0].y);
		p->instances[0].x += IMG_WH;
		refresh(g, tex.img[I_PR], p->instances[0].x, p->instances[0].y);
		refresh(g, tex.img[I_WALL], 0, 0);
		mlx_put_string(g->mlx, ft_itoa(++(g->moves)), 30, 30);
	}
	else if (g->map.data[y][x] == 'E' && !(g->map.coins))
	{
		mlx_put_string(g->mlx, ft_itoa(++(g->moves)), 30, 30);
		mlx_close_window(g->mlx);
	}
}
