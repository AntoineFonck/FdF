/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:28:04 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/26 15:39:04 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

/*
   unsigned long createcolor(int r, int g, int b)
   {   
   return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
   }
   */
/*
   void	int_to_rgb(t_param **param)
   {
   (*param)->red = ((*param)->color >> 16) & 255;
   (*param)->green = ((*param)->color >> 8) & 255;
   (*param)->blue = (*param)->color & 255;
   }
   */
int		rgb_to_int(unsigned int red, unsigned int green, unsigned int blue)
{
	int color;

	color = red << 16 | green << 8 | blue;
	return (color);
}
/*
   int main()
   {
   printf("%d", rgb_to_int(255, 255, 255));
   }
   */

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

void    fill_pix(int *data, int x, int y, int z)
{
	/*
	  int color;
	  int red;
	  int green;
	  int blue;
	  red = 0;
	  green = 0;
	  blue = 0;
	  color = rgb_to_int(red, green, blue);
	  */
	if ((x + y * WIN_WIDTH) < (WIN_WIDTH * WIN_HEIGHT) && (x + y * WIN_WIDTH) > 0 && x < WIN_WIDTH && x > 0)
	{
		choose_color(data, x, y, z);
	}
}
