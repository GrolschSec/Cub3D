/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:04:55 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/13 18:12:32 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game		game;
	t_texture	path;

	if (argc != 2)
		return (ft_error("Not enough arguments"), 1);
	if (parse_map(&game, &path, argv))
		return (2);
	window_init(&game);
	mlx_loop_hook(game.mlx_ptr, &raycast, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
