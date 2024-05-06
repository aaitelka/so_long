/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:16 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/06 18:25:15 by aaitelka         ###   ########.fr       */
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

char	*get_file_name(char *agrv[])
{
	return (agrv[1]);
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

char	**load_map(char *av[])
{
	char	*filename;
	char	*map;
	char	**map2d;

	filename = get_file_name(av);
	if (!is_valid_ext(filename))
		ft_putstr_fd("Error : invalid extention, should use [.ber] map file.\n", STDERR_FILENO);
	map = read_map(filename);
	map2d = ft_split(map, '\n');
	free(map);
	return (map2d);
}
