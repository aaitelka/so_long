/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:16 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/06 20:35:15 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

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

int	is_double_or_null(char *map)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (map[i])
    {
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

void check_map(char *map)
{
	if (is_double_or_null(map) == PLAYER)
		ft_printf("Error : map has double player.\n");
	else if (is_double_or_null(map) == DOOR)
		ft_printf("Error : map has double exit.\n");
	else
		return ;
	free(map);
	exit(EXIT_FAILURE);
}

char	**load_map(char *filename)
{
	char	*map;
	char	**map2d;

	if (!is_valid_ext(filename))
	{
		ft_putstr_fd("Error : invalid extention, should use [.ber] map file.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	map = read_map(filename);
	if (!map)
		return (NULL);
	check_map(map);
	map2d = ft_split(map, '\n');
	free(map);
	return (map2d);
}
