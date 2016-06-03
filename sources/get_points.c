/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 11:06:30 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:45:00 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_nb(char **map)
{
	int i;
	int y;
	int nb_words;

	y = 0;
	i = 0;
	nb_words = 0;
	while (map && map[y])
	{
		while (map[y][i])
		{
			if (map[y][i] != ' ')
				nb_words++;
			while (map[y][i] && map[y][i] != ' ')
				i++;
			if (map[y][i] == ' ')
				i++;
		}
		i = 0;
		y++;
	}
	return (nb_words);
}

static char	*get_nbr(char *str, int i)
{
	int		d;
	char	*nbr;

	d = 0;
	nbr = malloc(sizeof(char) * 10);
	if (str[i] == '-')
	{
		nbr[0] = '-';
		d++;
		i++;
	}
	if (ft_isdigit(str[i]) == 0)
		exit((int)ft_failure("FILE ERROR. (bad character after '-')", 0));
	while (ft_isdigit(str[i]) == 1)
	{
		nbr[d] = str[i];
		i++;
		d++;
	}
	nbr[d] = '\0';
	return (nbr);
}

static void	get_points2(t_env *env, char **map)
{
	char	*tmp;

	if ((ft_isdigit(map[Y_M][I_M]) == 0) && (map[Y_M][I_M] !=
			' ' && (map[Y_M][I_M] != '-')))
		exit((int)ft_failure("NON-DIGIT CHARACTER IN FILE.", 0));
	while (map[Y_M][I_M] == ' ')
		I_M++;
	if (ft_isdigit(map[Y_M][I_M]) == 1 || (map[Y_M][I_M] == '-'))
	{
		env->pts[D_M] = malloc(sizeof(t_point));
		env->pts[D_M]->x = X_M * 25 + (WIDHT_IMG / 3);
		env->pts[D_M]->x_base = env->pts[D_M]->x;
		env->pts[D_M]->y = Y_M * 25 + (HEIGHT_IMG / 3);
		env->pts[D_M]->y_base = env->pts[D_M]->y;
		tmp = get_nbr(map[Y_M], I_M);
		env->pts[D_M]->z = ft_atoi(tmp) * MULT_Z;
		free(tmp);
		env->pts[D_M]->z_base = env->pts[D_M]->z;
		while (ft_isdigit(map[Y_M][I_M]) == 1 || (map[Y_M][I_M] == '-'))
			I_M++;
		D_M++;
		X_M++;
	}
}

static void	free_map(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void		get_points(t_env *env, char *av)
{
	char **map;

	if (!(ft_get_file(av, &map)))
		exit((int)ft_failure("FILE ERROR (get_file).", 0));
	env->pts = (t_point**)malloc(sizeof(t_point*) * (count_nb(map) + 1));
	if (!(env->pts))
		exit((int)ft_failure("Malloc error -> ft_check_file -> pts.", 0));
	while (map[Y_M])
	{
		while (map[Y_M][I_M])
			get_points2(env, map);
		if (NB_COLUMNS != -1 && NB_COLUMNS != X_M)
			exit((int)ft_failure("NO RECTANGULAR MAP", 0));
		NB_COLUMNS = X_M;
		I_M = 0;
		X_M = 0;
		Y_M++;
	}
	NB_LINES = Y_M;
	NB_POINTS = NB_COLUMNS * NB_LINES;
	env->pts[D_M] = malloc(sizeof(t_point));
	free_map(map);
}
