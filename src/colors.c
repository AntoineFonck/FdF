/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:28:04 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/27 14:38:43 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int		rgb_to_int(unsigned int red, unsigned int green, unsigned int blue)
{
	int color;

	color = red << 16 | green << 8 | blue;
	return (color);
}

void	choose_color(int *data, int x, int y, int z)
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

void	fill_pix(int *data, int x, int y, int z)
{
	if ((x + y * WIN_WIDTH) < (WIN_WIDTH * WIN_HEIGHT) &&
			(x + y * WIN_WIDTH) > 0 && x < WIN_WIDTH && x > 0)
	{
		choose_color(data, x, y, z);
	}
}
