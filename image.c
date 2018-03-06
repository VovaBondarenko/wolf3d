/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 00:22:55 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/30 00:25:24 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_image		*new_mlx_image(t_map *map, int width, int heigth)
{
	t_image *image;

	image = ft_memalloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(map->mlx, width, heigth);
	if (!image->image)
		return (NULL);
	image->str = mlx_get_data_addr(image->image,
			&image->bpp, &image->str_len, &image->endian);
	return (image);
}

void		remove_image(t_map *map, t_image *image)
{
	if (image)
	{
		if (image->image)
			mlx_destroy_image(map->mlx, image->image);
		ft_memdel((void **)&image);
	}
}

void		clean_image(t_map *map, t_image *image)
{
	ft_bzero(image->str, map->width * map->height * image->bpp);
}

void		set_pixel(int x, int y, t_map *map, t_color *color)
{
	int		index;

	index = y * map->image->str_len + x * (map->image->bpp / 8);
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		map->image->str[index] = color->r;
		map->image->str[index + 1] = color->g;
		map->image->str[index + 2] = color->b;
	}
}
