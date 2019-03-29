/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:14:29 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/29 12:50:11 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	point_one(int x, int y, t_map *map)
{
	int i;
	int j;

	i = map->i;
	j = map->j;
	map->point_one.x = (map->const1 * x - map->const2 * y);
	map->point_one.y = (-(map->tab[i][j]) *
	map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
}

void	trace_horizontal(t_map *map)
{
	int x;
	int y;

	y = map->start_point.y;
	map->i = -1;
	while (++map->i < map->h_max)
	{
		x = map->start_point.x;
		map->j = 0;
		while (map->j < map->w_max)
		{
			point_one(x, y, map);
			x += map->offset;
			map->point_two.x = (map->const1 * x - map->const2 * y);
			map->j++;
			if (map->j < map->w_max)
			{
				map->point_two.y = (-(map->tab[map->i][map->j]) *
				map->change_alt + (map->const1 / 2) * (x + y));
				map->altitude_z = map->tab[map->i][map->j];
				draw_line(map);
			}
		}
		y += map->offset;
	}
}

void	trace_vertical(t_map *map)
{
	int x;
	int y;

	x = map->start_point.x;
	map->j = -1;
	while (++map->j < map->w_max)
	{
		y = map->start_point.y;
		map->i = 0;
		while (map->i < map->h_max)
		{
			point_one(x, y, map);
			y += map->offset;
			map->point_two.x = (map->const1 * x - map->const2 * y);
			map->i++;
			if (map->i < map->h_max)
			{
				map->point_two.y = (-(map->tab[map->i][map->j]) *
							map->change_alt + (map->const1 / 2) * (x + y));
				map->altitude_z = map->tab[map->i][map->j];
				draw_line(map);
			}
		}
		x += map->offset;
	}
}

void	trace_par_or_iso(t_map *map)
{
	if (map->view == 1)
	{
		map->view = 0;
		trace_horizontal_par(map);
		trace_vertical_par(map);
	}
	else
	{
		map->view = 1;
		trace_horizontal(map);
		trace_vertical(map);
	}
}

void	trace_all(t_map *map)
{
	if (map->view == 1)
	{
		trace_horizontal(map);
		trace_vertical(map);
	}
	else
	{
		trace_horizontal_par(map);
		trace_vertical_par(map);
	}
}
