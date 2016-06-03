/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 12:29:57 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:55:43 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			event_divers(int keycode, void *cp_env)
{
	t_env	*env;

	env = cp_env;
	if (keycode == KEY_ESC)
		end_program();
	else if (keycode == KEY_C || keycode == KEY_V || keycode == KEY_I ||
		keycode == KEY_O || keycode == KEY_P)
		change_color(env, keycode);
	else if (keycode == KEY_R)
		refresh_map(env);
	draw_map(env);
	return (0);
}

int			event_rotate(int keycode, void *cp_env)
{
	t_env	*env;

	env = cp_env;
	if (keycode == KEY_W)
		rotate_points(env, 'x', ROTATE_VALUE);
	else if (keycode == KEY_S)
		rotate_points(env, 'x', -ROTATE_VALUE);
	else if (keycode == KEY_A)
		rotate_points(env, 'y', -ROTATE_VALUE);
	else if (keycode == KEY_D)
		rotate_points(env, 'y', ROTATE_VALUE);
	else if (keycode == KEY_E)
		rotate_points(env, 'z', ROTATE_VALUE);
	else if (keycode == KEY_Q)
		rotate_points(env, 'z', -ROTATE_VALUE);
	draw_map(env);
	return (0);
}

int			event_zoom(int keycode, void *cp_env)
{
	t_env	*env;

	env = cp_env;
	if (keycode == KEY_PLUS)
		zoom_points(env, '+', ZOOM_VALUE);
	else if (keycode == KEY_MINUS)
		zoom_points(env, '-', ZOOM_VALUE);
	draw_map(env);
	return (0);
}

int			event_translate(int keycode, void *cp_env)
{
	t_env	*env;

	env = cp_env;
	if (keycode == KEY_UP)
		translate_points(env, KEY_UP, TRANSLATE_VALUE);
	else if (keycode == KEY_DOWN)
		translate_points(env, KEY_DOWN, TRANSLATE_VALUE);
	else if (keycode == KEY_LEFT)
		translate_points(env, KEY_LEFT, TRANSLATE_VALUE);
	else if (keycode == KEY_RIGHT)
		translate_points(env, KEY_RIGHT, TRANSLATE_VALUE);
	draw_map(env);
	return (0);
}

int			event(int keycode, void *env)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	if ((keycode == KEY_S || keycode == KEY_A || keycode == KEY_W ||
			keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E))
		return (event_rotate(keycode, env));
	else if (keycode == KEY_UP || keycode == KEY_DOWN ||
			keycode == KEY_LEFT || keycode == KEY_RIGHT)
		return (event_translate(keycode, env));
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		return (event_zoom(keycode, env));
	else if (keycode == KEY_ESC || keycode == KEY_C || keycode == KEY_V
			|| keycode == KEY_R || keycode == KEY_P || keycode == KEY_O
			|| keycode == KEY_I)
		return (event_divers(keycode, env));
	return (0);
}
