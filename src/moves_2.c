/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:11:08 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/14 11:20:52 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	rotate_left(t_game *game)
{
	float	oldDirX;
	float	oldPlaneX;

	oldDirX= game->pos.dir_x;
	oldPlaneX = game->pos.plane_x;
	game->pos.dir_x = game->pos.dir_x * cos(-ROT_SPEED) - game->pos.dir_y * sin(-ROT_SPEED);
	game->pos.dir_y = oldDirX * sin(-ROT_SPEED) + game->pos.dir_y * cos(-ROT_SPEED);
	game->pos.plane_x = game->pos.plane_x * cos(-ROT_SPEED) - game->pos.plane_y * sin(-ROT_SPEED);
	game->pos.plane_y = oldPlaneX * sin(-ROT_SPEED) + game->pos.plane_y * cos(-ROT_SPEED);
	raycast(game);
}

void rotate_right(t_game *game)
{
	float	oldDirX;
	float	oldPlaneX;

	oldDirX = game->pos.dir_x;
	oldPlaneX = game->pos.plane_x;
	game->pos.dir_x = game->pos.dir_x * cos(ROT_SPEED) - game->pos.dir_y * sin(ROT_SPEED);
	game->pos.dir_y = oldDirX * sin(ROT_SPEED) + game->pos.dir_y * cos(ROT_SPEED);
	game->pos.plane_x = game->pos.plane_x * cos(ROT_SPEED) - game->pos.plane_y * sin(ROT_SPEED);
	game->pos.plane_y = oldPlaneX * sin(ROT_SPEED) + game->pos.plane_y * cos(ROT_SPEED);
	raycast(game);
}
