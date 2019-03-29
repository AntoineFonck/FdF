/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_par.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:01:58 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/29 12:10:57 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	point_two(int x, int y, t_map *map)
{
	int i;
	int j;

	i = map->i;
	j = map->j;
	map->point_two.x = (x + (map->const1 * (-(map->tab[i][j])
						* map->change_alt)));
	map->point_two.y = (y + ((map->const1 / 2) * (-(map->tab[i][j])
						* map->change_alt)));
	map->altitude_z = map->tab[i][j];
}

void	trace_horizontal_par(t_map *map)
{
	int x;
	int y;

	y = map->start_point.ypar;
	map->i = -1;
	while (++map->i < map->h_max)
	{
		x = map->start_point.xpar;
		map->j = 0;
		while (map->j < map->w_max)
		{
			map->point_one.x = (x + (map->const1 *
							(-(map->tab[map->i][map->j]) * map->change_alt)));
			map->point_one.y = (y + ((map->const1 / 2) *
							(-(map->tab[map->i][map->j]) * map->change_alt)));
			x += map->offset;
			map->j++;
			if (map->j < map->w_max)
			{
				point_two(x, y, map);
				draw_line(map);
			}
		}
		y += map->offset;
	}
}

void	trace_vertical_par(t_map *map)
{
	int x;
	int y;

	x = map->start_point.xpar;
	map->j = -1;
	while (++map->j < map->w_max)
	{
		y = map->start_point.ypar;
		map->i = 0;
		while (map->i < map->h_max)
		{
			map->point_one.x = (x + (map->const1 *
							(-(map->tab[map->i][map->j]) * map->change_alt)));
			map->point_one.y = (y + ((map->const1 / 2) *
							(-(map->tab[map->i][map->j]) * map->change_alt)));
			y += map->offset;
			map->i++;
			if (map->i < map->h_max)
			{
				point_two(x, y, map);
				draw_line(map);
			}
		}
		x += map->offset;
	}
}
