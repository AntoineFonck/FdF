/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:18:34 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/27 16:27:57 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_map *map)
{
	if (map->w_max * map->h_max < 250)
	{
		map->offset = 40;
		map->change_alt = 1;
	}
	else
	{
		map->offset = 2;
		map->change_alt = 0.05;
	}
	map->const1 = 1;
	map->const2 = 1;
	map->start_point.x = WIN_WIDTH / 2;
	map->start_point.y = 0;
	map->start_point.h = WIN_HEIGHT / 2 - map->h_max / 2;
	//map->start_point.xcenter = map->w_max / 2 + map->start_point.x;
	//map->start_point.ycenter = map->h_max / 2 + map->start_point.h;
	map->view = 1;
	map->gamma = 0;
}

void	destroy_and_clear(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img.img_ptr);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map->img.data = (int *)mlx_get_data_addr(map->img.img_ptr,
					&map->img.bpp, &map->img.size_l, &map->img.endian);
}
