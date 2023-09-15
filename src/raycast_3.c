/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:49:01 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/15 17:50:21 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	find_wall_dir(t_raycast *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x < 0)
			ray->wall_dir = WEST;
		else
			ray->wall_dir = EAST;
	}
	else
	{
		if (ray->ray_dir_y < 0)
			ray->wall_dir = NORTH;
		else
			ray->wall_dir = SOUTH;
	}
}
