/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:48:19 by afonck            #+#    #+#             */
/*   Updated: 2019/03/27 14:04:42 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_count(void)
{
	ft_putstr("Error while counting number of lines, aborting...\n");
	return ;
}

char	**error_gnl(char *line, char **tab)
{
	ft_putstr("There was an error while parsing the file...\n");
	ft_memdel((void **)&tab);
	ft_memdel((void **)&line);
	return (NULL);
}

int		error_format(void)
{
	ft_putstr("problem with map format, aborting...\n");
	return (-1);
}

char	**error_open_close(char **tab, int option, int size)
{
	ft_putstr("Error while opening or closing the file...\n");
	if (option == 1)
		del_tab(tab, size);
	ft_memdel((void **)&tab);
	return (NULL);
}
