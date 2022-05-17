/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:43:13 by doykim            #+#    #+#             */
/*   Updated: 2022/01/17 09:28:52 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	len;
	unsigned int	len2;

	idx = 0;
	len = 0;
	len2 = 0;
	while (dest[len] != '\0')
		len++;
	while (src[len2])
		len2++;
	if (size <= len)
		return (size + len2);
	len2 += len;
	while (src[idx] && len < size - 1)
	{
		dest[len++] = src[idx++];
	}
	dest[len] = '\0';
	return (len2);
}
