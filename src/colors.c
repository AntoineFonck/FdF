/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:28:04 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/28 15:50:58 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colors(int *data, int x, int y, t_map *map)
{
	if (map->altitude_z > 1)
	{
		if (map->color == 1)
			data[x + y * WIN_WIDTH] = 0x5F021F;
		else if (map->color == 2)
			data[x + y * WIN_WIDTH] = 0xFD9303;
		else if (map->color == 3)
			data[x + y * WIN_WIDTH] = 0xA5D610;
		else if (map->color == 4)
			data[x + y * WIN_WIDTH] = 0x007FFF;
		else if (map->color == 5)
			data[x + y * WIN_WIDTH] = 0xFF6DE6;
	}
	else
		data[x + y * WIN_WIDTH] = 0xFFFFFF;
}

void	landscape_color(int *data, int x, int y, int z)
{
	if (z < -8)
		data[x + y * WIN_WIDTH] = 0x0000C8;
	else if (z >= -8 && z <= 0)
		data[x + y * WIN_WIDTH] = 0x0042BF;
	else if (z > 0 && z <= 30)
		data[x + y * WIN_WIDTH] = 0x05701E;
	else if (z > 30 && z <= 50)
		data[x + y * WIN_WIDTH] = 0x659C16;
	else if (z > 50 && z <= 80)
		data[x + y * WIN_WIDTH] = 0xBFC610;
	else if (z > 80 && z <= 110)
		data[x + y * WIN_WIDTH] = 0xF7FF42;
	else if (z > 110 && z <= 140)
		data[x + y * WIN_WIDTH] = 0xC4A564;
	else if (z > 140 && z <= 190)
		data[x + y * WIN_WIDTH] = 0x986D42;
	else if (z > 190 && z <= 250)
		data[x + y * WIN_WIDTH] = 0x79472A;
	else if (z > 250 && z <= 320)
		data[x + y * WIN_WIDTH] = 0x3B271A;
	else
		data[x + y * WIN_WIDTH] = 0xD9E7E8;
}

void	fill_pix(int *data, int x, int y, int z, t_map *map)
{
	if ((x + y * WIN_WIDTH) < (WIN_WIDTH * WIN_HEIGHT) &&
			(x + y * WIN_WIDTH) > 0 && x < WIN_WIDTH && x > 0)
	{
		if (map->color == 0)
			landscape_color(data, x, y, z);
		else
			colors(data, x, y, map);
	}
}
