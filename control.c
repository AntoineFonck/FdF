/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:13:34 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/25 16:02:05 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//int		key_press(int key, t_map *map);
//int		key_release(int key, t_map *map);
//int		mouse_press(int press/*, int x, int y*/, t_map *map);
//int		mouse_release(int press/*, int x, int y*/, t_map *map);
//int		mouse_moving(int x, int y, t_map *map);
//int		expose(t_map *map);

void	keys_and_mouse(t_map *map)
{
	//mlx_hook(map->win_ptr, 2, 0, key_press, map);
	//mlx_hook(map->win_ptr, 3, 0, key_release, map);
	mlx_hook(map->win_ptr, 4, 0, mouse_press, map);
	//mlx_hook(map->win_ptr, 5, 0, mouse_release, map);
	//mlx_hook(map->win_ptr, 6, 0, mouse_moving, map);
	//mlx_hook(map->win_ptr, 12, 0, expose, map);
	//mlx_hook(map->win_ptr, 17, 0, close, map);
}
