/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:47:42 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/16 11:08:12 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/**
 * @brief Calculate step and initial side distance for raycasting.
 * 
 * @param game Main game structure containing player's position.
 * @param ray Structure to store raycasting related variables.
 *
 * This function determines in which direction (positive or negative) the 
 * ray should step for both x and y coordinates. It also calculates the 
 * initial side distance for the ray in both x and y directions. This 
 * step calculation is important for the DDA algorithm used in raycasting.
 */
void	ft_calc_step_side_dist(t_game *game, t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->pos.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->pos.y) * ray->delta_dist_y;
	}
}

/**
 * @brief Executes the DDA algorithm for raycasting.
 * 
 * @param game Main game structure with game map.
 * @param ray Stores raycasting related variables.
 *
 * This function iteratively steps through the game map grid to find 
 * where the ray intersects with a wall. The DDA algorithm is used to 
 * efficiently traverse the grid. It updates the ray's x and y coordinates 
 * in the map and checks if a wall ('1' in the map) is hit. If a wall is 
 * intersected, it sets ray's hit variable to 1 and determines the wall's 
 * direction.
 */
void	dda_algorithm(t_game *game, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
		{
			ray->hit = 1;
			find_wall_dir(ray);
		}
	}
}

/**
 * @brief Calculate wall slice projection properties.
 * 
 * @param game Provides access to game state variables.
 * @param ray  Contains raycasting related information.
 * 
 * Determines the perpendicular distance of the ray to the wall it intersects,
 * based on whether the ray hits a horizontal or vertical wall slice. It then
 * computes the height of the wall slice on the screen, and the vertical start
 * and end points for drawing this slice.
 */
void	calc_wall_slice_projection(t_game *game, t_raycast *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x
				- game->pos.x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y
				- game->pos.y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(game->s_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + game->s_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->s_height / 2;
	if (ray->draw_end >= (int)game->s_height)
		ray->draw_end = game->s_height - 1;
}

/**
 * @brief Executes raycasting for each column of the screen.
 * 
 * @param game Contains game's current state and configurations.
 * @return Always returns 0.
 * 
 * This function calculates and projects the wall slices for each 
 * column of the screen using the raycasting technique.
 */
int	raycast(t_game *game)
{
	int			x;
	t_raycast	ray;

	x = -1;
	while (++x < (int)game->s_width)
	{
		init_raycast(&ray, game, x);
		ft_calc_step_side_dist(game, &ray);
		dda_algorithm(game, &ray);
		calc_wall_slice_projection(game, &ray);
		ver_line(game, &ray, x);
	}
	return (0);
}
