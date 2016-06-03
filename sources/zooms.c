/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:19:48 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:45:43 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		zoom(t_env *env, double value)
{
	int i;

	i = 0;
	while (i < NB_POINTS)
	{
		env->pts[i]->x -= (WIDHT_IMG / 3);
		env->pts[i]->y -= (HEIGHT_IMG / 3);
		env->pts[i]->x *= value;
		env->pts[i]->y *= value;
		env->pts[i]->x += (WIDHT_IMG / 3);
		env->pts[i]->y += (HEIGHT_IMG / 3);
		i++;
	}
}

static void		dezoom(t_env *env, double value)
{
	int i;

	i = 0;
	while (i < NB_POINTS)
	{
		env->pts[i]->x -= (WIDHT_IMG / 3);
		env->pts[i]->y -= (HEIGHT_IMG / 3);
		env->pts[i]->x /= value;
		env->pts[i]->y /= value;
		env->pts[i]->x += (WIDHT_IMG / 3);
		env->pts[i]->y += (HEIGHT_IMG / 3);
		i++;
	}
}

void			zoom_points(t_env *env, char type, double value)
{
	if (type == '+')
		zoom(env, value);
	else if (type == '-')
		dezoom(env, value);
}
