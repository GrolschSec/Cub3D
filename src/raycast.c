/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:13:48 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/30 21:51:13 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	initRaycasting(t_game *game, int x, t_raycast *ray)
{
	ft_memset(ray, 0, sizeof(raycast));
	ray->cameraX = 2 * x / (double)game->s_width - 1;
	ray->rayDirX = game->pos.dir_x + game->pos.plane_x * ray->cameraX;
	ray->rayDirY = game->pos.dir_y + game->pos.plane_y * ray->cameraX;
	ray->mapX = (int)game->pos.x;
	ray->mapY = (int)game->pos.y;
}

void	calculateStepAndSideDist(t_raycast *ray, t_game *game)
{
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (game->pos.x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - game->pos.x) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (game->pos.y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - game->pos.y) * ray->deltaDistY;
	}
}

void	performDDA(t_game *game, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (game->map[ray->mapX][ray->mapY] > 0)
		{
			ray->hit = 1;
		}
	}
}

void	drawVerticalLine(t_game *game, t_raycast *ray, int x)
{
    int	lineHeight;
    int	drawStart;
	int	drawEnd;
	int	color;

	lineHeight = (int)(game->s_height / ray->perpWallDist);
	drawStart = -lineHeight / 2 + game->s_height / 2;
	drawEnd = lineHeight / 2 + game->s_height / 2;
	color = 0xFFFFFF;
	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= game->s_height)
		drawEnd = game->s_height - 1;
	for (int y = drawStart; y < drawEnd; y++)
	{
		printf("Drawing pixel\n");
		mlx_pixel_put(game->mlx_ptr, game->mlx_win, x, y, color);
	}
}

void	raycast(t_game *game, int x)
{
    t_raycast ray;

    initRaycasting(game, x, &ray);
    calculateStepAndSideDist(&ray, game);
    performDDA(game, &ray);
    drawVerticalLine(game, &ray, x);
}
