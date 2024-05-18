/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:53:06 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/18 01:18:58 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assert_error(char *msg)
{
	ft_putstr_fd("Error : ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
