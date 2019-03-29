/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:16:29 by afonck            #+#    #+#             */
/*   Updated: 2019/03/29 13:03:16 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_nb_lines(char *arg, t_map *map)
{
	int		nblines;
	char	*line;
	int		fd;
	int		ret;

	nblines = 0;
	map->h_max = 0;
	if ((fd = open(arg, O_RDONLY)) == -1)
		return (error_count());
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		nblines++;
		if (check_line(line) == -1)
		{
			ft_memdel((void **)&line);
			return (error_count());
		}
		ft_memdel((void **)&line);
	}
	if (ret == 0)
		ft_memdel((void **)&line);
	if ((close(fd)) == -1)
		return (error_count());
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
	if (map->h_max == 0)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(*tab) * (map->h_max))) == NULL)
		return (NULL);
	if ((fd = open(arg, O_RDONLY)) == -1)
		return (error_open_close(tab, 0, map->h_max));
	while (get_next_line(fd, &line) > 0)
	{
		if ((tab[i] = ft_strdup(line)) == NULL)
			return (error_gnl(line, tab));
		ft_memdel((void **)&line);
		i++;
	}
	ft_memdel((void **)&line);
	if ((close(fd)) == -1)
		return (error_open_close(tab, 1, map->h_max));
	return (tab);
}

int		atoi_tab(char **tabchar, t_map *map)
{
	int		i;
	int		j;
	char	**tmp;

	map->w_max = 0;
	if ((map->tab = (int **)malloc(sizeof(int*) * map->h_max)) == NULL)
		return (-1);
	i = -1;
	map->w_max = countwords(tabchar[i + 1], ' ');
	while (++i < map->h_max)
	{
		if (map->w_max != (map->w_max = countwords(tabchar[i], ' ')))
			return (error_format(map->tab, i));
		if ((map->tab[i] = (int *)malloc(sizeof(int) * (map->w_max))) == NULL)
			return (del_int_tab(map->tab, (i - 1)));
		if ((tmp = ft_strsplit(tabchar[i], ' ')) == NULL)
			return (del_int_tab(map->tab, i));
		j = -1;
		while (++j < map->w_max)
			map->tab[i][j] = ft_atoi(tmp[j]);
		del_tab(tmp, map->w_max);
	}
	return (0);
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

t_map	*parse(char *argv)
{
	t_map	*map;
	char	**tabchar;

	if ((check_fdf(argv)) == 0)
	{
		ft_putstr("input file must end with .fdf\n");
		return (NULL);
	}
	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	if ((tabchar = check_and_read(argv, map)) == NULL)
	{
		ft_memdel((void **)&map);
		return (NULL);
	}
	if ((atoi_tab(tabchar, map)) == -1)
	{
		del_tab(tabchar, map->h_max);
		ft_memdel((void **)&map);
		return (NULL);
	}
	del_tab(tabchar, map->h_max);
	return (map);
}
