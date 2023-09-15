/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:39:30 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/15 16:19:09 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	is_valid_position(t_game *game, double new_x, double new_y)
{
	if (new_x - PLAYER_RADIUS < 0 || new_x + PLAYER_RADIUS >= game->m_width
		|| new_y - PLAYER_RADIUS < 0 || new_y + PLAYER_RADIUS >= game->m_height)
		return (0);
	if (game->map[(int)(new_y
			- PLAYER_RADIUS)][(int)(new_x - PLAYER_RADIUS)] == '1' ||
		game->map[(int)(new_y 
			+ PLAYER_RADIUS)][(int)(new_x - PLAYER_RADIUS)] == '1' ||
		game->map[(int)(new_y
			- PLAYER_RADIUS)][(int)(new_x + PLAYER_RADIUS)] == '1' ||
		game->map[(int)(new_y
			+ PLAYER_RADIUS)][(int)(new_x + PLAYER_RADIUS)] == '1')
		return (0);

	return (1);
}
