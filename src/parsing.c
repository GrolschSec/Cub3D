/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:09:12 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 18:35:33 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	parse_map(t_game *game, t_texture *path, char **argv)
{
	ft_memset(game, 0, sizeof(t_game));
	if (!has_cub_extension(argv[1]))
		return (ft_error("File is not a '.cub' file"), 1);
	/*NO MALLOC YET*/
	if (!open_file(argv[1], game))
		return (ft_error("Can't open file"), 2);
	/* OPEN FD */
	if (!parse_file(game, path))
		return (3);
	/* TEXTURES + MAP + FD */
	if (!verify_map(game))
		return (4);
	/* TEXTURES + MAP + FD */
	remove_spaces_from_map(game->map);
	/* TEXTURES + MAP + FD */
	/* NEED TO SET THE PLAYER POSITION IN THE STRUCT */
	if (!init_mlx(path, game))
		return (5);
	/* TEXTURES + MAP + FD + IMGS + MLX_PTR*/
	return (0);
}
