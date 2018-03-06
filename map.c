/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 00:31:50 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 00:36:17 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_block(t_map *map, int x, int y, t_color *color)
{
	int		b_x;
	int		b_y;
	int		size;

	size = WIDTH / 10 / map->height;
	b_y = 2 * size + size * y;
	while (b_y < 2 * size + size * (y + 1))
	{
		b_x = 98 * size + size * x;
		while (b_x < 98 * size + size * (x + 1))
		{
			set_pixel(b_x, b_y, map, color);
			b_x++;
		}
		b_y++;
	}
}

void		draw_map(t_map *map)
{
	int		x;
	int		y;
	t_color	color;

	y = 0;
	add_color(&color, 0, 0, 0);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (get_map_value(map, x, y) > 0)
				draw_block(map, x, y, &color);
			x++;
		}
		y++;
	}
	add_color(&color, 255, 0, 0);
	draw_block(map, map->player.x, map->player.y, &color);
}

int			get_map_value(t_map *map, int x, int y)
{
	if (!(x > 0 || x < map->width - 1 || y > 0 || y < map->height - 1))
		return (0);
	return (map->map_points[y][x]);
}

void		clean_map(t_map *map)
{
	int		y;

	y = 0;
	while (y < map->height)
	{
		ft_memdel((void **)&map->map_points[y]);
		y++;
	}
	ft_memdel((void **)&map->map_points);
}

int			create_map_points(t_map *map, int width, int height)
{
	int		index;

	map->width = width;
	map->height = height;
	if ((map->map_points = (int **)ft_memalloc(sizeof(int *) * height)) == NULL)
		return (0);
	index = 0;
	while (index < height)
	{
		map->map_points[index] = (int*)ft_memalloc(sizeof(int) * width);
		if (map->map_points[index] == NULL)
		{
			clean_map(map);
			return (0);
		}
		index++;
	}
	return (1);
}
