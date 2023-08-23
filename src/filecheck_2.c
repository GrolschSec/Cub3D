/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:58:21 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/23 12:23:33 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*extract_texture(char *file, char *identifier)
{
	char	*loc;
	char	*path;
	char	*end;
	int		length;

	loc = ft_strnstr(file, identifier, ft_strlen(file));
	if (!loc)
		return (NULL);
	loc += ft_strlen(identifier);
	while (*loc == ' ')
		loc++;
	end = loc;
	while (*end && *end != ' ' && *end != '\n')
		end++;
	length = end - loc;
	path = malloc(length + 1);
	if (!path)
		return (NULL);
	ft_strlcpy(path, loc, length + 1);
	return (path);
}

char	*file_to_line(t_game *game)
{
	char	*str;
	char	*buf;
	char	*tmp;
	int		res;

	str = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	res = 1;
	while (res)
	{
		res = read(game->fd, buf, BUFFER_SIZE);
		if (res < 0)
			return (free(buf), NULL);
		buf[res] = '\0';
		tmp = ft_strjoin(str, buf);
		if (str)
			free(str);
		str = tmp;
	}
	return (free(buf), close(game->fd), str);
}

int	extract_color(char *file, char *identifier, t_color *color)
{
	char	*loc;
	char	*end;
	int		values[3];
	int		i;

	i = 0;
	loc = ft_strnstr(file, identifier, ft_strlen(file));
	if (!loc)
		return (0);
	loc += ft_strlen(identifier);
	while (*loc == ' ')
		loc++;
	i = -1;
	while (++i < 3)
	{
		values[i] = ft_atoi(loc);
		end = ft_strchr(loc, ',');
		if (!end && i < 2)
			return (0);
		loc = end + 1;
	}
	color->red = values[0];
	color->green = values[1];
	color->blue = values[2];
	return (1);
}

int	set_colors(char *file, t_color *floor, t_color *ceiling)
{
	if (!extract_color(file, "F", floor))
		return (0);
	if (!extract_color(file, "C", ceiling))
		return (0);
	return (1);
}

int	set_map(char *file, t_game *game)
{
	char	*start_of_map;

	start_of_map = ft_strnstr(file, "\n1", ft_strlen(file));
	if (!start_of_map)
		return (ft_error("Invalid map"), 0);
	find_end_of_map(start_of_map, ft_strlen(start_of_map));
	if (!check_empty_line(start_of_map))
		return (ft_error("Invalid map"), 0);
	game->map = ft_split(start_of_map, '\n');
	if (!game->map)
		return (ft_error("Map extraction failed"), 0);
	return (1);
}
