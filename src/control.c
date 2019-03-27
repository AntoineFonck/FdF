/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:00:24 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/27 14:03:52 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys_and_mouse.h"

void	keys_and_mouse(t_map *map)
{
	mlx_hook(map->win_ptr, 2, 0, key_press, map);
	mlx_hook(map->win_ptr, 4, 0, mouse_press, map);
	mlx_hook(map->win_ptr, 5, 0, mouse_release, map);
	mlx_hook(map->win_ptr, 6, 0, mouse_moving, map);
	//mlx_hook(map->win_ptr, 12, 0, expose, map);
	//mlx_hook(map->win_ptr, 17, 0, close, map);
}

int		key_press(int key, void *param)
{
	t_map *map;

	map = (t_map *)param;
	if (key == W || key == S)
		zoom(key, map);
	else if (key == ARROW_UP || key == ARROW_DOWN ||
			key == ARROW_LEFT || key == ARROW_RIGHT)
		move(key, map);
	else if (key == MAIN_PLUS || key == NUM_PLUS ||
			key == MAIN_MIN || key == NUM_MIN)
		altitude(key, map);
	else if (key == N || key == M)// can change this again
		rotate(key, map);
	else if (key == C)
		change_view(map);
	else if (key == ESC)
		close_window(map);
	else if (key == R)
		reset(map);
	return (0);
}

int		mouse_press(int press, int x, int y, void *param)
{
	t_map *map;

	(void)x;
	(void)y;
	map = (t_map *)param;
	if (press == SCROLL_UP || press == SCROLL_DOWN)
		zoom(press, map);
	else if (press == LEFT_CLICK)
		map->mouse.pressed = 1;
	return (0);
}

/*
**	Mouse release needed?
*/

int		mouse_release(int press, int x, int y, void *param)
{
	t_map	*map;

	(void)x;
	(void)y;
	(void)press;
	map = (t_map *)param;
	map->mouse.pressed = 0;
	return (0);
}

/*
** Mouse moving needed?
*/

int		mouse_moving(int x, int y, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	map->mouse.previous_x = map->mouse.x;
	map->mouse.previous_y = map->mouse.y;
	map->mouse.x = x;
	map->mouse.y = y;
	if (map->mouse.pressed)
	{
		map->mouse.x += (x - map->mouse.previous_x) * 0.002;
		map->mouse.y += (y - map->mouse.previous_y) * 0.002;
		trace_all(map);
		//mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	}
	return (0);
}
