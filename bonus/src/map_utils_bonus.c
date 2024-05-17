/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:13:50 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 20:35:48 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(char *map[], int y, int x)
{
	if (map[y][x] == 'E')
		map[y][x] = '1';
	else if (map[y][x] != '1')
	{
		map[y][x] = '1';
		flood_fill(map, y - 1, x);
		flood_fill(map, y + 1, x);
		flood_fill(map, y, x - 1);
		flood_fill(map, y, x + 1);
	}
}

void	get_coins_position(t_map *map)
{
	int		i;
	int		j;
	t_point	*new_coin;

	i = 0;
	map->coins_pos = NULL;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == 'C')
			{
				new_coin = new_pos(i, j);
				add_pos(&map->coins_pos, new_coin);
			}
			j++;
		}
		i++;
	}
}

void	get_enemies_position(t_map *map)
{
	int		i;
	int		j;
	t_point	*new_enemy;

	i = 0;
	map->enemies_pos = NULL;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == 'N')
			{
				new_enemy = new_pos(i, j);
				add_pos(&map->enemies_pos, new_enemy);
			}
			j++;
		}
		i++;
	}
}

void	get_player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == 'P')
			{
				map->p_pos.x = j;
				map->p_pos.y = i;
				map->p_pos.next = NULL;
			}
			if (map->data[i][j] == 'E')
			{
				map->door_pos.x = j;
				map->door_pos.y = i;
				map->door_pos.next = NULL;
			}
			j++;
		}
		i++;
	}
}

int	count_coins(char *map2d[])
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}
