/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:03:15 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/26 16:03:29 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		count;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == to_find[0])
		{
			count = 0;
			while (str[count] != '\0' && to_find[count] != '\0')
			{
				if (str[count] != to_find[count])
					break ;
				count++;
			}
			if (to_find[count] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
