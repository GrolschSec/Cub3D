/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:22:03 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/16 11:12:05 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/**
 * @brief Set the initial direction based on a cardinal point.
 * 
 * @param game Contains game state, including player's position and direction.
 * 
 * This function sets the initial x and y directions for the player's viewpoint 
 * based on the given cardinal direction (N, S, E, W) in the game's position 
 * structure, updating the dir_x and dir_y properties accordingly.
 */
void	set_initial_dir(t_game *game)
{
	if (game->pos.direction == 'N')
	{
		game->pos.dir_x = 0;
		game->pos.dir_y = -1;
	}
	else if (game->pos.direction == 'S')
	{
		game->pos.dir_x = 0;
		game->pos.dir_y = 1;
	}
	else if (game->pos.direction == 'E')
	{
		game->pos.dir_x = 1;
		game->pos.dir_y = 0;
	}
	else if (game->pos.direction == 'W')
	{
		game->pos.dir_x = -1;
		game->pos.dir_y = 0;
	}
}

/**
 * @brief Set the initial camera plane based on player's cardinal direction.
 * 
 * @param game Contains game state, including player's position and direction.
 * 
 * Depending on the player's initial cardinal direction (N, S, E, W), this 
 * function determines the camera plane's orientation (plane_x and plane_y) 
 * within the game's position structure.
 */
void	set_initial_plane(t_game *game)
{
	if (game->pos.direction == 'N')
	{
		game->pos.plane_x = 0.66;
		game->pos.plane_y = 0;
	}
	else if (game->pos.direction == 'S')
	{
		game->pos.plane_x = -0.66;
		game->pos.plane_y = 0;
	}
	else if (game->pos.direction == 'E')
	{
		game->pos.plane_x = 0;
		game->pos.plane_y = 0.66;
	}
	else if (game->pos.direction == 'W')
	{
		game->pos.plane_x = 0;
		game->pos.plane_y = -0.66;
	}
}

/**
 * @brief Initialize game settings and configurations.
 * 
 * @param game Contains game state and configurations.
 * 
 * This function sets the player's initial direction, 
 * determines the camera plane's orientation based on 
 * the player's initial direction, and initializes 
 * in-game events.
 */
void	game_init(t_game *game)
{
	set_initial_dir(game);
	set_initial_plane(game);
	events(game);
}
