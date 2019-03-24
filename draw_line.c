/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:06:42 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/22 16:15:57 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw_vertical(int dy, int dx, int *data, int yinc, int xinc, t_map *map)
{
	int i;
	int cumul;

	i = 1;
	cumul = dy / 2;
	while (i <= dy)
	{
		map->point_one.y += yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			map->point_one.x += xinc;
		}
		fill_pix(data, map->point_one.x, map->point_one.y, map->altitude_z);
		i++;
	}
}

void	draw_horizontal(int dx, int dy, int *data, int yinc, int xinc, t_map *map)
{
	int i;
	int cumul;

	i = 1;
	cumul = dx / 2;
	while (i <= dx)
	{
		map->point_one.x += xinc;
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			map->point_one.y += yinc;
		}
		fill_pix(data, map->point_one.x, map->point_one.y, map->altitude_z);
		i++;
	}
}

int pos_or_neg(int i)
{
	if (i > 0)
		return (1);
	else
		return (-1);
}

void	draw_line(t_map *map, int *data)
{
	int dx;
	int dy;
	int xinc;
	int yinc;

	dx = map->point_two.x - map->point_one.x;
	dy = map->point_two.y - map->point_one.y;
	xinc = pos_or_neg(dx);
	yinc = pos_or_neg(dy);
	dx = ft_absolute(dx);
	dy = ft_absolute(dy);
	fill_pix(data, map->point_one.x, map->point_one.y, map->altitude_z);
	if (dx > dy)
		draw_horizontal(dx, dy, data, yinc, xinc, map);
	else
		draw_vertical(dy, dx, data, yinc, xinc, map);
}
