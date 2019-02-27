/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:16:29 by afonck            #+#    #+#             */
/*   Updated: 2019/02/27 11:51:22 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_nb_lines(char *arg)
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
	return (nblines);
}

char	**check_and_read(char *arg)
{
	char	**tab;
	char	*line;
	int		i;
	int		fd;

	i = 0;
	if ((tab = (char **)malloc(sizeof(*tab) * (count_nb_lines(arg)))) == NULL)
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

int		**atoi_tab(char **tabchar, int size)
{
	int i;
	int j;
	int **tabint;

	if ((tabint = (int **)malloc(sizeof(*tabint) * size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if ((tabint[i] = (int *)malloc(sizeof(**tabint) * (countwords(tabchar[i], ' ')))) == NULL)
			return (NULL);
		j = 0;
		while (tabchar[i][j])
		{
			j++;
		}
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
