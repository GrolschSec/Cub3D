/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:39:30 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/15 15:57:49 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	is_valid_position(t_game *game, double new_x, double new_y)
{
	if (new_x < 0 || new_x >= game->m_width
		|| new_y < 0 || new_y >= game->m_height)
		return (0);
	if (game->map[(int)new_y][(int)new_x] == '1')
		return (0);
	return (1);
}
