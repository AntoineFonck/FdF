/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:30:57 by afonck            #+#    #+#             */
/*   Updated: 2019/03/22 19:08:28 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include "colortest.c"

void	fill_pix(int *data, int x, int y, int z)
{
	//int color;
	//int red;
	//int green;
	//int blue;

	//red = 0;
	//green = 0;
	//blue = 0;

	//color = rgb_to_int(red, green, blue);
	if ((x + y * WIN_WIDTH) < (WIN_WIDTH * WIN_HEIGHT) && (x + y * WIN_WIDTH) > 0 && x < WIN_WIDTH && x > 0)
	{
		if (z < -5)
		{
			//red = 33;
			//blue = 229;
			//data[x + y * WIN_WIDTH] = rgb_to_int(red, green, blue);
			data[x + y * WIN_WIDTH] = 0x0000C8;
		}
		else if (z >= -5 && z <= 0)
		{
			//red = 0;
			//green = 66;
			//blue = 191;
			//data[x + y * WIN_WIDTH] = rgb_to_int(red, green, blue);
			data[x + y * WIN_WIDTH] = 0x0042BF;
		}
		else if (z > 0 && z <= 8)
			data[x + y * WIN_WIDTH] = 0x05701E;
		else if (z > 8 && z <= 16)
			data[x + y * WIN_WIDTH] = 0x659C16;
		else if (z > 16 && z <= 26)
			data[x + y * WIN_WIDTH] = 0xBFC610;
		else if (z > 26 && z <= 36)
			data[x + y * WIN_WIDTH] = 0xF7FF42;
		else if (z > 36 && z <= 50)
			data[x + y * WIN_WIDTH] = 0xC4A564;
		else if (z > 50 && z <= 70)
			data[x + y * WIN_WIDTH] = 0x986D42;
		else if (z > 70 && z <= 90)
			data[x + y * WIN_WIDTH] = 0x79472A;
		else if (z > 90 && z <= 130)
			data[x + y * WIN_WIDTH] = 0x3B271A;
		else if (z > 130 && z <= 170)
			data[x + y * WIN_WIDTH] = 0x659C16;
		else
			data[x + y * WIN_WIDTH] = 0xD9E7E8;
		/*
		if (z <= 7)
			data[x + y * WIN_WIDTH] = color;
		else if (z > 7 && z < 10)
			data[x + y * WIN_WIDTH] = color;
		else if (z == 10)
			data[x + y * WIN_WIDTH] = color;
		else
			data[x + y * WIN_WIDTH] = color;
			*/
		/*
		while (z != 0)
		{
			z--;
			if (blue < 256)
				color = rgb_to_int(red, (green -= 10), (blue -= 20));
		}
		data[x + y * WIN_WIDTH] = color;
		*/
	}
}

void		trace_horizontal(t_map *map, int *data)
{
	int x;
	int y;
	int i;
	int j;

	y = map->start_point.y;
	i = 0;
	while (i < map->h_max/*y < (map->h_max * offset)*/)
	{
		x = map->start_point.x;
		j = 0;
		while (j < map->w_max/*x < (map->w_max * offset)*/)
		{
			map->point_one.x = (map->const1 * x - map->const2 * y);
			map->point_one.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
			//fill_pix(data, map->point_one.x, map->point_one.y, 0xFFFFFF);
			x += map->offset;
			map->point_two.x = (map->const1 * x - map->const2 * y);
			j++;
			if (j < map->w_max)
			{
				map->point_two.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
				map->altitude_z = map->tab[i][j];
				draw_line(map->point_one.x, map->point_one.y, map->point_two.x, map->point_two.y, map->altitude_z, data);
			}
		}
		y += map->offset;
		i++;
	}
}


void trace_vertical(t_map *map, int *data)
{
	int x;
	int y;
	int i;
	int j;

	x = map->start_point.x;
	j = 0;
	while (j < map->w_max/*y < (map->h_max * offset)*/)
	{
		y = map->start_point.y;
		i = 0;
		while (i < map->h_max/*x < (map->w_max * offset)*/)
		{
			map->point_one.x = (map->const1 * x - map->const2 * y);
			map->point_one.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
			//fill_pix(data, map->point_one.x, map->point_one.y, 0xFFFFFF);
			y += map->offset;
			map->point_two.x = (map->const1 * x - map->const2 * y);
			i++;
			if (i < map->h_max)
			{
				map->point_two.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
				map->altitude_z = map->tab[i][j];
				draw_line(map->point_one.x, map->point_one.y, map->point_two.x, map->point_two.y, map->altitude_z, data);
			}
		}
		x += map->offset;
		j++;
	}
}

int		main(int argc, char **argv)
{
	//t_mlx	mlx;
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
	//if ((map->img = malloc(sizeof(t_img))) == NULL)
	//	return (1);
	if ((tabchar = check_and_read(argv[1], map)) != NULL)
		ft_putstr("check and read works\n");
	atoi_tab(tabchar, map);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Just To Try");
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map->img.data = (int *)mlx_get_data_addr(map->img.img_ptr, &map->img.bpp, &map->img.size_l, &map->img.endian);

	map->offset = 2;
	map->change_alt = 0.2;
	map->const1 = 1;
	map->const2 = 1;
	map->start_point.x = WIN_WIDTH / 2;
	map->start_point.y = 0;
	map->view = 1;
	trace_horizontal(map, map->img.data);
	trace_vertical(map, map->img.data);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	mlx_key_hook(map->win_ptr, &all, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
