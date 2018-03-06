/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 01:52:27 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 03:01:05 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF3D_H
# define WOLF3D_WOLF3D_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

# define WIDTH 1200
# define HEIGHT 800
# define TEXT_W 512
# define TEXT_H 512

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define T 17
# define M 46

typedef struct		s_color
{
	int				value;
	int				r;
	int				g;
	int				b;
	int				a;
}					t_color;

typedef struct		s_vector
{
	float			x;
	float			y;
}					t_vector;

typedef struct		s_player
{
	float			x;
	float			y;
	t_vector		delta;
	t_vector		pos;

}					t_player;

typedef struct		s_image
{
	void			*image;
	char			*str;
	int				bpp;
	int				endian;
	int				str_len;
}					t_image;

typedef struct		s_raycast
{
	int				step_x;
	int				step_y;
	float			ray_pos_x;
	float			ray_pos_y;
	float			side_dist_x;
	float			side_dist_y;
	int				side;
	float			ray_dir_x;
	float			ray_dir_y;
	int				map_x;
	int				map_y;
	float			delta_dist_x;
	float			delta_dist_y;
	float			wall_dist;
	int				wall_h;
	float			wall_x;
	float			wall_y;
	float			texture_width;
	int				texture_x;
	int				texture_y;
	float			dist_wall;
	float			dist_player;
	float			floor_x;
	float			floor_y;
	int				hit;
	int				draw_start;
	int				draw_end;
}					t_raycast;

typedef struct		s_textur_param
{
	float			current_fx;
	float			current_fy;
	float			floor_tx;
	float			floor_ty;
	float			current_dist;
	float			weight;
	int				width;
	int				height;
}					t_textur_param;

typedef struct		s_map
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				texture_off;
	int				music_off;
	int				**map_points;
	t_image			*image;
	t_player		player;
	t_raycast		rays;
	t_textur_param	*tx_param;
	void			*wall;
	void			*floor;
	void			*ceiling;
	int				change_tx;
}					t_map;

void				add_map1(t_map *map);
void				add_map2(t_map *map);
void				add_map3_p1(t_map *map);
void				add_map3_p2(t_map *map);
t_map				*init();
void				free_map(t_map *map);
void				close_app(char *str);
void				init_player(t_player *player, t_map *m);
void				move_player_check(int keycode, t_map *map);
int					draw(t_map *map);
void				get_texture(t_map *map, int x);
void				load_texture(t_map *map, int width, int height);
void				load_texture_one(t_map *map, int width, int height);
void				load_texture_two(t_map *map, int width, int height);
int					read_map(char *file, t_map *map);
void				hook(t_map *map);
void				draw_map(t_map *map);
void				get_color(t_map *map, t_color *color);
void				add_color(t_color *color, int r, int g, int b);
void				put_color(t_map *map, t_color *color, int x);
void				clean_map(t_map *map);
int					create_map_points(t_map *map, int width, int heigth);
int					get_map_value(t_map *map, int x, int y);
void				remove_image(t_map *map, t_image *image);
t_image				*new_mlx_image(t_map *map, int width, int heigth);
void				set_pixel(int x, int y, t_map *map, t_color *color);
void				get_texture(t_map *map, int x);
void				print_main_command(void);
int					keydown(int keycode, t_map *map);
void				wall_point(t_map *map);
void				check_dist_wp(t_map *map);
void				draw_floor(t_map *map);
void				draw_pixel(void *texture, int x, int y, t_color *color);
void				ray(t_map *map, int x);
void				add_x_map(t_map *map, int x_start, int x_end, int y);
void				add_y_map(t_map *map, int y_start, int y_end, int x);
void				change_map(t_map *map, int keycode);
void				player_pos(t_player *player, t_map *map);

#endif
