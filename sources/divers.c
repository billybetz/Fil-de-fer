/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:37:09 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:56:08 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color(t_env *env, int keycode)
{
	if (keycode == KEY_C)
		RAND += 10;
	else if (keycode == KEY_V)
		RAND -= 10;
	else if (keycode == KEY_I)
		RED_KEY += 5;
	else if (keycode == KEY_O)
		BLUE_KEY += 5;
	else if (keycode == KEY_P)
		GREEN_KEY += 5;
}

void	end_program(void)
{
	exit(ft_success("Map closed", 0));
}

void	refresh_map(t_env *env)
{
	int i;

	i = 0;
	while (i < NB_POINTS)
	{
		env->pts[i]->x = env->pts[i]->x_base;
		env->pts[i]->y = env->pts[i]->y_base;
		env->pts[i]->z = env->pts[i]->z_base;
		i++;
	}
}
