/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:50:05 by doykim            #+#    #+#             */
/*   Updated: 2022/01/10 18:37:41 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	idx;
	int	len1;
	int	len2;

	idx = 0;
	len1 = 0;
	len2 = 0;
	while (dest[len1] != '\0')
		len1++;
	while (src[len2] != '\0')
		len2++;
	while (idx < len2)
	{
		dest[len1++] = src[idx++];
	}
	dest[len1] = '\0';
	return (dest);
}
