/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:25:02 by afonck            #+#    #+#             */
/*   Updated: 2019/03/27 16:03:14 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	del_int_tab(map->tab, map->h_max);
	exit(0);
}

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
	if (key == W || key == SCROLL_UP)
	{
		map->change_alt += map->change_alt / map->offset;
		map->offset++;
		map->start_point.x -= map->w_max / 2;
		map->start_point.y -= map->h_max / 2;
		map->start_point.h -= map->h_max / 2;
		//map->start_point.ycenter -= map->h_max / 2;
		//map->start_point.xcenter -= map->w_max / 2;
	}
	else if ((key == S || key == SCROLL_DOWN) && map->offset > 1)
	{
		map->change_alt -= map->change_alt / map->offset;
		map->offset--;
		map->start_point.x += map->w_max / 2;
		map->start_point.y += map->h_max / 2;
		map->start_point.h += map->h_max / 2;
		//map->start_point.ycenter += map->h_max / 2;
		//map->start_point.xcenter += map->w_max / 2;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->offset);
	menu(map);
}

void	move(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == ARROW_UP)
	{
		map->start_point.y -= 10;
		map->start_point.h -= 10;
		if (map->view == 1)
			map->start_point.x -= 10;
	}
	else if (key == ARROW_DOWN)
	{
		map->start_point.y += 10;
		map->start_point.h += 10;
		if (map->view == 1)
			map->start_point.x += 10;
	}
	else if (key == ARROW_LEFT)
	{
		map->start_point.x -= 10;
		if (map->view == 1)
			map->start_point.y += 10;
	}
	else if (key == ARROW_RIGHT)
	{
		map->start_point.x += 10;
		if (map->view == 1)
			map->start_point.y -= 10;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
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

void	rotate(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == N)
	{
		map->gamma += 0.1;
	}
	else if (key == M)
	{
		map->gamma -= 0.1;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->gamma);
	menu(map);
}
