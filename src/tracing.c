/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:14:29 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/27 16:02:57 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(int *x, int *y, t_map *map)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - map->start_point.xcenter) * cos(map->gamma) - (previous_y - map->start_point.ycenter) * sin(map->gamma) + map->start_point.xcenter;
	*y = (previous_x - map->start_point.xcenter) * sin(map->gamma) + (previous_y - map->start_point.ycenter) * cos(map->gamma) + map->start_point.ycenter;
}

void	trace_horizontal(t_map *map, int *data)
{
	int x;
	int y;
	int i;
	int j;

	y = map->start_point.y;
	i = -1;
	while (++i < map->h_max)
	{
		x = map->start_point.x;
		j = 0;
		while (j < map->w_max)
		{
			map->point_one.x = (map->const1 * x - map->const2 * y);
			map->point_one.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
			x += map->offset;
			map->point_two.x = (map->const1 * x - map->const2 * y);
			j++;
			if (j < map->w_max)
			{
				map->point_two.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
				map->altitude_z = map->tab[i][j];
				//rotate_z(&(map->point_two.x), &(map->point_two.y), map);
				draw_line(map, data);
			}
		}
		y += map->offset;
	}
}

void	trace_vertical(t_map *map, int *data)
{
	int x;
	int y;
	int i;
	int j;

	x = map->start_point.x;
	j = -1;
	while (++j < map->w_max)
	{
		y = map->start_point.y;
		i = 0;
		while (i < map->h_max)
		{
			map->point_one.x = (map->const1 * x - map->const2 * y);
			map->point_one.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
			//rotate_z(&(map->point_one.x), &(map->point_one.y), map);
			y += map->offset;
			map->point_two.x = (map->const1 * x - map->const2 * y);
			i++;
			if (i < map->h_max)
			{
				map->point_two.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
				//rotate_z(&(map->point_two.x), &(map->point_two.y), map);
				map->altitude_z = map->tab[i][j];
				draw_line(map, data);
			}
		}
		x += map->offset;
	}
}

void	trace_horizontal_par(t_map *map, int *data)
{
	int x;
	int y;
	int i;
	int j;

	y = map->start_point.ypar;
	i = -1;
	while (++i < map->h_max)
	{
		x = map->start_point.xpar/* - map->w_max / 2*/;
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
				map->altitude_z = map->tab[i][j];
				draw_line(map, data);
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

	x = map->start_point.xpar/* - map->w_max / 2*/;
	j = -1;
	while (++j < map->w_max)
	{
		y = map->start_point.ypar;
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
				map->altitude_z = map->tab[i][j];
				draw_line(map, data);
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
		trace_horizontal_par(map, map->img.data);
		trace_vertical_par(map, map->img.data);
	}
	else
	{
		map->view = 1;
		trace_horizontal(map, map->img.data);
		trace_vertical(map, map->img.data);
	}
}

void	trace_all(t_map *map)
{
	if (map->view == 1)
	{
		trace_horizontal(map, map->img.data);
		trace_vertical(map, map->img.data);
	}
	else
	{
		trace_horizontal_par(map, map->img.data);
		trace_vertical_par(map, map->img.data);
	}
}
