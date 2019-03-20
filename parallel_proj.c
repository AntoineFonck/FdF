/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_proj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:36:36 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/20 14:25:32 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
void    fill_pix1(int *data, int x, int y, int color)
{
	    data[x + y * WIN_WIDTH] = color;
}
*/

void            trace_horizontal_par(t_map *map, int *data)
{
	int x;
	int y;
	int i;
	int j;
	double const1;

	y = 0;
	i = 0;
	const1 = 1;
	while (i < map->h_max)
	{
		x = 0; // or (WIN_WIDTH / 2) -> don't know how it's best to display in the end
		j = 0;
		while (j < map->w_max)
		{
			map->point_one.x = (x + (const1 * (-(map->tab[i][j]))));
			map->point_one.y = (y + ((const1 / 2) * (-(map->tab[i][j]))));
			// map->point_one.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
			//fill_pix1(data, map->point_one.x, map->point_one.y, 0xFFFFFF);
			x += map->offset;
			//map->point_two.x = (map->const1 * x - map->const2 * y);
			map->point_two.x = (x + (const1 * (-(map->tab[i][j]))));
			j++;
			if (j < map->w_max)
			{
				map->point_two.y = (y + ((const1 / 2) * (-(map->tab[i][j]))));
				//map->point_two.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
				draw_line(map->point_one.x, map->point_one.y, map->point_two.x, map->point_two.y, data);
			}
		}
		y += map->offset;
		i++;
	}
}


void trace_vertical_par(t_map *map, int *data)
{
	int x;
	int y;
	int i;
	int j;
	double const1;

	x = 0;
	j = 0;
	const1 = 1;
	while (j < map->w_max)
	{
		y = 0;
		i = 0;
		while (i < map->h_max)
		{
			//map->point_one.x = (map->const1 * x - map->const2 * y);
			//map->point_one.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
			map->point_one.x = (x + (const1 * (-(map->tab[i][j]))));
			map->point_one.y = (y + ((const1 / 2) * (-(map->tab[i][j]))));
			//fill_pix1(data, map->point_one.x, map->point_one.y, 0xFFFFFF);
			y += map->offset;
			//map->point_two.x = (map->const1 * x - map->const2 * y);
			map->point_two.x = (x + (const1 * (-(map->tab[i][j]))));
			i++;
			if (i < map->h_max)
			{
				map->point_two.y = (y + ((const1 / 2) * (-(map->tab[i][j]))));
				//map->point_two.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
				draw_line(map->point_one.x, map->point_one.y, map->point_two.x, map->point_two.y, data);
			}
		}
		x += map->offset;
		j++;
	}
}
