/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:51:22 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 20:43:28 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_point	*new_pos(int x, int y)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->dir = true;
	point->next = NULL;
	return (point);
}

void	add_pos(t_point **lst, t_point *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	clear_pos(t_point *point)
{
	t_point	*current;
	t_point	*next;

	if (!point)
		return ;
	current = point->next;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(point);
}
