/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:06:42 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/21 11:48:02 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw_vertical(int y, int x, int dy, int dx, int *data, int yinc, int xinc)
{
	int i;
	int cumul;

	i = 1;
	cumul = dy / 2;
	while (i <= dy)
	{
		y += yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			x += xinc;
		}
		data[x + y * WIN_WIDTH] = 0x00FF00;
		i++;
	}
}

void	draw_horizontal(int x, int y, int dx, int dy, int *data, int yinc, int xinc)
{
	int i;
	int cumul;

	i = 1;
	cumul = dx / 2;
	while (i <= dx)
	{
		x += xinc;
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			y += yinc;
		}
		data[x + y * WIN_WIDTH] = 0xFF00FF;
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

void	draw_line(int x1, int y1, int x2, int y2, int *data)
{
	int x;
	int y;
	int dx;
	int dy;
	int xinc;
	int yinc;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	xinc = pos_or_neg(dx);
	yinc = pos_or_neg(dy);
	dx = ft_absolute(dx);
	dy = ft_absolute(dy);
	data[x + y * WIN_WIDTH] = 0xFFFFFF;
	if (dx > dy)
	{
		draw_horizontal(x, y, dx, dy, data, yinc, xinc);
	}
	else
	{
		draw_vertical(y, x, dy, dx, data, yinc, xinc);
	}
}
