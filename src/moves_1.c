/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:09:03 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/16 11:14:08 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/**
 * @brief Moves the player forward based on the current direction.
 *
 * @param game Contains the game's current state and configurations.
 *
 * Calculates the new position using the current direction
 * and MOVE_SPEED. If the new position is valid (not colliding
 * with any obstacles), updates the player's position and
 * redraws the game screen.
 */
void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos.x + game->pos.dir_x * MOVE_SPEED;
	new_y = game->pos.y + game->pos.dir_y * MOVE_SPEED;
	if (!is_valid_position(game, game->pos.x, new_y)
		|| !is_valid_position(game, new_x, game->pos.y))
		return ;
	game->pos.x = new_x;
	game->pos.y = new_y;
	double_buffering(game);
}

/**
 * @brief Moves the player backward based on the current direction.
 *
 * @param game Contains the game's current state and configurations.
 *
 * Calculates the new position by going opposite to the current
 * direction and using MOVE_SPEED. If the new position is valid
 * (not colliding with any obstacles), updates the player's
 * position and redraws the game screen.
 */
void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos.x - game->pos.dir_x * MOVE_SPEED;
	new_y = game->pos.y - game->pos.dir_y * MOVE_SPEED;
	if (!is_valid_position(game, game->pos.x, new_y)
		|| !is_valid_position(game, new_x, game->pos.y))
		return ;
	game->pos.x = new_x;
	game->pos.y = new_y;
	double_buffering(game);
}

/**
 * @brief Moves the player to the left relative to the current direction.
 *
 * @param game Contains the game's current state and configurations.
 *
 * Calculates the new position by adjusting the direction to move
 * leftwards, using MOVE_SPEED. If the new position is valid
 * (not colliding with any obstacles), it updates the player's
 * position and redraws the game screen.
 */
void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos.x + game->pos.dir_y * MOVE_SPEED;
	new_y = game->pos.y - game->pos.dir_x * MOVE_SPEED;
	if (!is_valid_position(game, game->pos.x, new_y)
		|| !is_valid_position(game, new_x, game->pos.y))
		return ;
	game->pos.x = new_x;
	game->pos.y = new_y;
	double_buffering(game);
}

/**
 * @brief Moves the player to the right relative to the current direction.
 *
 * @param game Contains the game's current state and configurations.
 *
 * Calculates the new position by adjusting the direction to move
 * rightwards, using MOVE_SPEED. If the new position is valid
 * (not colliding with any obstacles), it updates the player's
 * position and redraws the game screen.
 */
void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos.x - game->pos.dir_y * MOVE_SPEED;
	new_y = game->pos.y + game->pos.dir_x * MOVE_SPEED;
	if (!is_valid_position(game, game->pos.x, new_y)
		|| !is_valid_position(game, new_x, game->pos.y))
		return ;
	game->pos.x = new_x;
	game->pos.y = new_y;
	double_buffering(game);
}
