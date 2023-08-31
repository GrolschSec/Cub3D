/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:13:48 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/31 14:08:41 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	initRaycasting(t_game *game, int x, t_raycast *ray)
{
	ft_memset(ray, 0, sizeof(raycast));
	ray->camera_x = 2 * x / (double)game->s_width - 1;
	ray->ray_dir_x = game->pos.dir_x + game->pos.plane_x * ray->camera_x;
	ray->ray_dir_y = game->pos.dir_y + game->pos.plane_y * ray->camera_x;
	ray->map_x = (int)game->pos.x;
	ray->map_y = (int)game->pos.y;
}

void	calculateStepAndSideDist(t_raycast *ray, t_game *game)
{
	ray->delta_d_x = fabs(1 / ray->ray_dir_x);
	ray->delta_d_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_d_x = (game->pos.x - ray->map_x) * ray->delta_d_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_d_x = (ray->map_x + 1.0 - game->pos.x) * ray->delta_d_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_d_y = (game->pos.y - ray->map_y) * ray->delta_d_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_d_y = (ray->map_y + 1.0 - game->pos.y) * ray->delta_d_y;
	}
}

void	performDDA(t_game *game, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_d_x < ray->side_d_y)
		{
			ray->side_d_x += ray->delta_d_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_d_y += ray->delta_d_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_x][ray->map_y] > 0)
		{
			ray->hit = 1;
		}
	}
}

void	drawVerticalLine(t_game *game, t_raycast *ray, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;

	line_height = (int)(game->s_height / ray->perp_wall_d);
	draw_start = -line_height / 2 + game->s_height / 2;
	draw_end = line_height / 2 + game->s_height / 2;
	color = 0xFFFFFF;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= game->s_height)
		draw_end = game->s_height - 1;
	for (int y = draw_start; y < draw_end; y++)
	{
		printf("Drawing pixel\n");
		mlx_pixel_put(game->mlx_ptr, game->mlx_win, x, y, color);
	}
}

void	raycast(t_game *game, int x)
{
	t_raycast	ray;

	initRaycasting(game, x, &ray);
	calculateStepAndSideDist(&ray, game);
	performDDA(game, &ray);
	drawVerticalLine(game, &ray, x);
}
