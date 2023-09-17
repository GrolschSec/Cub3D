/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:49:01 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/16 11:00:00 by yaassila         ###   ########.fr       */
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

t_img	*get_wall_texture(t_game *game, t_raycast *ray)
{
	t_img	*texture;

	if (ray->wall_dir == NORTH)
		texture = &game->i_north;
	else if (ray->wall_dir == SOUTH)
		texture = &game->i_south;
	else if (ray->wall_dir == EAST)
		texture = &game->i_east;
	else if (ray->wall_dir == WEST)
		texture = &game->i_west;
	return (texture);
}
