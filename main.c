/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:30:57 by afonck            #+#    #+#             */
/*   Updated: 2019/02/25 17:10:05 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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

void		put_coor_in_data(t_map *map, int *data)
{
	int x;
	int y;
	int offset;
	int i;
	int j;

	y = 0;
	i = 0;
	offset = 10;
	while (i < map->h_max/*y < (map->h_max * offset)*/)
	{
		x = ((offset * map->w_max) / 2) + offset;
		j = 0;
		while (j < map->w_max/*x < (map->w_max * offset)*/)
		{
			data[(x - y) + ((map->w_max * offset * 20) * ((x + y) / 2)) + (offset * map->w_max * map->h_max * map->tab[i][j])] = 0xFFFFFF;
			//save_line((x - y), ((x + y) / 2), ((x - y) + offset), (((x + y) / 2) + offset), data);
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
	//int	count_w;
	//int	count_h;

	//count_h = 0;
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
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, (map->w_max * 200), (map->h_max * 200)/*WIN_WIDTH, WIN_HEIGHT*/);
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
	//save_line(100, 100, 100, 150, mlx.img.data);
	put_coor_in_data(map, mlx.img.data);
	while (i < 208)
	{
		printf("data[%d] = %d\n", i, mlx.img.data[i]);
		i++;
	}
	printf("mlx.img.data[%d] = %d\n", i, mlx.img.data[i]);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 100, 100);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
