/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:16:29 by afonck            #+#    #+#             */
/*   Updated: 2019/02/27 12:24:14 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_nb_lines(char *arg, t_map *map)
{
	int nblines;
	int i;
	char *line;
	int fd;

	if ((fd = open(arg, O_RDONLY)) == -1)
		return (-1);
	nblines = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		nblines++;
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	if ((close(fd)) == -1)
		return (-1);
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
		return (NULL);
	if ((fd = open(arg, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		tab[i] = ft_strdup(line);
		ft_memdel((void **)&line);
		i++;
	}
	ft_memdel((void **)&line);
	if ((close(fd)) == -1)
		return (NULL);
	return (tab);
}

void	**atoi_tab(char **tabchar, t_map *map)
{
	int i;
	int j;
	char **tmp;

	if ((map->tab = (int **)malloc(sizeof(map->(*tab)) * map->h_max)) == NULL)
		return (NULL);
	i = 0;
	while (i < map->h_max)
	{
		if ((map->tab[i] = (int *)malloc(sizeof(map->(**tab)) * (countwords(tabchar[i], ' ')))) == NULL)
			return (NULL);
		tmp = ft_strsplit(tabchar[i], ' ');
		while (j < (countwords(tabchar[i], ' ')))
		{
			map->tab[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		j = 0;
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
