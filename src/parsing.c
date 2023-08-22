/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:09:12 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 14:57:57 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	parse_map(t_game *game, t_texture *path, char **argv)
{
	(void)path;

	if (!has_cub_extension(argv[1]))
		return (ft_error("File is not a '.cub' file"), 1);
	if (!open_file(argv[1], game))
		return (ft_error("Can't open file"), 2);
	if (!parse_file(game, path))
		return (3);
	return (0);
}
