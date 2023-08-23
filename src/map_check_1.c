/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:24:24 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/23 13:40:44 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	is_valid_char(char c)
{
	return (c == '0'
		|| c == '1'
		|| c == 'N'
		|| c == 'S'
		|| c == 'E'
		|| c == 'W'
		|| c == ' ');
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	validation_cond(t_game *game, int i, int j, int *p)
{
	if (!is_valid_char(game->map[i][j]))
		return (0);
	if (is_player_char(game->map[i][j]))
	{
		*p += 1;
		if (*p > 1)
			return (0);
	}
	return (1);
}

int	verify_map(t_game *game)
{
	int	i;
	int	j;
	int	p;

	i = -1;
	p = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (!validation_cond(game, i, j, &p))
				return (0);
		}
	}
	if (p != 1)
		return (0);
	set_initial_position(game);
	if (!is_closed_map(game->map))
		return (0);
	return (1);
}
