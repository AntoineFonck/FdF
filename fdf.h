/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:11:28 by afonck            #+#    #+#             */
/*   Updated: 2019/03/25 18:08:22 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# define WIN_WIDTH 1680
# define WIN_HEIGHT 1050

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;
/*
typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;
*/
typedef struct		s_screenpoint
{
	int				x;
	int				y;
}					t_screenpoint;

typedef struct		s_start_point
{
	int				x;
	int				y;
	int				h;
}					t_start_point;

typedef struct		s_map
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	int				**tab;
	int				h_max;
	int				w_max;
	int				altitude_z;
	int				view;
	int				menu;
	int				dx;
	int				dy;
	double			gamma;
	double			offset;
	double			const1;
	double			const2;
	double			change_alt;
	t_start_point	start_point;
	t_screenpoint	point_one;
	t_screenpoint	point_two;
}					t_map;

char				**check_and_read(char *arg, t_map *map);

void				count_nb_lines(char *arg, t_map *map);

int				atoi_tab(char **tabchar, t_map *map);

int					countwords(char *s, char c);

void				draw_line(t_map *map, int *data);

int					altitude(int key, t_map *map);

int					zoom(int key, t_map *map);

int					all(int key, t_map *map);

void				trace_horizontal(t_map *map, int *data);

void				trace_vertical(t_map *map, int *data);

void				fill_pix(int *data, int x, int y, int z);

void				menu(t_map *map);

void				trace_all(t_map *map);

void				trace_par_or_hor(t_map *map);

void				destroy_and_clear(t_map *map);

void				init_map(t_map *map);

void				keys_and_mouse(t_map *map);

int     key_press(int key, t_map *map);

int     key_release(int key, t_map *map);

int     mouse_press(int press, int x, int y, void *param);

int     mouse_release(int press/*, int x, int y*/, t_map *map);

int     mouse_moving(int x, int y, t_map *map);

int     expose(t_map *map);

void    init_map(t_map *map);

t_map	*parse(char *argv);

int			check_line(char *line);

int			check_fdf(char *argv);

void		error1(void);

char		**error2(char *line);

int			error3(void);

void		del_tab(char **tab, int len);
#endif
