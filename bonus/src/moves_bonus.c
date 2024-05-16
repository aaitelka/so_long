/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:44:52 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/16 15:41:27 by aaitelka         ###   ########.fr       */
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
	p = t.player_img[0];
	x = p->instances[0].x / IMG_WH;
	y = (p->instances[0].y - IMG_WH) / IMG_WH;
	g->map.data[p->instances[0].y / IMG_WH][p->instances[0].x / IMG_WH] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		refresh(g, t.main_img[I_GR], p->instances[0].x, p->instances[0].y);
		p->instances[0].y -= IMG_WH;
		if (g->map.data[y][x] == 'C')
		{
			g->map.data[y][x] = '0';
			refresh(g, t.main_img[I_GR], p->instances[0].x, p->instances[0].y);
			g->map.coins--;
		}
		refresh(g, t.player_img[1], p->instances[0].x, p->instances[0].y);
		refresh(g, t.main_img[I_WA], 0, 0);
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
	t_texture	t;
	mlx_image_t	*p;

	t = g->tex;
	p = t.player_img[0];
	x = (p->instances[0].x - IMG_WH) / IMG_WH;
	y = p->instances[0].y / IMG_WH;
	g->map.data[p->instances[0].y / IMG_WH][p->instances[0].x / IMG_WH] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		refresh(g, t.main_img[I_GR], p->instances[0].x, p->instances[0].y);
		if (g->map.data[y][x] == 'C')
		{
			g->map.data[y][x] = '0';
			refresh(g, t.main_img[I_GR], p->instances[0].x, p->instances[0].y);
			g->map.coins--;
		}
		p->instances[0].x -= IMG_WH;
		refresh(g, t.player_img[2], p->instances[0].x, p->instances[0].y);
		refresh(g, t.main_img[1], 0, 0);
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
	t_texture	t;
	mlx_image_t	*p;

	t = g->tex;
	p = t.player_img[0];
	x = p->instances[0].x / IMG_WH;
	y = (p->instances[0].y + IMG_WH) / IMG_WH;
	g->map.data[p->instances[0].y / IMG_WH][p->instances[0].x / IMG_WH] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		refresh(g, t.main_img[I_GR], p->instances[0].x, p->instances[0].y);
		if (g->map.data[y][x] == 'C')
		{
			g->map.data[y][x] = '0';
			refresh(g, t.main_img[I_GR], p->instances[0].x, p->instances[0].y);
			g->map.coins--;
		}
		p->instances[0].y += IMG_WH;
		refresh(g, t.player_img[0], p->instances[0].x, p->instances[0].y);
		refresh(g, t.main_img[1], 0, 0);
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
	t_texture	t;
	mlx_image_t	*p;

	t = g->tex;
	p = t.player_img[0];
	x = (p->instances[0].x + IMG_WH) / IMG_WH;
	y = p->instances[0].y / IMG_WH;
	g->map.data[p->instances[0].y / IMG_WH][p->instances[0].x / IMG_WH] = '0';
	if (g->map.data[y][x] == '0' || g->map.data[y][x] == 'C')
	{
		refresh(g, t.main_img[I_GR], p->instances[0].x, p->instances[0].y);
		if (g->map.data[y][x] == 'C')
		{
			g->map.data[y][x] = '0';
			refresh(g, t.main_img[I_GR], p->instances[0].x, p->instances[0].y);
			g->map.coins--;
		}
		p->instances[0].x += IMG_WH;
		refresh(g, t.player_img[3], p->instances[0].x, p->instances[0].y);
		refresh(g, t.main_img[1], 0, 0);
		mlx_put_string(g->mlx, ft_itoa(++(g->moves)), 30, 30);
	}
	else if (g->map.data[y][x] == 'E' && !(g->map.coins))
	{
		mlx_put_string(g->mlx, ft_itoa(++(g->moves)), 30, 30);
		mlx_close_window(g->mlx);
	}
}

// void	move_up(t_game *g)
// {
// 	if (g->map.data[g->map.py - 1][g->map.px] == '0' || g->map.data[g->map.py - 1][g->map.px] =='C')
// 	{
// 		if (g->map.data[g->map.py - 1][g->map.px] == 'C')
// 		{
// 			g->map.data[g->map.py][g->map.px] = '0';
// 			g->map.data[g->map.py - 1][g->map.px] = 'P';
// 			g->map.coins--;
// 			g->map.py -= 1;
// 		}
// 		else
// 		{
// 			g->map.data[g->map.py][g->map.px] = '0';
// 			g->map.data[g->map.py - 1][g->map.px] = 'P';
// 			g->map.py -= 1;
// 		}
// 	}
// }

// void	move_left(t_game *g)
// {
// 	if (g->map.data[g->map.py][g->map.px - 1] == '0' || g->map.data[g->map.py][g->map.px - 1] =='C')
// 	{
// 		if (g->map.data[g->map.py][g->map.px - 1] == 'C')
// 		{
// 			g->map.data[g->map.py][g->map.px] = '0';
// 			g->map.data[g->map.py][g->map.px - 1] = 'P';
// 			g->map.coins--;
// 			g->map.px -= 1;
// 		}
// 		else
// 		{
// 			g->map.data[g->map.py][g->map.px] = '0';
// 			g->map.data[g->map.py][g->map.px - 1] = 'P';
// 			g->map.px -= 1;
// 		}
// 	}
// }

// void	move_down(t_game *g)
// {
// 	if (g->map.data[g->map.py + 1][g->map.px] == '0' || g->map.data[g->map.py + 1][g->map.px] =='C')
// 	{
// 		if (g->map.data[g->map.py + 1][g->map.px] == 'C')
// 		{
// 			g->map.data[g->map.py][g->map.px] = '0';
// 			g->map.data[g->map.py + 1][g->map.px] = 'P';
// 			g->map.coins--;
// 			g->map.py += 1;
// 		}
// 		else
// 		{
// 			g->map.data[g->map.py][g->map.px] = '0';
// 			g->map.data[g->map.py + 1][g->map.px] = 'P';
// 			g->map.py += 1;
// 		}
// 	}
// }

// void	move_right(t_game *g)
// {
// 	if (g->map.data[g->map.py][g->map.px + 1] == '0' || g->map.data[g->map.py][g->map.px + 1] =='C')
// 	{
// 		if (g->map.data[g->map.py][g->map.px + 1] == 'C')
// 		{
// 			g->map.data[g->map.py][g->map.px] = '0';
// 			g->map.data[g->map.py][g->map.px + 1] = 'P';
// 			g->map.coins--;
// 			g->map.px += 1;
// 		}
// 		else
// 		{
// 			g->map.data[g->map.py][g->map.px] = '0';
// 			g->map.data[g->map.py][g->map.px + 1] = 'P';
// 			g->map.px += 1;
// 		}
// 	}
// }
