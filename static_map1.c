/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_map1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 00:40:24 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 00:41:15 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	add_y_map(t_map *map, int y_start, int y_end, int x)
{
	while (y_start < y_end)
		map->map_points[y_start++][x] = 1;
}

void	add_x_map(t_map *map, int x_start, int x_end, int y)
{
	while (x_start < x_end)
		map->map_points[y][x_start++] = 1;
}

void	add_map1(t_map *map)
{
	int	x;
	int	y;

	if (map->map_points)
		clean_map(map);
	map->width = 11;
	map->height = 11;
	create_map_points(map, map->width, map->height);
	add_x_map(map, 0, 11, 0);
	add_x_map(map, 0, 11, 10);
	add_y_map(map, 1, 10, 0);
	add_y_map(map, 1, 10, 10);
	y = 0;
	while (y < 11)
	{
		x = 2;
		while (x < 11)
		{
			map->map_points[y][x] = 1;
			x += 2;
		}
		y += 2;
	}
}

void	add_map2(t_map *map)
{
	int	x;
	int	y;

	if (map->map_points)
		clean_map(map);
	map->width = 15;
	map->height = 15;
	create_map_points(map, map->width, map->height);
	add_x_map(map, 0, 15, 0);
	add_x_map(map, 0, 15, 14);
	add_y_map(map, 1, 14, 0);
	add_y_map(map, 1, 14, 14);
	y = 0;
	while (y < 15)
	{
		x = 2;
		while (x < 15)
		{
			map->map_points[y][x] = 1;
			x += 2;
		}
		y += 2;
	}
}
