/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_proj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:36:36 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/22 11:39:19 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	trace_horizontal_par(t_map *map, int *data)
{
	int x;
	int y;
	int i;
	int j;

	y = /*WIN_WIDTH / 4*/0;
	i = -1;
	while (++i < map->h_max)
	{
		x = /*WIN_HEIGHT / 2*/0;
		j = 0;
		while (j < map->w_max)
		{
			map->point_one.x = (x + (map->const1 * (-(map->tab[i][j]) * map->change_alt)));
			map->point_one.y = (y + ((map->const1 / 2) * (-(map->tab[i][j]) * map->change_alt)));
			x += map->offset;
			j++;
			if (j < map->w_max)
			{
				map->point_two.x = (x + (map->const1 * (-(map->tab[i][j]) * map->change_alt)));
				map->point_two.y = (y + ((map->const1 / 2) * (-(map->tab[i][j]) * map->change_alt)));
				draw_line(map->point_one.x, map->point_one.y, map->point_two.x, map->point_two.y, data);
			}
		}
		y += map->offset;
	}
}

void	trace_vertical_par(t_map *map, int *data)
{
	int x;
	int y;
	int i;
	int j;

	x = /*WIN_HEIGHT / 2*/0;
	j = -1;
	while (++j < map->w_max)
	{
		y =/* WIN_WIDTH / 4*/0;
		i = 0;
		while (i < map->h_max)
		{
			map->point_one.x = (x + (map->const1 * (-(map->tab[i][j]) * map->change_alt)));
			map->point_one.y = (y + ((map->const1 / 2) * (-(map->tab[i][j]) * map->change_alt)));
			y += map->offset;
			i++;
			if (i < map->h_max)
			{
				map->point_two.x = (x + (map->const1 * (-(map->tab[i][j]) * map->change_alt)));
				map->point_two.y = (y + ((map->const1 / 2) * (-(map->tab[i][j]) * map->change_alt)));
				draw_line(map->point_one.x, map->point_one.y, map->point_two.x, map->point_two.y, data);
			}
		}
		x += map->offset;
	}
}