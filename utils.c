/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:20:42 by afonck            #+#    #+#             */
/*   Updated: 2019/03/25 16:29:02 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int             check_line(char *line)
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

int             check_fdf(char *argv)
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

void    error1(void)
{
	ft_putstr("Error while counting number of lines, aborting...\n");
	return ;
}

char    **error2(char *line)
{
	ft_memdel((void **)&line);
	return (NULL);
}

int             error3(void)
{
	ft_putstr("problem with map format, aborting...\n");
	return (-1);
}

void    del_tab(char **tab, int len)
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
