/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 19:19:14 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/28 15:34:23 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 40,
					0xFFFFFF, "Change altitude: + / -");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 60,
					0xFFFFFF, "Change position: cursors");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 20,
					0xFFFFFF, "Change the view (isometric/parallel): c");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 80,
					0xFFFFFF, "Zoom: w / s or scrolling");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 100,
			        0xFFFFFF, "Change colors:");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 120,
			        0xFFFFFF, "Landscape: L");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 135,
					0xFD9303, "Orange: o");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 150,
					0xFF6DE6, "Pink: p");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 165,
					0x5F021F, "Bordeaux: B");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 180,
					0x007FFF, "Azur: A");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 195,
					0xA5D610, "Green: G");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 215,
					0xFFFFFF, "Close the window: 'esc'");
}
