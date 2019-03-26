/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:48:19 by afonck            #+#    #+#             */
/*   Updated: 2019/03/26 17:32:26 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
