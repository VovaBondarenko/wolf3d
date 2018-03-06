/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 00:18:08 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 00:21:47 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			add_color(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

void			get_color(t_map *map, t_color *color)
{
	if (map->rays.side == 0)
	{
		if (map->rays.step_x == -1)
			add_color(color, 128, 0, 255);
		else
			add_color(color, 0, 102, 204);
	}
	else if (map->rays.side == 1 && map->rays.hit == 1)
	{
		if (map->rays.step_y == -1)
			add_color(color, 204, 204, 0);
		else
			add_color(color, 0, 204, 153);
	}
}

void			put_color(t_map *map, t_color *color, int x)
{
	int			y;
	t_color		c;

	y = 0;
	add_color(&c, 204, 255, 255);
	while (y < map->rays.draw_start)
	{
		set_pixel(x, y, map, &c);
		y++;
	}
	y = map->rays.draw_start;
	while (y < map->rays.draw_end)
	{
		set_pixel(x, y, map, color);
		y++;
	}
	y = map->rays.draw_end;
	add_color(&c, 175, 175, 175);
	while (y < HEIGHT)
	{
		set_pixel(x, y, map, &c);
		y++;
	}
}
