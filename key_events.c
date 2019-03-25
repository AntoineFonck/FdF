/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:25:02 by afonck            #+#    #+#             */
/*   Updated: 2019/03/25 17:38:19 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys_and_mouse.h"
int close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
}

int change_view(t_map *map)
{
	destroy_and_clear(map);
	trace_par_or_hor(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->change_alt);
	return(1);
}

int	altitude(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == 24)
		map->change_alt += 0.1;
	else if (key == 27)
		map->change_alt -= 0.1;
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->change_alt);
	return(1);
}

int	zoom(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == 13 || key == SCROLL_UP)// && map->const1 < 1)// && map->const2 < 1)
	{
		map->change_alt += map->change_alt / map->offset;
		map->offset++;
	}
	else if ((key == 1 || key == SCROLL_DOWN) && map->offset > 1)//&& map->const1 > 0.5)// && map->const2 > 0.5)
	{
		map->change_alt -= map->change_alt / map->offset;
		map->offset--;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->offset);
	return(1);
}

int move(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == 126) // UP
	{
		map->start_point.y -= 10;
		if (map->view == 1)
			map->start_point.x -= 10;
	}
	else if (key == 125) // DOWN
	{
		map->start_point.y += 10;
		if (map->view == 1)
			map->start_point.x += 10;
	}
	else if (key == 123) // LEFT
	{
		map->start_point.x -= 10;
		if (map->view == 1)
			map->start_point.y += 10;
	}
	else if (key == 124) // RIGHT
	{
		map->start_point.x += 10;
		if (map->view == 1)
			map->start_point.y -= 10;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->change_alt);
	return(1);
}

int	reset(t_map *map)
{
	destroy_and_clear(map);
	init_map(map);
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	return(1);
}

int	rotate(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == 88)
	{
		map->gamma += 0.2;
	}
	else if (key == 87)
	{
		map->gamma -= 0.2;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->gamma);
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
	else if (key == 8)
		change_view(map);
	else if (key == 88 || key == 87)
		rotate(key, map);
	else if (key == 15)
		reset(map);
	return (0);
}
