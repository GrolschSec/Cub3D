/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:20:07 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 17:25:15 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	check_left_right_wall(char **map, int *i, int j)
{
	int	len;

	while (map[*i])
	{
		len = ft_strlen(map[*i]);
		j = 0;
		while (map[*i][j] == ' ')
			j++;
		if (map[*i][j] != '1')
			return (0);
		j = len - 1;
		while (j >= 0 && map[*i][j] == ' ')
			j--;
		if (map[*i][j] != '1')
			return (0);
		*i += 1;
	}
	return (1);
}
