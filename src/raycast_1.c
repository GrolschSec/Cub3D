/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:13:48 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/18 14:00:00 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/**
 * @brief Initializes a raycasting operation for a given screen column.
 *
 * @param ray Pointer to the raycasting structure to be initialized.
 * @param game Contains player position, screen width, etc.
 * @param x Screen column for which raycasting will be performed.
 *
 * This function prepares the raycasting structure (`t_raycast`) for the
 * specific screen column (`x`) relative to the player's view. It sets the
 * direction of the ray based on the camera's position on the screen,
 * calculates distances to potential walls, and resets other ray properties.
 *
 * @note The function uses `1e30` to handle cases where the ray's direction is
 * completely horizontal or vertical. This avoids division by zero and ensures
 * the ray doesn't incorrectly detect a hit in these scenarios.
 */
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

/**
 * @brief Sets a pixel's color in the game's display buffer.
 *
 * @param game Pointer to the main game structure.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color value to set for the pixel.
 *
 * This function uses the MiniLibX function mlx_get_data_addr to access the
 * buffer memory. It then computes the position for the specified pixel (x, y)
 * and sets its color to the provided value.
 *
 * @note The calculation accounts for bits-per-pixel and size of each line in
 * the buffer to ensure correct memory placement.
 */
void	set_pixel_to_image(t_game *game, int x, int y, int color)
{
	t_pix	pix;

	pix.data = mlx_get_data_addr(game->mlx_buf, &pix.bpp, &pix.size_line,
			&pix.endian);
	pix.pos = (x * pix.bpp / 8) + (y * pix.size_line);
	*(unsigned int *)(pix.data + pix.pos) = color;
}

int	color_choose(t_game *game, t_raycast *ray, t_img *texture, int texture_y)
{
	double	wall_x;
	int		texture_x;
	t_pix	pix;
	int		color;

	if (ray->side == 0)
		wall_x = game->pos.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->pos.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)texture->width);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		texture_x = texture->width - texture_x - 1;
	if (ray->side == 1 && ray->ray_dir_y > 0)
		texture_x = texture->width - texture_x - 1;
	pix.data = mlx_get_data_addr(texture->data, &pix.bpp, &pix.size_line,
			&pix.endian);
	pix.pos = (texture_x * pix.bpp / 8) + (texture_y * pix.size_line);
	color = *(unsigned int *)(pix.data + pix.pos);
	return (color);
}

/**
 * @brief Draws a vertical line in the game's display buffer.
 *
 * @param game Pointer to the main game structure.
 * @param ray Pointer to the raycasting information.
 * @param x The x-coordinate of the vertical line.
 *
 * This function draws a vertical line at a given x-coordinate on the screen.
 * Between ray->draw_start and ray->draw_end, it paints the wall color.
 * Above this region, it paints the ceiling color, and below, it paints the
 * floor color.
 *
 * @note This utilizes the set_pixel_to_image function to place pixels
 * in the correct memory locations within the buffer.
 */
void	ver_line(t_game *game, t_raycast *ray, int x)
{
	t_img	*texture;
	double	texture_step;
	double	texture_pos;
	int		texture_y;
	int		y;

	texture = get_wall_texture(game, ray);
	texture_step = 1.0 * texture->height / ray->line_height;
	texture_pos = (ray->draw_start - game->s_height / 2 + ray->line_height / 2)
		* texture_step;
	y = -1;
	while (++y < game->s_height)
	{
		if (y >= ray->draw_start && y <= ray->draw_end)
		{
			texture_y = clamp_int((int)texture_pos, 0, texture->height - 1);
			texture_pos += texture_step;
			set_pixel_to_image(game, x, y, color_choose(game, ray, texture,
					texture_y));
		}
		else if (y < ray->draw_start)
			set_pixel_to_image(game, x, y, game->ceiling.mlx);
		else if (y > ray->draw_end)
			set_pixel_to_image(game, x, y, game->floor.mlx);
	}
}

/**
 * @brief Implements double buffering for smoother rendering.
 *
 * @param game Pointer to the main game structure.
 *
 * The function uses the MinilibX's double buffering technique to prevent
 * flickering during game rendering. It first creates an image buffer, then
 * raycasts and fills this buffer, clears the current window, and finally
 * draws the buffer to the window.
 *
 * Double buffering helps in displaying one frame while preparing the next
 * one, ensuring smooth transitions between frames.
 */
int	double_buffering(t_game *game)
{
	game->mlx_buf = mlx_new_image(game->mlx_ptr, game->s_width, game->s_height);
	raycast(game);
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->mlx_buf, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->mlx_buf);
	return (0);
}
