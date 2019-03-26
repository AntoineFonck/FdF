/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:25:02 by afonck            #+#    #+#             */
/*   Updated: 2019/03/26 17:10:55 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys_and_mouse.h"

void close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
}

void change_view(t_map *map)
{
	destroy_and_clear(map);
	trace_par_or_hor(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->change_alt);
		menu(map);
}

void	altitude(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == MAIN_PLUS || key == NUM_PLUS)
		map->change_alt += 0.04;
	else if (key == MAIN_MIN || key == NUM_MIN)
		map->change_alt -= 0.04;
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->change_alt);
		menu(map);
}

void	zoom(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == W || key == SCROLL_UP)// && map->const1 < 1)// && map->const2 < 1)
	{
		map->change_alt += map->change_alt / map->offset;
		map->offset++;
		map->start_point.x -= map->w_max / 2;
		map->start_point.y -= map->h_max / 2;
		map->start_point.h -= map->h_max / 2;
	}
	else if ((key == S || key == SCROLL_DOWN) && map->offset > 1)//&& map->const1 > 0.5)// && map->const2 > 0.5)
	{
		map->change_alt -= map->change_alt / map->offset;
		map->offset--;
		map->start_point.x += map->w_max / 2;
		map->start_point.y += map->h_max / 2;
		map->start_point.h += map->h_max / 2;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->offset);
		menu(map);
}

void  move(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == ARROW_UP) // UP
	{
		map->start_point.y -= 10;
		map->start_point.h -= 10;
		if (map->view == 1)
			map->start_point.x -= 10;
	}
	else if (key == ARROW_DOWN) // DOWN
	{
		map->start_point.y += 10;
		map->start_point.h += 10;
		if (map->view == 1)
			map->start_point.x += 10;
	}
	else if (key == ARROW_LEFT) // LEFT
	{
		map->start_point.x -= 10;
		if (map->view == 1)
			map->start_point.y += 10;
	}
	else if (key == ARROW_RIGHT) // RIGHT
	{
		map->start_point.x += 10;
		if (map->view == 1)
			map->start_point.y -= 10;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->change_alt);
		menu(map);
}

void	reset(t_map *map)
{
	destroy_and_clear(map);
	init_map(map);
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
		menu(map);
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
		menu(map);
	return(1);
}
/*
int all(int key, t_map *map)
{
//	if (key == 24 || key == 27 || key == 69 || key == 78)
//		altitude(key, map);
	//else if (key == 13 || key == 1)
	//	zoom(key, map);
	//else if (key == 123 || key == 124 || key == 125 || key == 126)
	//	move(key, map);
//	else if (key == 53)
//		close_window(map);
//	else if (key == 8)
//		change_view(map);
	else if (key == 88 || key == 87)
		rotate(key, map);
//	else if (key == 15)
//		reset(map);
	return (0);
}
*/
