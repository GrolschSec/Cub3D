/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:05:17 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/09/15 17:52:56 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "../src/libft/libft.h"
# include "../src/mlx/mlx.h"
# include "../src/mlx/mlx_int.h"
# include "get_next_line.h"
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define L_KEY 65361
# define R_KEY 65363
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.06
# define PLAYER_RADIUS 0.1

typedef struct s_pos
{
	float	x;
	float	y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	char	direction;
}				t_pos;

typedef struct s_color
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	int				mlx;
}				t_color;

typedef struct s_texture
{
	char	*p_north;
	char	*p_west;
	char	*p_east;
	char	*p_south;
}				t_texture;

typedef struct s_pix
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		pos;
}				t_pix;

enum e_orientation
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

typedef struct s_game
{
	int		fd;
	int		s_width;
	int		s_height;
	t_color	floor;
	t_color	ceiling;
	t_img	i_north;
	t_img	i_west;
	t_img	i_east;
	t_img	i_south;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_buf;
	char	**map;
	size_t	m_width;
	size_t	m_height;
	t_pos	pos;
}				t_game;

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		wall_dir;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_raycast;

/* WINDOW */
void	window_init(t_game *game);
int		handle_event(int keycode, t_game *game);
void	events(t_game *game);
int		close_window(t_game *game);
/* PARSING */
int		parse_map(t_game *game, t_texture *path, char **argv);
int		set_initial_position(t_game *game);
int		check_duplicate(char *file, char *identifier);
int		txt_color_dup_check(char *file);
/* FILECHECK_1 */
int		has_cub_extension(char *filename);
int		open_file(char *filename, t_game *game);
int		parse_file(t_game *game, t_texture *path);
int		set_textures(char *file, t_texture *path);
int		check_empty_line(char *map);
/* FILECHECK_2 */
char	*file_to_line(t_game *game);
char	*extract_texture(char *file, char *identifier);
int		extract_color(char *file, char *identifier, t_color *color);
int		set_colors(char *file, t_color *floor, t_color *ceiling);
int		set_map(char *file, t_game *game);
/* FILECHECK_3 */
void	find_end_of_map(char *str, int len);
int		str_to_rgb(const char *str, int *num);
int		check_color(char *loc);
int		is_nb_formatted(char *loc, char end);
int		check_color_char(char *loc);
/* FILECHECK_4 */
char	*find_start_of_map(char *str);
/* CONVERT_COLORS */
void	convert_color(t_color *color);
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
int		validation_cond(t_game *game, int i, int j, int *p);
/* MAP_CHECK_2 */
int		check_left_right_wall(char **map, int *i, int j);
void	remove_spaces_from_map(char **map);
/* MAP_CHECK_3 */
int		empty_not_open(char **map, int i, int j);
int		is_closed_map(char **map);
/* RESIZE MAP */
int		get_tab_len(char **map);
int		find_largest_line(char **map);
int		resize_line(t_game *game, char **map, int i);
int		resize_map(t_game *game);
/* INIT_TEXTURE */
int		init_texture(t_img *img, void *mlx_ptr, char *path);
void	dst_img(t_game *game);
int		init_mlx(t_texture *path, t_game *game);
/* MOVES_1 */
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
/* MOVES_2 */
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
/* GAME_INIT */
void	set_initial_dir(t_game *game);
void	set_initial_plane(t_game *game);
void	game_init(t_game *game);
void	refresh_display(t_game *game);
/* RAYCAST */
void	init_raycast(t_raycast *ray, t_game *game, int x);
int		raycast(t_game *game);
int		double_buffering(t_game *game);
void	set_pixel_to_image(t_game *game, int x, int y, int color);
int		color_choose(t_game *game, t_raycast *ray, t_img *texture,
			int texture_y);
void	ver_line(t_game *game, t_raycast *ray, int x);
/* RAYCAST 2 */
void	ft_calc_step_side_dist(t_game *game, t_raycast *ray);
void	dda_algorithm(t_game *game, t_raycast *ray);
void	calc_wall_slice_projection(t_game *game, t_raycast *ray);
/* RAYCAST 3 */
void	find_wall_dir(t_raycast *ray);
t_img	*get_wall_texture(t_game *game, t_raycast *ray);
/* COLLISION */
int		is_valid_position(t_game *game, double new_x, double new_y);
#endif
