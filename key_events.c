/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:25:02 by afonck            #+#    #+#             */
/*   Updated: 2019/03/22 17:00:34 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
}

int	altitude(int key, t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img.img_ptr);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map->img.data = (int *)mlx_get_data_addr(map->img.img_ptr, &map->img.bpp, &map->img.size_l, &map->img.endian);
	if (key == 24)
		map->change_alt += 0.5;
	else if (key == 27)
		map->change_alt -= 0.5;
	trace_horizontal(map, map->img.data);
	trace_vertical(map, map->img.data);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->change_alt);
	return(1);
}

int	zoom(int key, t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img.img_ptr);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map->img.data = (int *)mlx_get_data_addr(map->img.img_ptr, &map->img.bpp, &map->img.size_l, &map->img.endian);
	if (key == 13)// && map->const1 < 1)// && map->const2 < 1)
	{
		//map->const1 += 0.1;
		//map->const2 += 0.1;
		map->offset++;
		//map->change_alt += 0.118;
	}
	else if (key == 1 && map->offset > 0)//&& map->const1 > 0.5)// && map->const2 > 0.5)
	{
		//map->const1 -= 0.1;
		//map->const2 -= 0.1;
		map->offset--;
		//map->change_alt -= 2;
	}
	trace_horizontal(map, map->img.data);
	trace_vertical(map, map->img.data);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->offset);
	return(1);
}

int move(int key, t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img.img_ptr);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map->img.data = (int *)mlx_get_data_addr(map->img.img_ptr, &map->img.bpp, &map->img.size_l, &map->img.endian);
	if (key == 126) // UP
	{
		map->start_point.y -= 10;
		map->start_point.x -= 10;
	}
	else if (key == 125) // DOWN
	{
		map->start_point.y += 10;
		map->start_point.x += 10;
	}
	else if (key == 123) // LEFT
	{
		map->start_point.x -= 10;
		map->start_point.y += 10;
	}
	else if (key == 124) // RIGHT
	{
		map->start_point.x += 10;
		map->start_point.y -= 10;
	}
	trace_horizontal(map, map->img.data);
	trace_vertical(map, map->img.data);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->change_alt);
	return(1);
}

void reset_map(t_map *map)
{
	map->offset = 2;
	map->change_alt = 1;
	map->const1 = 1;
	map->const2 = 1;
	map->start_point.x = WIN_WIDTH / 2;
	map->start_point.y = 0;
}

int	reset(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img.img_ptr);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map->img.data = (int *)mlx_get_data_addr(map->img.img_ptr, &map->img.bpp, &map->img.size_l, &map->img.endian);
	reset_map(map);
	trace_horizontal(map, map->img.data);
	trace_vertical(map, map->img.data);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	return(1);
}

int all(int key, t_map *map)
{
	if (key == 24 || key == 27)
		altitude(key, map);
	else if (key == 13 || key == 1)
		zoom(key, map);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move(key, map);
	else if (key == 53)
		close_window(map);
	else if (key == 15)
		reset(map);
	return (0);
}