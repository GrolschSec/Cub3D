/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:04:55 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 13:40:33 by rlouvrie         ###   ########.fr       */
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
	parse_map(&game, &path, argv);
	/*texture_init(&game, &path);*/
	/*cub3d(&gameinfo)*/
	return (0);
}
