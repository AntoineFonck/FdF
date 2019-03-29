/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:25:02 by afonck            #+#    #+#             */
/*   Updated: 2019/03/29 11:52:48 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_view(t_map *map)
{
	destroy_and_clear(map);
	trace_par_or_iso(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	menu(map);
}

void	altitude(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == MAIN_PLUS || key == NUM_PLUS)
	{
		if (map->w_max * map->h_max < 250)
			map->change_alt++;
		else
			map->change_alt += 0.02;
	}
	else if (key == MAIN_MIN || key == NUM_MIN)
	{
		if (map->w_max * map->h_max < 250)
			map->change_alt--;
		else
			map->change_alt -= 0.02;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	menu(map);
}

void	zoom(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == W || key == SCROLL_UP)
	{
		map->change_alt += map->change_alt / map->offset;
		map->offset++;
		map->start_point.x -= map->w_max / 2;
		map->start_point.y -= map->h_max / 2;
		map->start_point.xpar -= map->w_max / 2;
		map->start_point.ypar -= map->h_max / 2;
	}
	else if ((key == S || key == SCROLL_DOWN) && map->offset > 1)
	{
		map->change_alt -= map->change_alt / map->offset;
		map->offset--;
		map->start_point.x += map->w_max / 2;
		map->start_point.y += map->h_max / 2;
		map->start_point.ypar += map->h_max / 2;
		map->start_point.xpar += map->w_max / 2;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	menu(map);
}

void	move(int key, t_map *map)
{
	destroy_and_clear(map);
	set_points(map, key);
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	menu(map);
}

void	change_c(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == L)
		map->color = 0;
	else if (key == B)
		map->color = 1;
	else if (key == O)
		map->color = 2;
	else if (key == G)
		map->color = 3;
	else if (key == A)
		map->color = 4;
	else if (key == P)
		map->color = 5;
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	menu(map);
}
