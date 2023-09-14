/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:13:48 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/14 17:41:28 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_raycast(t_raycast *ray, t_game *game, int x)
{
	ft_memset(ray, 0, sizeof(t_raycast));
	ray->camera_x = 2 * x / (double)game->s_width - 1;  // Screen width used here
	ray->ray_dir_x = game->pos.dir_x + game->pos.plane_x * ray->camera_x;
	ray->ray_dir_y = game->pos.dir_y + game->pos.plane_y * ray->camera_x;
	ray->map_x = (int)game->pos.x;
	ray->map_y = (int)game->pos.y;
	ray->delta_dist_x = (ray->ray_dir_x == 0) ? 1e30 : fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = (ray->ray_dir_y == 0) ? 1e30 : fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	set_pixel_to_image(t_game *game, int x, int y, int color)
{
    char    *data;
    int     bpp;
    int     size_line;
    int     endian;
    int     pos;

    data = mlx_get_data_addr(game->mlx_buf, &bpp, &size_line, &endian);
    pos = (x * bpp / 8) + (y * size_line);
    *(unsigned int *)(data + pos) = color;
}

void	ver_line(t_game *game, t_raycast *ray, int x, int color)
{
    int y;

    y = -1;
    while (++y < game->s_height)
    {
        if (y >= ray->draw_start && y <= ray->draw_end)
            set_pixel_to_image(game, x, y, color);
        else if (y < ray->draw_start)
            set_pixel_to_image(game, x, y, game->ceiling.mlx);
        else if (y > ray->draw_end)
            set_pixel_to_image(game, x, y, game->floor.mlx);
    }
}

int	double_buffering(t_game *game)
{
	game->mlx_buf = mlx_new_image(game->mlx_ptr, game->s_width, game->s_height);
	raycast(game);
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->mlx_buf, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->mlx_buf);
	return (0);
}

void	ft_calc_step_side_dist(t_game *game, t_raycast *ray)
{
	//calculate step and initial sideDist
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
	//perform DDA
	while (ray->hit == 0)
	{
    	//jump to next map square, either in x-direction, or in y-direction
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
		//Check if ray has hit a wall
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calc_wall_slice_projection(t_game *game, t_raycast *ray)
{
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if(ray->side == 0) 
		ray->perp_wall_dist = (ray->map_x - game->pos.x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->pos.y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	//Calculate height of line to draw on screen
	ray->line_height = (int)(game->s_height / ray->perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	ray->draw_start = -ray->line_height / 2 + game->s_height / 2;
	if(ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->s_height / 2;
	if(ray->draw_end >= (int)game->s_height)
		ray->draw_end = game->s_height - 1;
}

void	color_choose(t_game *game, t_raycast *ray)
{
	int	color;

	switch(game->map[ray->map_y][ray->map_x])
	{
		case 1:  color = 0xFF0000; break;
		case 2:  color = 0x00FF00; break;
		case 3:  color = 0x0000FF; break;
		case 4:  color = 0xFFFFFF; break;
		default: color = 0xFFFF00; break;
	}
	if (ray.side == 1)
		color = color / 2;
}

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
		color_choose(game, &ray);
		ver_line(game, &ray, x, color);
	}
	return (0);
}
