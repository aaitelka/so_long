/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:01:49 by aaitelka          #+#    #+#             */
/*   Updated: 2024/04/30 22:45:00 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include <stdbool.h>

#define EXT ".ber"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char *get_file_name(char *agrv[])
{
    return (agrv[1]);
}

bool is_valid_ext(char *filename)
{
    char    *ext;

    ext = ft_strrchr(filename, '.');
    if (!ft_strcmp(ext, EXT))
        return (true);
    return (false);
}

bool is_double(char *map, char c)
{
    int i;

    i = 0;
    while (map[i])
    {
        if (map[i] == c)
            return (true);
        i++;
    }
    return (false);
}

// bool is_valid_map(char *line)
// {
          
// }

char **read_map(char *filename)
{
    char    *line;
    char    **map;
    int     i;
    int     fd;

    i = 1;
    fd = open(filename, O_RDONLY);
    if (fd == ERROR)
        return (NULL);
    line = get_next_line(fd);
    while (line)
    {
        map = malloc(i * sizeof(char *));
        line = get_next_line(fd);
        map[i - 1] = line;
        printf("%s", map[i - 1]);
        i++;
    }
    map[i - 1] = NULL;
    close(fd);
    return (&map[0]);
}

void l()
{
    system("leaks so_long");
}

void clear_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int main(int ac, char *av[])
{
    atexit(l);

    if (ac == 2)
    {        
        char *filename = get_file_name(av);
        if (is_valid_ext(filename))
        {
            char **map = read_map(filename);
            if (!map)
                printf("Error\n");
            int i = 0;
            while (map[i])
            {
                printf("%s\n", map[i]);
                i++;
            }
            clear_map(map);
        }
        else
            printf("invalid\n"); 
    } else 
    {
        printf("Please add map!\n");
    }

    return (EXIT_SUCCESS);
}