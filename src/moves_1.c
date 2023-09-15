/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:09:03 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/15 16:14:25 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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
