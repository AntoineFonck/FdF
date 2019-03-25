/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:30:57 by afonck            #+#    #+#             */
/*   Updated: 2019/03/25 16:29:06 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_map	*map;
	int	i;

	i = 0;
	if (argc != 2)
		return (1);
	if (((map = parse(argv[1]))) == NULL)
		return (1);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map->img.data = (int *)mlx_get_data_addr(map->img.img_ptr, &map->img.bpp, &map->img.size_l, &map->img.endian);
	map->offset = 2;
	map->change_alt = 0.1;
	map->const1 = 1;
	map->const2 = 1;
	map->start_point.x = WIN_WIDTH / 2;
	map->start_point.y = 0;
	map->view = 1;
	//map->menu = 1;
	trace_all(map);
	//trace_horizontal(map, map->img.data);
	//trace_vertical(map, map->img.data);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	mlx_key_hook(map->win_ptr, &all, map);
	menu(map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
