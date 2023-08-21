/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:05:17 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/21 19:52:32 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include "../src/libft/libft.h"
# include "../src/mlx/mlx.h"

typedef struct	s_color
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}				t_color;

typedef struct	s_img_path
{
	char	*p_north;
	char	*p_west;
	char	*p_east;
	char	*p_south;
}				t_img_path;

typedef struct	s_game
{
	t_color	floor;
	t_color	ceiling;
	void	*i_north;
	void	*i_west;
	void	*i_east;
	void	*i_south;
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	int		x_pos;
	int		y_pos;
}				t_game;
#endif
