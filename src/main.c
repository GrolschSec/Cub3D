/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:04:55 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 21:01:28 by rlouvrie         ###   ########.fr       */
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
	return (0);
}
