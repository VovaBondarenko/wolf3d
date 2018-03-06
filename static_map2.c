/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 00:41:33 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 00:42:18 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	add_map3_p1(t_map *map)
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
		x = 0;
		while (x < 15)
		{
			if (!map->map_points[y][x])
				map->map_points[y][x] = 0;
			x++;
		}
		y++;
	}
	add_map3_p2(map);
}

void	add_map3_p2(t_map *map)
{
	int	x;
	int	y;

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
	add_y_map(map, 5, 9, 9);
	add_y_map(map, 1, 4, 2);
	add_y_map(map, 1, 4, 4);
	add_y_map(map, 1, 4, 6);
	add_y_map(map, 1, 4, 12);
	add_y_map(map, 7, 14, 5);
}
