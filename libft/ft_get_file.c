/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:49:33 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/16 13:57:53 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_file(char *av, char ***map)
{
	int		fd;
	int		nb_return;
	int		i;
	char	*line;

	i = 0;
	nb_return = 0;
	if ((fd = open(av, O_RDWR)) < 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		nb_return++;
	}
	close(fd);
	if (!(*map = (char**)malloc(sizeof(char*) * (nb_return + 1))))
		return (0);
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &((*map)[i])) > 0)
		i++;
	close(fd);
	(*map)[i] = NULL;
	return (1);
}
