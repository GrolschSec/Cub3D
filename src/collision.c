/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:39:30 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/16 11:16:50 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/**
 * @brief Checks if a given position on the game map is valid.
 * 
 * @param game Holds game's current state and configurations.
 * @param new_x The x-coordinate of the position to check.
 * @param new_y The y-coordinate of the position to check.
 * @return 1 if the position is valid; otherwise, 0.
 * 
 * The function ensures the player doesn't collide with the edges 
 * or any obstacles ('1' on the map grid). Positions overlapping 
 * with obstacles or out-of-bounds are deemed invalid.
 */
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
