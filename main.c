/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:30:57 by afonck            #+#    #+#             */
/*   Updated: 2019/03/18 15:53:04 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	fill_pix(int *data, int x, int y, /*int w_max, */int color)
{
	data[x + y/*(y * w_max * 10)*/] = color;
}

void	save_line(int x1, int y1, int x2, int y2, int *data)
{
	int x;
	int y;
	//int offset;

	//offset = 10;

	if (x1 <= x2 && (x2 - x1) >= abs(y2 - y1))
	{
		x = x1;
		while (x <= x2)
		{
			data[x + (y1 + ((y2 - y1) * (x - x1)) / (x2 - x1))] = 0xFF69B4;
			x++;
		}
	}
	else
	{
	y = y1;
		while (y <= y2)
		{
			data[y + (x1 * (((x2 - x1) + (y - y1)) / (y2 - y1)))] = 0xFFFFFF;
			y++;
		}
	}
}

void		put_coor_in_data(t_map *map, int *data)
{
	int x;
	int y;
	double myconst = 0.6;
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
			//save_line((x - y), ((map->w_max * offset * 20) * ((x + y) / 2)), (x + offset) - y, (((x +  offset) + y) / 2), data, offset);
			fill_pix(data, (myconst * x - myconst2 * y), ((map->tab[i][j] + (myconst / 2) * x + (myconst2 / 2) * y) * WIN_WIDTH), 0xFFFFFF);
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
