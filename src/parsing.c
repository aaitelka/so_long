/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:29:13 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/09 20:21:33 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

bool	is_valid_ext(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ft_strcmp(ext, EXT))
		return (true);
	return (false);
}

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

void	check_map(char *map)
{
	if (is_double_or_null(map) == PLAYER)
		ft_printf("Error : map has no (or double) player.\n");
	else if (is_double_or_null(map) == DOOR)
		ft_printf("Error : map has no (or double) exit.\n");
	else if (is_double_or_null(map) == 10)
		ft_printf("Error : map has one empty line or more.\n");
	else if (is_double_or_null(map) == 11)
		ft_printf("Error : map not rectangulare.\n");
	else if (is_double_or_null(map) == ERROR)
		ft_printf("Error : map has unknown character.\n");
	else
		return ;
	free(map);
	exit(EXIT_FAILURE);
}

char	*read_map(char *filename)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*map;

	if (!is_valid_ext(filename))
	{
		ft_printf("Error : invalid extention, should use [.ber] map file.\n");
		return (NULL);
	}
	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
		return (NULL);
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
