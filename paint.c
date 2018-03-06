/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 01:33:01 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 02:18:49 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			draw(t_map *map)
{
	int		x;
	t_color	color;

	x = 0;
	while (x < WIDTH)
	{
		ray(map, x);
		wall_point(map);
		draw_floor(map);
		check_dist_wp(map);
		get_color(map, &color);
		if (map->texture_off == 1)
			put_color(map, &color, x);
		else
			get_texture(map, x);
		x++;
	}
	draw_map(map);
	mlx_put_image_to_window(map->mlx, map->win, map->image->image, 0, 0);
	return (1);
}

void		check_dist(t_map *map)
{
	if (map->rays.side == 0)
		map->rays.wall_dist = (map->rays.map_x - map->player.x +
				(1 - map->rays.step_x) / 2) / map->rays.ray_dir_x;
	else
		map->rays.wall_dist = (map->rays.map_y - map->player.y +
				(1 - map->rays.step_y) / 2) / map->rays.ray_dir_y;
	map->rays.wall_h = HEIGHT / map->rays.wall_dist;
	map->rays.draw_start = -(map->rays.wall_h) / 2 + HEIGHT / 2;
	if (map->rays.draw_start < 0)
		map->rays.draw_start = 0;
	map->rays.draw_end = (map->rays.wall_h) / 2 + HEIGHT / 2;
	if (map->rays.draw_end >= HEIGHT)
		map->rays.draw_end = HEIGHT - 1;
}

void		hit_int_wall(t_map *map)
{
	map->rays.hit = 0;
	while (map->rays.hit == 0)
	{
		if (map->rays.side_dist_x < map->rays.side_dist_y)
		{
			map->rays.side_dist_x += map->rays.delta_dist_x;
			map->rays.map_x += map->rays.step_x;
			map->rays.side = 0;
		}
		else
		{
			map->rays.side_dist_y += map->rays.delta_dist_y;
			map->rays.map_y += map->rays.step_y;
			map->rays.side = 1;
		}
		if (map->rays.map_x > map->width || map->rays.map_y > map->height
				|| map->rays.map_x < 0 || map->rays.map_y < 0)
			break ;
		if (map->map_points[map->rays.map_y][map->rays.map_x] > 0)
			map->rays.hit = 1;
	}
}

void		calc_step(t_map *map)
{
	if (map->rays.ray_dir_x < 0)
	{
		map->rays.step_x = -1;
		map->rays.side_dist_x = (map->rays.ray_pos_x -
				map->rays.map_x) * map->rays.delta_dist_x;
	}
	else
	{
		map->rays.step_x = 1;
		map->rays.side_dist_x = (map->rays.map_x + 1.0 -
				map->rays.ray_pos_x) * map->rays.delta_dist_x;
	}
	if (map->rays.ray_dir_y < 0)
	{
		map->rays.step_y = -1;
		map->rays.side_dist_y = (map->rays.ray_pos_y -
				map->rays.map_y) * map->rays.delta_dist_y;
	}
	else
	{
		map->rays.step_y = 1;
		map->rays.side_dist_y = (map->rays.map_y + 1.0 -
				map->rays.ray_pos_y) * map->rays.delta_dist_y;
	}
}

void		ray(t_map *map, int x)
{
	float	cam;

	cam = 2.0f * x / (float)WIDTH - 1.0f;
	map->rays.ray_pos_x = map->player.x;
	map->rays.ray_pos_y = map->player.y;
	map->rays.ray_dir_x = map->player.delta.x + map->player.pos.x * cam;
	map->rays.ray_dir_y = map->player.delta.y + map->player.pos.y * cam;
	map->rays.map_x = (int)map->rays.ray_pos_x;
	map->rays.map_y = (int)map->rays.ray_pos_y;
	map->rays.delta_dist_x = sqrt(1 + (map->rays.ray_dir_y *
				map->rays.ray_dir_y) / (map->rays.ray_dir_x *
					map->rays.ray_dir_x));
	map->rays.delta_dist_y = sqrt(1 + (map->rays.ray_dir_x *
				map->rays.ray_dir_x) / (map->rays.ray_dir_y *
					map->rays.ray_dir_y));
	calc_step(map);
	hit_int_wall(map);
	if (map->rays.hit == 1)
		check_dist(map);
}
