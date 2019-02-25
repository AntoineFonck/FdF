/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:30:57 by afonck            #+#    #+#             */
/*   Updated: 2019/02/25 16:53:48 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	save_line(int x1, int y1, int x2, int y2, int *data)
{
	int x;
	int y;

	if (x1 <= x2 && (x2 - x1) >= abs(y2 - y1))
	{
		x = x1;
		while (x <= x2)
		{
			data[x * WIN_HEIGHT + (y1 + ((y2 - y1) * (x - x1)) / (x2 - x1))] = 0xFF69B4;
			x++;
		}
	}
	else
	{
		y = y1;
		while (y <= y2)
		{
			data[y * WIN_WIDTH + (x1 + ((x2 - x1) * (y - y1)) / (y2 - y1))] = 0xFFFFFF;
			y++;
		}
	}
}

int		main()
{
	t_mlx	mlx;
	//int	count_w;
	//int	count_h;

	//count_h = 0;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Just To Try");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);

	/*
	while (count_h < WIN_HEIGHT)
	{
		count_w = 0;
		while (count_w < WIN_WIDTH)
		{
			if (count_w % 2)
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
			else
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFF0000;
			count_w++;
		}
		count_h++;
	}
	*/
	save_line(0, 0, 40, 40, mlx.img.data);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
