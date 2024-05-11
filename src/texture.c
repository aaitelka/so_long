/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:45:15 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/11 20:00:15 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_path	init_paths()
{
	t_path	paths;

	paths.uris[I_GROUND] = TEXTURE_GROUND;
	paths.uris[I_WALL] = TEXTURE_WALL;
	paths.uris[I_COIN] = TEXTURE_COIN;
	paths.uris[I_DOOR] = TEXTURE_DOOR;
	paths.uris[I_PF] = PLAYER_FRONT;
	paths.uris[I_PB] = PLAYER_BACK;
	paths.uris[I_PL] = PLAYER_LEFT;
	paths.uris[I_PR] = PLAYER_RIGHT;
	paths.uris[8] = NULL;
	return (paths);
}
