/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:52:35 by doykim            #+#    #+#             */
/*   Updated: 2022/01/20 21:54:30 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
