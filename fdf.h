/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:11:28 by afonck            #+#    #+#             */
/*   Updated: 2019/03/21 14:14:38 by afonck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# define WIN_WIDTH 2560
# define WIN_HEIGHT 1440

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;
/*
typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;
*/
typedef struct	s_screenpoint
{
	int			x;
	int			y;
}				t_screenpoint;

typedef struct	s_map
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	int			**tab;
	int			h_max;
	int			w_max;
	int			offset;
	double		const1;
	double		const2;
	int			change_alt;
	t_screenpoint	point_one;
	t_screenpoint	point_two;
}				t_map;

char			**check_and_read(char *arg, t_map *map);

void			count_nb_lines(char *arg, t_map *map);

void			atoi_tab(char **tabchar, t_map *map);

int				countwords(char *s, char c);

void			draw_line(int x1, int y1, int x2, int y2, int *data);

int				zoom(int key, t_map *map);

void			trace_horizontal(t_map *map, int *data);

void			trace_vertical(t_map *map, int *data);
#endif
