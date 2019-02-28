/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:16:29 by afonck            #+#    #+#             */
/*   Updated: 2019/02/27 13:46:30 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	count_nb_lines(char *arg, t_map *map)
{
	int nblines;
	int i;
	char *line;
	int fd;

	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		ft_putstr("problem with open in countnblines\n");
		return ;
	}
	nblines = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		nblines++;
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	if ((close(fd)) == -1)
	{
		ft_putstr("problem with close in countnblines\n");
		return ;
	}
	map->h_max = nblines;
}

char	**check_and_read(char *arg, t_map *map)
{
	char	**tab;
	char	*line;
	int		i;
	int		fd;

	i = 0;
	count_nb_lines(arg, map);
	if ((tab = (char **)malloc(sizeof(*tab) * (map->h_max))) == NULL)
	{
		ft_putstr("problem with checkandread malloc for tab\n");
		return (NULL);
	}
	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		ft_putstr("problem with open in checkandread\n");
		return (NULL);
	}
	while (get_next_line(fd, &line) > 0)
	{
		tab[i] = ft_strdup(line);
		if (tab[i] == NULL)
			printf("problem with strdup line to tab[%d]\n", i);
		ft_memdel((void **)&line);
		i++;
	}
	ft_memdel((void **)&line);
	if ((close(fd)) == -1)
	{
		ft_putstr("problem with close in checkandread\n");
		return (NULL);
	}
	return (tab);
}

void	atoi_tab(char **tabchar, t_map *map)
{
	int i;
	int j;
	char **tmp;
	int temp;

	map->w_max = 0;
	if ((map->tab = (int **)malloc(sizeof(int*) * map->h_max)) == NULL)
	{
		ft_putstr("problem with malloc map->tab in atoi_tab");
		return ;
	}
	i = 0;
	while (i < map->h_max)
	{
		temp = countwords(tabchar[i], ' ');
		if (temp > map->w_max)
		{
			printf("temp is equal to %d for i=%d\n", temp, i);
			map->w_max = temp;
		}
		if ((map->tab[i] = (int *)malloc(sizeof(int) * (temp))) == NULL)
		{
			printf("problem with malloc map->tab[%d] in atoi_tab\n", i);
			return ;
		}
		if ((tmp = ft_strsplit(tabchar[i], ' ')) == NULL)
		{
			printf("problem with strsplit when i=%d in atoi_tab\n", i);
			return ;
		}
		j = 0;
		while (j < map->w_max/*(countwords(tabchar[i], ' '))*/)
		{
			map->tab[i][j] = ft_atoi(tmp[j]);
			ft_memdel((void **)&tmp[j]);
			j++;
		}
		ft_memdel((void **)&tmp);
		i++;
	}
}

int		countwords(char *s, char c)
{
	size_t	i;
	size_t	nbwords;

	i = 0;
	nbwords = 0;
	if (s[i] == 0)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			nbwords++;
		while (s[i + 1] && s[i] != c)
			i++;
		i++;
	}
	return (nbwords);
}
