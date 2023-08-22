/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:05:17 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 15:55:18 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../src/libft/libft.h"
# include "../src/mlx/mlx.h"
# include "get_next_line.h"

typedef struct	s_color
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}				t_color;

typedef struct	s_texture
{
	char	*p_north;
	char	*p_west;
	char	*p_east;
	char	*p_south;
}				t_texture;

typedef struct	s_game
{
	int		fd;
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

/* PARSING */
int		parse_map(t_game *game, t_texture *path, char **argv);
/* FILECHECK */
int		has_cub_extension(char *filename);
int		open_file(char *filename, t_game *game);
int		parse_file(t_game *game, t_texture *path);
char	*file_to_line(t_game *game);
int		set_textures(char *file, t_texture *path);
char 	*extract_texture(char *file, char *identifier);
int 	set_colors(char *file, t_color *floor, t_color *ceiling);
int		set_map(char *file, t_game *game);
/* ERROR */
void	ft_error(char *msg);
#endif
