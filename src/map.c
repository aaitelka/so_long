/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:16 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/11 19:47:55 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	size_2dmap(char *map2d[])
{
	int	size;

	size = 0;
	while (map2d[size])
		size++;
	return (size);
}

bool	is_valid_wall(char *map2d[])
{
	int	i;
	int	j;
	int	size;
	int	len;

	if (!*map2d)
		return (false);
	i = 0;
	size = size_2dmap(map2d);
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			len = ft_strlen(map2d[i]);
			if (map2d[0][j] != '1' || map2d[size - 1][j] != '1')
				return (false);
			else if (map2d[i][0] != '1' || map2d[i][len - 1] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

char	**load_map(char *filename)
{
	char	*map;
	char	**map2d;

	map = read_map(filename);
	if (!map)
		assert_error(ERR);
	check_map(map);
	map2d = ft_split(map, '\n');
	if (!map2d)
		return (free(map), NULL);
	if (!is_valid_wall(map2d))
	{
		free(map);
		clear_map(map2d);
		assert_error(ERR);
	}
	return (free(map), map2d);
}
