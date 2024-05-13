/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:16 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/13 17:50:52 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid_ext(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext)
		return (false);
	else if (!ft_strcmp(ext, EXT))
		return (true);
	return (false);
}

static int	size_2dmap(char *map2d[])
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

	i = 0;
	size = size_2dmap(map2d);
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			len = ft_strlen(map2d[i]);
			if (map2d[0][j] != WALL || map2d[size - 1][j] != WALL)
				return (false);
			else if (map2d[i][0] != WALL || map2d[i][len - 1] != WALL)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static char	*read_map(char *filename)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*map;

	if (!is_valid_ext(filename))
		assert_error(ERR_EXTENSION);
	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		assert_error(ERR_MAP_OPEN);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(map, line);
		free(map);
		map = temp;
		free(line);
	}
	return (close(fd), map);
}

char	**load_map(char *filename)
{
	char	*map;
	char	**map2d;

	map = read_map(filename);
	if (!map)
		assert_error("Error reading map\n");
	check_map(map);
	map2d = ft_split(map, '\n');
	if (!map2d)
		return (free(map), NULL);
	if (!is_valid_wall(map2d))
	{
		free(map);
		clear_map(map2d);
		assert_error(ERR_WALL);
	}
	return (free(map), map2d);
}
