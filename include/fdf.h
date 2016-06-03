/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:34:12 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/25 13:48:19 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16
# define KEY_U 32
# define KEY_I 34
# define KEY_O 31
# define KEY_P 35
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_M 46
# define KEY_ESC 53
# define KEY_PAD_0 82
# define KEY_PAD_1 83
# define KEY_PAD_2 84
# define KEY_PAD_3 85
# define KEY_PAD_4 86
# define KEY_PAD_5 87
# define KEY_PAD_6 88
# define KEY_PAD_7 89
# define KEY_PAD_8 91
# define KEY_PAD_9 92
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_DEL 51
# define KEY_RET 36
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define Y_M env->map->y
# define X_M env->map->x
# define I_M env->map->i
# define D_M env->map->d
# define NB_COLUMNS env->map->nb_columns
# define NB_LINES env->map->nb_lines
# define NB_POINTS env->map->nb_points
# define SIZE_X env->map->size_x
# define SIZE_Y env->map->size_x
# define SIZELINE env->img->size_line
# define R env->color->r
# define G env->color->g
# define B env->color->b
# define RAND env->color->rand
# define RED_KEY env->color->red
# define GREEN_KEY env->color->green
# define BLUE_KEY env->color->blue
# define MULT_Z 3
# define WIDHT_IMG 1300
# define HEIGHT_IMG 1300
# define WIDHT_WIN 1300
# define HEIGHT_WIN 1300
# define TRANSLATE_VALUE 42
# define ROTATE_VALUE 0.174533
# define ZOOM_VALUE 1.5
# define DIAG_OK 0
# define COLOR_MULT 20

typedef struct	s_matrix
{
	double		a1;
	double		a2;
	double		a3;
	double		b1;
	double		b2;
	double		b3;
	double		c1;
	double		c2;
	double		c3;
}				t_matrix;

typedef struct	s_image
{
	void		*ptr_img;
	char		*bits_img;
	int			size_line;
	int			bpp;
	int			end;
}				t_image;

typedef struct	s_mlx
{
	void		*ptr_mlx;
	void		*ptr_win;
}				t_mlx;

typedef struct	s_point
{
	double		x;
	double		x_base;
	double		y;
	double		y_base;
	double		z;
	double		z_base;
}				t_point;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
	int			t;
	int			red;
	int			green;
	int			blue;
	int			rand;
}				t_color;

typedef struct	s_drawline
{
	double		dx;
	double		dy;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		z1;
	double		z2;
	double		e;
}				t_drawline;

typedef struct	s_map
{
	int			nb_columns;
	int			nb_lines;
	int			nb_points;
	int			y;
	int			i;
	int			d;
	int			x;
	double		size_x;
	double		size_y;
}				t_map;

typedef struct	s_env
{
	t_image		*img;
	t_mlx		*mlx;
	t_point		**pts;
	t_color		*color;
	t_drawline	*d;
	t_matrix	*matrix;
	t_map		*map;
}				t_env;

void			get_points(t_env *env, char *av);
void			draw_map(t_env *env);
void			print_points(t_env	*env);

/*
**	==========	**
**	  EVENTS	**
**	==========	**
*/

int				event(int keycode, void *cp_env);
void			rotate_points(t_env *env, char axe, double teta);
void			translate_points(t_env *env, int keycode, double distance);
void			zoom_points(t_env *env, char type, double value);
void			change_color(t_env *env, int mkeycode);
void			end_program(void);
void			refresh_map(t_env *env);

/*
**	==========	**
**	 DRAWLINE	**
**	==========	**
*/

void			ft_drawline(t_env *env, t_point p1, t_point p2);
void			ft_get_color(t_env *env, double z1, double z2);
void			ft_write_pixel(t_env *env, int x, int y);
void			cadran1_a(t_drawline *draw, t_env *env);
void			cadran1_b(t_drawline *draw, t_env *env);
void			cadran2_a(t_drawline *draw, t_env *env);
void			cadran2_b(t_drawline *draw, t_env *env);
void			cadran3_a(t_drawline *draw, t_env *env);
void			cadran3_b(t_drawline *draw, t_env *env);
void			cadran4_a(t_drawline *draw, t_env *env);
void			cadran4_b(t_drawline *draw, t_env *env);
void			dx_null_a(t_drawline *draw, t_env *env);
void			dx_null_b(t_drawline *draw, t_env *env);
void			dy_null_a(t_drawline *draw, t_env *env);
void			dy_null_b(t_drawline *draw, t_env *env);
int				test(t_env *env);

#endif
