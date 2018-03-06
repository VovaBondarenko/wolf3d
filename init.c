/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 00:26:25 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 00:30:32 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				close_app(char *str)
{
	ft_putendl(str);
	exit(0);
}

void				free_map(t_map *map)
{
	if (map == NULL)
		return ;
	if (map->win == NULL)
		mlx_destroy_window(map->mlx, map->win);
	if (map->image == NULL)
		remove_image(map, map->image);
	ft_memdel((void**)&map);
}

void				init_tx_param(t_map *map)
{
	map->tx_param->width = 512;
	map->tx_param->height = 512;
}

t_map				*init(void)
{
	t_map			*map;
	t_textur_param	*tx_param;

	tx_param = (t_textur_param*)ft_memalloc(sizeof(t_textur_param));
	map = (t_map*)ft_memalloc(sizeof(t_map));
	if (tx_param == NULL)
		close_app("Texture struct is not malloc");
	if (map == NULL)
		close_app("Map is not malloc");
	map->texture_off = 1;
	map->music_off = 1;
	map->change_tx = 1;
	map->tx_param = tx_param;
	init_tx_param(map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "Wolf_3d");
	map->image = new_mlx_image(map, WIDTH, HEIGHT);
	if (!map->mlx || !map->win || !map->image || !map->tx_param)
	{
		close_app("Component is not initialize");
		free_map(map);
	}
	return (map);
}
