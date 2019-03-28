/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 19:19:14 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/28 15:47:53 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 30,
					0xFFFFFF, "Change altitude: + / -");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 50,
					0xFFFFFF, "Change position: cursors");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 10,
					0xFFFFFF, "Change view (isometric/parallel): C");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 70,
					0xFFFFFF, "Zoom: W / S or scrolling");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 90,
					0xFFFFFF, "Change colors:");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 110,
					0x659C16, "Landscape: L");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 125,
					0xFD9303, "Orange:    O");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 140,
					0xFF6DE6, "Pink:      P");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 155,
					0x5F021F, "Bordeaux:  B");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 170,
					0x007FFF, "Azur:      A");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 185,
					0xA5D610, "Green:     G");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 205,
					0xFFFFFF, "Close the window: 'esc'");
}
