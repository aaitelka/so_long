/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:51:22 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/17 16:41:29 by aaitelka         ###   ########.fr       */
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

void	iter(t_point *lst, void (*f)(int, int))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->x, lst->y);
		lst = lst->next;
	}
}
