/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:30:57 by afonck            #+#    #+#             */
/*   Updated: 2019/03/18 17:26:47 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	fill_pix(int *data, int x, int y, /*int w_max, */int color)
{
	data[x + y] = color;
}

int absolute(int i)
{
	if (i < 0)
		return(-i);
	else
		return(i);
}

void paint_line(int x1, int y1, int x2, int y2, int *data)
{
	int x;
	int y;
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	x = x1;
	y = x2;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx > 0)
		xinc = 1;
	else
		xinc = -1;
	if (dy > 0)
		yinc = 1;
	else
		yinc = -1;
	dx = absolute(dx);
	dy = absolute(dy);
	//data[x + y * WIN_WIDTH] = 0xFF69B4;
	fill_pix(data, x, y, 0xFF69B4);
	if (dx > dy)
	{
		cumul = dx / 2;
		i = 1;
		while (i <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			//data[x + y * WIN_WIDTH] = 0xFF00FF;
			fill_pix(data, x, y, 0xFF00FF);
			i++;
		}
	}
	else
	{
		cumul = dy / 2;
		i = 1;
		while (i <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			//data[x + y * WIN_WIDTH] = 0x00FF00;
			fill_pix(data, x, y, 0x00FF00);
			i++;
		}
	}
}

void		put_coor_in_data(t_map *map, int *data)
{
	int x;
	int y;
	double myconst = 1;
	double myconst2 = 1;
	int offset;
	int i;
	int j;

	y = 0;
	i = 0;
	offset = 10;
	while (i < map->h_max/*y < (map->h_max * offset)*/)
	{
		//x = 0;
		x = WIN_WIDTH / 2;
		j = 0;
		while (j < map->w_max/*x < (map->w_max * offset)*/)
		{
			fill_pix(data, (myconst * x - myconst2 * y), ((map->tab[i][j] + (myconst / 2) * x + (myconst2 / 2) * y) * WIN_WIDTH), 0xFFFFFF);
			paint_line((x - y) * offset, (x + y) * offset, ((x + offset) - y) * offset, ((x + offset) + y) * offset, data);
			x += offset;
			j++;
		}
		y += offset;
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	*map;
	char	**tabchar;
	int	i;

	i = 0;
	if (argc != 2)
		return (1);
	if ((map = malloc(sizeof(t_map))) == NULL)
		return (1);
	//if ((mlx.img = malloc(sizeof(t_img))) == NULL)
	//	return (1);
	if ((tabchar = check_and_read(argv[1], map)) != NULL)
		ft_putstr("check and read works\n");
	atoi_tab(tabchar, map);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Just To Try");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);

	put_coor_in_data(map, mlx.img.data);
	while (i < 208)
	{
		printf("data[%d] = %d\n", i, mlx.img.data[i]);
		i++;
	}
	printf("mlx.img.data[%d] = %d\n", i, mlx.img.data[i]);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
