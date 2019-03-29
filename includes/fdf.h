/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:11:28 by afonck            #+#    #+#             */
/*   Updated: 2019/03/29 11:26:18 by sluetzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include "keys_and_mouse.h"
# define WIN_WIDTH 2560
# define WIN_HEIGHT 1440

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_screenpoint
{
	int				x;
	int				y;
}					t_screenpoint;

typedef struct		s_start_point
{
	int				x;
	int				y;
	int				xpar;
	int				ypar;
}					t_start_point;

typedef struct		s_mouse
{
	int				x;
	int				y;
}					t_mouse;

typedef struct		s_map
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	int				**tab;
	double			h_max;
	double			w_max;
	int				altitude_z;
	int				view;
	int				color;
	int				menu;
	int				dx;
	int				dy;
	int				i;
	int				j;
	double			offset;
	double			const1;
	double			const2;
	double			change_alt;
	t_start_point	start_point;
	t_screenpoint	point_one;
	t_screenpoint	point_two;
	t_mouse			mouse;
}					t_map;

/*
** PARSING |||||||||||||||||||||||||||||
*/

t_map				*parse(char *argv);

char				**check_and_read(char *arg, t_map *map);

int					check_line(char *line);

int					check_fdf(char *argv);

void				count_nb_lines(char *arg, t_map *map);

int					atoi_tab(char **tabchar, t_map *map);

int					countwords(char *s, char c);

/*
** DRAWING ||||||||||||||||||||||||||||
*/

void				draw_line(t_map *map, int *data);

void				trace_par_or_iso(t_map *map);

void				trace_horizontal(t_map *map, int *data);

void				trace_vertical(t_map *map, int *data);

void                trace_horizontal_par(t_map *map, int *data);

void                trace_vertical_par(t_map *map, int *data);

void				trace_all(t_map *map);

void				fill_pix(int *data, int x, int y, int z, t_map *map);

void				change_c(int key, t_map *map);
/*
** KEY EVENTS |||||||||||||||||||||||||
*/

void				altitude(int key, t_map *map);

void				zoom(int key, t_map *map);

void				move(int key, t_map *map);

void				close_window(t_map *map);

void				reset(t_map *map);

void				change_view(t_map *map);

void				menu(t_map *map);

void				destroy_and_clear(t_map *map);

void				keys_and_mouse(t_map *map);

int					key_press(int key, void *param);

int					mouse_press(int press, int x, int y, void *param);

void				init_map(t_map *map);

/*
** ERRORS |||||||||||||||||||||||||||||||||
*/

void				error_count(void);

char				**error_gnl(char *line, char **tab);

int					error_format(int **tab, int size);

char				**error_open_close(char **tab, int option, int size);

/*
** FREEING |||||||||||||||||||||||||||||||
*/

void				del_tab(char **tab, int len);

int				del_int_tab(int **tab, int len);
#endif
