/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:09:12 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 19:26:28 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	set_initial_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N'
				|| game->map[i][j] == 'S'
				|| game->map[i][j] == 'E'
				|| game->map[i][j] == 'W')
			{
				game->x_pos = j;
				game->y_pos = i;
				game->direction = game->map[i][j];
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_map(t_game *game, t_texture *path, char **argv)
{
	ft_memset(game, 0, sizeof(t_game));
	ft_memset(path, 0, sizeof(t_texture));
	if (!has_cub_extension(argv[1]))
		return (ft_error("File is not a '.cub' file"), 1);
	if (!open_file(argv[1], game))
		return (ft_error("Can't open file"), 2);
	if (!parse_file(game, path))
		return (close(game->fd), free_texture(path), free_game(game), 3);
	close(game->fd);
	if (!verify_map(game))
		return (free_texture(path), free_game(game), 4);
	remove_spaces_from_map(game->map);
	set_initial_position(game);
	if (!init_mlx(path, game))
		return (free_texture(path), free_game(game), 5);
	return (0);
}
