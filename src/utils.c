/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:20:42 by afonck            #+#    #+#             */
/*   Updated: 2019/03/27 14:14:12 by sluetzen         ###   ########.fr       */
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

int	del_int_tab(int **tab, int len)
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
