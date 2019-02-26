/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:16:29 by afonck            #+#    #+#             */
/*   Updated: 2019/02/26 11:21:56 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**check_and_read(char *arg)
{
	char	**tab;
	char	*line;
	int		ret;
	int		max_h;

	max_h = 0;
	if ((fd = open(arg, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_strdup(tab[max_h], line);
		ft_memdel(&line);
		max_h++;
	}
	if (ret == 0)
		return (tab);
	return (NULL);
}
