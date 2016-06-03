/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:57:21 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:52:19 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_color(t_env *env, double z1, double z2)
{
	int	z;

	if (z1 > z2)
		z = z1 - ((z1 - z2) / 2);
	else if (z1 < z2)
		z = z2 - ((z2 - z1) / 2);
	else
		z = z1;
	R = ((z + RAND + RED_KEY) % 255);
	G = ((z + RAND + GREEN_KEY) % 255);
	B = ((z + RAND + BLUE_KEY) % 255);
}

void	ft_write_pixel(t_env *env, int x, int y)
{
	if (x > 0 && x < WIDHT_IMG && y > 0 && y < HEIGHT_IMG)
	{
		env->img->bits_img[(4 * (x + SIZELINE / 4 * y))] = B;
		env->img->bits_img[(4 * (x + SIZELINE / 4 * y)) + 1] = G;
		env->img->bits_img[(4 * (x + SIZELINE / 4 * y)) + 2] = R;
	}
}

void	other_cadran(t_drawline *draw, t_env *env)
{
	if (draw->dx < 0 && draw->dy > 0 && -(draw->dx) < draw->dy)
		cadran3_a(draw, env);
	else if (draw->dx < 0 && draw->dy > 0 && -(draw->dx) >= draw->dy)
		cadran3_b(draw, env);
	else if (draw->dx < 0 && draw->dy < 0 && draw->dx <= draw->dy)
		cadran4_a(draw, env);
	else if (draw->dx < 0 && draw->dy < 0 && draw->dx > draw->dy)
		cadran4_b(draw, env);
	else if (draw->dx == 0 && draw->dy > 0)
		(dx_null_a(draw, env));
	else if (draw->dx == 0 && draw->dy < 0)
		(dx_null_b(draw, env));
	else if (draw->dy == 0 && draw->dx > 0)
		(dy_null_a(draw, env));
	else if (draw->dy == 0 && draw->dx < 0)
		(dy_null_b(draw, env));
	else
		ft_write_pixel(env, (int)draw->x1, (int)draw->y1);
}

void	ft_drawline(t_env *env, t_point p1, t_point p2)
{
	t_drawline	*draw;

	ft_get_color(env, p1.z_base * COLOR_MULT, p2.z_base * COLOR_MULT);
	draw = malloc(sizeof(t_drawline));
	draw->x1 = p1.x;
	draw->x2 = p2.x;
	draw->y1 = p1.y;
	draw->y2 = p2.y;
	draw->dx = p2.x - p1.x;
	draw->dy = p2.y - p1.y;
	if (draw->dx > 0 && draw->dy < 0 && draw->dx < -(draw->dy))
		cadran1_a(draw, env);
	else if (draw->dx > 0 && draw->dy < 0 && draw->dx >= -(draw->dy))
		cadran1_b(draw, env);
	else if (draw->dx > 0 && draw->dy > 0 && draw->dx >= draw->dy)
		cadran2_a(draw, env);
	else if (draw->dx > 0 && draw->dy > 0 && draw->dx < draw->dy)
		cadran2_b(draw, env);
	else
		other_cadran(draw, env);
	free(draw);
}
