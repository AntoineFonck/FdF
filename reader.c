/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:16:29 by afonck            #+#    #+#             */
/*   Updated: 2019/03/25 15:03:03 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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

void	error1(void)
{
	ft_putstr("Error while counting number of lines, aborting...\n");
	return ;
}

void	count_nb_lines(char *arg, t_map *map)
{
	int		nblines;
	int		i;
	char	*line;
	int		fd;

	if ((fd = open(arg, O_RDONLY)) == -1)
		return (error1());
	nblines = 0;
	map->h_max = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		nblines++;
		if (check_line(line) == -1)
		{
			ft_memdel((void **)&line);
			return (error1());
		}
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	if ((close(fd)) == -1)
		return (error1());
	map->h_max = nblines;
}

char	**error2(char *line)
{
	ft_memdel((void **)&line);
	return (NULL);
}

char	**check_and_read(char *arg, t_map *map)
{
	char	**tab;
	char	*line;
	int		i;
	int		fd;

	i = 0;
	count_nb_lines(arg, map);
	if (map->h_max == 0)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(*tab) * (map->h_max))) == NULL)
		return (NULL);
	if ((fd = open(arg, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		if ((tab[i] = ft_strdup(line)) == NULL)
			return (error2(line));
		ft_memdel((void **)&line);
		i++;
	}
	ft_memdel((void **)&line);
	if ((close(fd)) == -1)
		return (NULL);
	return (tab);
}

void	error3(void)
{
	ft_putstr("problem with map format, aborting...\n");
	exit(-1);
	return ;
}

void	atoi_tab(char **tabchar, t_map *map)
{
	int		i;
	int		j;
	char	**tmp;

	map->w_max = 0;
	if ((map->tab = (int **)malloc(sizeof(int*) * map->h_max)) == NULL)
		return ;
	i = -1;
	map->w_max = countwords(tabchar[i + 1], ' ');
	while (++i < map->h_max)
	{
		if (map->w_max != (map->w_max = countwords(tabchar[i], ' ')))
			return (error3());
		if ((map->tab[i] = (int *)malloc(sizeof(int) * (map->w_max))) == NULL)
			return ;
		if ((tmp = ft_strsplit(tabchar[i], ' ')) == NULL)
			return ;
		j = -1;
		while (++j < map->w_max)
		{
			map->tab[i][j] = ft_atoi(tmp[j]);
			ft_memdel((void **)&tmp[j]);
		}
		ft_memdel((void **)&tmp);
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
