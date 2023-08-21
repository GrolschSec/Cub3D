/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:05:17 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/21 19:42:19 by rlouvrie         ###   ########.fr       */
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

typedef struct	s_game
{
	t_color	floor;
	t_color	ceiling;
	char	*p_north;
	char	*p_west;
	char	*p_east;
	char	*p_south;
	char	**map;
	int		x_pos;
	int		y_pos;
}				t_game;
#endif
