/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:47:42 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/14 18:12:16 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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
			ray->hit = 1;
	}
}

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

int	color_choose(t_raycast *ray)
{
	int	color;

	color = 0xFF0000;
	if (ray->side == 1)
		color = color / 2;
	return (color);
}

int	raycast(t_game *game)
{
	int			x;
	int			color;
	t_raycast	ray;

	x = -1;
	while (++x < (int)game->s_width)
	{
		init_raycast(&ray, game, x);
		ft_calc_step_side_dist(game, &ray);
		dda_algorithm(game, &ray);
		calc_wall_slice_projection(game, &ray);
		color = color_choose(&ray);
		ver_line(game, &ray, x, color);
	}
	return (0);
}
