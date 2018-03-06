/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 01:36:13 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 01:40:52 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			load_texture(t_map *map, int width, int height)
{
	if (map->change_tx == 1)
	{
		load_texture_one(map, width, height);
		map->change_tx = 0;
	}
	else
	{
		load_texture_two(map, width, height);
		map->change_tx = 1;
	}
}

void			load_texture_one(t_map *map, int width, int height)
{
	map->wall = mlx_xpm_file_to_image(map->mlx,
		"./textures/sand4.XPM", &width, &height);
	map->floor = mlx_xpm_file_to_image(map->mlx,
		"./textures/last.XPM", &width, &height);
	map->ceiling = mlx_xpm_file_to_image(map->mlx,
		"./textures/sand4.XPM", &width, &height);
}

void			load_texture_two(t_map *map, int width, int height)
{
	map->wall = mlx_xpm_file_to_image(map->mlx,
		"./textures/last.XPM", &width, &height);
	map->floor = mlx_xpm_file_to_image(map->mlx,
		"./textures/last.XPM", &width, &height);
	map->ceiling = mlx_xpm_file_to_image(map->mlx,
		"./textures/last.XPM", &width, &height);
}

void			impl_texture_ceil(t_map *map, int x, int y, t_color *color)
{
	y = HEIGHT - y;
	map->tx_param->current_dist = HEIGHT / (2.0 * y - HEIGHT);
	map->tx_param->weight = (map->tx_param->current_dist -
			map->rays.dist_player) /
		(map->rays.dist_wall - map->rays.dist_player);
	map->tx_param->current_fx = map->tx_param->weight * map->rays.floor_x +
		(1.0 - map->tx_param->weight) * map->player.x;
	map->tx_param->current_fy = map->tx_param->weight * map->rays.floor_y +
		(1.0 - map->tx_param->weight) * map->player.y;
	map->tx_param->floor_tx = (int)(map->tx_param->current_fx *
			map->tx_param->width) % map->tx_param->width;
	map->tx_param->floor_ty = (int)(map->tx_param->current_fy *
			map->tx_param->height) % map->tx_param->height;
	y = HEIGHT - y;
	draw_pixel(map->ceiling, map->tx_param->floor_tx * 512 / 512,
			map->tx_param->floor_ty * 512 / 512, color);
	set_pixel(x, y, map, color);
}

void			get_texture(t_map *map, int x)
{
	int			y;
	t_color		color;

	y = 0;
	add_color(&color, 0, 0, 0);
	while (y < map->rays.draw_start)
	{
		impl_texture_ceil(map, x, y, &color);
		y++;
	}
	y = map->rays.draw_start - 1;
	while (y < map->rays.draw_end)
	{
		draw_pixel(map->wall, map->rays.texture_x * 512 / 512,
				(y - map->rays.draw_start) * 512 / map->rays.wall_h, &color);
		set_pixel(x, y, map, &color);
		y++;
	}
	add_color(&color, 61, 41, 41);
	y = map->rays.draw_end - 1;
	while (y < HEIGHT)
	{
		set_pixel(x, y, map, &color);
		y++;
	}
}
