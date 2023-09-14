/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:22:03 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/14 17:52:45 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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

void	game_init(t_game *game)
{
	set_initial_dir(game);
	set_initial_plane(game);
	events(game);
}
