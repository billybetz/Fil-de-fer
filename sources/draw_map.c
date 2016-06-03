/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 13:52:45 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:40:49 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init(int *y, int *x, int *i, int *nb)
{
	*y = 0;
	*x = 0;
	*i = 0;
	*nb = 0;
}

void		put_points(t_env *env)
{
	int		y;
	int		x;
	int		i;
	int		nb;

	init(&y, &x, &i, &nb);
	SIZE_X = (env->pts[NB_COLUMNS - 1]->x) - (env->pts[0]->x);
	SIZE_Y = (env->pts[NB_LINES * (NB_COLUMNS - 1)]->y) - (env->pts[0]->y);
	while (i < NB_POINTS)
	{
		if (x < NB_COLUMNS - 1)
			ft_drawline(env, (*env->pts[i]), (*env->pts[i + 1]));
		if (y < NB_LINES - 1)
			ft_drawline(env, (*env->pts[i]), (*env->pts[i + NB_COLUMNS]));
		if (y < NB_LINES - 1 && x < NB_COLUMNS - 1 && DIAG_OK == 1)
			ft_drawline(env, (*env->pts[i]), (*env->pts[i + NB_COLUMNS + 1]));
		if (x == NB_COLUMNS - 1)
		{
			x = 0;
			y++;
		}
		else
			x++;
		i++;
	}
}

void		draw_map(t_env *env)
{
	mlx_destroy_image(env->mlx->ptr_mlx, env->img->ptr_img);
	env->img = malloc(sizeof(t_image));
	env->img->ptr_img = mlx_new_image(env->mlx->ptr_mlx, 1300, 1300);
	env->img->bits_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	put_points(env);
	mlx_put_image_to_window(env->mlx->ptr_mlx, env->mlx->ptr_win,
		env->img->ptr_img, 0, 0);
}
