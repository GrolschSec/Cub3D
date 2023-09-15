/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:13:48 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/15 11:14:22 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_raycast(t_raycast *ray, t_game *game, int x)
{
	ft_memset(ray, 0, sizeof(t_raycast));
	ray->camera_x = 2 * x / (double)game->s_width - 1;
	ray->ray_dir_x = game->pos.dir_x + game->pos.plane_x * ray->camera_x;
	ray->ray_dir_y = game->pos.dir_y + game->pos.plane_y * ray->camera_x;
	ray->map_x = (int)game->pos.x;
	ray->map_y = (int)game->pos.y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	set_pixel_to_image(t_game *game, int x, int y, int color)
{
	t_pix	pix;

	pix.data = mlx_get_data_addr(game->mlx_buf,
			&pix.bpp, &pix.size_line, &pix.endian);
	pix.pos = (x * pix.bpp / 8) + (y * pix.size_line);
	*(unsigned int *)(pix.data + pix.pos) = color;
}

void	ver_line(t_game *game, t_raycast *ray, int x, int color)
{
	int	y;

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
