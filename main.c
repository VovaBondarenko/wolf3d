/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 00:37:25 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 03:00:15 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		change_map(t_map *map, int keycode)
{
	if (keycode == 18)
		add_map1(map);
	else if (keycode == 19)
		add_map2(map);
	else if (keycode == 20)
		add_map3_p1(map);
	player_pos(&map->player, map);
	draw(map);
}

int			close_w(t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
	return (0);
}

void		hook(t_map *map)
{
	system("killall afplay 2&>/dev/null >/dev/null");
	print_main_command();
	mlx_hook(map->win, 2, 0, keydown, map);
	mlx_hook(map->win, 17, 0, close_w, map);
}

int			main(void)
{
	t_map	*map;

	map = init();
	load_texture(map, 512, 512);
	add_map1(map);
	init_player(&map->player, map);
	draw(map);
	hook(map);
	mlx_loop(map->mlx);
	return (0);
}
