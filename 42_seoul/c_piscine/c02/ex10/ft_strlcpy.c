/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:35:22 by doykim            #+#    #+#             */
/*   Updated: 2022/01/16 12:48:14 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char	*ch)
{
	unsigned int	i;

	i = 0;
	while (ch[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char	*dest, char	*src, unsigned int size)
{
	int				i;
	unsigned int	cpy_size;

	if (size > 0)
	{
		cpy_size = size - 1;
		i = 0;
		while (src[i] != '\0' && cpy_size > 0)
		{
			dest[i] = src[i];
			i++;
			cpy_size--;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
