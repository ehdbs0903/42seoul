/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:26:27 by doykim            #+#    #+#             */
/*   Updated: 2022/01/16 13:09:01 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx;
	unsigned int	len;

	idx = 0;
	len = 0;
	while (dest[len] != '\0')
		len++;
	while (src[idx] && idx < nb)
		dest[len++] = src[idx++];
	dest[len] = '\0';
	return (dest);
}
