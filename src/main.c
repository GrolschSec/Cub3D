/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:04:55 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/21 20:02:52 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game		game_info;
	t_texture	path;

	(void)path;
	(void)argv;
	if (argc != 2)
		ft_putstr_fd("Error\nNot enough arguments", 1);
	/*parse_mapinfo(&gameinfo, &path);*/
	/*map_init(&gameinfo, &path);*/
	/*cub3d(&gameinfo)*/
	return (0);
}
