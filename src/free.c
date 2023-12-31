/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:11:21 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 20:35:57 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_texture(t_texture *path)
{
	if (path->p_north)
		free(path->p_north);
	if (path->p_west)
		free(path->p_west);
	if (path->p_east)
		free(path->p_east);
	if (path->p_south)
		free(path->p_south);
}

void	free_map(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	dst_img(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}
