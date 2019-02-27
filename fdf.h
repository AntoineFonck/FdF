/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:11:28 by afonck            #+#    #+#             */
/*   Updated: 2019/02/27 13:12:31 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# define WIN_WIDTH 500
# define WIN_HEIGHT 500

typedef struct	s_map
{
	int			**tab;
	int			h_max;
	int			w_max;
}				t_map;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

char			**check_and_read(char *arg, t_map *map);

void			count_nb_lines(char *arg, t_map *map);

void			atoi_tab(char **tabchar, t_map *map);

int				countwords(char *s, char c);

#endif
