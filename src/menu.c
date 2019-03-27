/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 19:19:14 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/22 20:01:34 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_map *map)
{
	//mlx_string_put(map->mlx_ptr, map->win_ptr, 0, 20, 0xFFFFFF, "Hide Menu: h");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 0, 40, 0xFFFFFF, "Change altitude: + / -");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 0, 60, 0xFFFFFF, "Change position: cursors");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 0, 20, 0xFFFFFF, "Change the view (isometric/parallel): c");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 0, 80, 0xFFFFFF, "Zoom: w / s");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 0, 100, 0xFFFFFF, "Close the window: 'esc'");
}
