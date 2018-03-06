/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 00:43:17 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 00:47:42 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		player_pos(t_player *player, t_map *map)
{
	int		x;
	int		y;
	int		f;

	y = 0;
	f = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!(f = get_map_value(map, x, y)))
				break ;
			x++;
		}
		if (!f)
			break ;
		y++;
	}
	player->x = x + 0.5f;
	player->y = y + 0.5f;
}

void		move_player_lr(t_map *map, float angle)
{
	float	cosinus;
	float	sinus;
	float	tmp_x;
	float	tmp_y;

	cosinus = cos(angle);
	sinus = sin(angle);
	tmp_x = map->player.pos.x;
	tmp_y = map->player.pos.y;
	map->player.pos.x = tmp_x * cosinus - tmp_y * sinus;
	map->player.pos.y = tmp_x * sinus + tmp_y * cosinus;
	tmp_x = map->player.delta.x;
	tmp_y = map->player.delta.y;
	map->player.delta.x = tmp_x * cosinus - tmp_y * sinus;
	map->player.delta.y = tmp_x * sinus + tmp_y * cosinus;
}

void		move_player(t_map *map, float len)
{
	if (!get_map_value(map, map->player.x + len *
				map->player.delta.x, map->player.y))
		map->player.x += len * map->player.delta.x;
	if (!get_map_value(map, map->player.x, len *
				map->player.delta.y + map->player.y))
		map->player.y += len * map->player.delta.y;
}

void		move_player_check(int keycode, t_map *map)
{
	if (keycode == W)
		move_player(map, 0.5f);
	else if (keycode == S)
		move_player(map, -0.5f);
	else if (keycode == A)
		move_player_lr(map, -2.0f / 180.0f * M_PI);
	else if (keycode == D)
		move_player_lr(map, 2.0f / 180.0f * M_PI);
	draw(map);
}

void		init_player(t_player *player, t_map *map)
{
	player_pos(player, map);
	player->delta.x = 1.0f;
	player->delta.y = 0.0f;
	player->pos.x = 0.0f;
	player->pos.y = 2.0f / 3.0f;
}
