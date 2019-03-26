/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:00:24 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/26 17:10:57 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys_and_mouse.h"

void    keys_and_mouse(t_map *map)
{
	mlx_hook(map->win_ptr, 2, 0, key_press, map);
	//mlx_hook(map->win_ptr, 3, 0, key_release, map);
	mlx_hook(map->win_ptr, 4, 0, mouse_press, map);
	//mlx_hook(map->win_ptr, 5, 0, mouse_release, map);
	//mlx_hook(map->win_ptr, 6, 0, mouse_moving, map);
	//mlx_hook(map->win_ptr, 12, 0, expose, map);
	//mlx_hook(map->win_ptr, 17, 0, close, map);
}

int       key_press(int key, void *param)
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
	else if (key == C)
		change_view(map);
	else if (key == ESC)
		close_window(map);
	else if (key == R)
		reset(map);
	return (0);
}

int     mouse_press(int press, int x, int y, void *param)
{
	t_map *map;

	(void)x;
	(void)y;
	map = (t_map *)param;
	if (press == SCROLL_UP || press == SCROLL_DOWN)
		zoom(press, map);
	//else if (press == LEFT_CLICK)
	    //save in struct that mouse is clicked
	return (0);
}
