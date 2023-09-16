/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:49:01 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/16 11:08:18 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/**
 * @brief Determines the wall direction based on the ray's direction.
 * 
 * @param ray Contains information about the ray being cast.
 * 
 * If the ray's side is 0, it implies the ray intersects a wall in the
 * horizontal direction. In such a case, the wall's direction is 
 * determined based on ray's x direction. If not, it's determined by
 * ray's y direction. This function updates the wall_dir property 
 * of the passed ray accordingly.
 */
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
