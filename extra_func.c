/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 01:24:14 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 01:30:23 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		check_dist_wp(t_map *map)
{
	map->rays.dist_wall = map->rays.wall_dist;
	map->rays.dist_player = 0.0;
	if (map->rays.draw_end < 0)
		map->rays.draw_end = 800;
}

void		draw_floor(t_map *map)
{
	if (map->rays.side == 0)
	{
		if (map->rays.ray_dir_x > 0)
		{
			map->rays.floor_x = map->rays.map_x;
			map->rays.floor_y = map->rays.map_y + map->rays.wall_x;
		}
		else
		{
			map->rays.floor_x = map->rays.map_x + 1.0;
			map->rays.floor_y = map->rays.map_y + map->rays.wall_x;
		}
	}
	else if (map->rays.side == 1 && map->rays.ray_dir_y > 0)
	{
		map->rays.floor_x = map->rays.map_x + map->rays.wall_x;
		map->rays.floor_y = map->rays.map_y;
	}
	else if (map->rays.side == 1 && map->rays.ray_dir_y < 0)
	{
		map->rays.floor_x = map->rays.map_x + map->rays.wall_x;
		map->rays.floor_y = map->rays.map_y + 1.0;
	}
}

void		wall_point(t_map *map)
{
	map->rays.wall_x = (map->rays.side ? map->rays.ray_pos_x +
			map->rays.wall_dist * map->rays.ray_dir_x :
		map->rays.ray_pos_y + map->rays.wall_dist * map->rays.ray_dir_y);
	map->rays.wall_x -= floor(map->rays.wall_x);
	map->rays.texture_x = (int)(map->rays.wall_x * map->tx_param->width);
	if ((map->rays.side == 0 && map->rays.ray_dir_x > 0) ||
		(map->rays.side == 1 && map->rays.ray_dir_y < 0))
		map->rays.texture_x = 511 - map->rays.texture_x;
}

void		draw_pixel(void *texture, int x, int y, t_color *color)
{
	char	*tmp;
	int		bpp;
	int		str_len;
	int		endian;
	int		index;

	tmp = mlx_get_data_addr(texture, &bpp, &str_len, &endian);
	index = y * str_len + x * (bpp / 8);
	color->b = tmp[index];
	color->g = tmp[index + 1];
	color->r = tmp[index + 2];
}
