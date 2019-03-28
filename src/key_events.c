/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:25:02 by afonck            #+#    #+#             */
/*   Updated: 2019/03/28 15:07:48 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	del_int_tab(map->tab, map->h_max);
	ft_memdel((void **)&map);
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
		map->change_alt++;
	else if (key == MAIN_MIN || key == NUM_MIN)
		map->change_alt--;
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
		//map->start_point.ycenter -= map->h_max / 2;
		//map->start_point.xcenter -= map->w_max / 2;
	}
	else if ((key == S || key == SCROLL_DOWN) && map->offset > 1)
	{
		map->change_alt -= map->change_alt / map->offset;
		map->offset--;
		map->start_point.x += map->w_max / 2;
		map->start_point.y += map->h_max / 2;
		map->start_point.ypar += map->h_max / 2;
		map->start_point.xpar += map->w_max / 2;
		//map->start_point.ycenter += map->h_max / 2;
		//map->start_point.xcenter += map->w_max / 2;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	menu(map);
}

void	move(int key, t_map *map)
{
	destroy_and_clear(map);
	if (key == ARROW_UP)
	{
		map->start_point.y -= 10;
		map->start_point.ypar -= 10;
		map->start_point.x -= 10;
	}
	else if (key == ARROW_DOWN)
	{
		map->start_point.y += 10;
		map->start_point.ypar += 10;
		map->start_point.x += 10;
	}
	else if (key == ARROW_LEFT)
	{
		map->start_point.x -= 10;
		map->start_point.xpar -= 20;
		map->start_point.y += 10;
	}
	else if (key == ARROW_RIGHT)
	{
		map->start_point.x += 10;
		map->start_point.xpar += 20;
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
	menu(map);
}
