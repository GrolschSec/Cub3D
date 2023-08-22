/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:58:30 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 21:01:20 by rlouvrie         ###   ########.fr       */
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
		return (0);
	else if (keycode == A_KEY)
		return (0);
	else if (keycode == S_KEY)
		return (0);
	else if (keycode == D_KEY)
		return (0);
	else if (keycode == L_KEY)
		return (0);
	else if (keycode == R_KEY)
		return (0);
	return (0);
}

void	window_init(t_game *game)
{
	int	sizey;
	int	sizex;

	mlx_get_screen_size(game->mlx_ptr, &sizex, &sizey);
	sizex = (int)(sizex * 0.7);
	sizey = (int)(sizey * 0.7);
	game->mlx_win = mlx_new_window(game->mlx_ptr, sizex, sizey, "cub3D");
	mlx_hook(game->mlx_win, DestroyNotify,
		StructureNotifyMask, close_window, game);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, handle_event, game);
	mlx_loop(game->mlx_ptr);
}
