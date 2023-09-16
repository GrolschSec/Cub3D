/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:59:10 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/16 12:19:53 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	init_texture(t_img *img, void *mlx_ptr, char *path)
{
	ft_memset(img, 0, sizeof(t_img));
	img->data = mlx_xpm_file_to_image(mlx_ptr, path, &img->width, &img->height);
	if (!img->data)
		return (0);
	return (1);
}

void	dst_img(t_game *game)
{
	if (game->i_north.data)
		mlx_destroy_image(game->mlx_ptr, game->i_north.data);
	if (game->i_west.data)
		mlx_destroy_image(game->mlx_ptr, game->i_west.data);
	if (game->i_east.data)
		mlx_destroy_image(game->mlx_ptr, game->i_east.data);
	if (game->i_south.data)
		mlx_destroy_image(game->mlx_ptr, game->i_south.data);
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
	if (game->i_north.height != game->i_north.width
		|| game->i_south.height != game->i_south.width
		|| game->i_east.height != game->i_east.width
		|| game->i_west.height != game->i_west.width)
		return (ft_error("Textures should be square"), 0);
	return (free_texture(path), 1);
}
