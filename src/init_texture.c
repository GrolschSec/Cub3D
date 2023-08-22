/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:59:10 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 18:27:42 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	init_texture(t_img *img, void *mlx_ptr, char *path)
{
	img->ptr = mlx_xpm_file_to_image(mlx_ptr, path, &img->width, &img->height);
	if (!img->ptr)
		return (0);
	return (1);
}

void	dst_img(t_game *game)
{
	if (game->i_north.ptr)
		mlx_destroy_image(game->mlx_ptr, game->i_north.ptr);
	if (game->i_west.ptr)
		mlx_destroy_image(game->mlx_ptr, game->i_west.ptr);
	if (game->i_east.ptr)
		mlx_destroy_image(game->mlx_ptr, game->i_east.ptr);
	if (game->i_south.ptr)
		mlx_destroy_image(game->mlx_ptr, game->i_south.ptr);
}

int	init_mlx(t_texture *path, t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_error("Failed to init mlx"), 0);
	if (!init_texture(&game->i_north, game->mlx_ptr, path->p_north))
		return (ft_error("Failed to init texture"), 0);
	if (!init_texture(&game->i_west, game->mlx_ptr, path->p_west))
		return (ft_error("Failed to init texture"), 0);
	if (!init_texture(&game->i_east, game->mlx_ptr, path->p_east))
		return (ft_error("Failed to init texture"), 0);
	if (!init_texture(&game->i_south, game->mlx_ptr, path->p_south))
		return (ft_error("Failed to init texture"), 0);
	return (1);
}
