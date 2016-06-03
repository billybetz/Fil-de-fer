/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 13:42:49 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:42:46 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		apply_matrix(t_env *env, int i)
{
	double x_tmp;
	double y_tmp;

	x_tmp = (env->pts[i]->x * env->matrix->a1 + env->pts[i]->y *
			env->matrix->b1 + env->pts[i]->z * env->matrix->c1);
	y_tmp = (env->pts[i]->x * env->matrix->a2 + env->pts[i]->y *
			env->matrix->b2 + env->pts[i]->z * env->matrix->c2);
	env->pts[i]->z = (env->pts[i]->x * env->matrix->a3 + env->pts[i]->y *
			env->matrix->b3 + env->pts[i]->z * env->matrix->c3);
	env->pts[i]->x = x_tmp;
	env->pts[i]->y = y_tmp;
}

static void		x_rotate(t_env *env, double teta)
{
	int i;

	i = 0;
	env->matrix->a1 = 1;
	env->matrix->a2 = 0;
	env->matrix->a3 = 0;
	env->matrix->b1 = 0;
	env->matrix->b2 = cos(teta);
	env->matrix->b3 = -(sin(teta));
	env->matrix->c1 = 0;
	env->matrix->c2 = sin(teta);
	env->matrix->c3 = cos(teta);
	while (i < NB_POINTS)
	{
		env->pts[i]->x -= (WIDHT_IMG / 3);
		env->pts[i]->y -= (HEIGHT_IMG / 3);
		apply_matrix(env, i);
		env->pts[i]->x += (WIDHT_IMG / 3);
		env->pts[i]->y += (HEIGHT_IMG / 3);
		i++;
	}
}

static void		y_rotate(t_env *env, double teta)
{
	int i;

	i = 0;
	env->matrix->a1 = cos(teta);
	env->matrix->a2 = 0;
	env->matrix->a3 = sin(teta);
	env->matrix->b1 = 0;
	env->matrix->b2 = 1;
	env->matrix->b3 = 0;
	env->matrix->c1 = -sin(teta);
	env->matrix->c2 = 0;
	env->matrix->c3 = cos(teta);
	while (i < NB_POINTS)
	{
		env->pts[i]->x -= (WIDHT_IMG / 3);
		env->pts[i]->y -= (HEIGHT_IMG / 3);
		apply_matrix(env, i);
		env->pts[i]->x += (WIDHT_IMG / 3);
		env->pts[i]->y += (HEIGHT_IMG / 3);
		i++;
	}
}

static void		z_rotate(t_env *env, double teta)
{
	int i;

	i = 0;
	env->matrix->a1 = cos(teta);
	env->matrix->a2 = -sin(teta);
	env->matrix->a3 = 0;
	env->matrix->b1 = sin(teta);
	env->matrix->b2 = cos(teta);
	env->matrix->b3 = 0;
	env->matrix->c1 = 0;
	env->matrix->c2 = 0;
	env->matrix->c3 = 1;
	while (i < NB_POINTS)
	{
		env->pts[i]->x -= (WIDHT_IMG / 3);
		env->pts[i]->y -= (HEIGHT_IMG / 3);
		apply_matrix(env, i);
		env->pts[i]->x += (WIDHT_IMG / 3);
		env->pts[i]->y += (HEIGHT_IMG / 3);
		i++;
	}
}

void			rotate_points(t_env *env, char axe, double teta)
{
	if (axe == 'x')
		x_rotate(env, teta);
	else if (axe == 'y')
		y_rotate(env, teta);
	else if (axe == 'z')
		z_rotate(env, teta);
}
