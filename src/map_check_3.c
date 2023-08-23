/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:23:07 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/23 13:43:23 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	empty_not_open(char **map, int i, int j)
{
	int	len;

	len = ft_strlen(map[i]) - 1;
	if (i == 0 || j == 0 || j == len || !map[i + 1])
		return (0);
	else if (map[i - 1][j] != '1' && map[i - 1][j] != '0')
		return (0);
	else if (map[i + 1][j] != '1' && map[i + 1][j] != '0')
		return (0);
	else if (map[i][j - 1] != '1' && map[i][j - 1] != '0')
		return (0);
	else if (map[i][j + 1] != '1' && map[i][j + 1] != '0')
		return (0);
	return (1);
}

int	is_closed_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1' || map[i][j] == ' ')
				continue ;
			else if (!empty_not_open(map, i, j))
				return (0);
		}
	}
	return (1);
}
