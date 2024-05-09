/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:16 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/09 20:23:55 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

bool	valid_char(char c)
{
	return ((c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E' || c == '\n'));
}

int	is_double_or_null(char *map)
{
	int	i;
	int	p;
	int	e;
	int len;
	int	lenght;

	i = 0;
	p = 0;
	e = 0;
	len = 0;
	lenght = ft_strchr(map, '\n') - map;
	while (map[i])
	{
		if (!valid_char(map[i]))
			return (ERROR);
		if (map[i] != '\n')
			len++;
		if (map[i] == '\n' || map[i + 1] == '\0')
		{
			if (lenght != len)
				return (11);
			len = 0;
		}
		if (map[0] == '\n' || (map[i] == '\n' && map[i + 1] == '\n'))
			return (10);
		if (map[i] == 'P')
			p++;
		else if (map[i] == 'E')
			e++;
		i++;
	}
	if (p != 1)
		return (PLAYER);
	else if (e != 1)
		return (DOOR);
	return (0);
}

char	**load_map(char *filename)
{
	char	*map;
	char	**map2d;

	map = read_map(filename);
	if (!map)
	{
		ft_printf("Error : map is empty or map file not exists.\n");
		return (NULL);
	}
	check_map(map);
	map2d = ft_split(map, '\n');
	if (!map2d)
	{
		free(map);
		ft_printf("Error : malloc failed or map empty.\n");
		return (NULL);
	}
	if (!is_valid_wall(map2d))
	{
		free(map);
		clear_map(map2d);
		ft_printf("Error : map has non valid char in wall\n");
		return (NULL);
	}
	return (free(map), map2d);
}
