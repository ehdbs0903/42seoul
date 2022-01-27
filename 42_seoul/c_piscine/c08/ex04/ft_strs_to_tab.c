/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:27:30 by doykim            #+#    #+#             */
/*   Updated: 2022/01/24 20:54:51 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*dupstr;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	dupstr = (char *)malloc(sizeof (char) * (len + 1));
	if (dupstr == 0)
		return (0);
	while (i < len)
	{
		dupstr[i] = src[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*st_str;
	int			i;
	int			len;

	i = 0;
	st_str = (t_stock_str *)malloc(sizeof (t_stock_str) * (ac + 1));
	if (st_str == NULL)
		return (NULL);
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		st_str[i].size = len;
		st_str[i].str = av[i];
		st_str[i].copy = ft_strdup(av[i]);
		i++;
	}
	st_str[i].size = 0;
	st_str[i].str = 0;
	st_str[i].copy = 0;
	return (st_str);
}
