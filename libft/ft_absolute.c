/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluetzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:20:11 by sluetzen          #+#    #+#             */
/*   Updated: 2019/03/18 17:34:25 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_absolute(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}
