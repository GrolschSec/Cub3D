/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:09:03 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/14 14:43:53 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	move_forward(t_game *game)
{
	game->pos.x += game->pos.dir_x * MOVE_SPEED;
	game->pos.y += game->pos.dir_y * MOVE_SPEED;
	double_buffering(game);
}

void	move_backward(t_game *game)
{
	game->pos.x -= game->pos.dir_x * MOVE_SPEED;
	game->pos.y -= game->pos.dir_y * MOVE_SPEED;
	double_buffering(game);
}

void	move_left(t_game *game)
{
	game->pos.x += game->pos.dir_y * MOVE_SPEED;
	game->pos.y -= game->pos.dir_x * MOVE_SPEED;
	double_buffering(game);
}

void	move_right(t_game *game)
{
	game->pos.x -= game->pos.dir_y * MOVE_SPEED;
	game->pos.y += game->pos.dir_x * MOVE_SPEED;
	double_buffering(game);
}
