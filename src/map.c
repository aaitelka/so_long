/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:16 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/08 01:21:54 by aaitelka         ###   ########.fr       */
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

char	*read_map(char *filename)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*map;

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
	close(fd);
	return (map);
}

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

void	check_map(char *map)
{
	if (is_double_or_null(map) == PLAYER)
		ft_printf("Error : map has double player.\n");
	else if (is_double_or_null(map) == DOOR)
		ft_printf("Error : map has double exit.\n");
	else if (is_double_or_null(map) == 10)
		ft_printf("Error : map has empty line.\n");
	else if (is_double_or_null(map) == 11)
		ft_printf("Error : map not rectangulare.\n");
	else if (is_double_or_null(map) == ERROR)
		ft_printf("Error : map has unknown character.\n");
	else
		return ;
	free(map);
	exit(EXIT_FAILURE);
}

int	size_2dmap(char *map2d[])
{
	int size;

	size = 0;
	while (map2d[size])
		size++;
	return (size);
}

bool is_valid_wall(char *map2d[])
{
	int	i;
	int	j;
	int	size;
	int len;

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

	if (!is_valid_ext(filename))
	{
		ft_printf("Error : invalid extention, should use [.ber] map file.\n");
		exit(EXIT_FAILURE);
	}
	map = read_map(filename);
	if (!map)
	{
		ft_printf("Error : map is empty or map file not exists.");
		exit(EXIT_FAILURE);
	}
	check_map(map);
	map2d = ft_split(map, '\n');
	if (!*map2d || !is_valid_wall(map2d))
	{
		ft_printf("Error : map has non valid char in wall\n");
		exit(EXIT_FAILURE);
	}
	free(map);
	return (map2d);
}
