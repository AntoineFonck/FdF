/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:39:45 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/25 16:37:50 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys_and_mouse.h"

int		mouse_press(int press, int x, int y, void *param)
{
	t_map *map;

	(void)x;
	(void)y;
	map = (t_map *)param;
	zoom(press, map);
	/*
	destroy_and_clear(map);
	if (press == SCROLL_UP)
	{
		map->change_alt += map->change_alt / map->offset;
		map->offset++;
	}
	else if (press == SCROLL_DOWN && map->offset > 1)
	{
		map->change_alt -= map->change_alt / map->offset;
		map->offset--;
	}
	trace_all(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	ft_putnbr(map->change_alt);
	//else if (press == LEFT_CLICK)
	//save in struct that mouse is clicked
	*/
	return (0);
}
