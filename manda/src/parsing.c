/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:29:13 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/18 01:18:58 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_char(char c)
{
	return ((c == '0' || c == '1'
			|| c == 'P' || c == 'C'
			|| c == 'E' || c == '\n'));
}

static void	init_parse(t_parse *parse)
{
	parse->door = 0;
	parse->player = 0;
	parse->is_rect = 0;
	parse->invalid = 0;
	parse->new_line = 0;
	parse->collectible = 0;
}

static void	count_objects(t_parse *parse, char c)
{
	if (c == 'P')
		parse->player++;
	else if (c == 'E')
		parse->door ++;
	else if (c == 'C')
		parse->collectible++;
}

static void	parse_map(t_parse *parse, char *map, int length)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (map[i])
	{
		count_objects(parse, map[i]);
		if (!valid_char(map[i]) && parse->invalid++)
			break ;
		if (map[i] != '\n')
			len++;
		if (map[i] == '\n' || map[i + 1] == '\0')
		{
			if (length != len && parse->is_rect++)
				break ;
			len = 0;
		}
		if ((map[0] == '\n' || (map[i] == '\n' && map[i + 1] == '\n')
				|| (map[ft_strlen(map) - 1] == '\n')) && parse->new_line++)
			break ;
		i++;
	}
}

void	check_map(char *map)
{
	t_parse	parse;
	int		length;

	length = ft_strchr(map, '\n') - map;
	init_parse(&parse);
	parse_map(&parse, map, length);
	if (parse.new_line)
		ft_putstr_fd(ERR_MAP_EL, STDERR_FILENO);
	else if (parse.invalid)
		ft_putstr_fd(ERR_MAP_IC, STDERR_FILENO);
	else if (parse.is_rect)
		ft_putstr_fd(ERR_MAP_NR, STDERR_FILENO);
	else if (!(parse.player))
		ft_putstr_fd(ERR_MAP_HNP, STDERR_FILENO);
	else if (parse.player > 1)
		ft_putstr_fd(ERR_MAP_HMP, STDERR_FILENO);
	else if (!(parse.door))
		ft_putstr_fd(ERR_MAP_HNE, STDERR_FILENO);
	else if (parse.door > 1)
		ft_putstr_fd(ERR_MAP_HME, STDERR_FILENO);
	else if (!(parse.collectible))
		ft_putstr_fd(ERR_MAP_HNC, STDERR_FILENO);
	else
		return ;
	(free(map), exit(EXIT_FAILURE));
}
