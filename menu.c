/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 01:13:07 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 03:00:32 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	music_on_off(t_map *map)
{
	if (map->music_off == 0)
	{
		system("afplay ./music/smd.mp3&");
		map->music_off = 1;
	}
	else
	{
		system("killall afplay 2&>/dev/null >/dev/null");
		map->music_off = 0;
	}
}

void	change_texture_param(t_map *map)
{
	map->texture_off = (map->texture_off == 1 ? 0 : 1);
	draw(map);
}

void	close_wolf(void)
{
	ft_putendl("Close App");
	exit(0);
}

int		keydown(int keycode, t_map *map)
{
	if (keycode == ESC)
		close_wolf();
	else if (keycode == A || keycode == W || keycode == S || keycode == D)
		move_player_check(keycode, map);
	else if (keycode == T)
		change_texture_param(map);
	else if (keycode == M)
		music_on_off(map);
	if (keycode == 123)
		move_player_check(A, map);
	else if (keycode == 125)
		move_player_check(S, map);
	else if (keycode == 124)
		move_player_check(D, map);
	else if (keycode == 126)
		move_player_check(W, map);
	else if (keycode >= 18 && keycode <= 20)
		change_map(map, keycode);
	return (1);
}

void	print_main_command(void)
{
	ft_putendl("----------WELCOME----------");
	ft_putendl("---------------------------");
	ft_putendl("-User-Control:-----A-W-S-D-");
	ft_putendl("-Turn-On-Textures:-------T-");
	ft_putendl("-Change-Map:---------1-2-3-");
	ft_putendl("-Music-On-:--------------M-");
	ft_putendl("-Turn-On-Textures:-------T-");
	ft_putendl("-Quit:-----------------ESC-");
	ft_putendl("---------------------------");
}
