/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:33:27 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/24 13:47:22 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_env(t_env *env)
{
	env->img = malloc(sizeof(t_image));
	env->mlx = malloc(sizeof(t_mlx));
	env->color = malloc(sizeof(t_color));
	env->d = malloc(sizeof(t_drawline));
	env->matrix = malloc(sizeof(t_matrix));
	env->map = malloc(sizeof(t_map));
	env->map->nb_columns = -1;
	env->map->x = 0;
	env->map->y = 0;
	env->map->i = 0;
	env->map->d = 0;
	RAND = 30;
	RED_KEY = 0;
	GREEN_KEY = 0;
	BLUE_KEY = 0;
}

int			main(int ac, char **av)
{
	t_env	env;
	char	*msg;

	msg = "wrong number of arguments.\nUsage :\t./fdf [map]";
	if (ac != 2)
		return ((int)(ft_failure(msg, 0)));
	init_env(&env);
	get_points(&env, av[1]);
	env.mlx->ptr_mlx = mlx_init();
	env.mlx->ptr_win = mlx_new_window(env.mlx->ptr_mlx, WIDHT_WIN,
			HEIGHT_WIN, "FDF");
	env.img->ptr_img = mlx_new_image(env.mlx->ptr_mlx, WIDHT_IMG, HEIGHT_IMG);
	env.img->bits_img = mlx_get_data_addr(env.img->ptr_img, &(env.img->bpp),
			&(env.img->size_line), &(env.img->end));
	draw_map(&env);
	mlx_do_key_autorepeaton(env.mlx->ptr_mlx);
	mlx_hook(env.mlx->ptr_win, 2, 0, event, &env);
	mlx_loop(env.mlx->ptr_mlx);
	return (0);
}
