/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:00:24 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/28 15:26:36 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keys_and_mouse(t_map *map)
{
	mlx_hook(map->win_ptr, 2, 0, key_press, map);
	mlx_hook(map->win_ptr, 4, 0, mouse_press, map);
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
	else if (key == L || key == B || key == O || key == G || key == A || key == P)
		change_c(key, map);
	else if (key == N || key == M)
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
	return (0);
}
