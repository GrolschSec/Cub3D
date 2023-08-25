/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:03:05 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/25 13:30:27 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	has_cub_extension(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (dot && dot != filename
		&& ft_strncmp(dot, ".cub", ft_strlen(dot)) == 0)
		return (1);
	return (0);
}

int	open_file(char *filename, t_game *game)
{
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
		return (0);
	return (1);
}

int	parse_file(t_game *game, t_texture *path)
{
	char	*file;

	file = file_to_line(game);
	if (!file)
		return (ft_error("In reading file"), 0);
	if (!set_textures(file, path))
		return (ft_error("Can't find all textures required"), free(file), 0);
	if (!set_colors(file, &(game->floor), &(game->ceiling)))
		return (ft_error("Can't extract colors"), free(file), 0);
	if (!set_map(file, game))
		return (free(file), 0);
	if (!txt_color_dup_check(file))
		return (ft_error("Duplicate in file"), free(file), 0);
	return (free(file), 1);
}

int	set_textures(char *file, t_texture *path)
{
	path->p_north = extract_texture(file, "NO");
	path->p_west = extract_texture(file, "WE");
	path->p_east = extract_texture(file, "EA");
	path->p_south = extract_texture(file, "SO");
	if (!path->p_north || !path->p_west || !path->p_east || !path->p_south)
		return (0);
	return (1);
}

int	check_empty_line(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i + 1] && map[i] == '\n' && map[i + 1] == '\n')
			return (0);
	}
	return (1);
}
