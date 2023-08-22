/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:05:17 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 18:21:46 by rlouvrie         ###   ########.fr       */
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

typedef struct	s_img
{
	void	*ptr;
	int		width;
	int		height;
}				t_img;

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
	t_img	i_north;
	t_img	i_west;
	t_img	i_east;
	t_img	i_south;
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	int		x_pos;
	int		y_pos;
}				t_game;

/* PARSING */
int		parse_map(t_game *game, t_texture *path, char **argv);
/* FILECHECK_1 */
int		has_cub_extension(char *filename);
int		open_file(char *filename, t_game *game);
int		parse_file(t_game *game, t_texture *path);
/* FILECHECK_2 */
char	*file_to_line(t_game *game);
int		set_textures(char *file, t_texture *path);
char 	*extract_texture(char *file, char *identifier);
int 	set_colors(char *file, t_color *floor, t_color *ceiling);
int		set_map(char *file, t_game *game);
/* ERROR */
void	ft_error(char *msg);
/* FREE */
void	free_texture(t_texture *path);
void	free_map(char **tab);
void	free_game(t_game *game);
/* MAP_CHECK_1 */
int		verify_map(t_game *game);
int		is_valid_char(char c);
int		is_player_char(char c);
int		are_boundaries_walls(char **map);
int		validation_cond(t_game *game, int i, int j, int *p);
/* MAP_CHECK_2 */
int		check_left_right_wall(char **map, int *i, int j);
void	remove_spaces_from_map(char **map);
/* INIT_TEXTURE */
int		init_texture(t_img *img, void *mlx_ptr, char *path);
void	dst_img(t_game *game);
int		init_mlx(t_texture *path, t_game *game);
#endif
