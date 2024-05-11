/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:29:13 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/11 19:56:26 by aaitelka         ###   ########.fr       */
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

bool	valid_char(char c)
{
	return ((c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E' || c == '\n'));
}

int	is_double_or_null(char *map)
{
	int	i;
	int	p;
	int	e;
	int	c;
	int	len;
	int	lenght;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
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
		else if (map[i] == 'C')
			c++;
		i++;
	}
	if (p != 1)
		return (55);
	else if (e != 1)
		return (66);
	else if (c == 0)
		return (77);
	return (0);
}

void	check_map(char *map)
{
	if (is_double_or_null(map) == 55)
		ft_putstr_fd(ERR, STDERR_FILENO);
	else if (is_double_or_null(map) == 66)
		ft_putstr_fd(ERR, STDERR_FILENO);
	else if(is_double_or_null(map) == 77)
		ft_putstr_fd(ERR, STDERR_FILENO);
	else if (is_double_or_null(map) == 10)
		ft_putstr_fd(ERR, STDERR_FILENO);
	else if (is_double_or_null(map) == 11)
		ft_putstr_fd(ERR, STDERR_FILENO);
	else if (is_double_or_null(map) == ERROR)
		ft_putstr_fd(ERR, STDERR_FILENO);
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
		assert_error(ERR);
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
