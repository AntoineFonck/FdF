/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:30:57 by afonck            #+#    #+#             */
/*   Updated: 2019/02/14 15:59:28 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

int		deal_key(int key, t_coor *lol)
{
	mlx_pixel_put(lol->mlx_ptr, lol->win_ptr, lol->x, lol->y, 0xFFFFFF);
	lol->x++;
	lol->y++;
	return (0);
}

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_coor	*lol;

	if ((lol = malloc(sizeof(lol))) == NULL)
		return (1);
	lol->x = 0;
	lol->y = 0;
	lol->mlx_ptr = mlx_init();
	lol->win_ptr = mlx_new_window(lol->mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(lol->mlx_ptr, lol->win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(lol->win_ptr, deal_key, lol);
	mlx_loop(lol->mlx_ptr);
	return (0);
}
