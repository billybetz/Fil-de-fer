/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:19:22 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:53:37 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		x_translate(t_env *env, double dist)
{
	int i;

	i = 0;
	while (i < NB_POINTS)
	{
		env->pts[i]->x += dist;
		i++;
	}
}

static void		y_translate(t_env *env, double dist)
{
	int i;

	i = 0;
	while (i < NB_POINTS)
	{
		env->pts[i]->y += dist;
		i++;
	}
}

void			translate_points(t_env *env, int keycode, double distance)
{
	if (keycode == KEY_UP)
		y_translate(env, -distance);
	else if (keycode == KEY_DOWN)
		y_translate(env, distance);
	else if (keycode == KEY_RIGHT)
		x_translate(env, distance);
	else if (keycode == KEY_LEFT)
		x_translate(env, -distance);
}
