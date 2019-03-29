/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:20:42 by afonck            #+#    #+#             */
/*   Updated: 2019/03/29 11:32:23 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_line(char *line)
{
	size_t i;

	i = 0;
	while ((ft_isdigit(line[i]) || line[i] == '-' || line[i] == ' ') && line[i])
		i++;
	if (i < (ft_strlen(line)))
		return (-1);
	else
		return (0);
}

int		check_fdf(char *argv)
{
	int i;

	i = ft_strlen(argv) - 1;
	if (argv[i--] != 'f')
		return (0);
	if (argv[i--] != 'd')
		return (0);
	if (argv[i--] != 'f')
		return (0);
	if (argv[i--] != '.')
		return (0);
	return (1);
}

void	del_tab(char **tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_memdel((void **)&tab[i]);
		i++;
	}
	ft_memdel((void **)&tab);
	return ;
}

int		del_int_tab(int **tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_memdel((void **)&tab[i]);
		i++;
	}
	ft_memdel((void **)&tab);
	return (-1);
}

void	set_points(t_map *map, int key)
{
	if (key == ARROW_UP)
	{
		map->start_point.y -= 10;
		map->start_point.ypar -= 10;
		map->start_point.x -= 10;
	}
	else if (key == ARROW_DOWN)
	{
		map->start_point.y += 10;
		map->start_point.ypar += 10;
		map->start_point.x += 10;
	}
	else if (key == ARROW_LEFT)
	{
		map->start_point.x -= 10;
		map->start_point.xpar -= 20;
		map->start_point.y += 10;
	}
	else if (key == ARROW_RIGHT)
	{
		map->start_point.x += 10;
		map->start_point.xpar += 20;
		map->start_point.y -= 10;
	}
}
