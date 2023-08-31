/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:56:16 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/31 14:20:47 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	get_tab_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	find_largest_line(char **map)
{
	size_t	res;
	int		i;

	i = 0;
	res = 0;
	while (map[i])
	{
		if (res < ft_strlen(map[i]))
			res = ft_strlen(map[i]);
		i++;
	}
	return (res);
}

int	resize_line(t_game *game, char **map, int i)
{
	char	*tmp;
	size_t	loc;

	tmp = malloc(sizeof(char) * (game->m_width + 1));
	if (!tmp)
		return (0);
	loc = ft_strlen(map[i]);
	ft_strlcpy(tmp, map[i], loc + 1);
	tmp[loc] = ' ';
	while (++loc < game->m_width)
		tmp[loc] = ' ';
	tmp[loc] = '\0';
	free(map[i]);
	map[i] = tmp;
	return (1);
}

int	resize_map(t_game *game)
{
	int	i;

	game->m_height = get_tab_len(game->map);
	game->m_width = find_largest_line(game->map);
	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) < game->m_width)
		{
			if (!resize_line(game, game->map, i))
				return (0);
		}
		i++;
	}
	return (1);
}
