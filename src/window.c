/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:58:30 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/30 22:26:42 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
}

int	handle_event(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_window(game);
	else if (keycode == W_KEY)
		move_forward(game);
	else if (keycode == A_KEY)
		move_left(game);
	else if (keycode == S_KEY)
		move_backward(game);
	else if (keycode == D_KEY)
		move_right(game);
	else if (keycode == L_KEY)
		rotate_left(game);
	else if (keycode == R_KEY)
		rotate_right(game);
	return (0);
}

void	events(t_game *game)
{
	mlx_hook(game->mlx_win, DestroyNotify,
		StructureNotifyMask, close_window, game);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, handle_event, game);
}

void	window_init(t_game *game)
{
	game->s_width = 1280;
	game->s_height = 720;
	game->mlx_win = mlx_new_window(game->mlx_ptr,
		game->s_width, game->s_height, "cub3D");
	game_init(game);
}
