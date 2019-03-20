/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:30:57 by afonck            #+#    #+#             */
/*   Updated: 2019/03/20 12:34:10 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	fill_pix(int *data, int x, int y, int color)
{
	data[x + y * WIN_WIDTH] = color;
}

void		trace_horizontal(t_map *map, int *data)
{
	int x;
	int y;
	int i;
	int j;

	y = 0;
	i = 0;
	while (i < map->h_max/*y < (map->h_max * offset)*/)
	{
		x = WIN_WIDTH / 2;
		j = 0;
		while (j < map->w_max/*x < (map->w_max * offset)*/)
		{
			map->point_one.x = (map->const1 * x - map->const2 * y);
			map->point_one.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
			fill_pix(data, map->point_one.x, map->point_one.y, 0xFFFFFF);
			x += map->offset;
			map->point_two.x = (map->const1 * x - map->const2 * y);
			j++;
			if (j < map->w_max)
			{
				map->point_two.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
				draw_line(map->point_one.x, map->point_one.y, map->point_two.x, map->point_two.y, data);
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

	x = WIN_WIDTH / 2;
	j = 0;
	while (j < map->w_max/*y < (map->h_max * offset)*/)
	{
		y = 0;
		i = 0;
		while (i < map->h_max/*x < (map->w_max * offset)*/)
		{
			map->point_one.x = (map->const1 * x - map->const2 * y);
			map->point_one.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
			fill_pix(data, map->point_one.x, map->point_one.y, 0xFFFFFF);
			y += map->offset;
			map->point_two.x = (map->const1 * x - map->const2 * y);
			i++;
			if (i < map->h_max)
			{
				map->point_two.y = (-(map->tab[i][j]) * map->change_alt + (map->const1 / 2) * x + (map->const2 / 2) * y);
				draw_line(map->point_one.x, map->point_one.y, map->point_two.x, map->point_two.y, data);
			}
		}
		x += map->offset;
		j++;
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

	map->offset = 10;
	map->change_alt = 3;
	map->const1 = 1;
	map->const2 = 1;
	trace_horizontal(map, mlx.img.data);
	trace_vertical(map, mlx.img.data);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
