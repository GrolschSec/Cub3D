/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:09:12 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/15 16:25:29 by rlouvrie         ###   ########.fr       */
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
				game->pos.x = j + 0.1;
				game->pos.y = i + 0.1;
				game->pos.direction = game->map[i][j];
				game->map[i][j] = '0';
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicate(char *file, char *identifier)
{
	char	*loc;

	loc = ft_strnstr(file, identifier, ft_strlen(file));
	if (loc)
	{
		loc += ft_strlen(identifier);
		loc = ft_strnstr(loc, identifier, ft_strlen(loc));
		if (loc)
			return (0);
	}
	return (1);
}

int	txt_color_dup_check(char *file)
{
	if (!check_duplicate(file, "NO "))
		return (0);
	if (!check_duplicate(file, "WE "))
		return (0);
	if (!check_duplicate(file, "EA "))
		return (0);
	if (!check_duplicate(file, "SO "))
		return (0);
	if (!check_duplicate(file, "F "))
		return (0);
	if (!check_duplicate(file, "C "))
		return (0);
	return (1);
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
		return (ft_error("Invalid map"),
			free_texture(path), free_game(game), 4);
	if (!resize_map(game))
		return (ft_error("Can't allocate memory"), free(game), 5);
	if (!init_mlx(path, game))
		return (free_texture(path), free_game(game), 6);
	return (0);
}
